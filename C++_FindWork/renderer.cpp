#include "renderer.h"
#include "object.h"
#include "scene.h"
#include "manager.h"
#include "search.h"
#include "car_player.h"

// 静的メンバ変数の初期化
CText* CRenderer::m_pText = nullptr;

//===========================================================================================================
// コンストラクタ
//===========================================================================================================
CRenderer::CRenderer()
{
	m_pD3D = nullptr;
	m_pD3DDevice = nullptr;
	m_pFont = nullptr;
}

//===========================================================================================================
// デストラクタ
//===========================================================================================================
CRenderer::~CRenderer()
{

}

//===========================================================================================================
// 初期設定
//===========================================================================================================
HRESULT CRenderer::Init(HWND hWnd, BOOL bWindow)
{
	D3DDISPLAYMODE d3ddm;	// ディスプレイモード
	D3DPRESENT_PARAMETERS d3dpp;	// プレゼンテーションパラメータ

	// Direct3Dオブジェクトの生成
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	m_pText = new CText;
	m_pText->Init();

	if (m_pD3D == nullptr)
	{
		return E_FAIL;
	}

	// 現在のディスプレイモードを取得
	if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// デバイスのプレゼンテーションパラメータの設定
	ZeroMemory(&d3dpp, sizeof(d3dpp));							// パラメータのゼロクリア

	d3dpp.BackBufferWidth = SCREEN_WIDTH;						// ゲーム画面のサイズ(幅)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;						// ゲーム画面のサイズ(高さ)
	d3dpp.BackBufferFormat = d3ddm.Format;						// 
	d3dpp.BackBufferCount = 1;									// 
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;					// 
	d3dpp.EnableAutoDepthStencil = TRUE;						// 
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;					// 
	d3dpp.Windowed = bWindow;									// 
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// 
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;	// 

	// 
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pD3DDevice)))
	{
		// 
		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&m_pD3DDevice)))
		{
			if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&m_pD3DDevice)))
			{
				return E_FAIL;
			}
		}
	}

	//
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// デバック表示用フォントの生成
	D3DXCreateFont(m_pD3DDevice, 18, 0, 0, 0,
		FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "Terminal", &m_pFont);

	return S_OK;
}

//===========================================================================================================
// 終了処理
//===========================================================================================================
void CRenderer::Uninit()
{
	// 
	if (m_pD3DDevice != nullptr)
	{
		m_pD3DDevice->Release();
		m_pD3DDevice = nullptr;
	}

	// 
	if (m_pD3D != nullptr)
	{
		m_pD3D->Release();
		m_pD3D = nullptr;
	}

	if (m_pText != nullptr)
	{
		m_pText->Uninit();
		delete m_pText;
		m_pText = nullptr;
	}
}

//===========================================================================================================
// 更新処理
//===========================================================================================================
void CRenderer::Update()
{
	// 全て更新
	CObject::UpdateAll();
}

//===========================================================================================================
// 描画処理
//===========================================================================================================
void CRenderer::Draw()
{
	// 背景などの設定
	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		m_pD3DDevice->Clear(0, nullptr,
			(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
			D3DCOLOR_RGBA(100, 178, 255, 0), 1.0f, 0);
	}
	else
	{
		m_pD3DDevice->Clear(0, nullptr,
			(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
			D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	}

	

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	// 
	if (SUCCEEDED(m_pD3DDevice->BeginScene()))
	{
		char aStr[256] = {};
		char aEnemyStr[256] = {};

		CManager::GetCamera()->SetCamera();

		// 全て描画
		CObject::DrawAll();

		m_pText->DrawAll();

		// デバッグテキスト
		DebugPrint(aStr[0],aEnemyStr[0]);

		// 
		m_pD3DDevice->EndScene();

		// テキストの描画
		m_pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 255, 255, 255));

		m_pFont->DrawText(NULL, &aEnemyStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 255, 255, 255));
	}

	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

//===========================================================================================================
// デバッグテキストの描画
//===========================================================================================================
void CRenderer::DebugPrint(char& pStr, char& pStr2)
{
	CCarPlayer* pCarPlayer = nullptr;
	CCamera* pCamera = CManager::GetCamera();

	pCarPlayer = CSearch::SearchObject(pCarPlayer, CObject::TYPE::CAR_PLAYER);

	if (pCarPlayer == nullptr || pCamera == nullptr)
	{
		return;
	}

	sprintf(&pStr
		, "車の移動量 : %f , %f , %f"
		"\n車の向き : %f"
		"\n車のスピード : %f"
		"\nカメラの向き : x = %f , y = %f ,  z = %f"
		, pCarPlayer->GetMove().x, pCarPlayer->GetMove().y, pCarPlayer->GetMove().z
		, pCarPlayer->GetRot().y
		, pCarPlayer->GetAccumulationSpeed()
		,pCamera->GetRot().x,pCamera->GetRot().y,pCamera->GetRot().z
	);
}

//===========================================================================================================
// デバイスの取得
//===========================================================================================================
LPDIRECT3DDEVICE9 CRenderer::GetDevice()
{
	return m_pD3DDevice;
}