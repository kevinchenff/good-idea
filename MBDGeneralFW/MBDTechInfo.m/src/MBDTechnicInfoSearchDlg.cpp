// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDTechnicInfoSearchDlg.cpp
// The dialog : MBDTechnicInfoSearchDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#include "MBDTechnicInfoSearchDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef MBDTechnicInfoSearchDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif

#include "TreeNodeSelectNotif.h"

const int MAXCOUNT = 16;

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
MBDTechnicInfoSearchDlg::MBDTechnicInfoSearchDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"MBDTechnicInfoSearchDlg",CATDlgWndModal|CATDlgWndNoResize|CATDlgWndBtnOKCancel|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
),m_NodeLocate(1),m_xmlPath("")

{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _DatabaseTreeFrame = NULL;
 _OuterFrame = NULL;
 _BlankContainer = NULL;
 _SearchItemFrame = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION

 _SerialSearchLabel = NULL;
 _SerialSearchEditor = NULL;

 _ContentSearchLabel = NULL;
 _ContentSearchEditor = NULL;
 m_piTreeCtrl = NULL;

}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
MBDTechnicInfoSearchDlg::~MBDTechnicInfoSearchDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _DatabaseTreeFrame = NULL;
 _OuterFrame = NULL;
 _BlankContainer = NULL;
 _SearchItemFrame = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION

 _ContentSearchLabel = NULL;
 _ContentSearchEditor = NULL;

 _SerialSearchLabel = NULL;
 _SerialSearchEditor = NULL;

 if (m_piTreeCtrl != NULL)
 {
	 m_piTreeCtrl = NULL;
 }

}



