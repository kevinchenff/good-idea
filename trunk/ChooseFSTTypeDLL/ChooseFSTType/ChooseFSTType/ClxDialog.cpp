//////////////////////////////////////////////////////////////////////
// �Զ��ı�ؼ�λ�úʹ�С�ĶԻ�����
// �ļ�����lxDialog.cpp
// ���ߣ�StarLee(coolstarlee@sohu.com)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClxDialog.h"

// ��ʾ�ɸı��С��ͼ��ID
#ifndef OBM_SIZE
#define OBM_SIZE 32766
#endif

ClxDialog::ClxDialog(UINT nID, CWnd* pParent /*=NULL*/)
: CDialog(nID, pParent)
, m_iClientWidth(0)
, m_iClientHeight(0)
, m_iMinWidth(0)
, m_iMinHeight(0)
, m_pControlArray(NULL)
, m_iControlNumber(0)
, m_bShowSizeIcon(TRUE)
{}

BEGIN_MESSAGE_MAP(ClxDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_SIZING()
END_MESSAGE_MAP()

BOOL ClxDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���öԻ���Ϊ�ɱ��С��
	ModifyStyle(0, WS_SIZEBOX);

	// �ԶԻ���ĳ�ʼ��С��Ϊ�Ի���Ŀ�Ⱥ͸߶ȵ���Сֵ
	CRect rectDlg;
	GetWindowRect(rectDlg);
	m_iMinWidth = rectDlg.Width();
	m_iMinHeight = rectDlg.Height();

	// �õ��Ի���client����Ĵ�С 
	CRect rectClient;
	GetClientRect(rectClient);
	m_iClientWidth = rectClient.Width();
	m_iClientHeight = rectClient.Height();

	// Loadͼ��
	m_bmpSizeIcon.LoadOEMBitmap(OBM_SIZE);
	m_bmpSizeIcon.GetBitmap(&m_bitmap);

	// ������ʾͼ��ľ�̬�ؼ������ڶԻ������½�
	m_wndSizeIcon.Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight), this, 0);
	m_wndSizeIcon.SetBitmap(m_bmpSizeIcon);
	m_wndSizeIcon.MoveWindow(m_iClientWidth - m_bitmap.bmWidth, m_iClientHeight - m_bitmap.bmHeight, m_bitmap.bmWidth, m_bitmap.bmHeight);

	// ��ʾͼ��
	m_wndSizeIcon.ShowWindow(m_bShowSizeIcon);
	return TRUE;
}

void ClxDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	// �Ի����Ⱥ͸߶ȵ����� 
	int iIncrementX = cx - m_iClientWidth;
	int iIncrementY = cy - m_iClientHeight;
	// ��С��ʱ����Ϊ0
	if (nType == SIZE_MINIMIZED)
	{
		iIncrementX = iIncrementY = 0;
	}
	for (int i = 0; i < m_iControlNumber; i++)
	{
		CWnd *pWndCtrl = NULL;
		int iId = m_pControlArray[i].iId;
		int iFlag = m_pControlArray[i].iFlag;
		int iPercent = m_pControlArray[i].iPercent;

		// ��Чֵ
		if ((iPercent < 0) || (iPercent > 100))
		continue;

		// �õ��ؼ�ָ��
		pWndCtrl = GetDlgItem(iId);
		if ((NULL != pWndCtrl) && IsWindow(pWndCtrl->GetSafeHwnd()))
		{
			CRect rectCtrl;
			pWndCtrl->GetWindowRect(rectCtrl);

			ScreenToClient(rectCtrl);

			int iLeft = rectCtrl.left;
			int iTop = rectCtrl.top;
			int iWidth = rectCtrl.Width();
			int iHeight = rectCtrl.Height();
			//
			switch (iFlag)
			{
				case MOVEX: // X�����ƶ�
				iLeft += (iIncrementX * iPercent / 100);
				break;

				case MOVEY: // Y�����ƶ�
				iTop += (iIncrementY * iPercent / 100);
				break;

				case MOVEXY: // X�����Y����ͬʱ�ƶ�
				iLeft += (iIncrementX * iPercent / 100);
				iTop += (iIncrementY * iPercent / 100);
				break;

				case ELASTICX: // X����ı��С
				iWidth += (iIncrementX * iPercent / 100);
				break;

				case ELASTICY: // Y����ı��С
				iHeight += (iIncrementY * iPercent / 100);
				break;

				case ELASTICXY: // X�����Y����ͬʱ�ı��С
				iWidth += (iIncrementX * iPercent / 100);
				iHeight += (iIncrementY * iPercent / 100);
				break;

				default:
				;
			}

			// �ѿؼ��ƶ�����λ��
			pWndCtrl->MoveWindow(iLeft, iTop, iWidth, iHeight);
			
		}
	}
	// ��ͼ���ƶ����Ի������½�
	if (IsWindow(m_wndSizeIcon.GetSafeHwnd()))
	m_wndSizeIcon.MoveWindow(cx - m_bitmap.bmWidth, cy - m_bitmap.bmHeight, m_bitmap.bmWidth, m_bitmap.bmHeight);

	// ��¼�Ի���client����Ĵ�С
	if (nType != SIZE_MINIMIZED)
	{
		m_iClientWidth = cx;
		m_iClientHeight = cy;
	}
}

void ClxDialog::OnSizing(UINT nSide, LPRECT lpRect)
{
	CDialog::OnSizing(nSide, lpRect);

	// �Ի�����С�ڳ�ʼ��С

	int iWidth = lpRect->right - lpRect->left;
	int iHeight = lpRect->bottom - lpRect->top;

	if (iWidth <= m_iMinWidth)
	lpRect->right = lpRect->left + m_iMinWidth;

	if(iHeight <= m_iMinHeight)
	lpRect->bottom = lpRect->top + m_iMinHeight;
}

BOOL ClxDialog::SetControlProperty(PDLGCTLINFO lp, int nElements)
{
	// ���ÿؼ�������Ϣ

	if (NULL == lp)
	return FALSE;

	if (nElements <= 0)
	return FALSE;

	m_pControlArray = lp;
	m_iControlNumber = nElements;

	return TRUE;
}

void ClxDialog::ShowSizeIcon(BOOL bShow /*=NULL*/)
{
	m_bShowSizeIcon = bShow;
}