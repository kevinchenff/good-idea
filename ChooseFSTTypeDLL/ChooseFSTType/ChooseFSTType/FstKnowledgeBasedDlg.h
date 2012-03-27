#pragma once
#include "afxwin.h"
#include "FstKnowMainFstDlg.h"
#include "afxcmn.h"
class FstTypeMainDlg;
class FstKnowMainFstDlg;

// FstKnowledgeBasedDlg dialog

class FstKnowledgeBasedDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowledgeBasedDlg)

public:
	FstKnowledgeBasedDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowledgeBasedDlg();
	virtual BOOL OnInitDialog();

	//定义刷屏颜色变量
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();

// Dialog Data
	enum { IDD = IDD_KnowledgeChooseDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUpsteppb();
	afx_msg void OnBnClickedDownsteppb();
	afx_msg void OnBnClickedCancel();
	
public:
	CEdit m_SearchInfo;
	FstKnowMainFstDlg* m_piKnowMainFstDlg;
	FstTypeMainDlg* m_piFstTypeMainDlg;
public:
	CTreeCtrl m_ResultTree;
public:
	CComboBox m_SearchComb;
public:
	CEdit m_SearchValue;
public:
	afx_msg void OnCbnSelchangeSearchtypecomb();
};