void MBDTechnicInfoSearchDlg::Build()
{
//��������ļ�·��
XMLService::ReadXMLInfoFromFile(m_xmlPath,ListDbName,ListDbWBSItem,countNode,ListLableName,ListWBSItem,ListGSMToolName,ListGSMToolSwitch);

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 _DatabaseTreeFrame = new CATDlgFrame(this, "DatabaseTreeFrame", CATDlgFraNoTitle|CATDlgGridLayout);
_DatabaseTreeFrame -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _OuterFrame = new CATDlgFrame(this, "OuterFrame", CATDlgFraNoFrame|CATDlgGridLayout);
_OuterFrame -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _BlankContainer = new CATDlgContainer(_OuterFrame, "BlankContainer");
_BlankContainer -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _SearchItemFrame = new CATDlgFrame(_OuterFrame, "SearchItemFrame", CATDlgFraNoTitle|CATDlgGridLayout);
_SearchItemFrame -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//����mutillist��ʾ����
int  oHeight = 0,oWidth = 0; 
PrtService::GetWindowMaxSize(&oHeight,&oWidth );

//������ѯ����ѡ��
for (int i = 0; i < MAXCOUNT; i ++)
{
	CATDlgLabel *ItemLabel = new CATDlgLabel(_SearchItemFrame, "ItemLabel");
	ItemLabel -> SetGridConstraints(i, 0, 1, 1, CATGRID_LEFT|CATGRID_TOP|CATGRID_BOTTOM);
	ItemLabel -> SetTitle(ListLableName[i+1]);
	ItemLabel -> SetVisibility(CATDlgHide);
    m_ItemLabelList.Append(ItemLabel);

	CATDlgCombo *ItemCombo = new CATDlgCombo(_SearchItemFrame, "ItemCombo", CATDlgCmbDropDown);
	ItemCombo -> SetGridConstraints(i, 1, 1, 1, CATGRID_4SIDES);
	ItemCombo -> SetVisibleTextWidth(int (0.0375*oWidth));
	ItemCombo->SetVisibleTextHeight(20);

	ItemCombo -> SetVisibility(CATDlgHide);
	m_ItemComboList.Append(ItemCombo);
}

//��ʾ��Ҫ�Ŀؼ�
m_ShowItemComboList.RemoveAll();
int showcount = countNode[1] - 2;
for (int i = 1; i <= showcount; i ++)
{
	((CATDlgLabel*) m_ItemLabelList[i])->SetVisibility(CATDlgShow);
	((CATDlgLabel*) m_ItemLabelList[i])->SetTitle(ListLableName[i]);

	((CATDlgCombo*) m_ItemComboList[i])->SetVisibility(CATDlgShow);
	CATUnicodeString strComboName = CATUnicodeString(" ��ѡ�� < ��") + ListLableName[i] + CATUnicodeString("�� >");
	((CATDlgCombo*) m_ItemComboList[i])->SetLine(strComboName);

	m_ShowItemComboList.Append(m_ItemComboList[i]);
}

//��õ�ǰ��WBSITEM
int count = countNode[1];
for (int i = 1; i <= count; i ++)
{
	ListCurrentLableName.Append(ListLableName[i]);
	ListCurrentWBSItem.Append(ListWBSItem[i]);
}

//��ʾCOMBO�ؼ���������Ϣ
for (int i = 1; i <= m_ShowItemComboList.Size(); i ++)
{
	CATListValCATUnicodeString astrKeyWords;

	CATUnicodeString strWBSItem = CATUnicodeString("MBD_Sys_DropdownList=") + ListCurrentWBSItem[i];
	astrKeyWords.Append(strWBSItem);

	SetSearchItemComboList(astrKeyWords,(CATDlgCombo*)m_ShowItemComboList[i]);
}

//ע������ ����������ؼ�
_SerialSearchLabel = new CATDlgLabel(_SearchItemFrame, "MBDTECHSerialSearchLabel");
_SerialSearchLabel -> SetGridConstraints(MAXCOUNT, 0, 1, 1,CATGRID_LEFT|CATGRID_TOP|CATGRID_BOTTOM); //CATGRID_LEFT|CATGRID_RIGHT|CATGRID_BOTTOM
_SerialSearchLabel -> SetTitle(ListLableName[showcount+1]);
_SerialSearchEditor = new CATDlgEditor(_SearchItemFrame, "SerialSearchEditor");
_SerialSearchEditor -> SetGridConstraints(MAXCOUNT, 1, 1, 1, CATGRID_4SIDES);

_ContentSearchLabel = new CATDlgLabel(_SearchItemFrame, "MBDTECHContentSearchLabel");
_ContentSearchLabel -> SetGridConstraints(MAXCOUNT+1, 0, 1, 1,CATGRID_LEFT|CATGRID_TOP|CATGRID_BOTTOM); //CATGRID_LEFT|CATGRID_RIGHT|CATGRID_BOTTOM
_ContentSearchLabel -> SetTitle(ListLableName[showcount+2]);
_ContentSearchEditor = new CATDlgEditor(_SearchItemFrame, "ContentSearchEditor");
_ContentSearchEditor -> SetGridConstraints(MAXCOUNT+1, 1, 1, 1, CATGRID_4SIDES);
m_ShowItemComboList.Append(_SerialSearchEditor);
m_ShowItemComboList.Append(_ContentSearchEditor);


//-----------------------------------------------------
//��״�ṹ
//-----------------------------------------------------
_DatabaseTreeFrame -> SetGridRowResizable(0,1);
_DatabaseTreeFrame -> SetGridColumnResizable(0,1);
m_piTreeCtrl = new CAATreeCtrl(_DatabaseTreeFrame, "TreeCtrl");
m_piTreeCtrl -> SetGridConstraints(0,0,1,1,CATGRID_4SIDES);

for (int i = 1; i <= ListDbName.Size(); i ++)
{
	m_piTreeCtrl -> AddRootTreeNode(ListDbName[i], ""); 
}

//��ѯ���
this->SetOKTitle ("�����ѯ");

//���õ�һ��Ϊѡ��״̬
int iTreeNodeRank = 1; 
CATBaseUnknown *  opTreeNodeObject = new CATBaseUnknown();
m_piTreeCtrl->GetRootTreeNodeAt(iTreeNodeRank,&opTreeNodeObject);
m_piTreeCtrl->SelectTreeNode(opTreeNodeObject);

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

AddCallback (m_piTreeCtrl, TreeNodeSelectNotif::ClassName(),(CATSubscriberMethod)&MBDTechnicInfoSearchDlg::OnTreeNodeSelect,NULL);

//
for (int i = 1; i <= MAXCOUNT; i ++)
{
	AddAnalyseNotificationCB ((CATDlgCombo*)m_ItemComboList[i],((CATDlgCombo*)m_ItemComboList[i])->GetComboSelectNotification(),
		(CATCommandMethod)&MBDTechnicInfoSearchDlg::ComboItemSearchCB,NULL);
}

}

