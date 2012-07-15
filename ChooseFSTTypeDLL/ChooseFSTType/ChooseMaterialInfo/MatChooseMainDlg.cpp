// MatChooseMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatChooseMainDlg.h"


// MatChooseMainDlg dialog

IMPLEMENT_DYNAMIC(MatChooseMainDlg, CDialog)

MatChooseMainDlg::MatChooseMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MatChooseMainDlg::IDD, pParent),m_piSon(NULL)
{
	if (NULL != m_piSon)
	{
		m_piSon->DestroyWindow();
		m_piSon = NULL;
	}
}

MatChooseMainDlg::~MatChooseMainDlg()
{
}

void MatChooseMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MatChooseMainDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_NextStepPB, &MatChooseMainDlg::OnBnClickedNextsteppb)
END_MESSAGE_MAP()


// MatChooseMainDlg message handlers

void MatChooseMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC dcMem; 
	dcMem.CreateCompatibleDC(&dc); 

	CRect rect1;
	GetClientRect(&rect1); 		

	CBitmap m_bitmap;
	m_bitmap.LoadBitmap(IDB_BITBackground);

	BITMAP bitMap;
	m_bitmap.GetBitmap(&bitMap);

	CBitmap *pbmpOld=dcMem.SelectObject(&m_bitmap);  
	dc.StretchBlt(0,(rect1.Height()-bitMap.bmHeight),bitMap.bmWidth,bitMap.bmHeight,&dcMem,0,0,bitMap.bmWidth,bitMap.bmHeight,SRCCOPY); 
}

HBRUSH MatChooseMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor==CTLCOLOR_BTN)  
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_SCROLLBAR)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_EDIT)
	{;
	pDC->SetTextColor(RGB(0,0,0));
	pDC->SetBkColor(RGB(255,255,255));
	HBRUSH b=CreateSolidBrush(RGB(255,255,255));
	return b;
	}
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}

	else if(nCtlColor==CTLCOLOR_MSGBOX )
	{
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(250,230,200));
		HBRUSH b=CreateSolidBrush(RGB(250,230,200));
		return b;
	}
	return hbr;
}

void MatChooseMainDlg::OnBnClickedNextsteppb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new MatOtherInfoDlg(this);
	m_piSon->Create(IDD_OtherInfoDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

//查询函数，通过DLL访问数据库系统
HRESULT MatChooseMainDlg::QuaryDatabase()
{
	HRESULT rc = E_FAIL;
	// method
	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef HRESULT (*lpFun)(BSTR* ,int ,BSTR *&, int&); 
	hDll = LoadLibrary(_T("MBDStdWebService.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("提示信息" );
		LocalFree( lpMsgBuf );
		return;
	}

	BSTR iStrQuery[5];
	iStrQuery[0] = _com_util::ConvertStringToBSTR("DatabaseName=F_BEAD_FLANGE_SPEC_INFO");
	BSTR * ioQueryResult;
	//*ioQueryResult = new ArrayOfString[10];
	int in0_nSizeIs = 1;
	int out_nSizeIs = 0;

	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"MBDQuery");
		if (NULL==pMBDQuery)
		{
			AfxMessageBox(_T("DLL中函数寻找失败"));
		}


		//可能需要对输入条件进行判断，以求确定内容的可靠性

		HRESULT hr = pMBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

		if (SUCCEEDED(hr))
		{
			int i = 0;
			if (ioQueryResult != NULL)
			{
				while (NULL != *(ioQueryResult+i))
				{
					CString str(*(ioQueryResult+i));
					//MessageBox(NULL,str,TEXT("msg"),MB_OK);
					MessageBox(str,L"调用结果");
					i++;
				}
			}
		}

		::FreeLibrary(hDll);
	}
	
	//
	return rc;
}