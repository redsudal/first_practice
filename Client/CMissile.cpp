#include "pch.h"
#include "CMissile.h"
#include "CTimeMgr.h"

CMissile::CMissile()
	: m_fDir(1.f)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 pos = GetPos();

	pos.y += 200.f * fDT * (float)m_fDir;

	SetPos(pos);
}

void CMissile::render(HDC _dc)
{
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();

	Ellipse(_dc, (int)(pos.x - scale.x / 2.f), (int)(pos.y - scale.y / 2.f)
		, (int)(pos.x + scale.x / 2.f), (int)(pos.y + scale.y / 2.f));
}