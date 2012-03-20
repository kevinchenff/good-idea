// ChooseMaterialInfo.h : main header file for the ChooseMaterialInfo DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CChooseMaterialInfoApp
// See ChooseMaterialInfo.cpp for the implementation of this class
//

class CChooseMaterialInfoApp : public CWinApp
{
public:
	CChooseMaterialInfoApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
