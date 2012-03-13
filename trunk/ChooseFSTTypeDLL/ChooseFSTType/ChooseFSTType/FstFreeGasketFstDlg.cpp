// FstFreeGasketFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstFreeGasketFstDlg.h"
#include "FstFreeNutFstDlg.h"
#include "FstTypeMainDlg.h"
#include "FstFreeMainSpecFstDlg.h"
#include "FstFreeMainFstDlg.h"
#include "FstTypeMainDlg.h"



// FstFreeGasketFstDlg dialog

IMPLEMENT_DYNAMIC(FstFreeGasketFstDlg, CDialog)

FstFreeGasketFstDlg::FstFreeGasketFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstFreeGasketFstDlg::IDD, pParent)
{
	m_piParent = (FstFreeNutFstDlg*)pParent;
}

FstFreeGasketFstDlg::~FstFreeGasketFstDlg()
{
}

void FstFreeGasketFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FstFreeGasketFstDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_FreeMainFstUpPB, &FstFreeGasketFstDlg::OnBnClickedFreemainfstuppb)
	ON_BN_CLICKED(IDC_FreeMainFstDownPB, &FstFreeGasketFstDlg::OnBnClickedFreemainfstdownpb)
	ON_BN_CLICKED(IDGasketCANCEL, &FstFreeGasketFstDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FstFreeGasketFstDlg message handlers

HBRUSH FstFreeGasketFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstFreeGasketFstDlg::OnPaint()
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

void FstFreeGasketFstDlg::OnBnClickedFreemainfstuppb()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstFreeGasketFstDlg::OnBnClickedFreemainfstdownpb()
{
	// TODO: Add your control notification handler code here
	m_piParent->m_piParent->m_piParent->DestroyWindow();
	m_piParent->m_piParent->m_piParent->m_piParent->ShowWindow(SW_SHOW);
	m_piParent->m_piParent->m_piParent->m_piParent->CenterWindow();
}

void FstFreeGasketFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piParent->m_piParent->m_piParent->DestroyWindow();
	m_piParent->m_piParent->m_piParent->m_piParent->ShowWindow(SW_SHOW);
	m_piParent->m_piParent->m_piParent->m_piParent->CenterWindow();
}
