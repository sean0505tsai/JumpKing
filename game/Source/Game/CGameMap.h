#pragma once
#include "../Library/gameutil.h"
namespace game_framework {
	class CGameMap
	{
	public:
		CGameMap();					// constructor
		void init();				// 初始化
		// void loadResources();		// 載入圖片
		void onShow();				// 顯示地圖
		void setMap(int Y);
		void nextMap();
		void prevMap();
		int getCurrentMap();
		bool willCollide(int x, int y, int width, int height);			// 偵測碰撞

	protected:
		int mapArray[1][45][60] = {
			{
				{},
			}
		};

	private:
		int currentMap;
	};
}


