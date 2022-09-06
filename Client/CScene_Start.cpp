#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::Enter()
{
	// Object Ãß°¡
	CObject* pObj = new CObject;

	pObj->SetPos(Vec2(640.f, 380.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	m_arrObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);
}

void CScene_Start::Exit()
{

}
