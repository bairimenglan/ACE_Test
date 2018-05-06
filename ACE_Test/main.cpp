#include "Debug.h"
#include "Dllist.h"
//#define TEST_DEBUG
#define TEST_DLLIST

int main(int argc, char *argv[])
{

#ifdef TEST_DEBUG
	Debug *mDebug = new Debug();
	mDebug->runTestProc();
#endif

#ifdef TEST_DLLIST
	Dllist *mDllist = new Dllist();
	mDllist->runTestProc();
#endif

	getchar();
	return 0;
}