#pragma once
//===========================================================================================================================================================
// 
// car_normal.cpp�̃w�b�_�[ [car_normal.h]
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
	HRESULT Init()override;	// �����ݒ�
	void Uninit()override;	// �I��
	void Update()override;	// �X�V
	void Draw()override;	// �`��

	static CCarNormal* Create();   // ��������
private:

};

#endif // !CAR_NORMAL_H_
