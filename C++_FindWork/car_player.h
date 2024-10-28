#pragma once
//===========================================================================================================================================================
// 
// carplayer.cpp�̃w�b�_�[ [carplayer.h]
// Author : souma umeda
// 
//===========================================================================================================================================================
#ifndef _CAR_PLAYER_H_
#define _CAR_PLAYER_H_
#include "main.h"
#include "car.h"
#include "param_storage.h"

class CCarPlayer:public CCar
{
public:
	CCarPlayer();
	~CCarPlayer()override;
	HRESULT Init()override;	// �����ݒ�
	void Uninit()override;	// �I��
	void Update()override;	// �X�V
	void Draw()override;	// �`��

	static CCarPlayer* Create(CParamStorage::TYPE cartype);   // ��������
private:

};



#endif // !CAR_PLAYER_H_
