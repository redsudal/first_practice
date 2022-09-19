#include "pch.h"
#include "CCollider.h"

#include "CObject.h"
#include "CCore.h"

#include "SelectGDI.h"


CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vFinalPos(Vec2(0.f, 0.f))
	, m_vOffsetPos(Vec2(0.f, 0.f))
	, m_vScale(Vec2(0.f, 0.f))
{
}

CCollider::~CCollider()
{

}

void CCollider::finalupdate()
{
	// Object 의 위치를 따라간다
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = m_vOffsetPos + vObjectPos;
}

void CCollider::render(HDC _dc)
{
	SelectGDI green(_dc, PEN_TYPE::GREEN);
	SelectGDI hollow(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, (int)m_vFinalPos.x - m_vScale.x / 2.f
		, (int)m_vFinalPos.y - m_vScale.y / 2.f
		, (int)m_vFinalPos.x + m_vScale.x / 2.f
		, (int)m_vFinalPos.y + m_vScale.y / 2.f);
}
