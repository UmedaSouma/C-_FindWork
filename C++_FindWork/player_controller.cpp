//===========================================================================================================================================================
// 
// ƒvƒŒƒCƒ„[‚Ì‘€ì§Œä [player_controller.cpp]
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "player_controller.h"
#include "manager.h"

CPlayerController::CPlayerController()
{
}

CPlayerController::~CPlayerController()
{
}

void CPlayerController::Init()
{
}

void CPlayerController::Uninit()
{
}

void CPlayerController::Update(CCarPlayer* pCar)
{
	CInputKeyBoard* keyboard = CManager::GetKeyboard();
	CInputJoypad* joypad = CManager::GetJoypad();

	if (pCar != nullptr)
	{
		if (keyboard->GetPress(DIK_W))
		{
			pCar->ActionAccele();
		}
		
		if (keyboard->GetPress(DIK_S))
		{
			pCar->ActionBrake();
		}

		if (keyboard->GetPress(DIK_D))
		{
			pCar->ActionBend_R();
		}

		if (keyboard->GetPress(DIK_A))
		{
			pCar->ActionBend_L();
		}


		//if()



	}

}

void CPlayerController::Move()
{
}

