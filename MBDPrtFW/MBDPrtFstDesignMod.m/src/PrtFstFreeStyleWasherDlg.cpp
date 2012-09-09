// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleWasherDlg.cpp
// The dialog : PrtFstFreeStyleWasherDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstFreeStyleWasherDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstFreeStyleWasherDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif

const int MAXCOUNT = 4;


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstFreeStyleWasherDlg::PrtFstFreeStyleWasherDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstFreeStyleWasherDlg",CATDlgWndModal|CATDlgWndBtnClose|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Combo01 = NULL;
 _Label02 = NULL;
 _Combo02 = NULL;
 _Label03 = NULL;
 _Combo03 = NULL;
 _Label04 = NULL;
 _Combo04 = NULL;
 _Label05 = NULL;
 _Combo05 = NULL;
 _GoToSearchPB = NULL;
 _Label009 = NULL;
 _DiameterOffsetSpinner = NULL;
 _Frame002 = NULL;
 _RearchResultsML = NULL;
 _Frame008 = NULL;
 _PosSTARTRB = NULL;
 _PosENDRB = NULL;
 _Frame003 = NULL;
 _ChooseWashersML = NULL;
 _Frame005 = NULL;
 _RemovePB = NULL;
 _ClearAllPB = NULL;
 _Frame004 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION

 //
 m_lstStrPropertyName[0]=CATUnicodeString("紧固件标准号");
 m_lstStrPropertyName[1]=CATUnicodeString("紧固件规格");
 m_lstStrPropertyName[2]=CATUnicodeString("内径");
 m_lstStrPropertyName[3]=CATUnicodeString("外径");
 m_lstStrPropertyName[4]=CATUnicodeString("沉槽直径"); 
 m_lstStrPropertyName[5]=CATUnicodeString("厚度");
 m_lstStrPropertyName[6]=CATUnicodeString("重量（kg）");
 //
 m_IChoosedIndex = 0;
 //

 //
 m_lstStrPropertyName02[0]=CATUnicodeString("安装部位");
 m_lstStrPropertyName02[1]=CATUnicodeString("紧固件标准号");
 m_lstStrPropertyName02[2]=CATUnicodeString("紧固件名称");
 m_lstStrPropertyName02[3]=CATUnicodeString("材料");
 m_lstStrPropertyName02[4]=CATUnicodeString("表面处理");
 m_lstStrPropertyName02[5]=CATUnicodeString("单位制"); 
 m_lstStrPropertyName02[6]=CATUnicodeString("备注");
 m_lstStrPropertyName02[7]=CATUnicodeString("紧固件规格");
 m_lstStrPropertyName02[8]=CATUnicodeString("内径");
 m_lstStrPropertyName02[9]=CATUnicodeString("外径");
 m_lstStrPropertyName02[10]=CATUnicodeString("沉槽直径"); 
 m_lstStrPropertyName02[11]=CATUnicodeString("厚度");
 m_lstStrPropertyName02[12]=CATUnicodeString("重量（kg）");

}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstFreeStyleWasherDlg::~PrtFstFreeStyleWasherDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Combo01 = NULL;
 _Label02 = NULL;
 _Combo02 = NULL;
 _Label03 = NULL;
 _Combo03 = NULL;
 _Label04 = NULL;
 _Combo04 = NULL;
 _Label05 = NULL;
 _Combo05 = NULL;
 _GoToSearchPB = NULL;
 _Label009 = NULL;
 _DiameterOffsetSpinner = NULL;
 _Frame002 = NULL;
 _RearchResultsML = NULL;
 _Frame008 = NULL;
 _PosSTARTRB = NULL;
 _PosENDRB = NULL;
 _Frame003 = NULL;
 _ChooseWashersML = NULL;
 _Frame005 = NULL;
 _RemovePB = NULL;
 _ClearAllPB = NULL;
 _Frame004 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


 //清除内存
 for (int k=1;k<=m_plsStrCurrentWBSItem.Size();k++)
 {
	 CATLISTV(CATUnicodeString) * TempLstStr = (CATLISTV(CATUnicodeString) *)m_plsStrCurrentWBSItem[k];
	 delete TempLstStr;
 }

}



void PrtFstFreeStyleWasherDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(1,1);
 SetGridRowResizable(2,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridColumnResizable(1,1);
 _Label01 = new CATDlgLabel(_Frame001, "Label01");
_Label01 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Combo01 = new CATDlgCombo(_Frame001, "Combo01", CATDlgCmbDropDown);
_Combo01 -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Label02 = new CATDlgLabel(_Frame001, "Label02");
_Label02 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Combo02 = new CATDlgCombo(_Frame001, "Combo02", CATDlgCmbDropDown);
_Combo02 -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _Label03 = new CATDlgLabel(_Frame001, "Label03");
_Label03 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Combo03 = new CATDlgCombo(_Frame001, "Combo03", CATDlgCmbDropDown);
_Combo03 -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
 _Label04 = new CATDlgLabel(_Frame001, "Label04");
_Label04 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Combo04 = new CATDlgCombo(_Frame001, "Combo04", CATDlgCmbDropDown);
_Combo04 -> SetGridConstraints(3, 1, 1, 1, CATGRID_4SIDES);
 _Label05 = new CATDlgLabel(_Frame001, "Label05");
_Label05 -> SetGridConstraints(4, 0, 1, 1, CATGRID_4SIDES);
 _Combo05 = new CATDlgCombo(_Frame001, "Combo05", CATDlgCmbDropDown);
_Combo05 -> SetGridConstraints(4, 1, 1, 1, CATGRID_4SIDES);
 _GoToSearchPB = new CATDlgPushButton(_Frame001, "GoToSearchPB");
_GoToSearchPB -> SetGridConstraints(6, 1, 1, 1, CATGRID_4SIDES);
 _Label009 = new CATDlgLabel(_Frame001, "Label009");
_Label009 -> SetGridConstraints(5, 0, 1, 1, CATGRID_4SIDES);
 _DiameterOffsetSpinner = new CATDlgSpinner(_Frame001, "DiameterOffsetSpinner", CATDlgSpnEntry);
 _DiameterOffsetSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
_DiameterOffsetSpinner -> SetGridConstraints(5, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridRowResizable(1,1);
 _Frame002 -> SetGridColumnResizable(0,1);
 _RearchResultsML = new CATDlgMultiList(_Frame002, "RearchResultsML");
 //CATUnicodeString RearchResultsMLTitles [ 6 ];
 //RearchResultsMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle1");
 //RearchResultsMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle2");
 //RearchResultsMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle3");
 //RearchResultsMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle4");
 //RearchResultsMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle5");
 //RearchResultsMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame002.RearchResultsML.ColumnTitle6");
 _RearchResultsML -> SetColumnTitles(7, m_lstStrPropertyName);
 _RearchResultsML -> SetVisibleColumnCount( 6 );
_RearchResultsML -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame008 = new CATDlgFrame(_Frame002, "Frame008", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame008 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _PosSTARTRB = new CATDlgRadioButton(_Frame008, "PosSTARTRB");
_PosSTARTRB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _PosENDRB = new CATDlgRadioButton(_Frame008, "PosENDRB");
_PosENDRB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridRowResizable(0,1);
 _Frame003 -> SetGridColumnResizable(0,1);
 _ChooseWashersML = new CATDlgMultiList(_Frame003, "ChooseWashersML");
 //CATUnicodeString ChooseWashersMLTitles [ 6 ];
 //ChooseWashersMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle1");
 //ChooseWashersMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle2");
 //ChooseWashersMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle3");
 //ChooseWashersMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle4");
 //ChooseWashersMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle5");
 //ChooseWashersMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleWasherDlg", "Frame003.ChooseWashersML.ColumnTitle6");
 _ChooseWashersML -> SetColumnTitles(13, m_lstStrPropertyName02);
 _ChooseWashersML -> SetVisibleColumnCount( 6 );
_ChooseWashersML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame005 = new CATDlgFrame(_Frame003, "Frame005", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame005 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _RemovePB = new CATDlgPushButton(_Frame005, "RemovePB");
_RemovePB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _ClearAllPB = new CATDlgPushButton(_Frame005, "ClearAllPB");
_ClearAllPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame004 = new CATDlgFrame(this, "Frame004", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame004 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Frame004 -> SetGridColumnResizable(0,1);
 _NextStepPB = new CATDlgPushButton(_Frame004, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _LastStepPB = new CATDlgPushButton(_Frame004, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION


//初始化三种类型的主紧固件查询条件，分别是：普通螺母、单耳、双耳、角型
//记录标注号索引
CATLISTV(CATUnicodeString) *LstStrAtrrValue01 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue01).Append("F_WASHER_STD_CODE_INFO");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue01);
//记录规格号索引
CATLISTV(CATUnicodeString) *LstStrAtrrValue02 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue02).Append("F_WASHER_SPEC_INFO");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue02);
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue031 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue031).Append("F_WASHER_STD_CODE_INFO_MATERIAL");
(*LstStrAtrrValue031).Append("F_WASHER_STD_CODE_INFO_SURFACE_TREATMENT");
(*LstStrAtrrValue031).Append("F_WASHER_STD_CODE_INFO_FASTENER_NAME");
(*LstStrAtrrValue031).Append("F_WASHER_STD_CODE_INFO_FASTENER_MARK");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue031);
////
//
CATLISTV(CATUnicodeString) *LstStrAtrrValue032 = new CATLISTV(CATUnicodeString)();
(*LstStrAtrrValue032).Append("F_WASHER_SPEC_INFO_FASTENER_MARK");
(*LstStrAtrrValue032).Append("F_WASHER_SPEC_INFO_INTERNAL_DIAMETER");
m_plsStrCurrentWBSItem.Append(LstStrAtrrValue032);

//
CATUnicodeString strComboName01(" 请选择： < “垫圈类型” >");
_Combo01->SetLine(strComboName01);
_Combo01->SetLine("垫圈");


//初始化显示界面
CATUnicodeString strComboName03(" 请选择： < “材料名称” >");
CATUnicodeString strComboName04(" 请选择： < “表面处理方法” >");
CATUnicodeString strComboName05(" 请选择： < “螺母名称” >");
CATUnicodeString strComboName06(" 请选择： < “螺母规格号” >");

m_alsStrCurrentWBSShow.Append(strComboName03);
m_alsStrCurrentWBSShow.Append(strComboName04);
m_alsStrCurrentWBSShow.Append(strComboName05);
m_alsStrCurrentWBSShow.Append(strComboName06);

//加入所有COMBO到列表中
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
_PosENDRB->SetState(CATDlgCheck);

//对第一个COMBO设置单独的响应函数
AddAnalyseNotificationCB (_Combo01,_Combo01->GetComboSelectNotification(),
						  (CATCommandMethod)&PrtFstFreeStyleWasherDlg::MainFstComboItemCB,NULL);

//
for (int i = 1; i <= MAXCOUNT; i ++)
{
	AddAnalyseNotificationCB ((CATDlgCombo*)m_ItemComboList[i],((CATDlgCombo*)m_ItemComboList[i])->GetComboSelectNotification(),
		(CATCommandMethod)&PrtFstFreeStyleWasherDlg::ComboItemSearchCB,NULL);
}


//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

//初始化选择框
CATBoolean PrtFstFreeStyleWasherDlg::MainFstComboItemCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//清除结果内容
	_RearchResultsML->ClearLine();
	//
	_GoToSearchPB->SetSensitivity(CATDlgDisable);
	//获得第一个COMBO所选的内容
	int tempIndex;
	tempIndex = _Combo01->GetSelect();
	//
	m_IChoosedIndex=tempIndex;
	//
	if (m_IChoosedIndex != 0)
	{
		//
		//清除控件显示的信息
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
		//显示COMBO控件下拉框信息
		for (int i = 1; i <= m_ItemComboList.Size(); i ++)
		{
			CATListValCATUnicodeString astrKeyWords;

			CATUnicodeString strWBSItem = CATUnicodeString("DropdownList=") + m_alsStrCurrentWBSItem[i];
			astrKeyWords.Append(strWBSItem);

			SetSearchItemComboList(astrKeyWords,(CATDlgCombo*)m_ItemComboList[i]);
		}
	}
	else//如果为零的时候，清除所有下拉框信息
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

CATBoolean PrtFstFreeStyleWasherDlg::ComboItemSearchCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	//清除结果内容
	_RearchResultsML->ClearLine();
	//获得当前combo列表位置
	int comboIndex = m_ItemComboList.Locate(cmd);
	
	//搜索关键字列表
	CATLISTV(CATUnicodeString) aStrComboItemSelected;
	aStrComboItemSelected.Append(""); //添加一个空字符，占住位置，后面再修改它

	//获取搜索之前的COMBO的所有选择参数
	//采用循环方式
	for (int i = 1; i <= comboIndex; i++)
	{
		int tempIndex;
		tempIndex = ((CATDlgCombo*)m_ItemComboList[i])->GetSelect();

		if (tempIndex != 0)
		{
			CATUnicodeString strTempIndexItem ;
			((CATDlgCombo*)m_ItemComboList[i])->GetLine(strTempIndexItem,tempIndex);

			//构造赋值形式的字符串
			CATUnicodeString strTemp = m_alsStrCurrentWBSItem[i] + "=" + strTempIndexItem;
			aStrComboItemSelected.Append(strTemp);
		}

	}

	//更新选择该COMBO之后的COMBO的显示情况
	for (int j = comboIndex+1; j <= m_ItemComboList.Size(); j++)
	{
		CATUnicodeString strSearch = CATUnicodeString("DropdownList=") + m_alsStrCurrentWBSItem[j];
		aStrComboItemSelected[1] = strSearch;

		//调用函数清除并添加新内容
		((CATDlgCombo*) m_ItemComboList[j])->ClearLine();
		CATUnicodeString strComboName = m_alsStrCurrentWBSShow[j];
		((CATDlgCombo*) m_ItemComboList[j])->SetLine(strComboName);
		HRESULT hr = SetSearchItemComboList(aStrComboItemSelected,(CATDlgCombo*)m_ItemComboList[j]);
	}

	//
	//获得最后一个标准号COMBO所选的内容，用于控制gotosearch的显示状态
	int tempIndex;
	tempIndex = _Combo05->GetSelect();
	//
	if (tempIndex != 0)
	{
		//对按钮状态的控制
		_GoToSearchPB->SetSensitivity(CATDlgEnable);
	}
	else
	{
		//对按钮状态的控制
		_GoToSearchPB->SetSensitivity(CATDlgDisable);
	}

	return TRUE;
}

