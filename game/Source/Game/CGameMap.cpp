#include "stdafx.h"
#include "CGameMap.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace game_framework;

CGameMap::CGameMap() {
	init();
}

void CGameMap::init() {
	currentMap = 1;
	gameMap.LoadBitmapByString({ "resources/maps/title.bmp" });
	gameMap.SetTopLeft(0, 0);
	// map[0].LoadBitmapByString({ "resources/map/title.bmp" });
	/*
	for (int i = 1; i < 44; i++) {
		stringstream ss;
		ss << std::setfill('0') << std::setw(3) << i+1;
		string filename = "resources/map/map" + ss.str() +".bmp";
		map[i].LoadBitmapByString({ filename });
		map[i].SetTopLeft(0, 0);
	}
	*/
	/*
	map.LoadBitmapByString({
		"resources/map/map000.bmp",
		"resources/map/map001.bmp",
		"resources/map/map002.bmp",
		"resources/map/map003.bmp",
		"resources/map/map004.bmp",
		"resources/map/map005.bmp",
		"resources/map/map006.bmp",
		"resources/map/map007.bmp",
		"resources/map/map008.bmp",
		"resources/map/map009.bmp",
		"resources/map/map010.bmp",
		"resources/map/map011.bmp",
		"resources/map/map012.bmp",
		"resources/map/map013.bmp",
		"resources/map/map014.bmp",
		"resources/map/map015.bmp",
		"resources/map/map016.bmp",
		"resources/map/map017.bmp",
		"resources/map/map018.bmp",
		"resources/map/map019.bmp",
		"resources/map/map020.bmp",
		"resources/map/map021.bmp",
		"resources/map/map022.bmp",
		"resources/map/map023.bmp",
		"resources/map/map024.bmp",
		"resources/map/map025.bmp",
		"resources/map/map026.bmp",
		"resources/map/map027.bmp",
		"resources/map/map028.bmp",
		"resources/map/map029.bmp",
		"resources/map/map030.bmp",
		"resources/map/map031.bmp",
		"resources/map/map032.bmp",
		"resources/map/map033.bmp",
		"resources/map/map034.bmp",
		"resources/map/map035.bmp",
		"resources/map/map036.bmp",
		"resources/map/map037.bmp",
		"resources/map/map038.bmp",
		"resources/map/map039.bmp",
		"resources/map/map040.bmp",
		"resources/map/map041.bmp",
		"resources/map/map042.bmp",
		"resources/map/map043.bmp",
		});*/
}

void CGameMap::nextMap() {
	currentMap += 1;
}

void CGameMap::previousMap() {
	currentMap -= 1;
}

void CGameMap::onShow() {
	
	gameMap.ShowBitmap();
	//map[currentMap].ShowBitmap();
}