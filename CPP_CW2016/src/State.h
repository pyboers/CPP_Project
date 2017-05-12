#pragma once
#ifndef STATE_H
#define STATE_H
class State{
public:
	virtual void init();
	virtual void cleanup();
	virtual void pause();
	virtual void unpause();
	virtual void update();
};

#endif