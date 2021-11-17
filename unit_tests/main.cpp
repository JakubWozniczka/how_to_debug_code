#include "CameraMoveController.h"
#include <iostream>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <thread>


int main()
{
	CameraMoveController c;
	c.MoveCamera(123);
	c.GoToHome();
	return 0;

}
