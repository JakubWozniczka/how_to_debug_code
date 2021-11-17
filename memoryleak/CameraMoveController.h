#pragma once 

#include <stdexcept>
#include <stack>
#include <thread>
#include <boost/log/trivial.hpp>

enum class EngineState{HomePosition, Moving, Stopped};
	
void moveEngines(EngineState &currState, float& currentPos);


class CameraMoveController
{
	public:
	CameraMoveController():t(moveEngines, std::ref(engineState), std::ref(currentPos))
	{
		
	}
	void MoveCamera(float pos)
	{
		if(engineState == EngineState::Stopped ||
				engineState == EngineState::HomePosition)
		{

			engineState = EngineState::Moving;
		}
	}
	void StopCamera()
	{
		if (engineState == EngineState::Moving)
		{
			engineState = EngineState::Stopped;
		}

	}
	void GoToHome()
	{
		currentPos = 0;
		engineState = EngineState::HomePosition;
	}
	private:

	float currentPos=0;
	EngineState engineState = EngineState::HomePosition;
	std::thread t;
};
