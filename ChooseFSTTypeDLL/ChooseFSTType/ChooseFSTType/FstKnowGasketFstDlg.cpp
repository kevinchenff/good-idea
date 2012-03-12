// FstKnowGasketFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowGasketFstDlg.h"
#include "FstKnowMainFstLengthDlg.h"


// FstKnowGasketFstDlg dialog

IMPLEMENT_DYNAMIC(FstKnowGasketFstDlg, CDialog)

FstKnowGasketFstDlg::FstKnowGasketFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowGasketFstDlg::IDD, pParent)
{
	m_piParent = (FstKnowMainFstLengthDlg *)pParent;
}

FstKnowGasketFstDlg::~FstKnowGasketFstDlg()
{
}

void FstKnowGasketFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GasketFstLIST, m_ResultList);
}


BEGIN_MESSAGE_MAP(FstKnowGasketFstDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &FstKnowGasketFstDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &FstKnowGasketFstDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FstKnowGasketFstDlg message handlers

HBRUSH FstKnowGasketFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstKnowGasketFstDlg::OnPaint()
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
void FstKnowGasketFstDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	//m_piParent->CenterWindow();
	OnOK();
}

void FstKnowGasketFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	//m_piParent->CenterWindow();
	OnCancel();
}


BOOL FstKnowGasketFstDlg::OnInitDialog()
{

	CDialog::OnInitDialog();
	//
	m_ResultList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_ResultList.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_ResultList.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_ResultList.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_ResultList.InsertColumn(3,_T("公称直径"),LVCFMT_LEFT,100);
	m_ResultList.InsertColumn(4,_T("厚度"),LVCFMT_LEFT,100);
	//
	return TRUE;
}