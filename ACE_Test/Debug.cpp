#include "Debug.h"

Debug::Debug()
{
}


Debug::~Debug()
{
}


void Debug::runTestProc()
{
	ACE_TRACE(ACE_TEXT("ACE_TMAIN!"));
	ACE_DEBUG((LM_INFO, ACE_TEXT("Hello ACE Log Msg !")));
	getchar();
}