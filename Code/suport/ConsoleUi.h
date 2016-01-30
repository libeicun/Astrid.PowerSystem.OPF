#pragma once
#include "pf_calc_def_data_type.h"
#include "ConsoleUiStatusTable.h"
#include "ConsoleUiTransform.h"
#include "ConsoleUser.h"
#include <list>
using namespace std;
void	default_proc_when_input_invalid();
class CConsoleUi
{
	
private:
	CConsoleUiStatusTable		FsmTable;
	CConsoleUser				User;
	pf_uint32						Status;
	pf_bool						bEnExec;
	pf_bool						bEnStatusTrans;
	FPTypeNonePara			fpDefaultProc;

	CConsoleUiTransform		Trans;
public:
	CConsoleUi();
	~CConsoleUi();
	void	SetDefaultProc(FPTypeNonePara fp){
		fpDefaultProc = fp;
	}
	void	FsmInteractOnce();
	void	ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode,char*	strCode);
	void	ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode,char* strStatusTo);
	void	ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, char* strStatusTo, pf_bool previlige);
	void   ResgisterProc(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, pf_bool previlige);
	
	void	SetStatus(pf_uint32	code){
		Status = code;
	}
	void	EnableExec();
	void	DisableExec();
	void	EnableStausTrans();
	void	DisableStausTrans();


	void	PrivilegeUnLock(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo);
	void	UnPrivilegeUnLock(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo);




	pf_uint32	GetStatus(){
		return	Status;
	}
};

