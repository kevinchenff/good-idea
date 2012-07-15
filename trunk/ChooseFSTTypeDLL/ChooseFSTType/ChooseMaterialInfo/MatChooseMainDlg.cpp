// MatChooseMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatChooseMainDlg.h"


#include <string>
using std::string;

#include "comutil.h"

#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#ifdef _DEBUG

# pragma comment(lib, "comsuppwd.lib")

#else

# pragma comment(lib, "comsuppw.lib")

#endif

# pragma comment(lib, "wbemuuid.lib")



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
		return rc;
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
	return S_OK;
}


HRESULT MatChooseMainDlg::InsertDatabase()
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
		return rc;
	}

	BSTR iStrQuery[3];
	iStrQuery[0] = _com_util::ConvertStringToBSTR("MBD_Sys_DatabaseName=MBD_DB_HeatTreatment");
	iStrQuery[1] = _com_util::ConvertStringToBSTR("MBD_DBCol_HeatTreatment_MaterialMark=jjjgggg");
	iStrQuery[2] = _com_util::ConvertStringToBSTR("MBD_DBCol_HeatTreatment_StandardNote=jjjggggg");
	
	BSTR * ioQueryResult;
	//*ioQueryResult = new ArrayOfString[10];
	int in0_nSizeIs = 3;
	int out_nSizeIs = 0;

	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"MBDInsert");
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

	return S_OK;
}

// 解析lic
string* MatChooseMainDlg::SplitString(string str, string split, int& iSubStrs)
{
	int iPos = 0; //分割符位置
	int iNums = 0; //分割符的总数
	string strTemp = str;
	string strRight;

	vector <string> iplist;  
	vector <string>::iterator iplist_Iter;

	iPos = strTemp.find(split);
	if (iPos != -1)
	{
		strTemp = strTemp.substr(iPos + split.length(), str.length() - iPos - split.length());
	}

	//计算子字符串
	while (iPos != -1)
	{
		iPos = strTemp.find(split);
		if (iPos == -1)
		{
			iplist.push_back(strTemp);
			break;
		}
		strRight = strTemp.substr(iPos + split.length(), strTemp.length() - iPos - split.length());
		string strLeft("");
		strLeft = strTemp.substr(0,iPos);
		iplist.push_back(strLeft);

		strTemp = strRight;
		iNums++;
	}


	// 获得各个"#FEATURE"
	int j = 0;
	iSubStrs = iplist.size();
	string *pStrSplit = new string[iplist.size()];
	string strlicValue,strlicName("SIGN=");

	for ( iplist_Iter =iplist.begin( ),j = 0; iplist_Iter != iplist.end( ); iplist_Iter ++ ,j++)
	{
		iPos = iplist_Iter->find(strlicName);
		strlicValue = iplist_Iter->substr(iPos + strlicName.length(), iplist_Iter->length() - iPos - strlicName.length());

		CString cstrTran(strlicValue.c_str());

		cstrTran.Remove(L'\\');
		//cstrTran.Remove(L'\n');
		cstrTran.Remove(L' ');

		string strCs_str = CStringA(cstrTran);

		*(pStrSplit+j) = strCs_str;

	}

	return pStrSplit;
}

//Cstring To BSTR Convert
void MatChooseMainDlg::CstringToBSTR(CString icstr, BSTR &iobstr)
{
	iobstr=icstr.AllocSysString();
}


//Cstring To BSTR Convert
void MatChooseMainDlg::BSTRToCstring(CString &iocstr, BSTR ibstr)
{
	CString str(ibstr == NULL ? L"":ibstr);
    iocstr = str;
}
