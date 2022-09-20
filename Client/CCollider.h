#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject*	m_pOwner;		// collider 를 소유하고 있는 오브젝트
	Vec2		m_vOffsetPos;	// 오브젝트로 부터 상대적인 위치
	Vec2		m_vFinalPos;	// finalupdate 에서 매 프레임마다 계산
	Vec2		m_vScale;		// 충돌체(collider) 크기

	UINT		m_iID;

public:
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetFinalPos(Vec2 _vPos) { m_vFinalPos = _vPos; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetFinalPos() { return m_vFinalPos; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	CCollider();
	~CCollider();


	friend class CObject;
};

