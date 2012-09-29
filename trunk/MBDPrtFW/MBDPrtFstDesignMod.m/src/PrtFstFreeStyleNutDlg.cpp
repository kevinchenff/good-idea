// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleNutDlg.cpp
// The dialog : PrtFstFreeStyleNutDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstFreeStyleNutDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstFreeStyleNutDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif


const int MAXCOUNT = 4;



//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstFreeStyleNutDlg::PrtFstFreeStyleNutDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstFreeStyleNutDlg",CATDlgWndModal|CATDlgWndBtnClose|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _Label04 = NULL;
 _Combo01 = NULL;
 _Combo02 = NULL;
 _Combo03 = NULL;
 _Combo04 = NULL;
 _GoToSearchPB = NULL;
 _Label05 = NULL;
 _Combo05 = NULL;
 _Frame002 = NULL;
 _SearchResultML = NULL;
 _Frame003 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION

 //
 m_lstStrPropertyName[0]=CATUnicodeString("���̼���׼��");
 m_lstStrPropertyName[1]=CATUnicodeString("���̼���ʶ");
 m_lstStrPropertyName[2]=CATUnicodeString("����ֱ��");
 m_lstStrPropertyName[3]=CATUnicodeString("��ĸ���");
 m_lstStrPropertyName[4]=CATUnicodeString("�⾶"); 
 m_lstStrPropertyName[5]=CATUnicodeString("���");
 m_lstStrPropertyName[6]=CATUnicodeString("������kg��");
 m_lstStrPropertyName[7]=CATUnicodeString("�ܺ��"); 
 m_lstStrPropertyName[8]=CATUnicodeString("�ṹ���");
 m_lstStrPropertyName[9]=CATUnicodeString("�а���");
 m_lstStrPropertyName[10]=CATUnicodeString("í��ֱ��");
 m_lstStrPropertyName[11]=CATUnicodeString("í����");
 m_lstStrPropertyName[12]=CATUnicodeString("���Ķ�λ����");
 m_lstStrPropertyName[13]=CATUnicodeString("��ĸ��������");
 m_lstStrPropertyName[14]=CATUnicodeString("��ĸ��������");
 m_lstStrPropertyName[15]=CATUnicodeString("��ĸ��������");

 //
 m_IChoosedIndex = 0;
 //

}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstFreeStyleNutDlg::~PrtFstFreeStyleNutDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _Label04 = NULL;
 _Combo01 = NULL;
 _Combo02 = NULL;
 _Combo03 = NULL;
 _Combo04 = NULL;
 _GoToSearchPB = NULL;
 _Label05 = NULL;
 _Combo05 = NULL;
 _Frame002 = NULL;
 _SearchResultML = NULL;
 _Frame003 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION

 //����ڴ�
 for (int k=1;k<=m_plsStrCurrentWBSItem.Size();k++)
 {
	 CATLISTV(CATUnicodeString) * TempLstStr = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[k];
	 delete TempLstStr;
 }
}



void PrtFstFreeStyleNutDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(1,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridColumnResizable(1,1);
 _Label01 = new CATDlgLabel(_Frame001, "Label01");
_Label01 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Label02 = new CATDlgLabel(_Frame001, "Label02");
_Label02 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Label03 = new CATDlgLabel(_Frame001, "Label03");
_Label03 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Label04 = new CATDlgLabel(_Frame001, "Label04");
_Label04 -> SetGridConstraints(4, 0, 1, 1, CATGRID_4SIDES);
 _Combo01 = new CATDlgCombo(_Frame001, "Combo01", CATDlgCmbDropDown);
_Combo01 -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Combo02 = new CATDlgCombo(_Frame001, "Combo02", CATDlgCmbDropDown);
_Combo02 -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _Combo03 = new CATDlgCombo(_Frame001, "Combo03", CATDlgCmbDropDown);
_Combo03 -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
 _Combo04 = new CATDlgCombo(_Frame001, "Combo04", CATDlgCmbDropDown);
_Combo04 -> SetGridConstraints(3, 1, 1, 1, CATGRID_4SIDES);
 _GoToSearchPB = new CATDlgPushButton(_Frame001, "GoToSearchPB");
_GoToSearchPB -> SetGridConstraints(5, 1, 1, 1, CATGRID_4SIDES);
 _Label05 = new CATDlgLabel(_Frame001, "Label05");
_Label05 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Combo05 = new CATDlgCombo(_Frame001, "Combo05", CATDlgCmbDropDown);
_Combo05 -> SetGridConstraints(4, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridRowResizable(0,1);
 _Frame002 -> SetGridColumnResizable(0,1);
 _SearchResultML = new CATDlgMultiList(_Frame002, "SearchResultML");
 /*CATUnicodeString SearchResultMLTitles [ 8 ];
 SearchResultMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle1");
 SearchResultMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle2");
 SearchResultMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle3");
 SearchResultMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle4");
 SearchResultMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle5");
 SearchResultMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle6");
 SearchResultMLTitles[6] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle7");
 SearchResultMLTitles[7] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle8");*/
 _SearchResultML -> SetColumnTitles(16, m_lstStrPropertyName);
 _SearchResultML -> SetVisibleColumnCount( 14 );
_SearchResultML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridColumnResizable(0,1);
 _NextStepPB = new CATDlgPushButton(_Frame003, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _LastStepPB = new CATDlgPushButton(_Frame003, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//��ʼ���������͵������̼���ѯ�������ֱ��ǣ���ͨ��ĸ��������˫��������
//��¼��ע������
CATLISTV(CATUnicodeString) *LstStrAtrrValue01 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue01).Append("F_NUT_NORMAL_STD_CODE_INFO");
(*LstStrAtrrValue01).Append("F_NUT_SINGLE_EAR_PSL_STD");
(*LstStrAtrrValue01).Append("F_NUT_DOUBLE_EAR_PSL_STD"); 
(*LstStrAtrrValue01).Append("F_NUT_CORNER_SHAPE_PSL_STD");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue01);
//��¼��������
CATLISTV(CATUnicodeString) *LstStrAtrrValue02 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue02).Append("F_NUT_NORMAL_SPEC_INFO");
(*LstStrAtrrValue02).Append("F_NUT_SINGLE_EAR_PSL_SPEC");
(*LstStrAtrrValue02).Append("F_NUT_DOUBLE_EAR_PSL_SPEC");
(*LstStrAtrrValue02).Append("F_NUT_CORNER_SHAPE_PSL_SPEC");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue02);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue031 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue031).Append("F_NUT_NORMAL_STD_CODE_INFO_MATERIAL");
(*LstStrAtrrValue031).Append("F_NUT_NORMAL_STD_CODE_INFO_SURFACE_TREATMENT");
(*LstStrAtrrValue031).Append("F_NUT_NORMAL_STD_CODE_INFO_FASTENER_NAME");
(*LstStrAtrrValue031).Append("F_NUT_NORMAL_STD_CODE_INFO_FASTENER_MARK");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue031);
////
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue032 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue032).Append("F_NUT_NORMAL_SPEC_INFO_FASTENER_MARK");
(*LstStrAtrrValue032).Append("F_NUT_NORMAL_SPEC_INFO_DIAMETER");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue032);

//
CATLISTV(CATUnicodeString) *LstStrAtrrValue041 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue041).Append("F_NUT_SINGLE_EAR_PSL_STD_MATERIAL");
(*LstStrAtrrValue041).Append("F_NUT_SINGLE_EAR_PSL_STD_SURFACE_TREATMENT");
(*LstStrAtrrValue041).Append("F_NUT_SINGLE_EAR_PSL_STD_FASTENER_NAME");
(*LstStrAtrrValue041).Append("F_NUT_SINGLE_EAR_PSL_STD_FASTENER_MARK");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue041);

