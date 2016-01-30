#pragma once
#include "ConsoleUiTransform.h"
#include "ConsoleUiStatusTableLine.h"
#include <list>
using namespace std;
class CConsoleUiStatusTable
{
private:
	list<CConsoleUiStatusTableLine>	Table;
	pf_bool								LocateLine(pf_uint32 statusCodeFrom, list<CConsoleUiStatusTableLine>::iterator& iter);
	//pf_bool								LocateNode(list<CConsoleUiStatusTableLine>::iterator line_iter, pf_uint32 statusCodeTo,list<CConsoleUiTransform>::iterator& iter);
	pf_bool								LocateNode(list<CConsoleUiStatusTableLine>::iterator line_iter, pf_int8* strCode, list<CConsoleUiTransform>::iterator& iter);

public:

	CConsoleUiStatusTable();
	virtual ~CConsoleUiStatusTable();
	pf_bool		GetItem(pf_uint32 statusCodeFrom, char*	strCode, CConsoleUiTransform& item);
	void			AddItem(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, char* strStatusTo, pf_bool previlige);
	void			PrivilegeUnLockItem(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo);
	void			UnPrivilegeUnLockItem(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo);
};

