#pragma once
//===========================================================================================================================================================
// 
// car_enemy.cppのヘッダー [car_enemy.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _CAR_ENEMY_H_
#define _CAR_ENEMY_H_
#include "main.h"
#include "car.h"

class CCarEnemy:public CCar
{
public:
	CCarEnemy();
	~CCarEnemy()override;
	HRESULT Init()override;	// 初期設定
	void Uninit()override;	// 終了
	void Update()override;	// 更新
	void Draw()override;	// 描画

	static CCarEnemy* Create(CParamStorage::TYPE cartype,D3DXVECTOR3 pos);   // 生成処理
private:

};



#endif // !CAR_ENEMY_H_
