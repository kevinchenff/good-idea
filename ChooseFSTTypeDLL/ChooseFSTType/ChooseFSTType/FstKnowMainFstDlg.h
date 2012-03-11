#pragma once
#include "afxcmn.h"
#include "FstKnowNutFstDlg.h"
#include "FstKnowledgeBasedDlg.h"

class FstKnowledgeBasedDlg;
// FstKnowMainFstDlg dialog

class FstKnowMainFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowMainFstDlg)

public:
	FstKnowMainFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowMainFstDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_KnowMainFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedUpsteppb();
	afx_msg void OnBnClickedDownmainfststeppb();

	//
public:
	FstKnowledgeBasedDlg* m_piKnowledgeBaseddlg;
	FstKnowNutFstDlg* m_piKnowNutFstDlg;
	CListCtrl m_ResultList;
};

