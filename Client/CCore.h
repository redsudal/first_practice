#pragma once

#include "pch.h"

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능

//class CCore
//{
//private:
//	//static CCore* g_pInst;
//
//public:
//	// 정적 맴버함수
//	static CCore* GetInstance()
//	{
//		// 최초 호출 된 경우	
//		if (nullptr == g_pInst)
//		{
//			g_pInst = new CCore;
//		}
//		
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//		
//	}
//
//private:
//	CCore();
//	~CCore();
//};


class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution;	// 
	HDC		m_hDC;

	HBITMAP m_hBit;
	HDC		m_memDC;

	// 자주 사용하는 GDI Object
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

	

private:
	void CreateBrushPen();

public:
	HWND  GetMainHwnd() { return m_hWnd; }
	HDC	  GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
};