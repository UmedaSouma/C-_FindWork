//===========================================================================================================================================================
// 
// プレイヤーの管理クラス [player_manager.cpp]
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "player_manager.h"
#include "search.h"
#include "camera.h"
#include "manager.h"

CPlayerManager::CPlayerManager()
{
}

CPlayerManager::~CPlayerManager()
{
}

void CPlayerManager::Init()
{
	// 車を作成
	m_pCar = CCarPlayer::Create(CParamStorage::CAR_NORMAL);

	m_pController = new CPlayerController;
	m_pController->Init();
}

void CPlayerManager::Uninit()
{
	m_pCar->Uninit();

	// プレイヤーコントローラーの削除
	delete m_pController;
	m_pController = nullptr;
}

void CPlayerManager::Update()
{
	if (m_pCar != nullptr)
	{
		CCamera* pCamera = CManager::GetCamera();	// camera を持ってくる
		pCamera->SetTargetPos(m_pCar->GetPos());			// camera に playerpos を入れる



		m_pController->Update(m_pCar);
	}
}

CPlayerManager* CPlayerManager::Create()
{
	CPlayerManager* pPlayerManager = new CPlayerManager;

	pPlayerManager->Init();

	return pPlayerManager;
}

