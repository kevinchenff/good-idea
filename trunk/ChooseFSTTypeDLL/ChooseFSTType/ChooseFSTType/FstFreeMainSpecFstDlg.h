#pragma once

#include "FstFreeMainFstDlg.h"
#include "FstFreeNutFstDlg.h"
#include "afxcmn.h"
class FstFreeNutFstDlg;
// FstFreeMainSpecFstDlg dialog

class FstFreeMainSpecFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstFreeMainSpecFstDlg)

public:
	FstFreeMainSpecFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstFreeMainSpecFstDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_FreeMainSpecFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedFreemainspecfstuppb();
	afx_msg void OnBnClickedFreemainspecfstdownpb();
	afx_msg void OnBnClickedCancel();

public:
	FstFreeMainFstDlg* m_piParent;
	FstFreeNutFstDlg* m_piSon;
public:
	CListCtrl m_ResultList;
};
