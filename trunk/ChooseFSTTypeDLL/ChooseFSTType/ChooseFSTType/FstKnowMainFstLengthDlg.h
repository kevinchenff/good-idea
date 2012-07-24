#pragma once
#include "afxcmn.h"
// FstKnowMainFstLengthDlg dialog
class FstKnowNutFstDlg;
class FstKnowGasketFstDlg;

class FstKnowMainFstLengthDlg : public CDialog
{
	DECLARE_DYNAMIC(FstKnowMainFstLengthDlg)

public:
	FstKnowMainFstLengthDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstKnowMainFstLengthDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_KnowMainFstLengthDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedUpmainfstlengthsteppb();
	afx_msg void OnBnClickedDownmainfstlengthsteppb();
	afx_msg void OnBnClickedAddpb();

public:
	FstKnowNutFstDlg* m_piKnowNutFstDlg;
	FstKnowGasketFstDlg* m_piKnowGasketFstDlg;

public:
	// �����̼����ȹ���б�
	CListCtrl m_MainFstSpecResultList;
	// ��Ȧ�б�
	CListCtrl m_GasketFstResultList;
};