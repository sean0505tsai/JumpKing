#include "stdafx.h"
#include "CCharacter.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

CCharacter::CCharacter() {

}

void CCharacter::init() {
	loadResources();
	setTopLeft(400, 400);
}

void CCharacter::setTopLeft(int x, int y) {
	this->x = x;
	this->y = y;
	defaultRight.SetTopLeft(x, y);
}

void CCharacter::loadResources() {
	defaultRight.LoadBitmapByString({ "resources/character/defaultRight.bmp" }, RGB(0, 255, 0));
	defaultLeft.LoadBitmapByString({ "resources/character/defaultLeft.bmp" }, RGB(0, 255, 0));
	jumpCharging.LoadBitmapByString({ "resources/character/jump_1.bmp" }, RGB(0, 255, 0));
	riseLeft.LoadBitmapByString({ "resources/character/rise_left.bmp" }, RGB(0, 255, 0));
	riseRight.LoadBitmapByString({ "resources/character/rise_right.bmp" }, RGB(0, 255, 0));
	fallLeft.LoadBitmapByString({ "resources/character/falling_left.bmp" }, RGB(0, 255, 0));
	fallRight.LoadBitmapByString({ "resources/character/falling_right.bmp" }, RGB(0, 255, 0));
	fallHitLeft.LoadBitmapByString({ "resources/character/after_hit_left.bmp" }, RGB(0, 255, 0));
	fallHitRight.LoadBitmapByString({ "resources/character/after_hit_right.bmp" }, RGB(0, 255, 0));
	fallenLeft.LoadBitmapByString({ "resources/character/fall_left.bmp" }, RGB(0, 255, 0));
	fallenRight.LoadBitmapByString({ "resources/character/fall_right.bmp" }, RGB(0, 255, 0));
	movingRight.LoadBitmapByString({ "resources/character/move_right_1.bmp", 
		"resources/character/move_right_2.bmp", "resources/character/move_right_3.bmp" }, RGB(0, 255, 0));
	movingLeft.LoadBitmapByString({ "resources/character/move_left_1.bmp",
		"resources/character/move_left_2.bmp", "resources/character/move_left_3.bmp" }, RGB(0, 255, 0));
}

void CCharacter::moveRight() {
	x += 1;
}

void CCharacter::moveLeft() {
	x -= 1;
}

void CCharacter::jumpCharge() {
	if (yVelocity >= 0) {
		if (yVelocity < 21) {
			yVelocity++;
		}
	}
}

void CCharacter::onShow() {
	defaultRight.ShowBitmap();
}

void CCharacter::onMove() {

}