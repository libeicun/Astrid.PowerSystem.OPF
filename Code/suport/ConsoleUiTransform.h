#pragma once
#include "pf_calc_def_data_type.h"
#include "def_data_type_fptr.h"
#include "BindingsOfUserCmdCodeAndString.h"
#include <string.h>

class CConsoleUiTransform
{
public:
	CConsoleUiTransform();
	virtual ~CConsoleUiTransform();
private:
	pf_uint32			StatusCodeTo;
	pf_char*			StatusToString;
	pf_bool			bPrivilegeUnLock;

	BindingsOfUserCmdCodeAndString
		UserCmd;
	FPType2Paras	fp;





public:
	void	EnablePrivilegeUnLock(){
		bPrivilegeUnLock = 1;
	}
	void	DisablePrivilegeUnLock(){
		bPrivilegeUnLock = 0;
	}
	pf_bool	GetPrivilegeUnLock(){
		return	bPrivilegeUnLock;
	}
	void	Exec(pf_int8*	para1, pf_int8*	para2){
		if (fp == 0)
			return;
		(*fp)(para1, para2);
	}
	void		SetUserCmdString(pf_int8*	str){
		UserCmd.SetString(str);
	}
	pf_int8*			GetUserCmdString(){
		return UserCmd.GetString();
	}
	void		SetUserCmdCode(pf_uint32 code){
		UserCmd.SetCode( code);
	}
	pf_uint32	GetUserCmdCode(){
		return	UserCmd.GetCode();
	}


	void		SetStatusCode(pf_uint32 code){
		StatusCodeTo = code;
	}
	pf_uint32	GetStatusCode(){ 
		return StatusCodeTo; 
	}
	void		SetFuncPtr(FPType2Paras fp);
	void		SetStatusString(pf_char* str){
		delete[] StatusToString;
		StatusToString = new pf_char[strlen(str)+1];
		strcpy(StatusToString, str);
	}
	pf_char*		GetStatusString(){
		return	StatusToString;
	}

};

