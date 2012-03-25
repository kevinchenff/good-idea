#pragma once
#include "afxcmn.h"

class FstTypeMainDlg;
class FstFreeMainSpecFstDlg;
// FstFreeMainFstDlg dialog

class FstFreeMainFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstFreeMainFstDlg)

public:
	FstFreeMainFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstFreeMainFstDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_FreeMainFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedFreemainfstuppb();
	afx_msg void OnBnClickedFreemainfstdownpb();
	afx_msg void OnBnClickedCancel();

public:
	FstTypeMainDlg* m_piParent;
	FstFreeMainSpecFstDlg* m_piSon;

public:
	CListCtrl m_ResultList;
};
