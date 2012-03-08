// FstKnowledgeBasedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowledgeBasedDlg.h"
#include "FstKnowMainFstDlg.h"



// FstKnowledgeBasedDlg dialog

IMPLEMENT_DYNAMIC(FstKnowledgeBasedDlg, CDialog)

FstKnowledgeBasedDlg::FstKnowledgeBasedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowledgeBasedDlg::IDD, pParent),m_piKnowMainFstDlg(NULL)
{

}

FstKnowledgeBasedDlg::~FstKnowledgeBasedDlg()
{
	if (m_piKnowMainFstDlg != NULL)
	{
		m_piKnowMainFstDlg->DestroyWindow();
	}
}

void FstKnowledgeBasedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MainFstNameEDIT, m_SearchInfo);
}


BEGIN_MESSAGE_MAP(FstKnowledgeBasedDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_UpStepPB, &FstKnowledgeBasedDlg::OnBnClickedUpsteppb)
	ON_BN_CLICKED(IDC_DownStepPB, &FstKnowledgeBasedDlg::OnBnClickedDownsteppb)
END_MESSAGE_MAP()


// FstKnowledgeBasedDlg message handlers
HBRUSH FstKnowledgeBasedDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void FstKnowledgeBasedDlg::OnPaint()
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

void FstKnowledgeBasedDlg::OnBnClickedUpsteppb()
{
	// TODO: Add your control notification handler code here
	//�رոöԻ���
	this->OnOK();
	
}

void FstKnowledgeBasedDlg::OnBnClickedDownsteppb()
{
	// TODO: Add your control notification handler code here
	//�����Ҫ���������رնԻ���
	m_piKnowMainFstDlg = new FstKnowMainFstDlg(this);
	m_piKnowMainFstDlg->Create(IDD_KnowMainFstDlg,this);
	m_piKnowMainFstDlg->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}