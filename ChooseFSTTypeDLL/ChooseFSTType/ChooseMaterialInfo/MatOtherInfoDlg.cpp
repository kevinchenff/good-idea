// MatOtherInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatOtherInfoDlg.h"


// MatOtherInfoDlg dialog

IMPLEMENT_DYNAMIC(MatOtherInfoDlg, CDialog)

MatOtherInfoDlg::MatOtherInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MatOtherInfoDlg::IDD, pParent)
{
	m_piParent = (MatChooseMainDlg*)pParent;
}

MatOtherInfoDlg::~MatOtherInfoDlg()
{
}

void MatOtherInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MatOtherInfoDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDCANCEL, &MatOtherInfoDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOtherInfoOK, &MatOtherInfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MatOtherInfoDlg message handlers

HBRUSH MatOtherInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void MatOtherInfoDlg::OnPaint()
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


void MatOtherInfoDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	m_piParent->ShowWindow(SW_SHOW);
	m_piParent->CenterWindow();
	OnCancel();
}

void MatOtherInfoDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_piParent->EndDialog(TRUE);
	OnOK();
}
