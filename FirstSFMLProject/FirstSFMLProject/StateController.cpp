#include "stdafx.h"
#include "StateController.h"

bool StateController::instanceFlag = false;
StateController* StateController::instance = nullptr;

StateController* StateController::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new StateController();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void StateController::SetState(int gameState)
{
	State = gameState;
}
int StateController::getState() const
{
	return State;
}