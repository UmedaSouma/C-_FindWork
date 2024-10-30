//===========================================================================================================================================================
// 
// �Q�[���̏���
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "game.h"
#include "renderer.h"
#include "input.h"
#include "manager.h"
#include "model.h"
#include "search.h"
#include "player3D.h"
#include "block3D.h"
#include "item.h"
#include "billboard.h"
#include "car_player.h"
#include "car_enemy.h"
#include "param_storage.h"
#include "player_manager.h"

CParamStorage* CGame::m_pParamStorage = nullptr;
CPlayerManager* CGame::m_pPlayerManager = nullptr;
int CGame::m_nDelayEnd = 0; // �|���Ă��烊�U���g�ɂȂ�܂�
bool CGame::m_Delay = false;
//===========================================================================================================
// �R���X�g���N�^
//===========================================================================================================
CGame::CGame()
{
}

//===========================================================================================================
// �f�X�g���N�^
//===========================================================================================================
CGame::~CGame()
{
}

//===========================================================================================================
// �����ݒ�
//===========================================================================================================
HRESULT CGame::Init()
{

	CScene::Init();

	//CPlayer3D::Create({ 0.0f,0.0f,0.0f });

	for (int Vertical = 0; Vertical < 50; Vertical++)
	{
		for (int Horizon = 0; Horizon < 50; Horizon++)
		{
			CBlock3D::Create({ 0.0f + (Vertical * 20.0f*10.0f),-30.0f,0.0f + (Horizon * 20.0f*10.0f) });
		}
	}

	CBlock3D::Create({ 10.0f,50.0f,20.0f });

	CCarEnemy::Create(CParamStorage::CAR_NORMAL, { 0.0f,0.0f,100.0f });

	// �p�����[�^�[�Ǘ��N���X�쐬
	m_pParamStorage = new CParamStorage[CParamStorage::CAR_MAX];

	// �v���C���[�Ǘ��N���X�쐬
	m_pPlayerManager = new CPlayerManager;
	m_pPlayerManager->Init();

	//CBillboard::Create({ 30.0f,5.0f,0.0f });

	//CItem::Create({ 30.0f,0.0f,0.0f });

	return S_OK;
}

//===========================================================================================================
// ����UI�̃Z�b�g
//===========================================================================================================
void CGame::SetInitUI()
{
	//CUI::Create(
	//	{ SCREEN_WIDTH * 0.4f,SCREEN_HEIGHT * 0.78f,0.0f }
	//	, { 50.0f,50.0f,0 }
	//	, -1
	//	, "data\\TEXTURE\\ui_key_square_1_000.png"
	//);
	//CUI::Create(
	//	{ SCREEN_WIDTH * 0.6f,SCREEN_HEIGHT * 0.78f,0.0f }
	//	, { 50.0f,50.0f,0 }
	//	, -1
	//	, "data\\TEXTURE\\ui_key_square_2_000.png"
	//);
}

//===========================================================================================================
// �I������
//===========================================================================================================
void CGame::Uninit()
{
	if (m_pParamStorage != nullptr)
	{
		// �p�����[�^�[�̕ۊǌɂ��폜
		delete[] m_pParamStorage;
		m_pParamStorage = nullptr;
	}

	if (m_pPlayerManager != nullptr)
	{
		// �v���C���[�Ǘ����폜
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

	CScene::Uninit();
}

//===========================================================================================================
// �X�V����
//===========================================================================================================
void CGame::Update()
{
	CInputKeyBoard* keyboard = CManager::GetKeyboard();
	CFade* pFade = CManager::GetFade();

#ifdef _DEBUG
	

	// �f�o�b�O�p�E���ŃV�[���؂�ւ�
	if (keyboard->GetTrigger(DIK_RETURN))
	{
		pFade->SetFade(CScene::MODE_TITLE);

		//CManager::SetMode(CScene::MODE_GAME);
	}

	if (keyboard->GetTrigger(DIK_F2))
	{
		pFade->SetFade(CScene::MODE_EDITOR);
	}

#endif // _DEBUG

	m_pPlayerManager->Update();

	CScene::Update();
}

//===========================================================================================================
// �`�揈��
//===========================================================================================================
void CGame::Draw()
{
	CScene::Draw();
}