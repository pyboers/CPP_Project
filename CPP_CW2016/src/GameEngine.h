#pragma once
#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "header.h"
#include "templates.h"
#include "BaseEngine.h"
#include "GOLTileManager.h"	
class GameEngine : public BaseEngine{


public:
	GOLTileManager gol;
	GameEngine();

	void SetupBackgroundBuffer();

	void MouseDown(int iButton, int iX, int iY);

	int InitialiseObjects(void);



};

#endif