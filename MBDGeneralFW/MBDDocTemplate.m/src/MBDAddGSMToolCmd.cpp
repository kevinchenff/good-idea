// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// MBDAddGSMToolCmd.cpp
// The state chart based command: MBDAddGSMToolCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2010  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#include "MBDAddGSMToolCmd.h"

// Local dlg
#include "MBDAddGSMToolDlg.h"

#include "CATCreateExternalObject.h"
CATCreateClass( MBDAddGSMToolCmd);

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
MBDAddGSMToolCmd::MBDAddGSMToolCmd() :
  CATStateCommand ("MBDAddGSMToolCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_pDlg(NULL),m_piDoc(NULL)
  
{
	m_piDoc = PrtService::GetPrtDocument();
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
MBDAddGSMToolCmd::~MBDAddGSMToolCmd()
{
	if (m_pDlg != NULL) 
	{
		m_pDlg->RequestDelayedDestruction();
		m_pDlg = NULL;
	}
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void MBDAddGSMToolCmd::BuildGraph()
{
	// TODO: Define the StateChart 
	// ---------------------------

	if (m_piDoc != NULL)
	{
		//增加判断，针对CATPart，CATProduct两种文档分别对待。

		//当是product文件时，提示退出
		CATFrmEditor * pEditor =CATFrmEditor::GetCurrentEditor();
		CATPathElement spPath = pEditor->GetUIActiveObject( );

		CATBaseUnknown* pcurrbase = spPath.CurrentElement( );

		HRESULT rc = S_FALSE;
		CATIProduct *piProduct = NULL;
		CATIPrtPart *piPrtPart = NULL;

		//********************************************************************************
		// 当前文档为product工作环境时
		//********************************************************************************
		if (SUCCEEDED(pcurrbase->QueryInterface(IID_CATIProduct,(void**)& piProduct)))
		{
			// 当前状态没有激活的CATPart文件
			// AfxMessageBox(_T("当前状态没有激活的CATPart文件"));
			PrtService::ShowDlgNotify("添加MBD模板几何图形集提示","当前文档为CATProduct环境，请转换到CATPart环境再做操作！");
			piProduct->Release();
			piProduct=NULL;

			RequestDelayedDestruction();            
		}

		//********************************************************************************
		// 当前文档为part工作环境时
		//********************************************************************************
		else if (SUCCEEDED(pcurrbase->QueryInterface(IID_CATIPrtPart,(void**)& piPrtPart)))
		{
			// 通过上一步的FrmEditor获得文档的Document
			CATInit_var spInitOnDoc(m_piDoc);

			// 获得相应的容器类
			CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
			CATIPrtPart_var spPart = piPrtCont->GetPart();
			piPrtCont->Release();
			piPrtCont=NULL;
			CATISpecObject_var spSpecOnPart = spPart;

			// 获得Product，更改零件编号
			CATIProduct_var spProduct = spPart->GetProduct( );
			CATUnicodeString StrPartNumber = spProduct->GetPartNumber();

			//当是part文件时，开始操作功能
			m_pDlg = new MBDAddGSMToolDlg();
			m_pDlg->Build();
			m_pDlg->SetVisibility(CATDlgShow);
			m_pDlg->_PartNameEditor->SetText(StrPartNumber);

			AddAnalyseNotificationCB(m_pDlg,m_pDlg->GetDiaOKNotification(),
				(CATCommandMethod)&MBDAddGSMToolCmd::OnMBDOKAction,NULL);

			AddAnalyseNotificationCB(m_pDlg,m_pDlg->GetDiaCANCELNotification(),
				(CATCommandMethod)&MBDAddGSMToolCmd::OnMBDCancelAction,NULL);

			AddAnalyseNotificationCB(m_pDlg,m_pDlg->GetWindCloseNotification(),
				(CATCommandMethod)&MBDAddGSMToolCmd::OnMBDCancelAction,NULL);

			piPrtPart->Release();
			piPrtPart=NULL;
		}


	}
	else
	{
		// 当前状态没有激活的CATPart文件
		PrtService::ShowDlgNotify("添加MBD模板几何图形集提示","当前状态没有激活的CATPart文件");
		RequestDelayedDestruction();
	}
  
}

void MBDAddGSMToolCmd::OnMBDOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	int selIndex = m_pDlg->GetMBDTempType();

	if (selIndex == 0)
	{
		AddMBDGSMTools(m_piDoc);
	} 
	else if(selIndex == 1)
	{
		AddARMGSMTools(m_piDoc);
	}
	

	//Specify that the command is finished
	RequestDelayedDestruction();
}

void MBDAddGSMToolCmd::OnMBDCancelAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	//Specify that the command is finished
	RequestDelayedDestruction();
}

void MBDAddGSMToolCmd::AddARMGSMTools(CATDocument * piDocument)
{
	//--------------------------------------------------------------------------
	//  根据客户需求，创建模板内容
	//--------------------------------------------------------------------------
	CATUnicodeString StrPartNumber = m_pDlg->GetPartName();

	// 通过上一步的FrmEditor获得文档的Document
	CATInit_var spInitOnDoc(piDocument);

	// 获得相应的容器类
	CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
	CATIPrtPart_var spPart = piPrtCont->GetPart();

	CATISpecObject_var spSpecOnPart = spPart;

	// 获得Product，更改零件编号
	CATIProduct_var spProduct = spPart->GetProduct( );
	spProduct->SetPartNumber(StrPartNumber);
	spProduct->SetPrdInstanceName(StrPartNumber);

	// 更改PartBody命名
	CATIPartRequest_var spPrtRequst = spPart;
	CATBaseUnknown_var  oPartBody;
	spPrtRequst->GetMainBody("MfDefault3DView",oPartBody );

	CATIAlias_var spMainBodyAlias = oPartBody;
	spMainBodyAlias->SetAlias(StrPartNumber);


	// 按照模板要求添加几何图形集
	int oDiag = 0 ;
	CATIContainer_var	spPrtCon = piPrtCont;
	CATISpecObject_var spNewGSMTool01 = NULL_var;
	CATISpecObject_var spNewGSMTool02 = NULL_var;
	CATListValCATUnicodeString  ListStrName;
	CATListValCATUnicodeString  ListStrNameValue;
	CATListOfInt countNode;

	CATUnicodeString strNametemp;
	CATUnicodeString strValuetemp;

	//过程元素
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "过程元素", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;

	//设计依据
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "设计依据", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "设计依据1";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "设计依据2";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();


	//零部件描述
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "零部件描述", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "零部件名称";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "是否对称件";
	ListStrName.Append(strNametemp);
	strValuetemp = "否";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "是";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(2);

	strNametemp = "对称性描述";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "零部件类型";
	ListStrName.Append(strNametemp);
	strValuetemp = "普通件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "标准件";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(2);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 单元件类别
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "单元件类别", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "单元件类别";
	ListStrName.Append(strNametemp);
	strValuetemp = "一般件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "重要件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "关键件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(4);

	strNametemp = "关键或重要特性个数";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	
	// 标准注释
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "标准注释", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "标准注释1";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "标准注释2";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 零部件附注
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "零部件附注", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "密封定义";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "焊接要求";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "胶接定义";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "试验注释";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "附注1";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "附注2";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "附注3";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();	

	// 连接定义
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "连接定义", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;

	// 消耗辅助材料
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "消耗辅助材料", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "消耗辅助材料";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 标注集曲面外形
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "标注集曲面外形", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon,"XX-XXXX-X",spNewGSMTool01,spNewGSMTool02,oDiag,0,0);
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon,"XX-XXXX-X",spNewGSMTool01,spNewGSMTool02,oDiag,0,0);

	//设置MainBody为当前工作几何集
	spPart->SetCurrentFeature(oPartBody);

	// 更新零件
	PrtService::ObjectUpdate(spSpecOnPart);
	piPrtCont->Release();
	piPrtCont=NULL;
}

