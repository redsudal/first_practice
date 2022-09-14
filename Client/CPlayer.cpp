#include "pch.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CPlayer.h"
#include "CMissile.h"

#include "CSceneMgr.h"
#include "CScene.h"

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_TAP(KEY::W) || KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}

	if (KEY_TAP(KEY::S) || KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}

	if (KEY_TAP(KEY::A) || KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}

	if (KEY_TAP(KEY::D) || KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}

	if (KEY_TAP(KEY::UP)/* || KEY_HOLD(KEY::UP)*/)
	{
		CreateMissileFront();
		CreateMissileRightSide();
		CreateMissileLeftSide();
	}

	SetPos(vPos);
}

void CPlayer::CreateMissileFront()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(Vec2(0.f, 1.f));

	CScene* pCurSce = CSceneMgr::GetInst()->GetCurScene();
	pCurSce->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}

void CPlayer::CreateMissileRightSide()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));

	CScene* pCurSce = CSceneMgr::GetInst()->GetCurScene();
	pCurSce->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}

void CPlayer::CreateMissileLeftSide()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(Vec2(-1.f, 1.f));

	CScene* pCurSce = CSceneMgr::GetInst()->GetCurScene();
	pCurSce->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}
