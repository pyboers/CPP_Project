#include "Camera.h"

Camera::Camera(GameEngine *pEngine)
	: DisplayableObject(pEngine), pEngine(pEngine)
{
	x = 0;
	y = 0;
	SetVisible(false);
}

void Camera::DoUpdate(int iCurrentTime){
	if (pEngine->IsKeyPressed('w')){
		y += 4;
		//pEngine->FillBackground(0x000000);
		pEngine->gol.SetBaseTilesPositionOnScreen(x, y);
		// Tell it to draw tiles from x1,y1 to x2,y2 in tile array,
		// to the background of this screen
		pEngine->gol.DrawAllTiles(pEngine, pEngine->GetBackground(), 0, 0, 499, 499);
		pEngine->Redraw(true);
	}
}
