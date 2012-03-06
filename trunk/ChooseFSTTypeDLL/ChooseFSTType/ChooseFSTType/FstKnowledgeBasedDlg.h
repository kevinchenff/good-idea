#pragma once


// FstKnowledgeBasedDlg dialog

class FstKnowledgeBasedDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowledgeBasedDlg)

public:
	FstKnowledgeBasedDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowledgeBasedDlg();

	//定义刷屏颜色变量
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();

// Dialog Data
	enum { IDD = IDD_KnowledgeChooseDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
