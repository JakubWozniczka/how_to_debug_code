#pragma once 

#include <stdexcept>
#include <stack>
#include <thread>
#include <mutex>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>


enum class EngineState{HomePosition, Moving, Stopped};
void moveEngines(EngineState *currState, float* currentPos, std::mutex& m);


class CameraMoveController
{
	public:
	CameraMoveController()	
	{
		t= std::thread(moveEngines, &engineState, &currentPos, std::ref(m));
		//BOOST_LOG_TRIVIAL(trace) << "CameraMoveController constructor !!!!!!!!!!!!!!!!!!";
	}

	~CameraMoveController()
	{
		BOOST_LOG_TRIVIAL(trace) << "CameraMoveController dest";
	}

	void MoveCamera(float pos)
	{
		if (engineState == EngineState::Stopped ||
				engineState == EngineState::HomePosition)
		{
			engineState = EngineState::Moving;
		}
	}

	void StopCamera()
	{
		engineState = EngineState::Stopped;
	}

	void GoToHome()
	{
		currentPos = 0;
		engineState = EngineState::HomePosition;
	}

	private:

	float currentPos=0;
	EngineState engineState = EngineState::HomePosition;
	
	std::mutex m;
	std::thread t;
};
