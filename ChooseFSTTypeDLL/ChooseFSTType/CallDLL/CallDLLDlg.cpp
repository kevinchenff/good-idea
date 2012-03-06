// CallDLLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallDLL.h"
#include "CallDLLDlg.h"

#include <string>
using std::string;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCallDLLDlg 对话框




CCallDLLDlg::CCallDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallDLLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallDLLDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CallBUTTON, &CCallDLLDlg::OnBnClickedCallbutton)
END_MESSAGE_MAP()


// CCallDLLDlg 消息处理程序

BOOL CCallDLLDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCallDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCallDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCallDLLDlg::OnBnClickedCallbutton()
{
	// TODO: Add your control notification handler code here

	HINSTANCE hDll= NULL;//DLL句柄 	
	typedef void (*lpFun)(string&,string&,float&); 
	hDll = LoadLibrary(_T("ChooseFSTType.dll"));
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

		LocalFree( lpMsgBuf );
		return;
	}

	if (NULL!=hDll)
	{
		lpFun pShowDlg = (lpFun)GetProcAddress(hDll,"ShowFstTypeSelectionDlg");
		if (NULL==pShowDlg)
		{
			AfxMessageBox(_T("DLL中函数寻找失败"));
		}

		// 		char* pFilePath= new char[] ;
		// 		char* pFileName= new char[] ;
		string pFilePath;
		string pFileName;
		float thickness=0;
		pShowDlg(pFilePath,pFileName,thickness);
		CString s1,s2;
		s1=pFilePath.c_str();
		s2=pFileName.c_str(); 
		AfxMessageBox(s1);
		AfxMessageBox(s2);
		CString str1;
		str1.Format(_T("%f"),thickness);
		AfxMessageBox(str1);
		::FreeLibrary(hDll);

	}
}
