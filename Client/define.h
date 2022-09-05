#pragma once

// Singleton ¸ÅÅ©·Î
#define SINGLE(type) public:\
						static type* GetInst()\
					{\
						 static type mgr;\
							return &mgr; \
					}\
				private:\
					type();\
					~type();

#define DT CTimerMgr::GetInst()->GetDT()
#define fDT CTimerMgr::GetInst()->GetfDT()


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