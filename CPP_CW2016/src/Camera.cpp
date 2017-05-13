#include "Camera.h"

Camera::Camera(GameEngine *pEngine)
	: DisplayableObject(pEngine), pEngine(pEngine)
{
	x = 0;
	y = 0;
	SetVisible(false);
}

void Camera::Draw(){
	pEngine->DrawScreenRectangle(pEngine->GetScreenWidth() / 2 - 5, pEngine->GetScreenHeight() / 2 - 5, pEngine->GetScreenWidth() / 2 + 5, pEngine->GetScreenHeight() / 2 + 5, 0xFF0000);
	StoreLastScreenPositionForUndraw();
}

void Camera::DoUpdate(int iCurrentTime){
	bool changed = false;
	if (pEngine->IsKeyPressed('w')){
		y -= MOVESPEED;
		changed = true;
	}
	else if (pEngine->IsKeyPressed('s')){
		y += MOVESPEED;
		changed = true;
	}
	if (pEngine->IsKeyPressed('d')){
		x += MOVESPEED;
		changed = true;
	}
	else if (pEngine->IsKeyPressed('a')){
		x -= MOVESPEED;
		changed = true;
	}

	if (x <0){
		x = 0;
	}

	if (y <0){
		y = 0;
	}


	if (changed){
		pEngine->gol.CellularAutomataPass();
		pEngine->FillBackground(0x000000);
		int tilex = pEngine->gol.GetTileXForPositionOnScreen(x);
		int tiley = pEngine->gol.GetTileYForPositionOnScreen(y);
		if (tilex <0){
			tilex = 0;
		}

		if (tiley <0){
			tiley = 0;
		}
		int offsetx, offsety;
		for (offsetx = -20; offsetx <= 20; offsetx++){
			for (offsety = -20; offsety <= 20; offsety++){
				int realx = x + offsetx + pEngine->GetScreenWidth() / 2;
				int realy = y + offsety + pEngine->GetScreenHeight() / 2;
				if (pEngine->gol.IsValidTilePosition(realx, realy)){
					int tx = pEngine->gol.GetTileXForPositionOnScreen(realx);
					int ty = pEngine->gol.GetTileYForPositionOnScreen(realy);
					if (pEngine->gol.GetValue(tx, ty)){
						pEngine->gol.SetValue(tx, ty, 0);
					}
				}
			}
		}
		int mapwidth = tilex + pEngine->GetScreenWidth() / pEngine->gol.GetTileWidth();
		if (mapwidth >= pEngine->gol.getWidth()){
			mapwidth = pEngine->gol.getWidth() - 1;
		}

		int mapheight = tiley + pEngine->GetScreenHeight() / pEngine->gol.GetTileHeight();
		if (mapheight >= pEngine->gol.getHeight()){
			mapheight = pEngine->gol.getHeight() - 1;
		}
		pEngine->gol.DrawAllTilesAt(pEngine, pEngine->GetBackground(), tilex, tiley, mapwidth, mapheight, -(x%pEngine->gol.GetTileWidth()), -(y%pEngine->gol.GetTileHeight()));

		printf("%d\n", pEngine->GetScreenWidth() / pEngine->gol.GetTileWidth());
		pEngine->Redraw(true);
	}
}
