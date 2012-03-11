#pragma once
#include "afxcmn.h"
class FstKnowMainFstLengthDlg;

// FstKnowGasketFstDlg dialog

class FstKnowGasketFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowGasketFstDlg)

public:
	FstKnowGasketFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowGasketFstDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_KnowGasketFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	FstKnowMainFstLengthDlg* m_piParent;
	CListCtrl m_ResultList;
};