//
CATLISTV(CATUnicodeString) *LstStrAtrrValue042 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue042).Append("F_NUT_SINGLE_EAR_PSL_SPEC_FASTENER_MARK");
(*LstStrAtrrValue042).Append("F_NUT_SINGLE_EAR_PSL_SPEC_NOMINAL_DIAMETER");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue042);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue051 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue051).Append("F_NUT_DOUBLE_EAR_PSL_STD_MATERIAL");
(*LstStrAtrrValue051).Append("F_NUT_DOUBLE_EAR_PSL_STD_SURFACE_TREATMENT");
(*LstStrAtrrValue051).Append("F_NUT_DOUBLE_EAR_PSL_STD_FASTENER_NAME");
(*LstStrAtrrValue051).Append("F_NUT_DOUBLE_EAR_PSL_STD_FASTENER_MARK");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue051);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue052 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue052).Append("F_NUT_DOUBLE_EAR_PSL_SPEC_FASTENER_MARK");
(*LstStrAtrrValue052).Append("F_NUT_DOUBLE_EAR_PSL_SPEC_NOMINAL_DIAMETER");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue052);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue061 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue061).Append("F_NUT_CORNER_SHAPE_PSL_STD_MATERIAL");
(*LstStrAtrrValue061).Append("F_NUT_CORNER_SHAPE_PSL_STD_SURFACE_TREATMENT");
(*LstStrAtrrValue061).Append("F_NUT_CORNER_SHAPE_PSL_STD_FASTENER_NAME");
(*LstStrAtrrValue061).Append("F_NUT_CORNER_SHAPE_PSL_STD_FASTENER_MARK");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue061);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue062 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue062).Append("F_NUT_CORNER_SHAPE_PSL_SPEC_FASTENER_MARK");
(*LstStrAtrrValue062).Append("F_NUT_CORNER_SHAPE_PSL_SPEC_NOMINAL_DIAMETER");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue062);

//
CATUnicodeString strComboName01(" ��ѡ�� < ����ĸ���͡� >");
_Combo01->SetLine(strComboName01);
_Combo01->SetLine("��ͨ��ĸ");
_Combo01->SetLine("�����а�������ĸ");
_Combo01->SetLine("˫���а�������ĸ");
_Combo01->SetLine("�����а�������ĸ");

//��ʼ����ʾ����
CATUnicodeString strComboName03(" ��ѡ�� < ���������ơ� >");
CATUnicodeString strComboName04(" ��ѡ�� < �����洦�������� >");
CATUnicodeString strComboName05(" ��ѡ�� < ����ĸ���ơ� >");
CATUnicodeString strComboName06(" ��ѡ�� < ����ĸ��׼�š� >");

m_alsStrCurrentWBSShow.Append(strComboName03);
m_alsStrCurrentWBSShow.Append(strComboName04);
m_alsStrCurrentWBSShow.Append(strComboName05);
m_alsStrCurrentWBSShow.Append(strComboName06);

//��������COMBO���б���
//m_ItemComboList.Append(_Combo01);
m_ItemComboList.Append(_Combo02);
m_ItemComboList.Append(_Combo03);
m_ItemComboList.Append(_Combo04);
m_ItemComboList.Append(_Combo05);
//

//
for (int i=1; i<=MAXCOUNT; i++)
{
	((CATDlgCombo*)m_ItemComboList[i])->SetLine(m_alsStrCurrentWBSShow[i]);
	((CATDlgCombo*)m_ItemComboList[i])->SetVisibleTextHeight(20);
}

//


//�Ե�һ��COMBO���õ�������Ӧ����
AddAnalyseNotificationCB (_Combo01,_Combo01->GetComboSelectNotification(),
						  (CATCommandMethod)&PrtFstFreeStyleNutDlg::MainFstComboItemCB,NULL);

//
for (int i = 1; i <= MAXCOUNT; i ++)
{
	AddAnalyseNotificationCB ((CATDlgCombo*)m_ItemComboList[i],((CATDlgCombo*)m_ItemComboList[i])->GetComboSelectNotification(),
		(CATCommandMethod)&PrtFstFreeStyleNutDlg::ComboItemSearchCB,NULL);
}


