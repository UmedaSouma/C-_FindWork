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
#include "param_storage.h"

class CCar:public CModel
{
private:
	//================================================================

	//--------------------------------------------------------
	// < debugmemo >
	// 一旦ここで値を設定しとく。
	// 後でテキストファイルで入出力をする
	//--------------------------------------------------------
	static const int MAX_LIFE = 150;					// 最大速度
	static const int MAX_GEAR = 5;						// ギア数
	inline static const float MAX_WEIGHT = 30.0f;		// 重さ
	inline static const float MAX_BENDING = 0.1f;		// 曲がりやすさ

	inline static const float							// ギアごとのスピード
	MAX_SPEED[MAX_GEAR] = {
	12.0f,
	15.0f,
	18.0f,
	22.0f,
	30.0f
	};
	
	//================================================================

	// この車の運転手のタイプ
	typedef enum
	{
		DRIVER_NONE = 0,
		DRIVER_PLAYER,		// プレイヤー
		DRIVER_ENEMY,		// CPU
		DRIVER_MAX
	}DRIVER_TYPE;

public:
	CCar();
	~CCar()override;
	HRESULT Init()override;	// 初期設定
	void Uninit()override;	// 終了
	void Update()override;	// 更新
	void Draw()override;	// 描画

	static CCar* Create();   // 生成処理
private:
	CParamStorage::TYPE m_type;	// 車のタイプ
	CParamStorage::Param m_Param;	// パラメーターを扱う変数
public:

	//================================================
	// Setter,Getter
	//================================================

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

	//-- 最大体力 --
	void SetMaxLife(int maxlife) { m_Param.nMaxLife = maxlife; }
	int GetMaxLife() { return m_Param.nMaxLife; }

	//-- 体力 --
	void SetLife(int life) { m_Param.nLife = life; }
	int GetLife() { return m_Param.nLife; }

	//-- タイプ --
	void SetType(CParamStorage::TYPE type) { m_type = type; }
	CParamStorage::TYPE GetType() { return m_type; }
};

#endif // !CAR_H_