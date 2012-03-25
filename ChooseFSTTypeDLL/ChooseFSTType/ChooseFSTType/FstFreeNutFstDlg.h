#pragma once
#include "FstFreeMainSpecFstDlg.h"
#include "FstFreeGasketFstDlg.h"
#include "afxcmn.h"
class FstFreeGasketFstDlg;

// FstFreeNutFstDlg dialog

class FstFreeNutFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstFreeNutFstDlg)

public:
	FstFreeNutFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstFreeNutFstDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_FreeNutFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedFreenutfstuppb();
	afx_msg void OnBnClickedFreenutfstdownpb();
	afx_msg void OnBnClickedCancel();

public:
	FstFreeMainSpecFstDlg* m_piParent;
	FstFreeGasketFstDlg* m_piSon;
public:
	CListCtrl m_SearchResultList;
public:
	CListCtrl m_ChooseResultList;
};