//�����û����棬������ʾ��label �� combo
void MBDTechnicInfoSearchDlg::ChangeLableAndCombo()
{
	//��ȡ�����XML������Ϣ
	int startLabel = 0;
	for (int i = 1; i < m_NodeLocate; i++)
	{
		startLabel += countNode[i];
	}

	ListCurrentLableName.RemoveAll();
	ListCurrentWBSItem.RemoveAll();

	int count = countNode[m_NodeLocate];
	for (int i = 1; i <= count; i ++)
	{
		ListCurrentLableName.Append(ListLableName[i+startLabel]);
		ListCurrentWBSItem.Append(ListWBSItem[i+startLabel]);
	}

	//���ز�ѯ����ѡ��
	for (int i = 1; i <= m_ItemLabelList.Size(); i ++)
	{
		((CATDlgLabel*) m_ItemLabelList[i])->SetVisibility(CATDlgHide);
		((CATDlgCombo*) m_ItemComboList[i])->SetVisibility(CATDlgHide);
		((CATDlgCombo*) m_ItemComboList[i])->ClearLine();
	}

	//���Editor����
	_SerialSearchEditor->ClearLine();
	_ContentSearchEditor->ClearLine();

	//��ʾ��Ҫ�Ŀؼ�
	m_ShowItemComboList.RemoveAll();
	int showcount = count - 2;
	for (int i = 1; i <= showcount; i ++)
	{
		((CATDlgLabel*) m_ItemLabelList[i])->SetVisibility(CATDlgShow);
		((CATDlgLabel*) m_ItemLabelList[i])->SetTitle(ListCurrentLableName[i]);
		((CATDlgCombo*) m_ItemComboList[i])->SetVisibility(CATDlgShow);
		CATUnicodeString strComboName = CATUnicodeString(" ��ѡ�� < ��") + ListCurrentLableName[i] + CATUnicodeString("�� >");
		((CATDlgCombo*) m_ItemComboList[i])->SetLine(strComboName);

		m_ShowItemComboList.Append(m_ItemComboList[i]);
	}

	//��ʾCOMBO�ؼ���������Ϣ
	for (int i = 1; i <= m_ShowItemComboList.Size(); i ++)
	{
		CATListValCATUnicodeString astrKeyWords;

		CATUnicodeString strWBSItem = CATUnicodeString("MBD_Sys_DropdownList=") + ListCurrentWBSItem[i];
		astrKeyWords.Append(strWBSItem);
		
		SetSearchItemComboList(astrKeyWords,(CATDlgCombo*)m_ShowItemComboList[i]);
	}


	//ע�����������ؼ�
	_SerialSearchEditor -> SetTitle(ListCurrentLableName[showcount+1]);
	m_ShowItemComboList.Append(_SerialSearchEditor);
	_ContentSearchLabel -> SetTitle(ListCurrentLableName[showcount+2]);
	m_ShowItemComboList.Append(_ContentSearchEditor);

}

//���Ӷ��û�����ѡ�����νṹ�ؼ�����Ӧ
void MBDTechnicInfoSearchDlg::OnTreeNodeSelect(CATCallbackEvent event, void * client, CATNotification * iNotification, CATSubscriberData data, CATCallback callback)
{
	CATBaseUnknown * pTreeNode = NULL;
	m_piTreeCtrl -> GetSelectedTreeNode(&pTreeNode);
	m_piTreeCtrl -> GetCertainRootTreeNodeLocate(m_NodeLocate,pTreeNode);

	CATUnicodeString strLocate;
	strLocate.BuildFromNum(m_NodeLocate);

	//ShowDlgNotify("������ע����",strLocate);
	if (pTreeNode != NULL)
	{
		pTreeNode -> Release();
		pTreeNode = NULL;
	}

	//�ı������ʽ
	ChangeLableAndCombo();

	SetFocusOn(m_piTreeCtrl);
}

CATUnicodeString MBDTechnicInfoSearchDlg::GetDatabaseWBSItemInfo()
{
	return ListDbWBSItem[m_NodeLocate];
}

