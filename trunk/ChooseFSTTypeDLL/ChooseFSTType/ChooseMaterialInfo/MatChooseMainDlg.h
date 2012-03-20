#pragma once


// MatChooseMainDlg dialog

class MatChooseMainDlg : public CDialog
{
	DECLARE_DYNAMIC(MatChooseMainDlg)

public:
	MatChooseMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MatChooseMainDlg();

// Dialog Data
	enum { IDD = IDD_MaterialMainDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
