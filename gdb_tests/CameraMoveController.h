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
		//BOOST_LOG_TRIVIAL(trace) << "CameraMoveController const!~!!!!!!!!!!!!!!!!!";

	}
	~CameraMoveController()
	{
		BOOST_LOG_TRIVIAL(trace) << "CameraMoveController dest";
	}
	void MoveCamera()
	{
		std::lock_guard<std::mutex> l(m);
		if(engineState == EngineState::Stopped ||
				engineState == EngineState::HomePosition)
		{
			engineState = EngineState::Moving;
		}
	}
	void StopCamera()
	{
		std::lock_guard<std::mutex> l(m);
		engineState = EngineState::Stopped;
	}
	void GoToHome()
	{
		std::lock_guard<std::mutex> l(m);
		currentPos = 0;
		engineState = EngineState::HomePosition;
	}
	private:

	float currentPos=0;
	EngineState engineState = EngineState::HomePosition;
	
	std::mutex m;
	std::thread t;
};
