// MatChooseMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatChooseMainDlg.h"


// MatChooseMainDlg dialog

IMPLEMENT_DYNAMIC(MatChooseMainDlg, CDialog)

MatChooseMainDlg::MatChooseMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MatChooseMainDlg::IDD, pParent),m_piSon(NULL)
{
	if (NULL != m_piSon)
	{
		m_piSon->DestroyWindow();
		m_piSon = NULL;
	}
}

MatChooseMainDlg::~MatChooseMainDlg()
{
}

void MatChooseMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MatChooseMainDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_NextStepPB, &MatChooseMainDlg::OnBnClickedNextsteppb)
END_MESSAGE_MAP()


// MatChooseMainDlg message handlers

void MatChooseMainDlg::OnPaint()
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

HBRUSH MatChooseMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void MatChooseMainDlg::OnBnClickedNextsteppb()
{
	// TODO: Add your control notification handler code here
	m_piSon = new MatOtherInfoDlg(this);
	m_piSon->Create(IDD_OtherInfoDlg,this);
	m_piSon->CenterWindow();
	m_piSon->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}