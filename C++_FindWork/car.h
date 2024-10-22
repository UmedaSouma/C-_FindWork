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
public:
	CCar();
	~CCar()override;
	HRESULT Init()override;	// �����ݒ�
	void Uninit()override;	// �I��
	void Update()override;	// �X�V
	void Draw()override;	// �`��

	static CCar* Create();   // ��������
private:

	// �Ԃ̃p�����[�^�[
	struct Param
	{
		float fWeight;	// �Ԃ̏d��
		int nGearNum;	// �M�A��
		float fBending;	// �Ȃ���₷��
		float fMaxSpeed[];	// �ő�X�s�[�h
	};

	Param m_Param;	// �p�����[�^�[�������ϐ�

public:
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

};




#endif // !CAR_H_

//===========================================================================================================
// �Ԃ̃x�[�X�������ɏ���
//===========================================================================================================