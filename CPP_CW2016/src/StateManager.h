#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "State.h"
#include <stack>
class StateManager{
	std::stack<State *> states;

	void switchState(State *s);
	void enterState(State *s);
	void exitState();
	void runState();

};
#endif