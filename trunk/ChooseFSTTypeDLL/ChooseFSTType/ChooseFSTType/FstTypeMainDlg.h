#pragma once

//Headers
#include "afxcmn.h"
#include "Resource.h"
#include "afxwin.h"
#include "ClxDialog.h"

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
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// ����ѡ�����б�
	CListCtrl m_listCtrl;
};
