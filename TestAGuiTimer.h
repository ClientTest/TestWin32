#pragma once
#include "WinLib/WinLibQuote.h"
#include "WinLib/Timer/AGuiTimerHandle.h"

class CTestAGuiTimer:public IAGuiTimerHandle
{
public:
	CTestAGuiTimer(void);
	~CTestAGuiTimer(void);

public:
	static void doTest();
	void TestMain();

public:
	virtual void OnAGuiTimer(uint32 nId);
};

