// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignCmd.cpp
// The state chart based command: PrtFstDesignCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstDesignCmd.h"
#include "CATIndicationAgent.h"
#include "CATMathPlane.h"
#include "CATFace.h"
#include "CATSurface.h"

#include "CATCreateExternalObject.h"
CATCreateClass( PrtFstDesignCmd);

//
#include "CATIMfZeroDimResult.h"
#include "CATIMfBiDimResult.h"


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstDesignCmd::PrtFstDesignCmd() :
  CATStateCommand ("PrtFstDesignCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_piDlg(NULL),m_piDoc(NULL),m_piFirstSurfSLAgt(NULL),m_piSecSurfSLAgt(NULL),m_piPointSLAgt(NULL)
  ,m_piFirstSurfAgt(NULL),m_piSecSurfAgt(NULL),m_piPointsAgt(NULL),m_piPrdSLAgt(NULL),m_piPointGSMPBAgt(NULL),m_piPrdAgt(NULL)
  ,m_piPointGSMAgt(NULL)
{
	//初始化获得当前文档及名称
	m_piDoc = PrtService::GetPrtDocument();
	PrtService::GetPrdNumberFormDoc(m_piDoc,m_strDocName);

	m_piEditor = CATFrmEditor::GetCurrentEditor();
	if (NULL != m_piEditor)
	{
		m_piHSO = m_piEditor->GetHSO();
		m_piHSO->Empty();
	}

	//判断是否为ZP模型;
	if (!IsThisZPPrt())
	{
		PrtService::ShowDlgNotify("提示","该功能仅在装配上下文环境且ZP模型中操作，点击关闭！");
		RequestDelayedDestruction();
	}

	if (!PrdService::IsContextualPrd())
	{
		PrtService::ShowDlgNotify("提示","该功能仅在装配上下文环境且ZP模型中操作，点击关闭！");
		RequestDelayedDestruction();
	}
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstDesignCmd::~PrtFstDesignCmd()
{
	if (m_piDlg != NULL)
	{
		m_piDlg->RequestDelayedDestruction();
		m_piDlg = NULL;
	}

	if (NULL!=m_piPointsAgt)
	{
		m_piPointsAgt->RequestDelayedDestruction();
		m_piPointsAgt=NULL;
	}

	if (NULL!=m_piFirstSurfAgt)
	{
		m_piFirstSurfAgt->RequestDelayedDestruction();
		m_piFirstSurfAgt=NULL;
	}

	if (NULL!=m_piSecSurfAgt)
	{
		m_piSecSurfAgt->RequestDelayedDestruction();
		m_piSecSurfAgt=NULL;
	}

	if (NULL!=m_piFirstSurfSLAgt)
	{
		m_piFirstSurfSLAgt->RequestDelayedDestruction();
		m_piFirstSurfSLAgt=NULL;
	}
	if (NULL!=m_piSecSurfSLAgt)
	{
		m_piSecSurfSLAgt->RequestDelayedDestruction();
		m_piSecSurfSLAgt=NULL;
	}
	if (NULL!=m_piPointSLAgt)
	{
		m_piPointSLAgt->RequestDelayedDestruction();
		m_piPointSLAgt=NULL;
	}	

	if (NULL!=m_piPrdSLAgt)
	{
		m_piPrdSLAgt->RequestDelayedDestruction();
		m_piPrdSLAgt=NULL;
	}	

	if (NULL!=m_piPointGSMPBAgt)
	{
		m_piPointGSMPBAgt->RequestDelayedDestruction();
		m_piPointGSMPBAgt=NULL;
	}	

	if (NULL!=m_piPointGSMAgt)
	{
		m_piPointGSMAgt->RequestDelayedDestruction();
		m_piPointGSMAgt=NULL;
	}	

	if (NULL!=m_piPrdAgt)
	{
		m_piPrdAgt->RequestDelayedDestruction();
		m_piPrdAgt=NULL;
	}
   
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void PrtFstDesignCmd::BuildGraph()
{
	m_piDlg = new PrtFstDesignDlg();
	m_piDlg->Build();
	m_piDlg->SetVisibility(CATDlgShow); 


	// 主对话框的消息响应
	AddAnalyseNotificationCB (m_piDlg, 
		m_piDlg->GetDiaOKNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::OkDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_piDlg, 
		m_piDlg->GetWindCloseNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::CloseDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_piDlg, 
		m_piDlg->GetDiaCANCELNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::CloseDlgCB,
		NULL);

	//创建安装点代理
	m_piPointsAgt = new CATFeatureImportAgent("选择安装点");
	m_piPointsAgt->SetBehavior( CATDlgEngWithPSOHSO | CATDlgEngWithPrevaluation | CATDlgEngMultiAcquisition | CATDlgEngRepeat);
	m_piPointsAgt->SetAgentBehavior(MfRelimitedFeaturization|MfPermanentBody); 
	m_piPointsAgt->AddElementType(IID_CATIMfZeroDimResult);

	//创建第一安装面代理
	m_piFirstSurfAgt = new CATFeatureImportAgent("选择第一安装面");
	m_piFirstSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSOHSO | CATDlgEngRepeat  );
	m_piFirstSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	/*m_piFirstSurfAgt -> SetOrderedElementType ( "CATIMfBiDimResult" );
	m_piFirstSurfAgt -> AddOrderedElementType ( "CATFace"  );
	m_piFirstSurfAgt -> AddOrderedElementType ( "CATSurface"  );*/
	m_piFirstSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_piFirstSurfAgt -> AddElementType (IID_CATSurface);

	//创建第二安装面代理
	m_piSecSurfAgt = new CATFeatureImportAgent("选择第二安装面");
	m_piSecSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSOHSO | CATDlgEngRepeat  );
	m_piSecSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_piSecSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_piSecSurfAgt -> AddElementType (IID_CATSurface);

	//创建prd代理
	m_piPrdAgt = new CATPathElementAgent("选择连接零件");
	m_piPrdAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSOHSO | CATDlgEngRepeat  );
	m_piPrdAgt -> AddElementType (IID_CATIProduct);
	CATAcquisitionFilter * pFilterForPrt = Filter((FilterMethod) & PrtFstDesignCmd::SeletedIsPart,(void*)NULL);
	m_piPrdAgt->SetFilter(pFilterForPrt);

	//创建GSM代理
	m_piPointGSMAgt = new CATFeatureImportAgent("选择点几何图形集");
	m_piPointGSMAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSOHSO | CATDlgEngRepeat  );
	m_piPointGSMAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_piPointGSMAgt -> AddElementType (IID_CATIGSMTool);

	//points SL
	m_piPointSLAgt = new CATDialogAgent("选择安装点");
	m_piPointSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piPointSLAgt->AcceptOnNotify(m_piDlg->_PointsSL,m_piDlg->_PointsSL->GetListSelectNotification());

	//first Surf SL
	m_piFirstSurfSLAgt = new CATDialogAgent("选择第一安装面");
	m_piFirstSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piFirstSurfSLAgt->AcceptOnNotify(m_piDlg->_FirstSurfSL,m_piDlg->_FirstSurfSL->GetListSelectNotification());

	//second Surf SL
	m_piSecSurfSLAgt = new CATDialogAgent("选择第二安装面");
	m_piSecSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piSecSurfSLAgt->AcceptOnNotify(m_piDlg->_SecondSurfSL,m_piDlg->_SecondSurfSL->GetListSelectNotification());

	//Prd SL
	m_piPrdSLAgt = new CATDialogAgent("选择连接零件");
	m_piPrdSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piPrdSLAgt->AcceptOnNotify(m_piDlg->_PrdSL,m_piDlg->_PrdSL->GetListSelectNotification());

	//Choose Point GSM PB
	m_piPointGSMPBAgt = new CATDialogAgent("选择点几何图形集");
	m_piPointGSMPBAgt->SetBehavior(CATDlgEngRepeat);
	m_piPointGSMPBAgt->AcceptOnNotify(m_piDlg->_ChoosePointGSMToolPB,m_piDlg->_ChoosePointGSMToolPB->GetPushBActivateNotification());


	//Define the StateChart
	CATDialogState * StSelectPrds = GetInitialState("选择连接零件");
	StSelectPrds -> AddDialogAgent (m_piPrdAgt);
	StSelectPrds -> AddDialogAgent (m_piPointSLAgt);
	StSelectPrds -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPrds -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectPoints = AddDialogState("选择安装点");
	StSelectPoints -> AddDialogAgent (m_piPointsAgt);
	StSelectPoints -> AddDialogAgent (m_piPointSLAgt);
	StSelectPoints -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPoints -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPoints -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPoints -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectPointGSM = AddDialogState("选择点几何图形集");
	StSelectPointGSM -> AddDialogAgent (m_piPointGSMAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPointSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectFirstSurf = AddDialogState("选择第一安装面");
	StSelectFirstSurf -> AddDialogAgent (m_piFirstSurfAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPointSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPrdSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectSecSurf = AddDialogState("选择第二安装面");
	StSelectSecSurf -> AddDialogAgent (m_piSecSurfAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPointSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPrdSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPointGSMPBAgt);

	//转换关系 点到点
	AddTransition(StSelectPoints, StSelectPoints, 
		IsLastModifiedAgentCondition(m_piPointsAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePoints));

	//转换关系 点到点
	AddTransition(StSelectPoints, StSelectPoints, 
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//转换关系 点到面1
	AddTransition(StSelectPoints, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	//转换关系 点到面2
	AddTransition(StSelectPoints, StSelectSecSurf, 
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//转换关系 面1到点
	AddTransition(StSelectFirstSurf,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//转换关系 面2到点
	AddTransition(StSelectSecSurf,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//转换关系 面1到面1
	AddTransition(StSelectFirstSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChooseFirstSurfs));

	//转换关系 面1到面1
	AddTransition(StSelectFirstSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	//转换关系 面2到面2
	AddTransition(StSelectSecSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChooseSecSurfs));

	//转换关系 面2到面2
	AddTransition(StSelectSecSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//转换关系 面1到面2
	AddTransition(StSelectFirstSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//转换关系 面2到面1
	AddTransition(StSelectSecSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	// [11/18/2011 zhangwenyang]
	//转换关系 Prd Prd
	AddTransition(StSelectPrds,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePrds));
	//转换关系 Prd Prd
	AddTransition(StSelectPrds,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//转换关系 GSM GSM
	AddTransition(StSelectPointGSM,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePointGSM));

	//转换关系 GSM GSM
	AddTransition(StSelectPointGSM,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//转换关系 Prd GSM
	AddTransition(StSelectPrds,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//转换关系 GSM Prd
	AddTransition(StSelectPointGSM,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	// [11/18/2011 zhangwenyang]
	//转换关系 Prd 点
	AddTransition(StSelectPrds,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));
	//转换关系 点 Prd 
	AddTransition(StSelectPoints,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//转换关系 Prd 面1
	AddTransition(StSelectPrds, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));
	//转换关系 面1 Prd 
	AddTransition(StSelectFirstSurf,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//转换关系 Prd 面2
	AddTransition(StSelectPrds,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));
	//转换关系 面2 Prd 
	AddTransition(StSelectSecSurf,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	// [11/18/2011 zhangwenyang]
	//转换关系 GSM 点
	AddTransition(StSelectPointGSM,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));
	//转换关系 点 GSM 
	AddTransition(StSelectPoints,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));
	
	//转换关系 GSM 面1
	AddTransition(StSelectPointGSM, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));
	//转换关系 面1 GSM 
	AddTransition(StSelectFirstSurf,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//转换关系 GSM 面2
	AddTransition(StSelectPointGSM,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));
	//转换关系 面2 GSM 
	AddTransition(StSelectSecSurf,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));


}

void PrtFstDesignCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	if (NULL != m_piDlg)
	{
		m_piDlg->RequestDelayedDestruction();
		m_piDlg = NULL;
	}	

	RequestDelayedDestruction();

}
void PrtFstDesignCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	if (NULL != m_piDlg)
	{
		m_piDlg->RequestDelayedDestruction();
		m_piDlg = NULL;
	}	

	RequestDelayedDestruction();
}

//判断是否为ZP模型
BOOL PrtFstDesignCmd::IsThisZPPrt()
{
	if (m_strDocName != "")
	{
		int istart=m_strDocName.SearchSubString("-ZP",0,CATUnicodeString::CATSearchModeBackward);
		if (istart == (m_strDocName.GetLengthInChar()-3) || istart == (m_strDocName.GetLengthInChar()-4))
		{
			return TRUE;
		}
		else return FALSE;
	}
	else return FALSE;
}

//各种转换消息响应函数
CATBoolean PrtFstDesignCmd::ChoosePoints( void *UsefulData)
{
	//定义集群
	CATSO * pSO = NULL ;
	pSO = m_piPointsAgt->GetListOfValues();
	if ( NULL != pSO )
	{
		int lg = pSO->GetSize();
		for ( int i=0 ; i < lg ; i++)
		{
			CATPathElement * pPath = (CATPathElement*) (*pSO)[i];
			CATPathElement * pSubPath = NULL;

			CATBaseUnknown * pLeaf =NULL ;
			if ( NULL != pPath )
				pSubPath = pPath->GetSubPath("CATISpecObject");
			pLeaf = (*pSubPath)[pSubPath->GetSize()-1];

			CATISpecObject_var spLeaf = pLeaf;
			BOOL existFlag = FALSE;
			for (int j = 1; j <= m_lstSpecPoints.Size(); j++)
			{
				if (m_lstSpecPoints[j] == spLeaf)
				{
					existFlag = TRUE;
					break;
				}
			}
			if (!existFlag) //不存在放入
			{
				//先清空列表
				if (m_lstSpecPoints.Size() == 0)
				{
					m_piDlg->_PointsSL->ClearLine();
				}
				//
				m_lstSpecPoints.Append(spLeaf);

				//
				CATUnicodeString strShowPath("");
				strShowPath = spLeaf->GetDisplayName();
				PrtService::PathElementString(pSubPath,strShowPath,TRUE);
				m_piDlg->_PointsSL->SetLine(strShowPath);
			}
			
		}
	}

	//清空列表选择状态
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	m_piPointsAgt->InitializeAcquisition();
	return TRUE;

}

CATBoolean PrtFstDesignCmd::ChooseFirstSurfs( void *UsefulData)
{
	HRESULT hr = E_FAIL;
	CATBaseUnknown* piSelectElement =m_piFirstSurfAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		CATISpecObject_var spSpecOnSelection = NULL_var;
		spSpecOnSelection = piSelectElement;

		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean exitFlag = FALSE;
			for (int i = 1; i <= m_lstSpecFirstSurfs.Size(); i ++)
			{
				if (m_lstSpecFirstSurfs[i] == spSpecOnSelection)
				{
					m_lstSpecFirstSurfs.RemoveValue(spSpecOnSelection);
					PrtService::RemoveHSO(spSpecOnSelection);
					exitFlag = TRUE;
					break;
				}
			}

			if (exitFlag == FALSE)
			{
				m_lstSpecFirstSurfs.Append(spSpecOnSelection);
				PrtService::HighlightHSO(spSpecOnSelection);
			}

			if (m_lstSpecFirstSurfs.Size()>=1)
			{
				CATUnicodeString strLineShow("共选择");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecFirstSurfs.Size());
				strLineShow += strNumber + "个面";
				m_piDlg->_FirstSurfSL->SetLine(strLineShow,0,CATDlgDataModify);
			}
			if (m_lstSpecFirstSurfs.Size()==0)
			{
				m_piDlg->_FirstSurfSL->SetLine("请选择面",0,CATDlgDataModify);
			}
		}
	}

	//
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();
	int firstRom = 0;
	m_piDlg->_FirstSurfSL->SetSelect(&firstRom,1,0);

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;	
}

CATBoolean PrtFstDesignCmd::ChooseSecSurfs( void *UsefulData)
{

	HRESULT hr = E_FAIL;
	CATBaseUnknown* piSelectElement =m_piSecSurfAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		CATISpecObject_var spSpecOnSelection = NULL_var;
		spSpecOnSelection = piSelectElement;

		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean exitFlag = FALSE;
			for (int i = 1; i <= m_lstSpecSecSurfs.Size(); i ++)
			{
				if (m_lstSpecSecSurfs[i] == spSpecOnSelection)
				{
					m_lstSpecSecSurfs.RemoveValue(spSpecOnSelection);
					PrtService::RemoveHSO(spSpecOnSelection);
					exitFlag = TRUE;
					break;
				}
			}

			if (exitFlag == FALSE)
			{
				m_lstSpecSecSurfs.Append(spSpecOnSelection);
				PrtService::HighlightHSO(spSpecOnSelection);
			}
			
			if (m_lstSpecSecSurfs.Size()>=1)
			{
				CATUnicodeString strLineShow("共选择");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecSecSurfs.Size());
				strLineShow += strNumber + "个面";
				m_piDlg->_SecondSurfSL->SetLine(strLineShow,0,CATDlgDataModify);
			}
			if (m_lstSpecSecSurfs.Size()==0)
			{
				m_piDlg->_SecondSurfSL->SetLine("请选择面",0,CATDlgDataModify);
			}
		}
	}

	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	int firstRom = 0;
	m_piDlg->_SecondSurfSL->SetSelect(&firstRom,1,0);

	m_piSecSurfAgt->InitializeAcquisition();
	return TRUE;	

}


