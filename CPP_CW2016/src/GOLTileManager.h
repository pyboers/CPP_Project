#pragma once
#ifndef GOLTILEMANAGER_H
#define GOLTILEMANAGER_H
#define GAMEENGINE_H
#include "header.h"
#include "templates.h"
#include "TileManager.h"
class GOLTileManager : public TileManager{

public:
	GOLTileManager(int iTileHeight, int iTileWidth, int width, int height) : TileManager(iTileHeight, iTileHeight){
		SetSize(width, height);
		generateNoise();
	}
	void generateNoise();

	void CellularAutomataPass();


};
#endif