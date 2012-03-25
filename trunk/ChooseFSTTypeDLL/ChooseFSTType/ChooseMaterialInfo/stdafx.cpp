// stdafx.cpp : source file that includes just the standard includes
// ChooseMaterialInfo.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#include "MatChooseMainDlg.h"
#include "resource.h"
#include <string>
using std::string;

extern "C" __declspec(dllexport) BOOL ShowMaterialSelectionDlg(string& oFilePath,string& oFileName,float& oThickness)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxEnableControlContainer();
	MatChooseMainDlg pMainDlg;
	if(IDOK == pMainDlg.DoModal())
	{
		//
		return TRUE;
	}	
	else
	{
		//
		/*oFilePath=(LPSTR)(LPCTSTR)("");
		oFileName=(LPSTR)(LPCTSTR)("");
		oThickness=0;*/
		return FALSE;
	}



}