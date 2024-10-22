#pragma once
//===========================================================================================================================================================
// 
// car.cppのヘッダー [car.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _CAR_H_
#define _CAR_H_
#include "main.h"
#include "model.h"

class CCar:public CModel
{
public:
	CCar();
	~CCar()override;
	HRESULT Init()override;	// 初期設定
	void Uninit()override;	// 終了
	void Update()override;	// 更新
	void Draw()override;	// 描画

	static CCar* Create();   // 生成処理
private:

	// 車のパラメーター
	struct Param
	{
		float fWeight;	// 車の重さ
		int nGearNum;	// ギア数
		float fBending;	// 曲がりやすさ
		float fMaxSpeed[];	// 最大スピード
	};

	Param m_Param;	// パラメーターを扱う変数

public:
	//-- 重さ --
	void SetWeight(float Weight) { m_Param.fWeight = Weight; }
	float GetWeight() { return m_Param.fWeight; }

	//-- ギアの数 --
	void SetGearNum(int num) { m_Param.nGearNum = num; }
	int GetGearNum() { return m_Param.nGearNum; }
	
	//-- 曲がりやすさ --
	void SetBending(float benging) { m_Param.fBending = benging; }
	float GetBending() { return m_Param.fBending; }

	//-- ギアごとの最高速度 --
	void SetMaxSpeed(int idx, float MaxSpeed) { m_Param.fMaxSpeed[idx] = MaxSpeed; }
	float GetfMaxSpeed(int idx) { return m_Param.fMaxSpeed[idx]; }

};




#endif // !CAR_H_

//===========================================================================================================
// 車のベースをここに書く
//===========================================================================================================