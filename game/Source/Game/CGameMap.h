#pragma once
#include "../Library/gameutil.h"
namespace game_framework {
	class CGameMap
	{
	public:
		CGameMap();					// constructor
		void init();				// 初始化
		void onShow();				// 顯示地圖
		void setMap(int Y);
		void nextMap();
		void prevMap();
		int getCurrentMap();
		bool willCollide(int x, int y, int width, int height);			// 偵測碰撞

	protected:

		int currentMap;
		vector<vector<vector<int>>> myVector(43, std::vector<std::vector<int>>(3, std::vector<int>(3, 0)));
	};
}


