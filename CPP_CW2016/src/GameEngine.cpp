#include "GameEngine.h"

GameEngine::GameEngine() : BaseEngine(6){

}

void GameEngine::SetupBackgroundBuffer(void)
{
	FillBackground(0x000000);
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