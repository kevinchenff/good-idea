// FstFreeNutFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstFreeNutFstDlg.h"
#include "FstTypeMainDlg.h"
#include "FstFreeMainSpecFstDlg.h"
#include "FstFreeMainFstDlg.h"
#include "FstTypeMainDlg.h"


// FstFreeNutFstDlg dialog

IMPLEMENT_DYNAMIC(FstFreeNutFstDlg, CDialog)

FstFreeNutFstDlg::FstFreeNutFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstFreeNutFstDlg::IDD, pParent),m_piSon(NULL)
{
	m_piParent = (FstFreeMainSpecFstDlg*)pParent;
}

FstFreeNutFstDlg::~FstFreeNutFstDlg()
{
	if (m_piSon != NULL)
	{
		m_piSon->DestroyWindow();
	}
}

void FstFreeNutFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FreeNutFstLIST, m_SearchResultList);
	DDX_Control(pDX, IDC_FreeNutFstResultLIST, m_ChooseResultList);
}


BEGIN_MESSAGE_MAP(FstFreeNutFstDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_FreeNutFstUpPB, &FstFreeNutFstDlg::OnBnClickedFreenutfstuppb)
	ON_BN_CLICKED(IDC_FreeNutFstDownPB, &FstFreeNutFstDlg::OnBnClickedFreenutfstdownpb)
	ON_BN_CLICKED(IDNutCANCEL, &FstFreeNutFstDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FstFreeNutFstDlg message handlers

HBRUSH FstFreeNutFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstFreeNutFstDlg::OnPaint()
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

void FstFreeNutFstDlg::OnBnClickedFreenutfstuppb()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstFreeNutFstDlg::OnBnClickedFreenutfstdownpb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new FstFreeGasketFstDlg(this);
	m_piSon->Create(IDD_FreeGasketFstDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

void FstFreeNutFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piParent->m_piParent->DestroyWindow();
	m_piParent->m_piParent->m_piParent->ShowWindow(SW_SHOW);
	m_piParent->m_piParent->m_piParent->CenterWindow();
}

BOOL FstFreeNutFstDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	m_SearchResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_SearchResultList.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_SearchResultList.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_SearchResultList.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_SearchResultList.InsertColumn(3,_T("公称直径"),LVCFMT_LEFT,100);
	m_SearchResultList.InsertColumn(4,_T("厚度"),LVCFMT_LEFT,100);
	//
	m_ChooseResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_ChooseResultList.InsertColumn(0,_T("规格号"),LVCFMT_LEFT,100);
	m_ChooseResultList.InsertColumn(1,_T("名称"),LVCFMT_LEFT,120);
	m_ChooseResultList.InsertColumn(2,_T("类型"),LVCFMT_LEFT,100);
	m_ChooseResultList.InsertColumn(3,_T("安装部位"),LVCFMT_LEFT,80);
	m_ChooseResultList.InsertColumn(4,_T("公称直径"),LVCFMT_LEFT,80);
	m_ChooseResultList.InsertColumn(5,_T("厚度"),LVCFMT_LEFT,100);

	return TRUE;
}