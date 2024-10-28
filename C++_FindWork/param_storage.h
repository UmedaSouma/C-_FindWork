#pragma once
//===========================================================================================================================================================
// 
// param_storage.cpp�̃w�b�_�[ [param_storage.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _PARAM_STORAGE_H_
#define _PARAM_STORAGE_H_
#include "main.h"


class CParamStorage
{
public:

#define MAX_WORLD_GEAR	(10)	// �M�A�ő�l
	//======================================
	// �Ԃ̃^�C�v
	//======================================
	typedef enum
	{
		CAR_NORMAL = 0,
		CAR_TRACK,
		CAR_SPORTS,
		CAR_MAX
	}TYPE;

	//===================================================
	// �Ԃ̃p�����[�^�[
	//===================================================
	struct Param
	{
		int nMaxLife;		// �ő�̗�
		int nMaxGear;		// �M�A��
		float fWeight;		// �Ԃ̏d��
		float fBending;		// �Ȃ���₷��
		float fMaxSpeed[5];	// �ő�X�s�[�h
	};

	CParamStorage();
	~CParamStorage();

private:
	TYPE m_type;	// �Ԃ̃^�C�v
	Param m_Param;	// �p�����[�^�[�������ϐ�
public:

	//================================================
	// Setter,Getter
	//================================================

	//-- �d�� --
	void SetWeight(float Weight) { m_Param.fWeight = Weight; }
	float GetWeight() { return m_Param.fWeight; }

	//-- �M�A�̐� --
	void SetGearMax(int num) { m_Param.nMaxGear = num; }
	int GetGearMax() { return m_Param.nMaxGear; }

	//-- �Ȃ���₷�� --
	void SetBending(float benging) { m_Param.fBending = benging; }
	float GetBending() { return m_Param.fBending; }

	//-- �M�A���Ƃ̍ō����x --
	void SetMaxSpeed(int idx, float MaxSpeed) { m_Param.fMaxSpeed[idx] = MaxSpeed; }
	float GetfMaxSpeed(int idx) { return m_Param.fMaxSpeed[idx]; }

	//-- �ő�̗� --
	void SetMaxLife(int maxlife) { m_Param.nMaxLife = maxlife; }
	int GetMaxLife() { return m_Param.nMaxLife; }

	//-- �^�C�v --
	void SetType(TYPE type) { m_type = type; }
	TYPE GetType() { return m_type; }
};


#endif // !PARAM_STORAGE_H_