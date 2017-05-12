#include "GOLTileManager.h"

void GOLTileManager::generateNoise(){
	int i, j;
	for (i = 0; i < m_iMapWidth; i++){
		for (j = 0; j < m_iMapHeight; j++){
			SetValue(i, j, rand()%100 < 45);
		}
	}
}

void GOLTileManager::CellularAutomataPass(){
	int *datacopy = (int *)malloc(m_iMapWidth * m_iMapHeight * sizeof(int));;
	memcpy(datacopy, m_pData, m_iMapWidth * m_iMapHeight * sizeof(int));
	int i, j;
	for (i = 0; i < m_iMapWidth; i++){
		for (j = 0; j < m_iMapHeight; j++){
			SetValue(i, j, rand() % 100 < 45);
		}
	}
}