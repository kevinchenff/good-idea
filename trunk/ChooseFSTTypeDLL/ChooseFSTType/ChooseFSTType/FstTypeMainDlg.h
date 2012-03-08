#pragma once

//Headers
#include "afxcmn.h"
#include "Resource.h"
#include "afxwin.h"
#include "ClxDialog.h"
#include "FstKnowledgeBasedDlg.h"
#include "FstKnowMainFstDlg.h"


// FstTypeMainDlg dialog

class FstTypeMainDlg : public ClxDialog
{
	DECLARE_DYNAMIC(FstTypeMainDlg)

public:
	FstTypeMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FstTypeMainDlg();
	virtual BOOL OnInitDialog();
	//
// Dialog Data
	enum { IDD = IDD_ChooseFSTTypeMain };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	//����ˢ����ɫ����
	afx_msg void OnBnClickedChoosefstpb();
	afx_msg void OnBnClickedOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	CString  GetEXEPath();//�õ���ǰexe·��

public:
	// ����ѡ�����б�
	CListCtrl m_listCtrl;
	CButton m_BackDataBaseCheck;
	CButton m_KnowRadio, m_FreeRadio;
	FstKnowledgeBasedDlg m_pKnowDlg;
};
