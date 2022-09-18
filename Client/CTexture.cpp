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
	// ���Ϸκ��� �ε��� �����͸� ��Ʈ������ ����
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// ��Ʈ�ʰ� ������ dc
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());
	
	// ��Ʈ�ʰ� dc ���� 
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

    // ��Ʈ�� ����
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);

	assert(m_hBit);
}
