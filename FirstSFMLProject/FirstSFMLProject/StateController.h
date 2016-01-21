#ifndef _STATECONTROLLER_H_
#define _STATECONTROLLER_H_
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>


class StateController
{
private:
	static bool instanceFlag;
	static StateController* instance;
	StateController()
	{
		State = MENU;
	}
	int State;


public:
	static const int MENU = 0, PLAY = 1, PAUSE = 2, GAMEOVER = 3, CREDITS = 4, SPLASH = 5, SCORESCREEN = 6;
	static StateController* GetInstance();
	~StateController()
	{
		instanceFlag = false;
	}
	void SetState(int);
	int getState() const;

};
#endif