#pragma once
#include "pf_calc_def_data_type.h"
#include <list>
#include <string.h>
#include "BindingsOfUserCmdCodeAndString.h"



class CConsoleUser
{
private:
	char*								UserInputString;
	pf_int8*							UserCmdString;
	pf_int8*							UserPara1String;
	pf_int8*							UserPara2String;

public:
	CConsoleUser();
	CConsoleUser(pf_uint32		inputMaxLen);
	virtual ~CConsoleUser();
	void								GetInput();
	pf_int8*							GetString();
	pf_int8*							GetCmdString();
	pf_int8*							GetPara1String();
	pf_int8*							GetPara2String();
};




#if 0
class ConsoleStatusPackage
{

public:
	pf_uint32											StatusCode;
	std::list<BindingsOfUserCmdCodeAndString>	UserBindingList;
	ConsoleStatusPackage(pf_uint32 code){
		StatusCode = code;
	}
	ConsoleStatusPackage(){
		StatusCode = 0;
	}
	ConsoleStatusPackage(const ConsoleStatusPackage& b){
		StatusCode = b.StatusCode;
		UserBindingList = b.UserBindingList;
	}
	/*ConsoleStatusPackage& operator=(const ConsoleStatusPackage b){
	ConsoleStatusPackage	r;
	r.StatusCode = b.StatusCode;
	r.UserBindingList = b.UserBindingList;
	}*/
	~ConsoleStatusPackage(){
	}

};

#endif