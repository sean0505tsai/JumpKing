// #include "stdafx.h"
// #include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
// #include "audio.h"
// #include "gamelib.h"
#include "CCharacter.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CCharacter::CCharacter()	// Constructor
	{
		Initialize();
	}

	int CCharacter::GetX1()		// return 左上角x座標
	{
		return x;
	}

	int CCharacter::GetY1()		//return 左上角y座標
	{
		return y;
	}

	int CCharacter::GetX2()		// return 右下角x座標
	{
		return x + rightDefault.Width();
	}

	int CCharacter::GetY2()		// return 右下角y座標
	{
		return y + rightDefault.Height();
	}

	void CCharacter::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 380;
		const int INITIAL_VELOCITY = 0;
		x = X_POS;
		y = Y_POS;
		character_direction = RIGHT;
		floor = 380;
		isMovingLeft = isMovingRight = isJumping = isMovingDown
			 = isCharging = isMovingUp = false;
		initial_velocity = INITIAL_VELOCITY;
		velocity = initial_velocity;
	}

	void CCharacter::LoadBitmap()
	{

		rightDefault.LoadBitmap(IDB_CHARACTER_DEFAULT, RGB(0, 255, 0));
		leftDefault.LoadBitmap(IDB_DEFAULT_LEFT, RGB(0, 255, 0));
		charge.LoadBitmap(IDB_CHARACTER_CHARGE, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_1, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_3, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));

		moveLeft.AddBitmap(IDB_MOVE_LEFT_1, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_3, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
	}

	void CCharacter::OnMove()
	{
		const int STEP_SIZE = 2;
		moveRight.OnMove();
		moveLeft.OnMove();
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		
		if (isCharging) {
			if (initial_velocity <= 20) initial_velocity++;
		}

		if (!isMovingUp) {
			if (isJumping) {			// 上升狀態
				if (velocity > 0) {
					y -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
					velocity--;		// 受重力影響，下次的上升速度降低
				}
				else {
					isJumping = false; // 當速度 <= 0，上升終止，下次改為下降
					velocity = 1;	// 下降的初速(velocity)為1
				}
			}
			else {				// 下降狀態
				if (y < floor - 1) {  // 當y座標還沒碰到地板
					initial_velocity = 0;
					y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
					velocity++;		// 受重力影響，下次的下降速度增加
				}
				else {
					y = floor - 1;  // 當y座標低於地板，更正為地板上
					velocity = 0;
					isJumping = false;
				}
			}
		}
		

		if (isMovingUp) {
			y -= STEP_SIZE;
		}
	}

	void CCharacter::SetMovingLeft(bool flag)
	{	
		if(! isCharging) isMovingLeft = flag;
		character_direction = LEFT;
	}

	void CCharacter::SetMovingRight(bool flag)
	{
		if(! isCharging) isMovingRight = flag;
		character_direction = RIGHT;
	}

	void CCharacter::SetMovingUp(bool flag) {
		isMovingUp = flag;
	}

	void CCharacter::JumpCharge(bool flag) {
		isCharging = flag;
	}

	void CCharacter::SetJump(bool flag)
	{
		velocity = initial_velocity;
		if (velocity != 0) isJumping = flag;
	}

	void CCharacter::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CCharacter::OnShow()
	{
		rightDefault.SetTopLeft(x, y);
		leftDefault.SetTopLeft(x, y);
		moveRight.SetTopLeft(x, y);
		moveLeft.SetTopLeft(x, y);
		charge.SetTopLeft(x, y);
		if (isCharging) charge.ShowBitmap();
		else if (isMovingRight) moveRight.OnShow();
		else if (isMovingLeft) moveLeft.OnShow();
		else {
			if (character_direction == RIGHT) rightDefault.ShowBitmap();
			else leftDefault.ShowBitmap();
		}

	}
}