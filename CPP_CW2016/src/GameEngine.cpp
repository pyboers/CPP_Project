#include "GameEngine.h"
#include "Camera.h"

GameEngine::GameEngine() : BaseEngine(6), gol(10, 10, 500, 500){

}

void GameEngine::SetupBackgroundBuffer(void)
{
	StoreObjectInArray(new Camera(this));
	FillBackground(0x000000);
	gol.initValues(15);
	// Specify the screen x,y of top left corner
	gol.SetBaseTilesPositionOnScreen(0, 0);
	// Tell it to draw tiles from x1,y1 to x2,y2 in tile array,
	// to the background of this screen
	gol.DrawAllTiles(this, this->GetBackground(), 0, 0, gol.getWidth()-1, gol.getHeight()-1);
}


void GameEngine::MouseDown(int iButton, int iX, int iY)
{
	
}

int GameEngine::InitialiseObjects(void)
{
	// Record the fact that we are about to change the array - so it doesn't get
	//used elsewhere without reloading it
	DrawableObjectsChanged();
	// Destroy any existing objects
	DestroyOldObjects();
	// Creates an array to store the objects
	// Needs to have room for the NULL at the end
	CreateObjectArray(2);
	

	return 0;
}