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

#define DT CTimerMgr::GetInst()->GetDT()
#define fDT CTimerMgr::GetInst()->GetfDT()