// FstKnowMainFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
//头文件
#include "FstKnowMainFstLengthDlg.h"
#include "FstKnowMainFstDlg.h"
#include "FstTypeMainDlg.h"
#include "FstKnowGasketFstDlg.h"
#include "FstKnowNutFstDlg.h"
#include "FstKnowledgeBasedDlg.h"

// FstKnowMainFstDlg dialog

IMPLEMENT_DYNAMIC(FstKnowMainFstDlg, CDialog)

FstKnowMainFstDlg::FstKnowMainFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowMainFstDlg::IDD, pParent),m_piKnowNutFstDlg(NULL)
{
	m_piKnowledgeBaseddlg = (FstKnowledgeBasedDlg*)pParent;
}

FstKnowMainFstDlg::~FstKnowMainFstDlg()
{
	if (m_piKnowNutFstDlg != NULL)
	{
		m_piKnowNutFstDlg->DestroyWindow();
	}
}

void FstKnowMainFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MainFstLIST, m_ResultList);
}


BEGIN_MESSAGE_MAP(FstKnowMainFstDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCANCEL, &FstKnowMainFstDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_UpMainFstStepPB, &FstKnowMainFstDlg::OnBnClickedUpsteppb)
	ON_BN_CLICKED(IDC_DownMainFstStepPB, &FstKnowMainFstDlg::OnBnClickedDownmainfststeppb)
END_MESSAGE_MAP()


// FstKnowMainFstDlg message handlers

void FstKnowMainFstDlg::OnPaint()
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

HBRUSH FstKnowMainFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstKnowMainFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piKnowledgeBaseddlg->DestroyWindow();
	m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
	m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->CenterWindow();
}

void FstKnowMainFstDlg::OnBnClickedUpsteppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowledgeBaseddlg->ShowWindow(SW_SHOW);
	m_piKnowledgeBaseddlg->CenterWindow();
	OnCancel();
}
void FstKnowMainFstDlg::OnBnClickedDownmainfststeppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowNutFstDlg = new FstKnowNutFstDlg(this);
	m_piKnowNutFstDlg->Create(IDD_KnowNutFstDlg,this);
	m_piKnowNutFstDlg->CenterWindow();
	m_piKnowNutFstDlg->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

BOOL FstKnowMainFstDlg::OnInitDialog()
{

	CDialog::OnInitDialog();
	//
	m_ResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_ResultList.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_ResultList.InsertColumn(1,_T("标准号"),LVCFMT_LEFT,120);
	m_ResultList.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_ResultList.InsertColumn(3,_T("类型"),LVCFMT_LEFT,100);
	m_ResultList.InsertColumn(4,_T("公称直径"),LVCFMT_LEFT,100);
	//
	return TRUE;

}