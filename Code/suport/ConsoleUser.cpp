#include "ConsoleUser.h"
#include "stringExtends.h"
#include <stdio.h>
CConsoleUser::CConsoleUser()
{
	
	UserInputString = new char[50];
	UserCmdString = new char[50];
	UserPara1String = new char[50];
	UserPara2String= new char[50];
}
CConsoleUser::CConsoleUser(pf_uint32	inputMaxLen)
{
	UserInputString = new char[inputMaxLen];
	UserCmdString = new char[50];
	UserPara1String = new char[50];
	UserPara2String = new char[50];
}


CConsoleUser::~CConsoleUser()
{
	delete	UserInputString;
	delete	UserCmdString;
	delete	UserPara1String;
	delete	UserPara2String;
}

pf_int8*							CConsoleUser::GetString()
{
	return	UserInputString;
}


void CConsoleUser::GetInput()
{

	printf(">>");
	gets(UserInputString);

	strcpy(UserCmdString, "");
	strcpy(UserPara1String, "");
	strcpy(UserPara2String, "");

	char* copy = new char[strlen(UserInputString) + 1];
	strcpy(copy, UserInputString);//创建m_answer的拷贝，存入copy

	strcpy(UserCmdString, strfleft(copy, ' '));

	strcpy(copy, UserInputString);//创建m_answer的拷贝，存入copy

	strfright(copy, ' ');//切除前段字符
	strcpy(UserPara1String, strfleft(copy, ' '));//提取

	strcpy(copy, UserInputString);//创建m_answer的拷贝，存入copy

	strcpy(copy, strfright(copy, ' '));//切除前段字符
	strcpy(copy, strfright(copy, ' '));//切除前段字符

	strcpy(UserPara2String, strfleft(copy, ' '));//提取

	delete[] copy;
}


pf_int8*							CConsoleUser::GetCmdString(){
	return	UserCmdString;
}
pf_int8*							CConsoleUser::GetPara1String(){
	return	UserPara1String;
}
pf_int8*							CConsoleUser::GetPara2String(){
	return	UserPara2String;
}

/*
void CConsoleUser::BindCmdCode(pf_uint32 StatusCode, pf_uint32	CmdCode, char* InputStr)
{

	std::list<ConsoleStatusPackage>::iterator	p;

	pf_bool											find=
	LocatePackage(StatusCode, p);
	
	std::list<ConsoleStatusPackage>::iterator	packageNode ;
	ConsoleStatusPackage							package;

	if (!find)
	{
		BindingsOfUserCmdCodeAndString	binding(CmdCode,InputStr) ;
		ConsoleStatusPackage				pack(StatusCode);
		pack.StatusCode = StatusCode;
		pack.UserBindingList.push_back(binding);
		StatusList.push_back(pack);
	}
	else

	{
		packageNode = p;
		package = *packageNode;
		BindingsOfUserCmdCodeAndString	binding (CmdCode, InputStr);
		packageNode->UserBindingList.push_back(binding);
	}	

}*/



/*
pf_uint32 CConsoleUser::GetUserCmdCode(pf_uint32	StatusCode)
{
	pf_uint32																cmdCode = 0;
	std::list<ConsoleStatusPackage>::iterator						p;
	pf_bool	find = LocatePackage(StatusCode, p);
	std::list<BindingsOfUserCmdCodeAndString>					bindingList;
	std::list<BindingsOfUserCmdCodeAndString>::iterator			iter;
	BindingsOfUserCmdCodeAndString								bindingData(1, "");
	pf_uint32																i = 0;

	if (find)
	{
		pf_uint32	Size = p->UserBindingList.size();
		for (iter = p->UserBindingList.begin(); iter != p->UserBindingList.end(); iter++)
		{
			bindingData = *iter;
			if (strsubstr(bindingData.String, UserInputString))
			{
				cmdCode = bindingData.Code;
				break;
			}
		}
		if (i >= Size)
		{
			cmdCode = 0;
		}

	}

	return cmdCode;
}*/
/*
pf_bool CConsoleUser::LocatePackage(pf_uint32	StatusCode, std::list< ConsoleStatusPackage>::iterator& in)
{
	std::list<ConsoleStatusPackage>::iterator	packageNode ;
	std::list<ConsoleStatusPackage>::iterator	iter ;
	ConsoleStatusPackage				package ;
	pf_uint32									i = 0;
	pf_bool								ret=0;
	//StatusList.resetIterator();
	pf_uint32	Size = StatusList.size();
	if (Size==0)
	{
		ret = 0;
	}
	for (iter=StatusList.begin(); iter!=StatusList.end(); iter++)
	{
		package = *iter;
		if (package.StatusCode == StatusCode)
		{
			in=	iter;
			ret = 1;
		}
	}
	return ret;
}
*/
