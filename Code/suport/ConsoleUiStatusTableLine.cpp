#include "ConsoleUiStatusTableLine.h"


CConsoleUiStatusTableLine::CConsoleUiStatusTableLine()
{
}


CConsoleUiStatusTableLine::~CConsoleUiStatusTableLine()
{
}
void	CConsoleUiStatusTableLine::AddNode(FPType2Paras fp, pf_uint32	 userCmdCode, pf_int8* strCode,pf_char*strStatus, pf_uint32	statusTo,pf_bool previlige)
{
	CConsoleUiTransform	t;
	t.SetFuncPtr(fp);
	t.SetStatusCode(statusTo);
	t.SetUserCmdCode(userCmdCode);
	t.SetUserCmdString(strCode);
	t.SetStatusString(strStatus);
	if(previlige)
		t.EnablePrivilegeUnLock();
	Nodes.push_back(t);
}
