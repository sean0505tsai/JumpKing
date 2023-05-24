﻿#pragma once
#include "../Library/gameutil.h"
namespace game_framework {
	class CCharacter
	{
	public:
		CCharacter();		// constructor
		void init();
		int getResourceShow();
		
		void onMove();
		void setMoveLeft(bool flag);
		void setMoveRight(bool flag);
		void setMoveUp(bool flag);		// dev mode
		void setMoveDown(bool flag);	// dev mode
		void jumpCharge(bool flag);
		
		void onShow();
		int getX();
		int getYshow();		// 提供mygame_run顯示用座標
		int getYactual();	// 提供CGameMap判斷位置用座標

		void nextResource();
		void previousResource();

	protected:
		void jump();
		// void setState();

		/*
		// 人物狀態
		enum characterState {
			motionless,		// 在表面上無移動
			movingLeft,		// 平面上往左移動
			movingRight,	// 平面上往右移動
			jumping,		// 跳躍/上升中
			falling,		// 落下中
			fallAndHit,		// 落下途中撞擊
			charging		// 跳躍蓄力中
		};
		*/

		bool isOnSurface;		// 無垂直移動
		bool isMovingLeft;		// 平面上往左移動
		bool isMovingRight;		// 平面上往右移動
		bool isMovingUp;		// 往上移動中 (dev mode)
		bool isMovingDown;		// 往下移動中 (dev mode)
		bool isCharging;		// 跳躍蓄力中
		bool isRising;			// 跳躍/上升中
		bool isFalling;			// 落下中
		bool hitWhenFalling;	// 落下途中撞擊


		// 角色面對方向
		/*
		enum characterFacing {
			left, 
			right
		};
		*/

		int state;
		int facing;		// 0: 左, 1:右

		// 座標相關
		int X;			// X座標
		int Yactual;	// 實際Y座標
		int Yshow;		// 顯示Y座標
		const int STEP_SIZE = 2;

		// 移動速度相關
		int acceleration;	// 跳躍加速度
		int velocityY;		// 垂直速度
		int velocityX;		// 水平速度
		int gravity;		// 重力加速度

		// 顯示哪張圖
		int bitmapShow;

	};
}


