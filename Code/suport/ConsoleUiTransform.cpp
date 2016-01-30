#include "ConsoleUiTransform.h"


CConsoleUiTransform::CConsoleUiTransform()
{
	StatusToString = new pf_char[2];
	strcpy(StatusToString, "");

	StatusCodeTo=0;

	UserCmd.SetCode(0);
	fp=0;

	bPrivilegeUnLock = 0;

}


CConsoleUiTransform::~CConsoleUiTransform()
{
}

void CConsoleUiTransform::SetFuncPtr(FPType2Paras fp)
{

	this->fp = fp;
}
