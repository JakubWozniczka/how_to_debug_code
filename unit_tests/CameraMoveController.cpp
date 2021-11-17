#include "CameraMoveController.h"

float SubTwoFloats(float a, float b)
{
	return a - b;
}

std::ostream& operator<<(std::ostream& os, const EngineState& engine)
{
	if (engine == EngineState::HomePosition)
		os << std::string("EngineState::HomePosition");
	else if (engine == EngineState::Moving)
		os << std::string("EngineState::Moving");
	else if (engine == EngineState::Stopped)
		os << std::string("EngineState::Stopped");
	//else
	//	throw std::runtime_error("Uninitialized value");
	return os;
}

void CameraMoveController::MoveCamera(float pos)
{
	if(engineState == EngineState::Stopped ||
			engineState == EngineState::HomePosition)
	{
		currentPos += pos;
		engineState = EngineState::Moving;
	}
}
void CameraMoveController::StopCamera()
{
	if (engineState == EngineState::Moving)
	{
		engineState = EngineState::Stopped;
	}
}
void CameraMoveController::GoToHome()
{
	currentPos = 0;
	engineState = EngineState::HomePosition;
}
EngineState CameraMoveController::GetCurrentState()
{
	return engineState;
}

