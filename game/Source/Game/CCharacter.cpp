#include "stdafx.h"
#include "CCharacter.h"
#include "../Library/gameutil.h"
using namespace game_framework;

CCharacter::CCharacter() {

}

void CCharacter::init() {
	// facing = right;
	// state = motionless;
	bitmapShow = 0;				// 顯示哪張圖
	X = 0;						// X座標
	Yactual = 500;				// 實際Y座標
	Yshow = 500;				// 顯示用Y座標

	acceleration = 0;
	acceleration = 0;
	velocityX = 0;
	velocityY = 0;
	gravity = 0;

	isOnSurface = true;
	isMovingLeft = false;
	isMovingRight = false;
	isMovingUp = false;
	isMovingDown = false;
	isRising = false;
	isFalling = false;
	hitWhenFalling = false;
}

int CCharacter::getResourceShow() {
	// 計算Yshow
	return bitmapShow;
}

void CCharacter::setMoveLeft(bool flag) {
	if (isOnSurface) {
		isMovingLeft = flag;					// 在平面上才能往左移動
	}
}

void CCharacter::setMoveRight(bool flag) {
	if (isOnSurface) {
		isMovingRight = flag;					// 在平面上才能往右移動
	}
}

void CCharacter::setMoveUp(bool flag) {
	isMovingUp = flag;
}

void CCharacter::setMoveDown(bool flag) {
	isMovingDown = flag;
}

void CCharacter::jumpCharge(bool flag) {
	if (acceleration < 20) acceleration++;		// 加速度<20則增加，最大為20
}

void CCharacter::jump() {
	velocityY = acceleration;					// 設置速度
	acceleration = 0;							// 重設加速度
}


void CCharacter::onMove() {
	// 物理狀態
	if (isMovingLeft && isOnSurface) {
		X -= STEP_SIZE;
	}
	if (isMovingRight) {
		X += STEP_SIZE;
	}
	if (isMovingUp) {
		Yactual -= STEP_SIZE;
	}
	if (isMovingDown) {
		Yactual += STEP_SIZE;
	}
}

int CCharacter::getX() {
	return X;
}

int CCharacter::getYshow() {

	// 計算顯示座標，以左上點為基準
	if (Yactual >= 0 && Yactual <=710) {
		return Yactual;
	}
	else {
		Yshow = Yactual % 720 + 720;
		return Yshow;
	}
	
}

int CCharacter::getYactual() {
	return Yactual;
}

// dev mode 
void CCharacter::nextResource() {
	if (bitmapShow < 12) bitmapShow += 1;
}

// dev mode
void CCharacter::previousResource() {
	if (bitmapShow > 0) bitmapShow -= 1;
}