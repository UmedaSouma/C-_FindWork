#pragma once
//===========================================================================================================================================================
// 
// car_normal.cppのヘッダー [car_normal.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _CAR_NORMAL_H_
#define _CAR_NORMAL_H_
#include "main.h"
#include "car.h"


class CCarNormal:public CCar
{
public:
	CCarNormal();
	~CCarNormal()override;
	HRESULT Init()override;	// 初期設定
	void Uninit()override;	// 終了
	void Update()override;	// 更新
	void Draw()override;	// 描画

	static CCarNormal* Create();   // 生成処理
private:

};

#endif // !CAR_NORMAL_H_