void MBDAddGSMToolCmd::AddMBDGSMTools(CATDocument * piDocument)
{
	//--------------------------------------------------------------------------
	//  根据客户需求，创建模板内容
	//--------------------------------------------------------------------------
	CATUnicodeString StrPartNumber = m_pDlg->GetPartName();

	// 通过上一步的FrmEditor获得文档的Document
	CATInit_var spInitOnDoc(piDocument);

	// 获得相应的容器类
	CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
	CATIPrtPart_var spPart = piPrtCont->GetPart();

	CATISpecObject_var spSpecOnPart = spPart;

	// 获得Product，更改零件编号
	CATIProduct_var spProduct = spPart->GetProduct( );
	spProduct->SetPartNumber(StrPartNumber);

	// 更改PartBody命名
	CATIPartRequest_var spPrtRequst = spPart;
	CATBaseUnknown_var  oPartBody;
	spPrtRequst->GetMainBody("MfDefault3DView",oPartBody );

	CATIAlias_var spMainBodyAlias = oPartBody;
	spMainBodyAlias->SetAlias(StrPartNumber);


	// 按照模板要求添加几何图形集
	int oDiag = 0 ;
	CATIContainer_var	spPrtCon = piPrtCont;
	CATISpecObject_var spNewGSMTool01 = NULL_var;
	CATISpecObject_var spNewGSMTool02 = NULL_var;
	CATListValCATUnicodeString  ListStrName;
	CATListValCATUnicodeString  ListStrNameValue;
	CATListOfInt countNode;

	CATUnicodeString strNametemp;
	CATUnicodeString strValuetemp;

	//过程元素
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "过程元素", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;

	//设计依据
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "设计依据", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "设计依据1";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "设计依据2";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();


	//零部件描述
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "零部件描述", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "零部件名称";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "是否对称件";
	ListStrName.Append(strNametemp);
	strValuetemp = "否";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "是";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(2);

	strNametemp = "对称性描述";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);	
	countNode.Append(1);

	strNametemp = "零部件类型";
	ListStrName.Append(strNametemp);
	strValuetemp = "普通件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "标准件";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(2);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 单元件类别
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "单元件类别", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "单元件类别";
	ListStrName.Append(strNametemp);
	strValuetemp = "一般件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "重要件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "关键件";	
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(4);

	strNametemp = "关键或重要特性个数";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";	
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 材料描述
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "材料描述", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "材料类别";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	/*strValuetemp = "铝合金";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "钛合金";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "铜合金";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "镁合金";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "复合材料";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "其它";
	ListStrNameValue.Append(strValuetemp);
	strValuetemp = "钢";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(7);*/

	strNametemp = "材料牌号";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "材料规格";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "材料技术条件";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "毛料尺寸";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 标准注释
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "标准注释", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "标准注释1";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "标准注释2";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();

	// 零部件附注
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "零部件附注", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "热处理要求";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "表面处理要求";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "表面粗糙度要求";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "形位公差";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "特种检查";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "破坏检查";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "锐边倒角";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	strNametemp = "一般公差";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	strNametemp = "检印标记";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	strNametemp = "焊接要求";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	strNametemp = "试验注释";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	strNametemp = "其它";
	ListStrName.Append(strNametemp);
	strValuetemp = "无";
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);

	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();	

	// 消耗辅助材料
	PrtService::CAAGsiCreateGeometricFeatureSets (spPrtCon, "消耗辅助材料", NULL_var ,spNewGSMTool01, oDiag , 1 , 0) ;
	strNametemp = "消耗辅助材料";
	strValuetemp = "无";
	ListStrName.Append(strNametemp);
	ListStrNameValue.Append(strValuetemp);
	countNode.Append(1);
	PrtService::SetGSMToolParamEnum(piDocument,spNewGSMTool01,ListStrName,countNode,ListStrNameValue);
	ListStrName.RemoveAll();
	ListStrNameValue.RemoveAll();
	countNode.RemoveAll();
	
	//设置MainBody为当前工作几何集
	spPart->SetCurrentFeature(oPartBody);

	// 更新零件
	PrtService::ObjectUpdate(spSpecOnPart);
	piPrtCont->Release();
	piPrtCont=NULL;
}
