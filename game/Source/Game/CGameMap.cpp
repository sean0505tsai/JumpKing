#include "stdafx.h"
#include "CGameMap.h"

using namespace game_framework;

CGameMap::CGameMap() {
	currentMap = 0;
}

void CGameMap::init() {

}

void CGameMap::onShow() {
	//gameMaps[0].ShowBitmap();
}

int CGameMap::getCurrentMap() {
	return currentMap;
}

void CGameMap::nextMap() {
	if (currentMap < 42) {
		currentMap += 1;
	}
}

void CGameMap::prevMap() {
	if (currentMap > 0) {
		currentMap -= 1;
	}
}

void CGameMap::setMap(int Y) {
	if (Y >= 0) {			// Y座標 > 0
		currentMap = 0;
	}
	else {					// Y座標 < 0
		currentMap = (((Y / 720)*-1)+1);
	}
}

bool CGameMap::willCollide(int x, int y, int width, int height) {
	int x1 = x + width;
	int y1 = y + height;
	return false;
}