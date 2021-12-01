#pragma once 

#include <stdexcept>
#include <stack>
#include <thread>


float SubTwoFloats(float a, float b);
enum class EngineState{HomePosition, Moving, Stopped};

std::ostream& operator<<(std::ostream& os, const EngineState& engine);


class CameraMoveController
{
	public:
	CameraMoveController()
	{
	}
	void MoveCamera();
	void StopCamera();
	void GoToHome();
	EngineState GetCurrentState();
	float GetCurrentPos()
	{
		return currentPos;
	}
	private:

	float currentPos=0;
	EngineState engineState;
};
