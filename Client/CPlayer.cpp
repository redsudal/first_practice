#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD
		|| CKeyMgr::GetInst()->GetKeyState(KEY::UP) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
	{
		vPos.y -= 200.f * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::HOLD
		|| CKeyMgr::GetInst()->GetKeyState(KEY::DOWN) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
	{
		vPos.y += 200.f * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD
		|| CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
	{
		vPos.x -= 200.f * fDT;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD
		|| CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		vPos.x += 200.f * fDT;
	}

	SetPos(vPos);
}

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}
