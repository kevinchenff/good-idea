// FstKnowMainFstLengthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowMainFstLengthDlg.h"
#include "FstKnowMainFstDlg.h"
#include "FstTypeMainDlg.h"



// FstKnowMainFstLengthDlg dialog

IMPLEMENT_DYNAMIC(FstKnowMainFstLengthDlg, CDialog)

FstKnowMainFstLengthDlg::FstKnowMainFstLengthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowMainFstLengthDlg::IDD, pParent)
{
	m_piKnowNutFstDlg = (FstKnowNutFstDlg*)pParent;
}

FstKnowMainFstLengthDlg::~FstKnowMainFstLengthDlg()
{
}

void FstKnowMainFstLengthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FstKnowMainFstLengthDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCANCEL, &FstKnowMainFstLengthDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_UpMainFstLengthStepPB, &FstKnowMainFstLengthDlg::OnBnClickedUpmainfstlengthsteppb)
	ON_BN_CLICKED(IDC_DownMainFstLengthStepPB, &FstKnowMainFstLengthDlg::OnBnClickedDownmainfstlengthsteppb)
	ON_WM_DESTROY()
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
	m_piKnowNutFstDlg->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstKnowMainFstLengthDlg::OnBnClickedUpmainfstlengthsteppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowNutFstDlg->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstKnowMainFstLengthDlg::OnBnClickedDownmainfstlengthsteppb()
{
	// TODO: Add your control notification handler code here
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->DestroyWindow();
	m_piKnowNutFstDlg->m_piKnowMainFstDlg->m_piKnowledgeBaseddlg->m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
}

void FstKnowMainFstLengthDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	//m_piKnowNutFstDlg->PostMessage(WM_DELETE_DLG,(WPARAM)this);
}
