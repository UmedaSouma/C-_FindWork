//===========================================================================================================================================================
// 
// パラメーターの保管 [param_storage.cpp]
// Author : souma umeda
// 
//===========================================================================================================================================================
#include "param_storage.h"

CParamStorage::CParamStorage()
{
	m_Param.fWeight = 0.0f;
	m_Param.fBending = 0.0f;
	m_Param.nMaxGear = 0;
	m_Param.nMaxLife = 0;
	
	for (int i = 0; i < MAX_GEAR; i++)
	{
		m_Param.fMaxSpeed[i] = 0.0f;
	}

	m_type = TYPE::CAR_NORMAL;

}

CParamStorage::~CParamStorage()
{
}
