#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "header.h"
#include "templates.h"
#include "DisplayableObject.h"
#include "GameEngine.h"
class Camera : public DisplayableObject{
	GameEngine *pEngine;
	int x, y;
public:
	Camera::Camera(GameEngine *pEngine);
	void DoUpdate(int iCurrentTime);

};

#endif