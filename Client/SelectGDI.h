#pragma once
class SelectGDI
{
private:
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;
	HDC		m_hDC;

public:
	SelectGDI(HDC _dc, PEN_TYPE _eType);
	SelectGDI(HDC _dc, BRUSH_TYPE _eType);
	~SelectGDI();
};

