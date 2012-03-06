#pragma once

//Headers
#include "afxcmn.h"
#include "Resource.h"
#include "afxwin.h"
#include "ClxDialog.h"
#include "FstKnowledgeBasedDlg.h"


// FstTypeMainDlg dialog

class FstTypeMainDlg : public ClxDialog
{
	DECLARE_DYNAMIC(FstTypeMainDlg)

public:
	FstTypeMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstTypeMainDlg();
	virtual BOOL OnInitDialog();
	//����ˢ����ɫ����
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	CString  GetEXEPath();//�õ���ǰexe·��

	//
// Dialog Data
	enum { IDD = IDD_ChooseFSTTypeMain };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	// ����ѡ�����б�
	CListCtrl m_listCtrl;
public:
	afx_msg void OnBnClickedChoosefstpb();
public:
	CButton m_BackDataBaseCheck;
	CButton m_KnowRadio, m_FreeRadio;
	FstKnowledgeBasedDlg m_pKnowDlg;
public:
	afx_msg void OnBnClickedOk();
};
