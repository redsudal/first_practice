#include "pch.h"
#include "CTexture.h"

#include"CCore.h"

CTexture::CTexture()
	: m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
{
}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void CTexture::load(const wstring& _strFilePath)
{
	// 파일로부터 로딩한 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// 비트맵과 연결할 dc
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());
	
	// 비트맵과 dc 연결 
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

    // 비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);

	assert(m_hBit);
}