//============================================================
// [4/27/2011 ev5adm]
// 设置搜索条件combo下拉框的显示内容
//============================================================
HRESULT PrtFstFreeStyleWasherDlg::SetSearchItemComboList(CATListValCATUnicodeString astrKeyWords,CATDlgCombo * piDlgCombo)
{
	HRESULT hr = S_OK;
	//清空
	//存储搜索得到的combo value 
	CATListValCATUnicodeString strListOfSearchResult;
	CATListValCATUnicodeString astrCombolistValue;
	//调用查询接口
	hr = MBDWebservice::QueryDataWebService(astrKeyWords,strListOfSearchResult);

	//过滤需要的信息
	if (SUCCEEDED(hr))
	{
		//获得数据条目，及每条目数据个数，分别对应第二、第三，数据内容从第六条开始
		CATUnicodeString strCount=strListOfSearchResult[2];
		CATUnicodeString strCutNumb=strListOfSearchResult[3];
		double dCount=0,dCutNumb=1;
		strCount.ConvertToNum(&dCount);
		strCutNumb.ConvertToNum(&dCutNumb);

		//计算以3为倍数的循环次数
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
	//显示在combo下拉列表中
	for (int j = 1; j <= astrCombolistValue.Size(); j++)
	{
		piDlgCombo->SetLine(astrCombolistValue[j]);
	}

	return hr;
}

//获取所有WBSItem信息
void PrtFstFreeStyleWasherDlg::GetAllWBSItemInfo(CATLISTV(CATUnicodeString) &listStrSearchItems)
{
	//获取所选查询库信息
	CATUnicodeString strDatabase("");
	strDatabase = CATUnicodeString("DatabaseName=") + m_StrCurrentDataBaseName; 
	listStrSearchItems.Append(strDatabase);

	//获取所有设置信息
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