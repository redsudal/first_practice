#include "pch.h"
#include "CMissile.h"
#include "CTimeMgr.h"

CMissile::CMissile()
	: m_fTheta(PI / 2.f)
	, m_vDir(Vec2(1.f, 1.f))
{
	m_vDir.Normalize();
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 pos = GetPos();

	//pos.x += 200.f * cosf(m_fTheta) * fDT;
	//pos.y -= 200.f * sinf(m_fTheta) * fDT;

	pos.x += 200.f * m_vDir.x * fDT;
	pos.y -= 200.f * m_vDir.y * fDT;

	SetPos(pos);
}

void CMissile::render(HDC _dc)
{
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();

	Ellipse(_dc, (int)(pos.x - scale.x / 2.f), (int)(pos.y - scale.y / 2.f)
		, (int)(pos.x + scale.x / 2.f), (int)(pos.y + scale.y / 2.f));
}