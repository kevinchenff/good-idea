// FstTypeMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstTypeMainDlg.h"
#include "afxdlgs.h"
#include <afx.h>


// FstTypeMainDlg dialog

IMPLEMENT_DYNAMIC(FstTypeMainDlg, CDialog)

FstTypeMainDlg::FstTypeMainDlg(CWnd* pParent /*=NULL*/)
	:ClxDialog(FstTypeMainDlg::IDD, pParent)
{

}

FstTypeMainDlg::~FstTypeMainDlg()
{
}

void FstTypeMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTJstResult, m_listCtrl);
	DDX_Control(pDX, IDC_SaveBackKnowCHECK, m_BackDataBaseCheck);
	DDX_Control(pDX, IDC_KnowledgeRADIO, m_KnowRadio);
	DDX_Control(pDX, IDC_FreeRADIO, m_FreeRadio);
}


BEGIN_MESSAGE_MAP(FstTypeMainDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ChooseFstPB, &FstTypeMainDlg::OnBnClickedChoosefstpb)
	ON_BN_CLICKED(IDOK, &FstTypeMainDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// FstTypeMainDlg message handlers

//
BOOL FstTypeMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	m_listCtrl.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_listCtrl.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_listCtrl.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_listCtrl.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_listCtrl.InsertColumn(3,_T("类型"),LVCFMT_LEFT,100);
	m_listCtrl.InsertColumn(4,_T("安装部位"),LVCFMT_LEFT,100);
	//
	return TRUE;
}

HBRUSH FstTypeMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstTypeMainDlg::OnPaint()
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

CString  FstTypeMainDlg::GetEXEPath()   
{   
	CString    sPath;   
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);   
	sPath.ReleaseBuffer    ();   
	int    nPos;   
	nPos=sPath.ReverseFind('\\');   
	sPath=sPath.Left(nPos);   
	return    sPath; 
}


void FstTypeMainDlg::OnBnClickedChoosefstpb()
{
	// TODO: Add your control notification handler code here
	// 开始选择紧固件按钮响应，首先提示选择类型
	if (m_KnowRadio.GetCheck())
	{
		m_pKnowDlg.DoModal();
	}
	else if (m_FreeRadio.GetCheck())
	{
		//显示自由选择模式
	}
	else
	{
		//给予提示信息
		MessageBox(_T("请选择紧固件选择方式！"),_T("错误提示"));
	}
}
void FstTypeMainDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
}
