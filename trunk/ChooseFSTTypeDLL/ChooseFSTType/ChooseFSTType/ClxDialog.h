#pragma once
#include "afxwin.h"

/////////////////////////////////////////////////////////////////////////////////////
// �Զ��ı�ؼ�λ�úʹ�С�ĶԻ�����
// �ļ�����lxDialog.h
// ���ߣ�StarLee(coolstarlee@sohu.com)
/////////////////////////////////////////////////////////////////////////////////////

class ClxDialog : public CDialog
{
public:
	ClxDialog(UINT nID, CWnd* pParent = NULL);

	typedef struct _dlgControlTag 
	{
		int iId;
		int iFlag;
		int iPercent;
	} DLGCTLINFO, *PDLGCTLINFO;

	enum
	{
		MOVEX = 0,
		MOVEY,
		MOVEXY,
		ELASTICX,
		ELASTICY,
		ELASTICXY
	};

	// ���ÿؼ���Ϣ
	BOOL SetControlProperty(PDLGCTLINFO lp, int nElements);

	// �Ƿ��ڶԻ������½���ʾ��ʾ�ɸı��С��ͼ��
	void ShowSizeIcon(BOOL bShow = TRUE);

protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	DECLARE_MESSAGE_MAP()

private:
	int m_iClientWidth; // �Ի���client����Ŀ��
	int m_iClientHeight; // �Ի���client����ĸ߶�
	int m_iMinWidth; // �Ի������С���
	int m_iMinHeight; // �Ի������С�߶�
	PDLGCTLINFO m_pControlArray; // �ؼ���Ϣ����ָ��
	int m_iControlNumber; // ���ÿؼ���Ϣ�Ŀؼ�����
	BOOL m_bShowSizeIcon; // �Ƿ���ʾ��ʾ�ɸı��С��ͼ��
	CStatic m_wndSizeIcon; // ��ͼ��ľ�̬�ؼ�
	// ����ͼ���bitmap
	CBitmap m_bmpSizeIcon; 
	BITMAP m_bitmap; 
};