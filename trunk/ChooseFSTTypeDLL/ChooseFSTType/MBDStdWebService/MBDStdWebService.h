// MBDStdWebService.h : main header file for the MBDStdWebService DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#include "WebService.h"
using namespace Service;


// CMBDStdWebServiceApp
// See MBDStdWebService.cpp for the implementation of this class
//

class CMBDStdWebServiceApp : public CDialog
{
public:
	CMBDStdWebServiceApp();

// Overrides
public:
	// 定义MBD数据查询函数	
	HRESULT MBDQuery(BSTR* iStrQuery,int in0_nSizeIs,BSTR *&ioQueryResult,int &out_nSizeIs);

	HRESULT MBDInsert(BSTR* in0, int in0_nSizeIs, BSTR* &out, int &out_nSizeIs);

	HRESULT GetURLAddress(char *& strURLAddress);

	inline const char * LOCAL_2_MCBS(LPCTSTR lpstr);

	inline LPCTSTR MCBS_2_LOCAL(const char *lpstr);

	BSTR GetCurrentDataPath();



	DECLARE_MESSAGE_MAP()
};
