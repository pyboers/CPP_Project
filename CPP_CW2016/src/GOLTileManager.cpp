#include "GOLTileManager.h"

void GOLTileManager::generateNoise(){
	int i, j;
	for (i = 0; i < m_iMapWidth; i++){
		for (j = 0; j < m_iMapHeight; j++){
			SetValue(i, j, rand()%100 <= 50);
		}
	}
}

int GOLTileManager::getWidth(){
	return m_iMapWidth;
}

int GOLTileManager::getHeight(){
	return m_iMapHeight;
}

// Override this to draw tiles.
void GOLTileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	// Base class implementation just draws some grey tiles
	unsigned int iColour;
	if (GetValue(iMapX, iMapY)){
		iColour = 0x000000;
	}
	else{
		iColour = 0xFFFFFF;
	}
	pEngine->DrawRectangle(
		iStartPositionScreenX,
		iStartPositionScreenY,
		iStartPositionScreenX + GetTileWidth() - 1,
		iStartPositionScreenY + GetTileHeight() - 1,
		iColour,
		pSurface);
}

void GOLTileManager::initValues(int iterations){
	generateNoise();
	int n;
	for (n = 0; n < iterations; n++){
		CellularAutomataPass();
	}
}

bool GOLTileManager::isValidCoordinate(int x, int y){
	return x >= 0 && x <m_iMapWidth && y >= 0 && y < m_iMapHeight;
}

void GOLTileManager::CellularAutomataPass(){
	int *datacopy = (int *)malloc(m_iMapWidth * m_iMapHeight * sizeof(int));
	int n;
	for (n = 0; n < m_iMapWidth * m_iMapHeight; n++){
		datacopy[n] = m_pData[n];
	}

	int i, j;
	for (i = 0; i < m_iMapWidth; i++){
		for (j = 0; j < m_iMapHeight; j++){
			int count = 0;
			int k, l;
			//This could be made more efficient by hard coding the if statements.
			for (k = -1; k <= 1; k++){
				for (l = -1; l <= 1; l++){
					if (isValidCoordinate(i + k, j + l) && datacopy[(i + k) + (j + l) * m_iMapWidth]){
						count++;
					}
				}
			}
			if (datacopy[i + j*m_iMapWidth]){
				count--; //subtracting when it counted itself. 
			}
			if ((datacopy[i+(j* m_iMapWidth)] && count >= 4) || (!datacopy[i+ j* m_iMapWidth] && count >= 5)){
				SetValue(i, j, 1);
			}else{
				SetValue(i, j, 0);
			}
		}
	}
	delete[] datacopy;
}