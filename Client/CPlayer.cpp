#include "pch.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CPlayer.h"
#include "CMissile.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CPathMgr.h"
#include "CTexture.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	// Texture 로딩하기
	m_pTex = new CTexture;

	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += L"Texture\\player.bmp";
	m_pTex->load(strFilePath);
}

CPlayer::~CPlayer()
{
	if (nullptr != m_pTex)
		delete m_pTex;
}

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

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	//BitBlt(_dc
	//	, vPos.x - (float)(iWidth / 2)
	//	, vPos.y - (float)(iHeight / 2)
	//	, iWidth, iHeight
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);

	TransparentBlt(_dc
		, int(vPos.x - (float)(iWidth / 2))
		, int(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 255, 0));
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
	pMissile->SetDir(Vec2(1.f, 1.f));

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
