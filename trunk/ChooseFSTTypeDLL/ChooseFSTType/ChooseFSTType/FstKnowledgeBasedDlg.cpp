// FstKnowledgeBasedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseFSTType.h"
#include "FstKnowledgeBasedDlg.h"
#include "FstKnowMainFstDlg.h"
#include "FstTypeMainDlg.h"


// FstKnowledgeBasedDlg dialog

IMPLEMENT_DYNAMIC(FstKnowledgeBasedDlg, CDialog)

FstKnowledgeBasedDlg::FstKnowledgeBasedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FstKnowledgeBasedDlg::IDD, pParent),m_piKnowMainFstDlg(NULL)
{
	m_piFstTypeMainDlg = (FstTypeMainDlg*)pParent;
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
	ON_BN_CLICKED(IDCANCEL, &FstKnowledgeBasedDlg::OnBnClickedCancel)
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
	//关闭该对话框
	m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
	DestroyWindow();	
}

void FstKnowledgeBasedDlg::OnBnClickedDownsteppb()
{
	// TODO: Add your control notification handler code here
	//传入必要参数，并关闭对话框
	m_piKnowMainFstDlg = new FstKnowMainFstDlg(this);
	m_piKnowMainFstDlg->Create(IDD_KnowMainFstDlg,this);
	m_piKnowMainFstDlg->CenterWindow();
	m_piKnowMainFstDlg->ShowWindow(SW_SHOW);
	//
	this->ShowWindow(SW_HIDE);
}
void FstKnowledgeBasedDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	m_piFstTypeMainDlg->ShowWindow(SW_SHOW);
	OnCancel();
}

BOOL FstKnowledgeBasedDlg::OnInitDialog()
{

	CDialog::OnInitDialog();
	//
	/*m_listCtrl.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES );
	m_listCtrl.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_listCtrl.InsertColumn(1,_T("规格号"),LVCFMT_LEFT,120);
	m_listCtrl.InsertColumn(2,_T("名称"),LVCFMT_LEFT,150);
	m_listCtrl.InsertColumn(3,_T("类型"),LVCFMT_LEFT,100);
	m_listCtrl.InsertColumn(4,_T("安装部位"),LVCFMT_LEFT,100);*/
	//
	return TRUE;

}