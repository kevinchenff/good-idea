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
	DDX_Control(pDX, IDC_KnowFstResultTREE, m_ResultTree);
	DDX_Control(pDX, IDC_SearchTypeCOMB, m_SearchComb);
	DDX_Control(pDX, IDC_FstValueEDIT, m_SearchValue);
}


BEGIN_MESSAGE_MAP(FstKnowledgeBasedDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_UpStepPB, &FstKnowledgeBasedDlg::OnBnClickedUpsteppb)
	ON_BN_CLICKED(IDC_DownStepPB, &FstKnowledgeBasedDlg::OnBnClickedDownsteppb)
	ON_BN_CLICKED(IDCANCEL, &FstKnowledgeBasedDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_SearchTypeCOMB, &FstKnowledgeBasedDlg::OnCbnSelchangeSearchtypecomb)
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
	HTREEITEM ptreeItem01 = m_ResultTree.InsertItem(_T("主紧固件标准号01"),TVI_ROOT);//根结点
	m_ResultTree.InsertItem(_T("螺母标准号01"),0,0,ptreeItem01); 
	HTREEITEM ptreeItem02 = m_ResultTree.InsertItem(_T("主紧固件标准号02"),TVI_ROOT);//根结点
	m_ResultTree.InsertItem(_T("螺母标准号02"),0,0,ptreeItem02); 
	//
	m_SearchInfo.SetWindowText(_T("紧固件标准号"));
	m_SearchInfo.SetReadOnly();
	//
	m_SearchValue.SetReadOnly();
	//
	m_SearchComb.InsertString(0,_T("全部"));
	m_SearchComb.InsertString(1,_T("等于"));
	m_SearchComb.InsertString(2,_T("包含"));
	m_SearchComb.SetCurSel(0);
	//
	return TRUE;
}
void FstKnowledgeBasedDlg::OnCbnSelchangeSearchtypecomb()
{
	// TODO: Add your control notification handler code here
	if (m_SearchComb.GetCurSel() == 0)
	{
		m_SearchValue.SetWindowText(_T(""));
		m_SearchValue.SetReadOnly();
	}
	else
	{
		m_SearchValue.SetReadOnly(FALSE);
	}
}
