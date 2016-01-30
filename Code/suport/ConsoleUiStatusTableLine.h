#pragma once
#include "ConsoleUiTransform.h"
#include <list>
using namespace std;
class CConsoleUiStatusTableLine
{
private:
	
	pf_uint32							StatusCodeFrom;
public:
	list<CConsoleUiTransform>	Nodes;
	CConsoleUiStatusTableLine();
	virtual ~CConsoleUiStatusTableLine();
	pf_uint32 GetStatusCode(){ 
		return StatusCodeFrom; 
	}
	void	SetStatusCode(pf_uint32 code){
		StatusCodeFrom = code;
	}
	//const CList<CConsoleUiTransform>  const GetNodeList(){ return Nodes; };
	void       AddNode(FPType2Paras fp, pf_uint32	 userCmdCode, pf_int8* strCode, pf_char*strStatus, pf_uint32	statusTo,pf_bool previlige);
};

