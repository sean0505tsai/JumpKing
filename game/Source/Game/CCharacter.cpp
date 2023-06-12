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
	X = 456;						// X座標
	Yactual = 580;				// 實際Y座標
	Yshow = 580;				// 顯示用Y座標

	isFacingRight = true;		// 預設面向右
	acceleration = 0;
	acceleration = 0;
	velocityX = 0;
	velocityY = 0;

	isMovingUp = false;			// dev mode
	isMovingDown = false;		// dev mode

	// isOnSurface = true;			// 平面上的狀態
	isMovingLeft = false;
	isMovingRight = false;
	
	isCharging = false;			//跳躍蓄力, 在平面上才可觸發 
	isRising = false;			// 跳躍後觸發
	isFalling = false;			// 初速被重力減完後觸發
	hitWhenFalling = false;		// 落下途中遭受撞擊

	topCollision = false;		// 上方碰撞
	bottomCollision = 1;	// 下方碰撞
	leftCollision = true;		// 左碰撞
	rightCollision = true;	// 右碰撞
}

int CCharacter::getResourceShow() {
	// 計算Yshow
	return bitmapShow;
}

void CCharacter::setMoveLeft(bool flag) {
	isFacingRight = false;
	if (bottomCollision == 1 && !isCharging) {
		isMovingLeft = flag;					// 在平面上才能往左移動
	}
	else isMovingLeft = false;
}

void CCharacter::setMoveRight(bool flag) {
	isFacingRight = true;
	if (bottomCollision == 1 && !isCharging) {
		isMovingRight = flag;					// 在平面上才能往右移動
	}
	else isMovingRight = false;
}

void CCharacter::setMoveUp(bool flag) {
	isMovingUp = flag;
}

void CCharacter::setMoveDown(bool flag) {
	isMovingDown = flag;
}

void CCharacter::jumpCharge(bool flag) {
	if (flag == false) {
		isCharging = false;
		isRising = true;
		jump();
	}
	else if (bottomCollision == 1) {
		isCharging = flag;
		if(acceleration <20) acceleration++;	// 加速度<20則增加，最大為20
	}
}

void CCharacter::jump() {
	velocityY = acceleration;					// 設置速度
	acceleration = 0;							// 重設加速度
}


void CCharacter::onShow() {

	/*	角色動畫:
		0: 預設向右圖	5: 向右跳躍圖		9: 落下途中受撞擊_右
		1: 預設向左圖	6: 向右跳躍圖		10: 落下途中受撞擊_左
		2: 向右走動畫	7: 向右落下圖		11: 從高處落地_右
		3: 向左走動畫	8: 向左落下圖		12: 從高處落地_左
		4: 跳躍蓄力
	*/

	if (isCharging) bitmapShow = 4;
	
	if (!isFacingRight) {		// 面向左
		if (isMovingLeft) bitmapShow = 3;
		else bitmapShow = 1;
	}
	else if (isFacingRight) {	// 面向右
		if (isMovingRight) bitmapShow = 2;
		else bitmapShow = 0;
	}
	
	
}

void CCharacter::onMove() {
	
	if (Yactual < 580) bottomCollision = 1;

	/*	角色動畫:
		0: 預設向右圖	5: 向右跳躍圖		9: 落下途中受撞擊_右
		1: 預設向左圖	6: 向右跳躍圖		10: 落下途中受撞擊_左
		2: 向右走動畫	7: 向右落下圖		11: 從高處落地_右
		3: 向左走動畫	8: 向左落下圖		12: 從高處落地_左
		4: 跳躍蓄力		
	*/
	
	const int STEP_SIZE = 3;

	// 物理狀態
	if (isMovingLeft && bottomCollision != 0) {
		X -= STEP_SIZE;
		bitmapShow = 3;
	}
	if (isMovingRight) {
		X += STEP_SIZE;
		bitmapShow = 2;
	}
	if (isMovingUp) {		// dev
		Yactual -= STEP_SIZE;
	}
	if (isMovingDown) {		// dev
		Yactual += STEP_SIZE;
	}
	if (isCharging) {
		bitmapShow = 4;
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


void CCharacter::setTopCollision(bool flag) {
	topCollision = flag;
}

void CCharacter::setBottomCollision(int flag) {
	bottomCollision = flag;
}

void CCharacter::setLeftCollision(bool flag) {
	leftCollision = flag;
}

void CCharacter::setRightCollision(bool flag) {
	rightCollision = flag;
}