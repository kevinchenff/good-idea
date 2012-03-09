#pragma once


// FstKnowNutFstDlg dialog

class FstKnowNutFstDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowNutFstDlg)

public:
	FstKnowNutFstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowNutFstDlg();

// Dialog Data
	enum { IDD = IDD_KnowNutFstDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);


public:
	afx_msg void OnBnClickedUpnutfststeppb();
	CWnd* m_piKnowMainFstDlg;
public:
	afx_msg void OnBnClickedDownnutfststeppb();
};
