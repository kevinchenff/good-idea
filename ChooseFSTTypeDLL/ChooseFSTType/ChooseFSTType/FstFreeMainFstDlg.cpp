// FstFreeMainFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstFreeMainFstDlg.h"
#include "FstTypeMainDlg.h"
#include "FstFreeMainSpecFstDlg.h"


// FstFreeMainFstDlg dialog

IMPLEMENT_DYNAMIC(FstFreeMainFstDlg, CDialog)

FstFreeMainFstDlg::FstFreeMainFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstFreeMainFstDlg::IDD, pParent),m_piSon(NULL)
{
	m_piParent = (FstTypeMainDlg*)pParent;
}

FstFreeMainFstDlg::~FstFreeMainFstDlg()
{
	if (m_piSon != NULL)
	{
		m_piSon->DestroyWindow();
	}
}

void FstFreeMainFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FstFreeMainFstDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_FreeMainFstUpPB, &FstFreeMainFstDlg::OnBnClickedFreemainfstuppb)
	ON_BN_CLICKED(IDC_FreeMainFstDownPB, &FstFreeMainFstDlg::OnBnClickedFreemainfstdownpb)
	ON_BN_CLICKED(IDMainCANCEL, &FstFreeMainFstDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FstFreeMainFstDlg message handlers

HBRUSH FstFreeMainFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstFreeMainFstDlg::OnPaint()
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

void FstFreeMainFstDlg::OnBnClickedFreemainfstuppb()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstFreeMainFstDlg::OnBnClickedFreemainfstdownpb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new FstFreeMainSpecFstDlg(this);
	m_piSon->Create(IDD_FreeMainSpecFstDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}

void FstFreeMainFstDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	OnCancel();
}
