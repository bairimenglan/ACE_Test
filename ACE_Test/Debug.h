#pragma once

#ifndef WIN32
#define WIN32
#endif

#define ACE_NTRACE 0 //׷�ٺ��������ĺ궨��  0������   1���ر�
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
