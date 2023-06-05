#pragma once
// #include "mygame.h"
namespace game_framework {

	class CCharacter
	{
	public:
		CCharacter();
		int  GetX1();					// ���W�� x �y��
		int  GetY1();					// ���W�� y �y��
		int  GetX2();					// �k�U�� x �y��
		int  GetY2();					// �k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����
		void OnShow();					// �N�ϧζK��e��
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �K��
		void SetJump(bool flag);		// �]�w�O�_���D�Ϊ�t
		void JumpCharge(bool flag);		// ���D�W�O
		void SetXY(int nx, int ny);		// �]�w���W���y��
	protected:
		CMovingBitmap rightDefault;		// ����V�k�w�]��
		CMovingBitmap leftDefault;		// ����V���w�]��
		CMovingBitmap leftFallHitGround;	//	���B���U�����a��(��)
		CMovingBitmap rightFallHitGround;	//	���B���U�����a��(�k)
		CMovingBitmap leftRising;
		CMovingBitmap rightRising;
		CMovingBitmap leftFalling;
		CMovingBitmap rightFalling;
		CMovingBitmap charge;
		CAnimation moveRight;
		CAnimation moveLeft;
		int x, y;					// ���W���y��
		int floor;

		enum direction_flag {
			LEFT = 1,
			RIGHT = 0
		};

		int character_direction;			// ���⭱���V
		bool upperCollision;				// �W��O�_�I��
		bool bottomCollision;				// �U��O�_�I��
		bool leftCollision;					// ����O�_�I��
		bool rightCollision;				// �k��O�_�I��

		bool isMovingUp;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumping;				// �O�_���b���W����
		bool rising;				// true���W�ɡBfalse���U��

		bool isCharging;			// �O�_���b�W�O
		int initial_velocity;		// ���D��t
		int velocity;				// �ثe���t��(�I/��)
	};
}