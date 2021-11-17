

#include <iostream>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <thread>
#include "Server.h"
#include <pthread.h>

int Global;
void *Thread1(void *x) {
  Global = 42;
  return x;
}


int main(int argc, char** argv)
{
	/*{
	
		pthread_t t;
		pthread_create(&t, NULL, Thread1, NULL);
		Global = 43;
		pthread_join(t, NULL);
	}*/
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: async_tcp_echo_server <port>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		using namespace std; // For atoi.
		server s(io_service, atoi(argv[1]));

		io_service.run();
	}
	catch (std::exception& e)
	{
		BOOST_LOG_TRIVIAL(trace) << "Exception: " << e.what() << "\n";
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return Global;

}
