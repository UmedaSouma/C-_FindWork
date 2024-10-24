//===========================================================================================================================================================
// 
// game.cppのヘッダー
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "main.h"
#include "scene.h"
#include "param_storage.h"

class CGame :public CScene
{
public:
	CGame();
	~CGame()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void SetInitUI();	// uiのセット
private:
	static int m_nDelayEnd;	// 倒してからリザルトになるまで
	static bool m_Delay;

public:
	static CParamStorage* pParamStorage;

};