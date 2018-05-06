#pragma once

#ifndef WIN32
#define WIN32
#endif

#define ACE_NTRACE 0 //追踪函数开启的宏定义  0：开启   1：关闭
#include "ace/Log_Msg.h"
#include "Test.h"
class Debug :
	public Test
{
public:
	Debug();
	~Debug();
	virtual void runTestProc();
};
