#include "CameraMoveController.h"

void moveEngines(EngineState &currState, float& currentPos)
{
	for(;;)
	{
		if(currState == EngineState::Moving)
		{
			currentPos += 0.0001;
		}
	}
}

