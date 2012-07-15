#pragma once
#include "Resource.h"
#include "MatOtherInfoDlg.h"
class MatOtherInfoDlg;

// MatChooseMainDlg dialog

class MatChooseMainDlg : public CDialog
{
	DECLARE_DYNAMIC(MatChooseMainDlg)

public:
	MatChooseMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MatChooseMainDlg();


	//查询函数，通过DLL访问数据库系统
	HRESULT QuaryDatabase();

// Dialog Data
	enum { IDD = IDD_MaterialMainDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedNextsteppb();

public:
	MatOtherInfoDlg* m_piSon;
};
