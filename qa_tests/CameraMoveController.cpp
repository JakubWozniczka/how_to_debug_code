#include <chrono>
#include <thread>
#include "CameraMoveController.h"
#include <boost/log/trivial.hpp>

void moveEngines(EngineState* currState, float* currentPos, std::mutex& m)
{
	for(;;)
	{
		std::unique_lock<std::mutex> l(m);
		if(*currState == EngineState::Moving)
		{
			*currentPos += 0.001;
			if (*currentPos >= 1)
			{	
				*currentPos = 0;
			}
			BOOST_LOG_TRIVIAL(trace) << "Camera moves to pos : " << *currentPos << " State: "<< (int)*currState <<"\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));		
		}
	}
}

