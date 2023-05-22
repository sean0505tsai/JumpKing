#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if (isPause == false) {
		character.onMove();
	}

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	isPause = false;

	// character init
	character.init();

	// map init


	// load map resources
	for (int i = 0; i < 43; i++) {
		std::stringstream ss;
		ss << i;
		// std::string filename = "resources/map_720/map" + ss.str() + ".bmp";
		mapResource[i].LoadBitmapByString({ "resources/map_720/map" + ss.str() + ".bmp" });
		mapResource[i].SetTopLeft(0, 0);
	}


	// load character resources and set default value
	// 0: 預設向右圖
	characterResource[0].LoadBitmapByString({ "resources/character/defaultRight.bmp" }, RGB(0, 255, 0));
	characterResource[0].SetTopLeft(character.getX(), character.getYshow());

	// 1: 預設向左圖
	characterResource[1].LoadBitmapByString({ "resources/character/defaultLeft.bmp" }, RGB(0, 255, 0));
	characterResource[1].SetTopLeft(character.getX(), character.getYshow());

	// 2: 向右走動畫
	characterResource[2].LoadBitmapByString({ "resources/character/moving_right/move_right_1.bmp" }, RGB(0, 255, 0));
	characterResource[2].SetTopLeft(character.getX(), character.getYshow());

	// 3: 向左走動畫
	characterResource[3].LoadBitmapByString({ "resources/character/moving_left/move_left_1.bmp" }, RGB(0, 255, 0));
	characterResource[3].SetTopLeft(character.getX(), character.getYshow());

	// 4: 跳躍蓄力
	characterResource[4].LoadBitmapByString({ "resources/character/charge.bmp" }, RGB(0, 255, 0));
	characterResource[4].SetTopLeft(character.getX(), character.getYshow());

	// 5: 向右跳躍圖
	characterResource[5].LoadBitmapByString({ "resources/character/rise_right.bmp" }, RGB(0, 255, 0));
	characterResource[5].SetTopLeft(character.getX(), character.getYshow());

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE) {
		// pause menu
		pause();
	}

	if (!isPause) {					// 非暫停狀態才接受 keyboard input

		if (nChar == VK_LEFT) {
			// 角色往左移動
			character.setMoveLeft(true);
		}

		if (nChar == VK_RIGHT) {
			// 角色往右移動
			character.setMoveRight(true);
		}

		if (nChar == VK_SPACE) {
			// 跳躍蓄力
			character.jumpCharge(true);
		}

		if (nChar == VK_UP) {
			character.setMoveUp(true);		// dev mode
		}

		if (nChar == VK_DOWN) {
			character.setMoveDown(true);	// dev mode
		}

		if (nChar == VK_NUMPAD8) {

			gameMap.nextMap();		// next map (dev mode)
		}

		if (nChar == VK_NUMPAD2) {

			gameMap.prevMap();		// previous map (dev mode)
		}
	}

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_LEFT) {
		// 角色往左移動
		character.setMoveLeft(false);
	}

	if (nChar == VK_RIGHT) {
		// 角色往右移動
		character.setMoveRight(false);
	}

	if (nChar == VK_SPACE) {
		// 跳躍蓄力
		character.jumpCharge(false);
	}

	if (nChar == VK_UP) {
		character.setMoveUp(false);		// dev mode
	}

	if (nChar == VK_DOWN) {
		character.setMoveDown(false);	// dev mode
	}

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	gameMap.setMap(character.getYactual());
	mapResource[gameMap.getCurrentMap()].ShowBitmap();
	characterResource[0].SetTopLeft(character.getX(), character.getYshow());
	characterResource[0].ShowBitmap(1.5);

	if (isPause) {
		drawPauseText();
	}
}

void CGameStateRun::pause()
{
	if (!isPause) {
		isPause = true;			// 設為暫停狀態
	}
	else {
		isPause = false;		// 解除暫停狀態
	}
}

void CGameStateRun::drawPauseText() {

	CDC* pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 20, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 10, 10, "PAUSE");
	CDDraw::ReleaseBackCDC();
}