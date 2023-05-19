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
	velocityX = 0;
	velocityY = 0;

	isMovingLeft = false;
	isMovingRight = false;
	isMovingUp = false;
	isMovingDown = false;
	isRising = false;
	isFalling = false;
	hitWhenFalling = false;
}

int CCharacter::resourceShow() {
	// 計算Yshow
	return bitmapShow;
}

void CCharacter::setMoveLeft(bool flag) {
	if (velocityY == 0) {
		isMovingLeft = flag;					// 在平面上才能往左移動
	}
}

void CCharacter::setMoveRight(bool flag) {
	if (velocityY == 0) {
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
	if (acceleration < 20) acceleration++;		// 加速度<20則增加
}

void CCharacter::jump() {
	velocityY = acceleration;					// 設置速度
	acceleration = 0;							// 重設加速度
}


void CCharacter::onMove() {
	// 物理狀態
	if (isMovingLeft) {
		X -= 2;
	}
	if (isMovingRight) {
		X += 2;
	}
	if (isMovingUp) {
		Yactual -= 2;
	}
	if (isMovingDown) {
		Yactual += 2;
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