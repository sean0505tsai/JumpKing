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

bool CGameMap::topCollision(int x, int y, int width) {
	bool flag = false;
	int Ytarget = ( ( ( (y - 720) - 1) / 16) + 1934 );	// 16*16 pixel為一格, 960*720 pixel為一關, 統一先上移720 pixel
	int Xstart = x / 16;							// 將實際座標轉換為地圖陣列座標
	int Xend = ( (x + width) - 1) / 16;
	for (int i = Xstart; i <= Xend; i++) {
		if (mapArray[Ytarget][i] != 0) flag = true;	// 檢查是否碰撞, mapArray[y][x]
	}
	return flag;
}

int CGameMap::bottomCollision(int x, int y, int width, int height) {
	int flag = 0;
	int Ytarget = ( ( ( (y - 720) + height) / 16) + 1934);		// 16*16 pixel為一格, 960*720 pixel為一關, 統一先上移720 pixel
	int Xstart = x / 16;								// 將實際座標轉換為地圖陣列座標
	int Xend = ( (x + width) - 1) / 16;
	for (int i = Xstart; i <= Xend; i++) {
		if (mapArray[Ytarget][i] != 0) flag = mapArray[Ytarget][i];	// 檢查是否碰撞, mapArray[y][x]
	}
	return flag;
}

bool CGameMap::leftCollision(int x, int y, int height) {
	bool flag = false;
	int Xtarget = ((x - 1) / 16);              // 16*16 pixel為一格, 960*720 pixel為一關, 統一先上移720 pixel
	int Ystart = (((y - 720) / 16) + 1934);							// 將實際座標轉換為地圖陣列座標
	int Yend = ((((y - 720) + height) - 1) / 16) + 1934;
	for (int i = Ystart; i <= Yend; i++) {
		if (mapArray[i][Xtarget] != 0) flag = true;	// 檢查是否碰撞, mapArray[y][x]
	}
	return flag;
}


bool CGameMap::rightCollision(int x, int y, int width, int height) {
	bool flag = false;
	int Xtarget = ((x + width) / 16);              // 16*16 pixel為一格, 960*720 pixel為一關, 統一先上移720 pixel
	int Ystart = (((y - 720) / 16) + 1934);							// 將實際座標轉換為地圖陣列座標
	int Yend = ((((y - 720) + height) - 1) / 16) + 1934;
	for (int i = Ystart; i <= Yend; i++) {
		if (mapArray[i][Xtarget] != 0) flag = true;	// 檢查是否碰撞, mapArray[y][x]
	}
	return flag;
}