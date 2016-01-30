#include <stdlib.h>
#include <stdio.h>
#include "UserCmdAndStatus.h"
#include "UserProcesses.h"
#include "ConsoleUi.h"
#include "SMatrixCSC.h"
#include "SMatrixSP1_3.h"
#include "Timing.h"
#if 0
#define OFFSET	0;
void main()
{
	CSMatrixSP1_3<pf_f64>	mat(5, 5);
	mat.Set(0, 0, 2);
	mat.Set(1, 0, 3);

	mat.Set(0, 1, 3);
	mat.Set(4, 1, 4);
	mat.Set(2, 1, -1);

	mat.Set(3, 2, 1);
	mat.Set(4, 2, 2);
	mat.Set(2, 2, -3);
	mat.Set(1, 2, 4);
	mat.Set(0, 2, 1);
	mat.Set(1, 2, 5);

	mat.Set(2, 3, 2);
	mat.Set(1, 4, 6);
	mat.Set(4, 4, 1);

	mat.Print();
}
#endif

#if 0
void main()
{
	CSMatrixCSC<pf_f64>	mat(5, 5);
	std::list<CBindingOfAxAi<pf_f32>>::iterator iter;
	mat.Set(0, 0, 2);
	mat.Set(1, 0, 3);

	mat.Set(0, 1, 3);
	mat.Set(4, 1, 4);
	mat.Set(2, 1, -1);

	mat.Set(3, 2, 1);
	mat.Set(4, 2, 2);
	mat.Set(2, 2, -3);
	mat.Set(1, 2, 4);
	mat.Set(0, 2, 1);
	mat.Set(1, 2, 5);

	mat.Set(2, 3, 2);
	mat.Set(1, 4, 6);
	mat.Set(4, 4, 1);
	//mat.LocateNode(3, 0);

	mat.Print();
	mat.GetSparsity();


}


#endif
#if 1
CConsoleUi	cui;
int main()
{

	

	cui.SetStatus(eStatusWaitForCmd);
	cui.SetDefaultProc(fDefaultProc);
	/*cui.ResgisterProc(eStatusWaitForCmd, eStatusPostBuildDataFile,
		fPfBDF, eUserCmdBuildDataFile, "builddatafile");
	cui.ResgisterProc(eStatusPostBuildDataFile, eStatusWaitForCmd,
		fReturn, eUserReturn, "return");
	cui.ResgisterProc(eStatusWaitForCmd, eStatusPostPfCalc,
		fPfCalcOnce, eUserCmdPfCalc, "powerflowlodafolwcalc");
	cui.ResgisterProc(eStatusPostPfCalc, eStatusWaitForCmd,
		fReturn, eUserReturn, "return");
	cui.ResgisterProc(eStatusPostPfCalc, eStatusPostBuildDataFile,
		fPfBDF, eUserCmdBuildDataFile, "builddatafile");
	cui.ResgisterProc(eStatusPostBuildDataFile, eStatusPostPfCalc,
		fPfCalcOnce, eUserCmdPfCalc, "powerflowlodafolwcalc");
*/
	cui.ResgisterProc(eStatusWaitForCmd, eStatusWaitForCmd,
		fPfCalcOnce, eUserCmdPfCalc, "powerflowlodafolwcalc");
	cui.ResgisterProc(eStatusWaitForCmd, eStatusWaitForCmd,
		fSyscall, eUserCmdPfCalc, "system");
	cui.ResgisterProc(eStatusWaitForCmd, eStatusLocked,
		fLock, eUserCmdPfCalc, "lock");
	cui.ResgisterProc(eStatusLocked, eStatusWaitForCmd,
		fUnLock, eUserCmdPfCalc, "unlock",1);

	CTiming::On();
	while(1)
	{
		//system("cls");
		cui.FsmInteractOnce();
	}
	return 0;

	
}
#endif 