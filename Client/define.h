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