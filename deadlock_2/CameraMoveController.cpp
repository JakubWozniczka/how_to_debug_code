#include <chrono>
#include <thread>
#include "CameraMoveController.h"
#include <boost/log/trivial.hpp>

void moveEngines(EngineState* currState, float* currentPos, std::mutex& m_controller, std::mutex& m_engine)
{
	for(;;)
	{
		std::unique_lock<std::mutex> l(m_controller);
		std::unique_lock<std::mutex> l1(m_engine);
		if(*currState == EngineState::Moving)
		{
			*currentPos += 0.001;
			if (*currentPos >= 1)
			{	
				*currentPos = 0;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));		
		}
	}
}

