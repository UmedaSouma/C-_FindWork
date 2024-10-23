#pragma once
//===========================================================================================================================================================
// 
// car.cpp�̃w�b�_�[ [car.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _CAR_H_
#define _CAR_H_
#include "main.h"
#include "model.h"

class CCar:public CModel
{
private:
	//================================================================

	//--------------------------------------------------------
	// < debugmemo >
	// ��U�����Œl��ݒ肵�Ƃ��B
	// ��Ńe�L�X�g�t�@�C���œ��o�͂�����
	//--------------------------------------------------------
	static const int MAX_LIFE = 150;					// �ő呬�x
	static const int MAX_GEAR = 5;						// �M�A��
	inline static const float MAX_WEIGHT = 30.0f;		// �d��
	inline static const float MAX_BENDING = 0.1f;		// �Ȃ���₷��

	inline static const float							// �M�A���Ƃ̃X�s�[�h
	MAX_SPEED[MAX_GEAR] = {
	12.0f,
	15.0f,
	18.0f,
	22.0f,
	30.0f
	};
	
	//================================================================

public:
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


	CCar();
	~CCar()override;
	HRESULT Init()override;	// �����ݒ�
	void Uninit()override;	// �I��
	void Update()override;	// �X�V
	void Draw()override;	// �`��

	static CCar* Create();   // ��������
private:
	//===================================================
	// �Ԃ̃p�����[�^�[
	//===================================================
	struct Param
	{
		int nMaxLife;		// �ő�̗�
		int nLife;			// �̗�
		int nGearNum;		// �M�A��
		float fWeight;		// �Ԃ̏d��
		float fBending;		// �Ȃ���₷��
		float fMaxSpeed[5];	// �ő�X�s�[�h
	};

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
	void SetGearNum(int num) { m_Param.nGearNum = num; }
	int GetGearNum() { return m_Param.nGearNum; }
	
	//-- �Ȃ���₷�� --
	void SetBending(float benging) { m_Param.fBending = benging; }
	float GetBending() { return m_Param.fBending; }

	//-- �M�A���Ƃ̍ō����x --
	void SetMaxSpeed(int idx, float MaxSpeed) { m_Param.fMaxSpeed[idx] = MaxSpeed; }
	float GetfMaxSpeed(int idx) { return m_Param.fMaxSpeed[idx]; }

	//-- �ő�̗� --
	void SetMaxLife(int maxlife) { m_Param.nMaxLife = maxlife; }
	int GetMaxLife() { return m_Param.nMaxLife; }

	//-- �̗� --
	void SetLife(int life) { m_Param.nLife = life; }
	int GetLife() { return m_Param.nLife; }

	//-- �^�C�v --
	void SetType(TYPE type) { m_type = type; }
	TYPE GetType() { return m_type; }
};

#endif // !CAR_H_