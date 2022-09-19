#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CWall.h"
#include "CMonster.h"
#include "CCore.h"

#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}

void CScene_Start::Enter()
{
	// Object 추가
	CObject* pObj = new CPlayer;
	pObj->SetPos(Vec2(640.f, 380.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// wall object 추가
	CObject* pWObj = new CWall;
	pWObj->SetPos(Vec2(940.f, 180.f));
	pWObj->SetScale(Vec2(50.f, 50.f));
	AddObject(pWObj, GROUP_TYPE::DEFAULT);

	// 몬스터 배치 반복문
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CMonster* pMonsterObj = nullptr;

	float fTerm = (vResolution.x - (50.f * 2)) / 4.f;

	for (int i = 0; i < 5; ++i)
	{
		CMonster* pMonsterObj = new CMonster;
		pMonsterObj->SetPos(Vec2(50.f + (float)i * fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(50.f, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	// 충돌 지정
	// Player 그룹과 Monster 그룹 간의 충돌체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::MISSILE);
}

void CScene_Start::Exit()
{
	CCollisionMgr::GetInst()->ResetCheck();
}
