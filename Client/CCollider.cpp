#include "pch.h"
#include "CCollider.h"

#include "CObject.h"
#include "CCore.h"

#include "SelectGDI.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_iID(g_iNextID++)
{
}

CCollider::~CCollider()
{

}

void CCollider::finalupdate()
{
	// Object �� ��ġ�� ���󰣴�
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
