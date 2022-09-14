#pragma once



// Singleton ��ũ��
#define SINGLE(type) public:\
						static type* GetInst()\
					{\
						 static type mgr;\
							return &mgr; \
					}\
				private:\
					type();\
					~type();

#define DT CTimeMgr::GetInst()->GetDT()
#define fDT CTimeMgr::GetInst()->GetfDT()

#define KEYCHECK(key, state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_TAP(key) KEYCHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEYCHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEYCHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEYCHECK(key, KEY_STATE::NONE)

#define PI 3.1415926535f

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILBE,
	MONSTER,


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};