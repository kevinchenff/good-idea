#pragma once
#include "Resource.h"
#include "MatOtherInfoDlg.h"
class MatOtherInfoDlg;

#include "afxcoll.h"
#include <vector>
#include "string.h"
#include "wchar.h"
#include "iostream"
using namespace std;

// MatChooseMainDlg dialog

class MatChooseMainDlg : public CDialog
{
	DECLARE_DYNAMIC(MatChooseMainDlg)

public:
	MatChooseMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MatChooseMainDlg();


	//��ѯ������ͨ��DLL�������ݿ�ϵͳ
	HRESULT QuaryDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult);

	//���뺯����ͨ��DLL��д��Ϣ�����ݿ�ϵͳ
	HRESULT InsertDatabase(CStringArray &ialstCStrInput, CStringArray &ioalstCStrResult);

	//�ַ�����������
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
};
