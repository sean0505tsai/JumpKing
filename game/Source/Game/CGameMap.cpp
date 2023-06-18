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

int CGameMap::topCollision(int x, int y, int width, int pixelsToCheck) {
	int Xstart = x / 16;						// 計算 Xstart
	int Xend = (x + width - 1) / 16;			// 計算 Xend

	for (int i = Xstart; i <= Xend; i++) {
		for (int j = y-1; j >= y - pixelsToCheck; j--) {
			int YtargetCheck = ((j - 719) / 16) + 1934; // 檢查上方像素的 Ytarget
			if (mapArray[YtargetCheck][i] != 0) {
				return y - j; // 回傳碰撞發生的像素數
			}
		}
	}

	return 0; // 沒有發生碰撞，回傳 0
}


int CGameMap::bottomCollision(int x, int y, int width, int height, int pixelsToCheck) {
	int Xstart = x / 16;								// 將實際座標轉換為地圖陣列座標
	int Xend = ( (x + width) - 1) / 16;

	for (int i = Xstart; i <= Xend; i++) {
		for (int j = y + height; j <= y + height -1 + pixelsToCheck; j++) {
			int YtargetCheck = ((j - 719) / 16) + 1934; // 檢查下方像素的 Ytarget
			if (mapArray[YtargetCheck][i] != 0) {
				return (j - (y + height -1));
			}
		}
		
	}
	return 0;		// 沒有碰撞, return 0
}

int CGameMap::leftCollision(int x, int y, int height, int pixelsToCheck) {
	int Xtarget = ((x - 1) / 16);					// 計算 Xtarget
	int Ystart = (((y - 719) / 16) + 1934);			// 計算 Ystart
	int Yend = ((((y - 719) + height) - 1) / 16) + 1934; // 計算 Yend

	for (int i = Ystart; i <= Yend; i++) {
		for (int j = x - 1; j >= x - pixelsToCheck; j--) {
			int XtargetCheck = (j / 16);
			if (mapArray[i][XtargetCheck] != 0) {
				return x - j;			// 回傳碰撞發生的距離，以像素為單位
			}
		}
	}
	return 0;
}


int CGameMap::rightCollision(int x, int y, int width, int height, int pixelsToCheck) {
	int Ystart = (((y - 719) / 16) + 1934);							// 將實際座標轉換為地圖陣列座標
	int Yend = ((((y - 719) + height) - 1) / 16) + 1934;
	
	for (int i = Ystart; i <= Yend; i++) {
		for (int j = x + width; j <= x + width - 1 + pixelsToCheck; j++) {
			int XtargetCheck = j / 16;
			if (mapArray[i][XtargetCheck] != 0) {
				return j - (x + width - 1);
			}
		}

	}
	return 0;
}