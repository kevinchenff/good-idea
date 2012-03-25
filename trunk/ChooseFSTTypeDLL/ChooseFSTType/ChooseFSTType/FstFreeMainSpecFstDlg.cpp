// FstFreeMainSpecFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstFreeMainSpecFstDlg.h"
#include "FstFreeMainFstDlg.h"
#include "FstTypeMainDlg.h"


// FstFreeMainSpecFstDlg dialog

IMPLEMENT_DYNAMIC(FstFreeMainSpecFstDlg, CDialog)

FstFreeMainSpecFstDlg::FstFreeMainSpecFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstFreeMainSpecFstDlg::IDD, pParent),m_piSon(NULL)
{
	m_piParent = (FstFreeMainFstDlg*)pParent;
}

FstFreeMainSpecFstDlg::~FstFreeMainSpecFstDlg()
{
	if (m_piSon != NULL)
	{
		m_piSon->DestroyWindow();
	}
}

void FstFreeMainSpecFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FreeMainSpecFstLIST, m_ResultList);
}


BEGIN_MESSAGE_MAP(FstFreeMainSpecFstDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_FreeMainSpecFstUpPB, &FstFreeMainSpecFstDlg::OnBnClickedFreemainspecfstuppb)
	ON_BN_CLICKED(IDC_FreeMainSpecFstDownPB, &FstFreeMainSpecFstDlg::OnBnClickedFreemainspecfstdownpb)
	ON_BN_CLICKED(IDMainSpecCANCEL, &FstFreeMainSpecFstDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FstFreeMainSpecFstDlg message handlers

HBRUSH FstFreeMainSpecFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstFreeMainSpecFstDlg::OnPaint()
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

void FstFreeMainSpecFstDlg::OnBnClickedFreemainspecfstuppb()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstFreeMainSpecFstDlg::OnBnClickedFreemainspecfstdownpb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new FstFreeNutFstDlg(this);
	m_piSon->Create(IDD_FreeNutFstDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

void FstFreeMainSpecFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piParent->DestroyWindow();
	m_piParent->m_piParent->ShowWindow(SW_SHOW);
	m_piParent->m_piParent->CenterWindow();
}

BOOL FstFreeMainSpecFstDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	m_ResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_ResultList.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_ResultList.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_ResultList.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_ResultList.InsertColumn(3,_T("长度"),LVCFMT_LEFT,100);
	m_ResultList.InsertColumn(4,_T("余量"),LVCFMT_LEFT,100);
	//
	return TRUE;
}