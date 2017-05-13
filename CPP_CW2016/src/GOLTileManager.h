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
	}

	void initValues(int iterations);

	void GOLTileManager::DrawTileAt(
		BaseEngine* pEngine,
		SDL_Surface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const;

	int getWidth();
	int getHeight();

	void generateNoise();

	void CellularAutomataPass();

	bool isValidCoordinate(int x, int y);


};
#endif