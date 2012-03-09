// FstKnowNutFstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowNutFstDlg.h"
#include "FstKnowMainFstDlg.h"



// FstKnowNutFstDlg dialog

IMPLEMENT_DYNAMIC(FstKnowNutFstDlg, CDialog)

FstKnowNutFstDlg::FstKnowNutFstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowNutFstDlg::IDD, pParent)
{
	m_piKnowMainFstDlg = pParent;
}

FstKnowNutFstDlg::~FstKnowNutFstDlg()
{
}

void FstKnowNutFstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FstKnowNutFstDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_UpNutFstStepPB, &FstKnowNutFstDlg::OnBnClickedUpnutfststeppb)
	ON_BN_CLICKED(IDC_DownNutFstStepPB, &FstKnowNutFstDlg::OnBnClickedDownnutfststeppb)
END_MESSAGE_MAP()


// FstKnowNutFstDlg message handlers

void FstKnowNutFstDlg::OnPaint()
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

HBRUSH FstKnowNutFstDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstKnowNutFstDlg::OnBnClickedUpnutfststeppb()
{
	// TODO: Add your control notification handler code here
	((FstKnowMainFstDlg*)m_piKnowMainFstDlg)->ShowWindow(SW_SHOW);
	OnCancel();
}

void FstKnowNutFstDlg::OnBnClickedDownnutfststeppb()
{
	// TODO: Add your control notification handler code here
	//根据所选主紧固件类型及参数情况，判断是否需要添加垫圈

	MessageBox(_T("请选择紧固件选择方式！"),_T("提示"),MB_ICONWARNING|MB_OK);
	
}