//激活相关代理
CATBoolean PrtFstDesignCmd::ActivePointsSL( void *UsefulData)
{
	//清除选择
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	m_piPointsAgt->InitializeAcquisition();
	return TRUE;	
}
CATBoolean PrtFstDesignCmd::ActiveFirstSurfSL( void *UsefulData)
{
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstDesignCmd::ActiveSecSurfSL( void *UsefulData)
{
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	m_piSecSurfAgt->InitializeAcquisition();
	return TRUE;
}

CATBoolean PrtFstDesignCmd::ActivePrdSL( void *UsefulData)
{
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();

	m_piPrdAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstDesignCmd::ActivePointGSMPB( void *UsefulData)
{
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_PrdSL->ClearSelect();

	m_piPointGSMAgt->InitializeAcquisition();
	return TRUE;
}

//响应
CATBoolean PrtFstDesignCmd::ChoosePrds( void *UsefulData)
{
	HRESULT hr = E_FAIL;
	CATBaseUnknown* piSelectElement =m_piPrdAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		CATISpecObject_var spSpecOnSelection = NULL_var;
		spSpecOnSelection = piSelectElement;

		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean exitFlag = FALSE;
			for (int i = 1; i <= m_lstSpecPrds.Size(); i ++)
			{
				if (m_lstSpecPrds[i] == spSpecOnSelection)
				{
					m_lstSpecPrds.RemoveValue(spSpecOnSelection);
					exitFlag = TRUE;
					break;
				}
			}

			if (exitFlag == FALSE)
			{
				m_lstSpecPrds.Append(spSpecOnSelection);				
			}

			m_piDlg->_PrdSL->ClearLine();
			for (int i = 1; i <= m_lstSpecPrds.Size(); i ++)
			{
				CATIAlias_var spAlias = m_lstSpecPrds[i];
				CATUnicodeString strAlias = spAlias->GetAlias();
				m_piDlg->_PrdSL->SetLine(strAlias);
			}

			if (m_lstSpecPrds.Size()==0)
			{
				m_piDlg->_PrdSL->SetLine("请选择连接零件");
			}
		}
	}

	//
	m_piDlg->_PointsSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;	
}

CATBoolean PrtFstDesignCmd::ChoosePointGSM( void *UsefulData)
{



	m_piDlg->_PrdSL->ClearSelect();
	m_piDlg->_FirstSurfSL->ClearSelect();
	m_piDlg->_SecondSurfSL->ClearSelect();

	m_piPointGSMAgt->InitializeAcquisition();
	return TRUE;
}

CATBoolean PrtFstDesignCmd::SeletedIsPart(CATDialogAgent * iAgent, void * iUsefulData)
{
	CATBoolean rc = FALSE ;
	if ( NULL == iAgent ) return rc ;

	CATBaseUnknown* piSelectElement =m_piPrdAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		CATIProduct_var spPrd = NULL_var;
		spPrd = piSelectElement;

		CATUnicodeString strDocType("");
		PrdService::GetInstPrdType(spPrd,strDocType);

		if (strDocType == "CATPart")
		{
			return TRUE;
		}
	}

	return rc;
}