//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

//��ʼ��ѡ���
CATBoolean PrtFstFreeStyleNutDlg::MainFstComboItemCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//����������
	_SearchResultML->ClearLine();
	//
	_NextStepPB->SetSensitivity(CATDlgDisable);
	//
	_GoToSearchPB->SetSensitivity(CATDlgDisable);
	//��õ�һ��COMBO��ѡ������
	int tempIndex;
	tempIndex = _Combo01->GetSelect();
	//
	m_IChoosedIndex=tempIndex;
	//
	if (m_IChoosedIndex != 0)
	{
		//
		//����ؼ���ʾ����Ϣ
		for (int i=1; i<=MAXCOUNT; i++)
		{
			((CATDlgCombo*)m_ItemComboList[i])->ClearLine();
			((CATDlgCombo*)m_ItemComboList[i])->SetLine(m_alsStrCurrentWBSShow[i]);
		}
		//
		CATLISTV(CATUnicodeString) * TempLstStr01 = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[1];
		m_StrCurrentDataBaseName = (* TempLstStr01)[m_IChoosedIndex];
		//
		CATLISTV(CATUnicodeString) * TempLstStr02 = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[m_IChoosedIndex*2-1+2];
		m_alsStrCurrentWBSItem = *TempLstStr02;
		//
		CATLISTV(CATUnicodeString) * TempLstStr03 = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[2];
		m_StrNextStepDataBaseName = (* TempLstStr03)[m_IChoosedIndex];
		//
		CATLISTV(CATUnicodeString) * TempLstStr04 = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[m_IChoosedIndex*2+2];
		m_strNextStepWBSItem = *TempLstStr04;

		//
		//��ʾCOMBO�ؼ���������Ϣ
		for (int i = 1; i <= m_ItemComboList.Size(); i ++)
		{
			CATListValCATUnicodeString astrKeyWords;

			CATUnicodeString strWBSItem = CATUnicodeString("DropdownList=") + m_alsStrCurrentWBSItem[i];
			astrKeyWords.Append(strWBSItem);

			SetSearchItemComboList(astrKeyWords,(CATDlgCombo*)m_ItemComboList[i]);
		}
	}
	else//���Ϊ���ʱ�����������������Ϣ
	{
		//
		for (int i=1; i<=MAXCOUNT; i++)
		{
			((CATDlgCombo*)m_ItemComboList[i])->ClearLine();
			((CATDlgCombo*)m_ItemComboList[i])->SetLine(m_alsStrCurrentWBSShow[i]);
		}
	}

	return TRUE;
}

CATBoolean PrtFstFreeStyleNutDlg::ComboItemSearchCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	//����������
	_SearchResultML->ClearLine();
	//��õ�ǰcombo�б�λ��
	int comboIndex = m_ItemComboList.Locate(cmd);
	//cout<<"�û���ѡ����"<<comboIndex<<endl;
	//
	_NextStepPB->SetSensitivity(CATDlgDisable);

	//�����ؼ����б�
	CATLISTV(CATUnicodeString) aStrComboItemSelected;
	aStrComboItemSelected.Append(""); //����һ�����ַ���ռסλ�ã��������޸���

	//��ȡ����֮ǰ��COMBO������ѡ�����
	//����ѭ����ʽ
	for (int i = 1; i <= comboIndex; i++)
	{
		int tempIndex;
		tempIndex = ((CATDlgCombo*)m_ItemComboList[i])->GetSelect();

		if (tempIndex != 0)
		{
			CATUnicodeString strTempIndexItem ;
			((CATDlgCombo*)m_ItemComboList[i])->GetLine(strTempIndexItem,tempIndex);

			//���츳ֵ��ʽ���ַ���
			CATUnicodeString strTemp = m_alsStrCurrentWBSItem[i] + "=" + strTempIndexItem;
			aStrComboItemSelected.Append(strTemp);
		}

	}

	//����ѡ���COMBO֮���COMBO����ʾ���
	for (int j = comboIndex+1; j <= m_ItemComboList.Size(); j++)
	{
		CATUnicodeString strSearch = CATUnicodeString("DropdownList=") + m_alsStrCurrentWBSItem[j];
		aStrComboItemSelected[1] = strSearch;

		//���ú������������������
		((CATDlgCombo*) m_ItemComboList[j])->ClearLine();
		CATUnicodeString strComboName = m_alsStrCurrentWBSShow[j];
		((CATDlgCombo*) m_ItemComboList[j])->SetLine(strComboName);
		HRESULT hr = SetSearchItemComboList(aStrComboItemSelected,(CATDlgCombo*)m_ItemComboList[j]);
	}

	//
	//������һ����׼��COMBO��ѡ�����ݣ����ڿ���gotosearch����ʾ״̬
	int tempIndex;
	tempIndex = _Combo05->GetSelect();
	//
	if (tempIndex != 0)
	{
		//�԰�ť״̬�Ŀ���
		_GoToSearchPB->SetSensitivity(CATDlgEnable);
	}
	else
	{
		//�԰�ť״̬�Ŀ���
		_GoToSearchPB->SetSensitivity(CATDlgDisable);
	}

	return TRUE;
}

