#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%


	load_images();
	//
	// 開始載入資料
	//
	Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SPACE) {
		phase = 2;
	}

	if (phase == 2) {
		if (nChar == VK_DOWN) {
			if(selector < 3){
				selector += 1;
				cursor.SetTopLeft(cursor.GetLeft(), cursor.GetTop() + 40);
			}
		}
		else if (nChar == VK_UP) {
			if (selector > 1) {
				selector -= 1;
				cursor.SetTopLeft(cursor.GetLeft(), cursor.GetTop() - 40);
			}
		}

		if (nChar == VK_RETURN) {
			if (selector < 3) {
				GotoGameState(GAME_STATE_RUN);
			}
		}
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	// GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	title.ShowBitmap();
	if (phase == 1) {
		hint.ShowBitmap();
		hint.SetAnimation(600, false);
	}
	else if (phase == 2) {
		draw_text();
		cursor.ShowBitmap();
	}

	// draw_text();
}

void CGameStateInit::load_images() {

	// load background
	title.LoadBitmapByString({ "resources/init/title_720.bmp" });
	title.SetTopLeft(0, 0);

	// load hint
	hint.LoadBitmapByString({ "resources/init/hint_720.bmp", "resources/init/hint_720_1.bmp"});
	hint.SetTopLeft(430, 448);

	cursor.LoadBitmapByString({ "resources/init/cursor_720.bmp" }, RGB(0, 255, 0));
	cursor.SetTopLeft(400, 451);
}

void CGameStateInit::draw_text() {
	CDC* pDC = CDDraw::GetBackCDC();
	// CFont* fp;

	/* Print title */
	CTextDraw::ChangeFontLog(pDC, 20, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 430, 448, "CONTINUE");
	CTextDraw::Print(pDC, 430, 488, "NEW GAME");
	CTextDraw::ChangeFontLog(pDC, 20, "微軟正黑體", RGB(150, 150, 150));
	CTextDraw::Print(pDC, 430, 528, "TUTORIAL");

	CDDraw::ReleaseBackCDC();
}
