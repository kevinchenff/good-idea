// FstKnowMainFstLengthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowMainFstLengthDlg.h"
#include "FstKnowMainFstDlg.h"
#include "FstTypeMainDlg.h"
#include "FstKnowGasketFstDlg.h"


// FstKnowMainFstLengthDlg dialog

IMPLEMENT_DYNAMIC(FstKnowMainFstLengthDlg, CDialog)

FstKnowMainFstLengthDlg::FstKnowMainFstLengthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowMainFstLengthDlg::IDD, pParent),m_piKnowGasketFstDlg(NULL)
{
	m_piKnowNutFstDlg = (FstKnowNutFstDlg*)pParent;
}

FstKnowMainFstLengthDlg::~FstKnowMainFstLengthDlg()
{
	if (m_piKnowGasketFstDlg != NULL)
	{
		m_piKnowGasketFstDlg->DestroyWindow();
	}
}

void FstKnowMainFstLengthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MainFstSpecLIST, m_MainFstSpecResultList);
	DDX_Control(pDX, IDC_GasketLIST, m_GasketFstResultList);
}


BEGIN_MESSAGE_MAP(FstKnowMainFstLengthDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCANCEL, &FstKnowMainFstLengthDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_UpMainFstLengthStepPB, &FstKnowMainFstLengthDlg::OnBnClickedUpmainfstlengthsteppb)
	ON_BN_CLICKED(IDC_DownMainFstLengthStepPB, &FstKnowMainFstLengthDlg::OnBnClickedDownmainfstlengthsteppb)
	ON_BN_CLICKED(IDC_AddPB, &FstKnowMainFstLengthDlg::OnBnClickedAddpb)
END_MESSAGE_MAP()


// FstKnowMainFstLengthDlg message handlers

void FstKnowMainFstLengthDlg::OnPaint()
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

HBRUSH FstKnowMainFstLengthDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstKnowMainFstLengthDlg::OnBnClickedCancel()
{
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->DestroyWindow();
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
	//m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->CenterWindow();
}

void FstKnowMainFstLengthDlg::OnBnClickedUpmainfstlengthsteppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowNutFstDlg->ShowWindow(SW_SHOW);
	//m_piKnowNutFstDlg->CenterWindow();
	OnCancel();
}

void FstKnowMainFstLengthDlg::OnBnClickedDownmainfstlengthsteppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->DestroyWindow();
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
	//m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->CenterWindow();
}

void FstKnowMainFstLengthDlg::OnBnClickedAddpb()
{
	// TODO: Add your control notification handler code here
	m_piKnowGasketFstDlg = new FstKnowGasketFstDlg(this);
	m_piKnowGasketFstDlg->Create(IDD_KnowGasketFstDlg,this);
	m_piKnowGasketFstDlg->CenterWindow();
	m_piKnowGasketFstDlg->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

BOOL FstKnowMainFstLengthDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	m_MainFstSpecResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_MainFstSpecResultList.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_MainFstSpecResultList.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_MainFstSpecResultList.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_MainFstSpecResultList.InsertColumn(3,_T("长度"),LVCFMT_LEFT,100);
	m_MainFstSpecResultList.InsertColumn(4,_T("余量"),LVCFMT_LEFT,100);
	//
	m_GasketFstResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_GasketFstResultList.InsertColumn(0,_T("规格号"),LVCFMT_LEFT,50);
	m_GasketFstResultList.InsertColumn(1,_T("名称"),LVCFMT_LEFT,120);
	m_GasketFstResultList.InsertColumn(2,_T("类型"),LVCFMT_LEFT,120);
	m_GasketFstResultList.InsertColumn(3,_T("安装部位"),LVCFMT_LEFT,100);
	m_GasketFstResultList.InsertColumn(4,_T("公称直径"),LVCFMT_LEFT,100);
	m_GasketFstResultList.InsertColumn(5,_T("厚度"),LVCFMT_LEFT,100);
	//
	return TRUE;

}
