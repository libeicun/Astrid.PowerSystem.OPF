#include "ConsoleUiStatusTable.h"
#include "stringExtends.h"

CConsoleUiStatusTable::CConsoleUiStatusTable()
{
}


CConsoleUiStatusTable::~CConsoleUiStatusTable()
{
}

pf_bool	CConsoleUiStatusTable::LocateLine(pf_uint32 statusCodeFrom, list<CConsoleUiStatusTableLine>::iterator& in)
{

	list<CConsoleUiStatusTableLine>::iterator	p;
	pf_bool											ret = 0;
	CConsoleUiStatusTableLine					StatusTableLineData;

	for (p = Table.begin(); p != Table.end(); p++)
	{
		StatusTableLineData = *(p);
		if (StatusTableLineData.GetStatusCode() == statusCodeFrom)
		{
			ret = 1;
			in = p;
			break;
		}
	}
	return	ret;
}
pf_bool CConsoleUiStatusTable::LocateNode(list<CConsoleUiStatusTableLine>::iterator line_iter, pf_int8* strCode, list<CConsoleUiTransform>::iterator& iter)
{
	pf_bool	ret=0;

	list<CConsoleUiTransform>			tList;
	list<CConsoleUiTransform>::iterator	t;
	CConsoleUiTransform					tData;
	for (t = line_iter->Nodes.begin(); t != line_iter->Nodes.end(); t++)
	{

		tData = *t;
		if (strsubstr(tData.GetUserCmdString(), strCode))
		{
			iter = t;
			ret = 1;
			break;
		}
	}
	return	ret;
}
void CConsoleUiStatusTable::AddItem(pf_uint32 statusCodeFrom, pf_uint32 statusCodeTo, FPType2Paras pProc, pf_uint32 cmdCode, char*	strCode, char* strStatusTo, pf_bool previlige)
{
	list<CConsoleUiStatusTableLine>::iterator p;

	pf_bool	find = LocateLine(statusCodeFrom,p);
	if (!find)
	{
		CConsoleUiStatusTableLine	newLine;
		newLine.SetStatusCode(statusCodeFrom);
		newLine.AddNode(pProc, cmdCode, strCode,strStatusTo, statusCodeTo,previlige);
		Table.push_back(newLine);

	}
	else
	{
		p->AddNode(pProc, cmdCode, strCode, strStatusTo, statusCodeTo,previlige);
	}

}


pf_bool	CConsoleUiStatusTable::GetItem(pf_uint32 statusCodeFrom, char*	strCode, CConsoleUiTransform& item)
{
	pf_bool	ret=0;

	list<CConsoleUiStatusTableLine>::iterator	pLine;
	list<CConsoleUiTransform>::iterator			pNode;
	pf_bool	findLine = LocateLine(statusCodeFrom, pLine);
	if (!findLine)/*There is no line match the statusCodeFrom.*/
		return 0;
	else/*An matched line found.*/
	{
		pf_bool	findNode = LocateNode(pLine, strCode, pNode);
		if (!findNode)/*There is no found node in the line.*/
		{
			return 0;
		}
		else/*Matched node found.*/
		{
			item = *pNode;
			ret = 1;
		}
	}
	return ret;
}