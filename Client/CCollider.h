#pragma once

class CObject;

class CCollider
{
private:
	CObject*	m_pOwner;		// collider �� �����ϰ� �ִ� ������Ʈ
	Vec2		m_vOffsetPos;	// ������Ʈ�� ���� ������� ��ġ
	Vec2		m_vFinalPos;	// finalupdate ���� �� �����Ӹ��� ���
	Vec2		m_vScale;		// �浹ü(collider) ũ��

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

