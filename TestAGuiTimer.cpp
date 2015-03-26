#include "StdAfx.h"
#include "TestAGuiTimer.h"

#define AGUI_TIMER_CHECK_SEND_QUEUE  1000 
#define AGUI_TIMER_KEEP_ALIVE        1001 

void CTestAGuiTimer::doTest()
{
	printf("CTestAGuiTimer run.............\n");
	CTestAGuiTimer instance;
	instance.TestMain();
	while(true)
	{

	}
}

void CTestAGuiTimer::OnAGuiTimer(uint32 nId)
{
	switch(nId)
	{
	case AGUI_TIMER_CHECK_SEND_QUEUE:
		{
			printf("timer on AGUI_TIMER_CHECK_SEND_QUEUE\n");
			static int nCount = 0;
			nCount++;
			if(nCount>=4)
			{
				KillAGuiTime(AGUI_TIMER_CHECK_SEND_QUEUE);
			}
		}
		break;
	case AGUI_TIMER_KEEP_ALIVE:
		{
			printf("timer on AGUI_TIMER_KEEP_ALIVE\n");
			static int nCount = 0;
			nCount++;
			if(nCount>=1)
			{
				KillAGuiTime(AGUI_TIMER_KEEP_ALIVE);
			}
		}
		break;
	default:
		break;
	}
}

void CTestAGuiTimer::TestMain()
{
	IAGuiTimerHandle::StartTimer();
	SetAGuiTimeInterval(AGUI_TIMER_CHECK_SEND_QUEUE,1);
	SetAGuiTimeInterval(AGUI_TIMER_KEEP_ALIVE,3);
	//SetAGuiTimeOut(AGUI_TIMER_KEEP_ALIVE,3);
}

CTestAGuiTimer::CTestAGuiTimer(void)
{
}


CTestAGuiTimer::~CTestAGuiTimer(void)
{
	IAGuiTimerHandle::StopTimer();
}
