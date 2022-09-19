#include "pch.h"
#include "SelectGDI.h"

#include "CCore.h"

SelectGDI::SelectGDI(HDC _dc, PEN_TYPE _eType)
	: m_hDC(_dc)
	, m_hDefaultPen(nullptr)
	, m_hDefaultBrush(nullptr)
{
	HPEN hPen = CCore::GetInst()->GetPen(PEN_TYPE::GREEN);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);
}

SelectGDI::SelectGDI(HDC _dc, BRUSH_TYPE _eType)
	: m_hDC(_dc)
	, m_hDefaultPen(nullptr)
	, m_hDefaultBrush(nullptr)
{
	HBRUSH hBrush = CCore::GetInst()->GetBrush(BRUSH_TYPE::HOLLOW);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush);
}

SelectGDI::~SelectGDI()
{
	SelectObject(m_hDC, m_hDefaultBrush);
	SelectObject(m_hDC, m_hDefaultPen);
}
