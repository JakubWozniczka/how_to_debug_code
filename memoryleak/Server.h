#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "CameraMoveController.h"
//#include <sanitizer/lsan_interface.h>

using boost::asio::ip::tcp;

class session
{
public:
  session(boost::asio::io_service& io_service)
    : socket_(io_service), controller(new CameraMoveController())
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        boost::bind(&session::handle_read, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

private:
  void handle_read(const boost::system::error_code& error,
      size_t bytes_transferred)
  {
    if (!error)
    {
		BOOST_LOG_TRIVIAL(trace) << "Command received:  : " << data_ << "\n";
		if (!std::string("turn off").compare(data_))
		{
			controller->StopCamera();
			BOOST_LOG_TRIVIAL(trace) << "Camera move stop: " << data_ << "\n";
		}
		else if (!std::string("turn on").compare(data_))
		{
			controller->MoveCamera();
			BOOST_LOG_TRIVIAL(trace) << "Camera move start: " << data_ << "\n";
		}
		else if (!std::string("home").compare(data_))
		{
			controller->GoToHome();
			BOOST_LOG_TRIVIAL(trace) << "Camera go to home: " << data_ << "\n";
		}

		//__lsan_do_recoverable_leak_check();
    }
    else
    {
      delete this;
    }
  }

  void handle_write(const boost::system::error_code& error)
  {
    if (!error)
    {
      socket_.async_read_some(boost::asio::buffer(data_, max_length),
          boost::bind(&session::handle_read, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
    else
    {
      delete this;
    }
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
  CameraMoveController* controller;
};

class server
{
public:
  server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
  {
    start_accept();
  }

private:
  void start_accept()
  {
    session* new_session = new session(io_service_);
    acceptor_.async_accept(new_session->socket(),
        boost::bind(&server::handle_accept, this, new_session,
          boost::asio::placeholders::error));
  }

  void handle_accept(session* new_session,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      new_session->start();
    }
    else
    {
      delete new_session;
    }

    start_accept();
  }

  boost::asio::io_service& io_service_;
  tcp::acceptor acceptor_;
};
