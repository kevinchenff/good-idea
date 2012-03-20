// MatChooseMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChooseMaterialInfo.h"
#include "MatChooseMainDlg.h"


// MatChooseMainDlg dialog

IMPLEMENT_DYNAMIC(MatChooseMainDlg, CDialog)

MatChooseMainDlg::MatChooseMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MatChooseMainDlg::IDD, pParent)
{

}

MatChooseMainDlg::~MatChooseMainDlg()
{
}

void MatChooseMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MatChooseMainDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MatChooseMainDlg message handlers

void MatChooseMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH MatChooseMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
