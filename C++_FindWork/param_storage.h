#pragma once
//===========================================================================================================================================================
// 
// param_storage.cppのヘッダー [param_storage.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _PARAM_STORAGE_H_
#define _PARAM_STORAGE_H_
#include "main.h"


class CParamStorage
{
public:

#define MAX_WORLD_GEAR	(10)	// ギア最大値
	//======================================
	// 車のタイプ
	//======================================
	typedef enum
	{
		CAR_NORMAL = 0,
		CAR_TRACK,
		CAR_SPORTS,
		CAR_MAX
	}TYPE;

	//===================================================
	// 車のパラメーター
	//===================================================
	struct Param
	{
		int nMaxLife;		// 最大体力
		int nMaxGear;		// ギア数
		float fWeight;		// 車の重さ
		float fBending;		// 曲がりやすさ
		float fMaxSpeed[5];	// 最大スピード
	};

	CParamStorage();
	~CParamStorage();

private:
	TYPE m_type;	// 車のタイプ
	Param m_Param;	// パラメーターを扱う変数
public:

	//================================================
	// Setter,Getter
	//================================================

	//-- 重さ --
	void SetWeight(float Weight) { m_Param.fWeight = Weight; }
	float GetWeight() { return m_Param.fWeight; }

	//-- ギアの数 --
	void SetGearMax(int num) { m_Param.nMaxGear = num; }
	int GetGearMax() { return m_Param.nMaxGear; }

	//-- 曲がりやすさ --
	void SetBending(float benging) { m_Param.fBending = benging; }
	float GetBending() { return m_Param.fBending; }

	//-- ギアごとの最高速度 --
	void SetMaxSpeed(int idx, float MaxSpeed) { m_Param.fMaxSpeed[idx] = MaxSpeed; }
	float GetfMaxSpeed(int idx) { return m_Param.fMaxSpeed[idx]; }

	//-- 最大体力 --
	void SetMaxLife(int maxlife) { m_Param.nMaxLife = maxlife; }
	int GetMaxLife() { return m_Param.nMaxLife; }

	//-- タイプ --
	void SetType(TYPE type) { m_type = type; }
	TYPE GetType() { return m_type; }
};


#endif // !PARAM_STORAGE_H_