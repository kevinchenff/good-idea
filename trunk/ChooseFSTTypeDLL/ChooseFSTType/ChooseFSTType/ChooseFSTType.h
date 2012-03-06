// ChooseFSTType.h : main header file for the ChooseFSTType DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CChooseFSTTypeApp
// See ChooseFSTType.cpp for the implementation of this class
//

class CChooseFSTTypeApp : public CWinApp
{
public:
	CChooseFSTTypeApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