//============================================================
// [4/27/2011 ev5adm]
// ������������combo���������ʾ����
//============================================================
HRESULT PrtFstFreeStyleNutDlg::SetSearchItemComboList(CATListValCATUnicodeString astrKeyWords,CATDlgCombo * piDlgCombo)
{
	HRESULT hr = S_OK;
	//���
	//�洢�����õ���combo value 
	CATListValCATUnicodeString strListOfSearchResult;
	CATListValCATUnicodeString astrCombolistValue;
	//���ò�ѯ�ӿ�
	hr = MBDWebservice::QueryDataWebService(astrKeyWords,strListOfSearchResult);

	//������Ҫ����Ϣ
	if (SUCCEEDED(hr))
	{
		//���������Ŀ����ÿ��Ŀ���ݸ������ֱ��Ӧ�ڶ����������������ݴӵ�������ʼ
		CATUnicodeString strCount=strListOfSearchResult[2];
		CATUnicodeString strCutNumb=strListOfSearchResult[3];
		double dCount=0,dCutNumb=1;
		strCount.ConvertToNum(&dCount);
		strCutNumb.ConvertToNum(&dCutNumb);

		//������3Ϊ������ѭ������
		int cyclecount = (int)((strListOfSearchResult.Size()-5)/dCutNumb);
		//
		if (cyclecount==dCount && dCutNumb==1)
		{
			if (cyclecount >= 1)
			{

				for (int i = 1; i <= cyclecount; i++)
				{
					astrCombolistValue.Append(strListOfSearchResult[i+5]);
				}

			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//��ʾ��combo�����б���
	for (int j = 1; j <= astrCombolistValue.Size(); j++)
	{
		piDlgCombo->SetLine(astrCombolistValue[j]);
	}

	return hr;
}

//��ȡ����WBSItem��Ϣ
void PrtFstFreeStyleNutDlg::GetAllWBSItemInfo(CATLISTV(CATUnicodeString) &listStrSearchItems)
{
	//��ȡ��ѡ��ѯ����Ϣ
	CATUnicodeString strDatabase("");
	strDatabase = CATUnicodeString("DatabaseName=") + m_StrCurrentDataBaseName; 
	listStrSearchItems.Append(strDatabase);

	//��ȡ����������Ϣ
	int count = m_ItemComboList.Size();

	for (int i = 1; i <= count; i ++)
	{
		int selectComboItem = ((CATDlgCombo*) m_ItemComboList[i])->GetSelect();

		if (selectComboItem != 0)
		{
			CATUnicodeString strComboValue("");
			((CATDlgCombo*) m_ItemComboList[i])->GetLine(strComboValue,selectComboItem);

			CATUnicodeString strValue("");
			strValue = m_alsStrCurrentWBSItem[i] + "==" + strComboValue;
			listStrSearchItems.Append(strValue);
		}


	}
}