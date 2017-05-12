#include "StateManager.h"

void StateManager::enterState(State *s){
	if (states.size() > 0){
		states.top()->pause();
	}
	states.push(s);
	states.top()->init();
}

void StateManager::exitState(){
	State * t = states.top();
	states.pop();
	delete(t);
	if (states.size() > 0){
		states.top()->unpause();
	}
}

void StateManager::runState(){
	states.top()->update();
}

void StateManager::switchState(State *s){
	State * t = states.top();
	states.pop();
	delete(t);
	states.push(s);
	s->init();
}