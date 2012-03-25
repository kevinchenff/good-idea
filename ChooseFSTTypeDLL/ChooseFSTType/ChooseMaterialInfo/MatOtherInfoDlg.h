#pragma once
#include "MatChooseMainDlg.h"
class MatChooseMainDlg;

// MatOtherInfoDlg dialog

class MatOtherInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(MatOtherInfoDlg)

public:
	MatOtherInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MatOtherInfoDlg();

// Dialog Data
	enum { IDD = IDD_OtherInfoDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();

	MatChooseMainDlg *m_piParent;
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk();
};