//��ȡ����WBSItem��Ϣ
void MBDTechnicInfoSearchDlg::GetAllWBSItemInfo(CATLISTV(CATUnicodeString) &listStrSearchItems)
{
	//��ȡ��ѡ��ѯ����Ϣ
	CATUnicodeString strDatabase("");
	strDatabase = CATUnicodeString("MBD_Sys_DatabaseName") + "=" + ListDbWBSItem[m_NodeLocate]; 
	listStrSearchItems.Append(strDatabase);

	//��ȡ����������Ϣ
	int count = m_ShowItemComboList.Size();

	for (int i = 1; i <= count-2; i ++)
	{
		int selectComboItem = ((CATDlgCombo*) m_ShowItemComboList[i])->GetSelect();
		
		if (selectComboItem != 0)
		{
			CATUnicodeString strComboValue("");
			((CATDlgCombo*) m_ShowItemComboList[i])->GetLine(strComboValue,selectComboItem);
			
			CATUnicodeString strValue("");
			strValue = ListCurrentWBSItem[i] + "=" + strComboValue;
			listStrSearchItems.Append(strValue);
		}

		
	}

	// Append Editor Values
	CATUnicodeString strSerialValue("");
	strSerialValue = ((CATDlgEditor*) m_ShowItemComboList[count-1])->GetText();
	if (strSerialValue != "")
	{
		strSerialValue = ListCurrentWBSItem[count-1] + "=" + strSerialValue;
		listStrSearchItems.Append(strSerialValue);
	}
	else
	{
		strSerialValue = ListCurrentWBSItem[count-1] + "=########";
		listStrSearchItems.Append(strSerialValue);
	}

	CATUnicodeString strEditorValue("");
	strEditorValue = ((CATDlgEditor*) m_ShowItemComboList[count])->GetText();
	if (strEditorValue != "")
	{
		strEditorValue = ListCurrentWBSItem[count] + "=" + strEditorValue;
		listStrSearchItems.Append(strEditorValue);
	}
	else
	{
		strEditorValue = ListCurrentWBSItem[count] + "=########";
		listStrSearchItems.Append(strEditorValue);
	}
	
}


//============================================================
// [4/27/2011 ev5adm]
// ������������combo���������ʾ����
//============================================================
HRESULT MBDTechnicInfoSearchDlg::SetSearchItemComboList(CATListValCATUnicodeString astrKeyWords,CATDlgCombo * piDlgCombo)
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
		//������2Ϊ������ѭ������
		int cyclecount = (int)((strListOfSearchResult.Size()-2)/2);

		if (cyclecount >= 1)
		{

			for (int i = 1; i <= cyclecount; i++)
			{
				astrCombolistValue.Append(strListOfSearchResult[i*2 + 1]);
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

CATBoolean MBDTechnicInfoSearchDlg::ComboItemSearchCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	//��õ�ǰcombo�б�λ��
	int comboIndex = m_ItemComboList.Locate(cmd);
	//cout<<"�û���ѡ����"<<comboIndex<<endl;

	//�����ؼ����б�
	CATLISTV(CATUnicodeString) aStrComboItemSelected;
	aStrComboItemSelected.Append(""); //����һ�����ַ���ռסλ�ã��������޸���

	//��ȡ����֮ǰ��COMBO������ѡ�����
	//����ѭ����ʽ
	for (int i = 1; i <= comboIndex; i++)
	{
		int tempIndex;
		tempIndex = ((CATDlgCombo*)m_ShowItemComboList[i])->GetSelect();

		if (tempIndex != 0)
		{
			CATUnicodeString strTempIndexItem ;
			((CATDlgCombo*)m_ShowItemComboList[i])->GetLine(strTempIndexItem,tempIndex);

			//���츳ֵ��ʽ���ַ���
			CATUnicodeString strTemp = ListCurrentWBSItem[i] + "=" + strTempIndexItem;
			aStrComboItemSelected.Append(strTemp);
		}

	}

	//����ѡ���COMBO֮���COMBO����ʾ���
	//��ȥ����ԭ���������ΪEDITORָ�룬��combo
	for (int j = comboIndex+1; j <= m_ShowItemComboList.Size() - 2; j++)
	{
		CATUnicodeString strSearch = CATUnicodeString("MBD_Sys_DropdownList=") + ListCurrentWBSItem[j];
		aStrComboItemSelected[1] = strSearch;

		//���ú������������������
		((CATDlgCombo*) m_ItemComboList[j])->ClearLine();
		CATUnicodeString strComboName = CATUnicodeString("��ѡ�� < ��") + ListCurrentLableName[j] + CATUnicodeString("�� >");
		((CATDlgCombo*) m_ItemComboList[j])->SetLine(strComboName);
		HRESULT hr = SetSearchItemComboList(aStrComboItemSelected,(CATDlgCombo*)m_ShowItemComboList[j]);
	}
	
	return TRUE;
}