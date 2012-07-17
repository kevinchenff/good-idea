#pragma once
#include "Resource.h"
#include "MatOtherInfoDlg.h"
class MatOtherInfoDlg;

#include "afxcoll.h"
#include <afxtempl.h>
#include <vector>
#include "string.h"
#include "wchar.h"
#include "iostream"
#include "afxwin.h"
using namespace std;

// MatChooseMainDlg dialog

class MatChooseMainDlg : public CDialog
{
	DECLARE_DYNAMIC(MatChooseMainDlg)

public:
	MatChooseMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MatChooseMainDlg();
	//
	//查询函数，通过DLL访问数据库系统
	HRESULT QuaryDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult);

	//插入函数，通过DLL反写信息到数据库系统
	HRESULT InsertDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult);

	//字符串解析函数
	string* SplitString(string str, string split, int& iSubStrs);
	//Cstring To BSTR Convert
	void CstringToBSTR(CString icstr, BSTR &iobstr);
	//
	//Cstring To BSTR Convert
	void BSTRToCstring(CString &iocstr, BSTR ibstr);

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
public:
	afx_msg void OnBnClickedSearchpb();
public:
	CComboBox m_COMBO01;
public:
	CComboBox m_COMBO02;
public:
	CComboBox m_COMBO03;
public:
	CComboBox m_COMBO04;
public:
	CComboBox m_COMBO05;
public:
	CComboBox m_COMBO06;
public:
	CComboBox m_COMBO07;

};
