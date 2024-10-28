//===========================================================================================================================================================
// 
// game.cpp�̃w�b�_�[
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "main.h"
#include "scene.h"
#include "param_storage.h"
#include "player_manager.h"

class CGame :public CScene
{
public:
	CGame();
	~CGame()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void SetInitUI();	// ui�̃Z�b�g
private:
	static int m_nDelayEnd;	// �|���Ă��烊�U���g�ɂȂ�܂�
	static bool m_Delay;

public:
	static CParamStorage* m_pParamStorage;
	static CPlayerManager* m_pPlayerManager;
};