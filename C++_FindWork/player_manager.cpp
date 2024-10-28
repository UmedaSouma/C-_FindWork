//===========================================================================================================================================================
// 
// �v���C���[�̊Ǘ��N���X [player_manager.cpp]
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
	// �Ԃ��쐬
	m_pCar = CCarPlayer::Create(CParamStorage::CAR_NORMAL);

	m_pController = new CPlayerController;
	m_pController->Init();
}

void CPlayerManager::Uninit()
{
	m_pCar->Uninit();

	// �v���C���[�R���g���[���[�̍폜
	delete m_pController;
	m_pController = nullptr;
}

void CPlayerManager::Update()
{
	if (m_pCar != nullptr)
	{
		CCamera* pCamera = CManager::GetCamera();	// camera �������Ă���
		pCamera->SetTargetPos(m_pCar->GetPos());			// camera �� playerpos ������



		m_pController->Update(m_pCar);
	}
}

CPlayerManager* CPlayerManager::Create()
{
	CPlayerManager* pPlayerManager = new CPlayerManager;

	pPlayerManager->Init();

	return pPlayerManager;
}

