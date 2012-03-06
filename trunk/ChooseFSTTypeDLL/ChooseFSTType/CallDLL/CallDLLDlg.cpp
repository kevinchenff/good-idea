// CallDLLDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallDLL.h"
#include "CallDLLDlg.h"

#include <string>
using std::string;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCallDLLDlg �Ի���




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


// CCallDLLDlg ��Ϣ�������

BOOL CCallDLLDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCallDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CCallDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCallDLLDlg::OnBnClickedCallbutton()
{
	// TODO: Add your control notification handler code here

	HINSTANCE hDll= NULL;//DLL��� 	
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
			AfxMessageBox(_T("DLL�к���Ѱ��ʧ��"));
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
