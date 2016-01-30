#include "ConsoleUi.h"
#include "stringExtends.h"
#include <stdio.h>
CConsoleUi::CConsoleUi()
{
	Status = 0;
	fpDefaultProc = default_proc_when_input_invalid;
	bEnExec = 1;
	bEnStatusTrans = 1;
	Trans.SetStatusString("");

}
CConsoleUi::~CConsoleUi()
{
}
void CConsoleUi::ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode)
{
	FsmTable.AddItem(statusCodeFrom, statusCodeTo, pProc, cmdCode, strCode,"",0);
}
void CConsoleUi::ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, char* strStatusTo){
	FsmTable.AddItem(statusCodeFrom, statusCodeTo, pProc, cmdCode, strCode, strStatusTo,0);
}

void	CConsoleUi::ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, char* strStatusTo, pf_bool previlige){
	FsmTable.AddItem(statusCodeFrom, statusCodeTo, pProc, cmdCode, strCode, strStatusTo, previlige);
}
void CConsoleUi::ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, pf_bool previlige)
{
	FsmTable.AddItem(statusCodeFrom, statusCodeTo, pProc, cmdCode, strCode, "", previlige);
}
void CConsoleUi::FsmInteractOnce()
{

	pf_uint32			 StatusCur;
	static				pf_bool	enCur = 1;
	User.GetInput();
	pf_bool	find = FsmTable.GetItem(Status, User.GetCmdString(), Trans);
	if (!find)
	{
		(*fpDefaultProc)();

	}
	else
	{
		if (bEnExec || Trans.GetPrivilegeUnLock()){
			Trans.Exec(User.GetPara1String(), User.GetPara2String());
			if (bEnStatusTrans)
				enCur = 1;
			if (enCur)
				Status = Trans.GetStatusCode();
			if (!bEnStatusTrans)
				enCur = 0;
		}
	}
	/*if (Status == Trans.GetStatusCode())
	{
		pf_char*	s = Trans.GetStatusString();
		if (strcmp(s, "") != 0)
			printf("%s", s);
	}*/



}

void	CConsoleUi::EnableStausTrans(){
	bEnStatusTrans = 1;
}
void	CConsoleUi::DisableStausTrans(){
	bEnStatusTrans = 0;
}
void	CConsoleUi::EnableExec(){
	bEnExec = 1;
}
void	CConsoleUi::DisableExec(){
	bEnExec = 0;
}

void default_proc_when_input_invalid()
{
	printf("Invalid Input Dectected.\nPlease Check it out.\n");
}
