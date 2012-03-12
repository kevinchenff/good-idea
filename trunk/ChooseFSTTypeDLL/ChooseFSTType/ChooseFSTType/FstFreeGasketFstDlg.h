#pragma once
#include "FstFreeNutFstDlg.h"
class FstFreeNutFstDlg;

// FstFreeGasketFstDlg dialog

class FstFreeGasketFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstFreeGasketFstDlg)

public:
	FstFreeGasketFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstFreeGasketFstDlg();

// Dialog Data
	enum { IDD = IDD_FreeGasketFstDlg };

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
	FstFreeNutFstDlg* m_piParent;
	
};
