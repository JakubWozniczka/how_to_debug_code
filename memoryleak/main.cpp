#include <iostream>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <thread>
#include "Server.h"
#include <pthread.h>

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: async_tcp_echo_server <port>\n";
			return 1;
		}
		//void *p = malloc(7);
		//p = 0; // The memory is leaked here.
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

	return 0;

}
