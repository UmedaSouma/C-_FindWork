#pragma once
//===========================================================================================================================================================
// 
// car_enemy.cpp�̃w�b�_�[ [car_enemy.h]
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
	HRESULT Init()override;	// �����ݒ�
	void Uninit()override;	// �I��
	void Update()override;	// �X�V
	void Draw()override;	// �`��

	static CCarEnemy* Create(CParamStorage::TYPE cartype,D3DXVECTOR3 pos);   // ��������
private:

};



#endif // !CAR_ENEMY_H_
