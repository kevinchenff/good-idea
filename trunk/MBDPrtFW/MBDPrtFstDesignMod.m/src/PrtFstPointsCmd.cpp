// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstPointsCmd.cpp
// The state chart based command: PrtFstPointsCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#include "PrtFstPointsCmd.h"
#include "CATIndicationAgent.h"
#include "CATMathPlane.h"

#include "CATCreateExternalObject.h"
CATCreateClass( PrtFstPointsCmd);

#include "iostream"
using namespace std;

#include "CATLine.h"
#include "CATSurface.h"
#include "CATIMfBiDimResult.h"
#include "CATIMfMonoDimResult.h"
#include "CATCurve.h"
#include "PrtService.h"
#include "CATIMfBRep.h"
#include "CATIGSMAssemble.h"
#include "CATIGSMCurvePar.h"
#include "CATIMeasurableCurve.h"
#include "CATIGSMExtremum.h"


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstPointsCmd::PrtFstPointsCmd() :
  CATStateCommand ("PrtFstPointsCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_pDlg(NULL),m_pCurveAgt(NULL),m_pSurfAgt(NULL),m_pCurveSLAgt(NULL),m_pSurfSLAgt(NULL)
  ,m_SpecSurfs(NULL_var),m_piDoc(NULL)
{
	//初始化获得当前文档及名称
	m_piDoc = PrtService::GetPrtDocument();
	PrtService::GetPrdNumberFormDoc(m_piDoc,m_strDocName);

	//判断是否为ZP模型;
	if ((!IsThisZPPrt(m_strDocName))||(!PrdService::IsContextualPrd()))
	{
		PrtService::ShowDlgNotify("提示","该功能仅在装配上下文环境且ZP模型中操作，点击关闭！");
		RequestDelayedDestruction();
	}
}

//判断是否为ZP模型
BOOL PrtFstPointsCmd::IsThisZPPrt(CATUnicodeString istrDocName)
{
	  if (istrDocName != "")
	  {
		  int istart=istrDocName.SearchSubString("-ZP",0,CATUnicodeString::CATSearchModeBackward);
		  if (istart != -1)
		  {
			  return TRUE;
		  }
		  else return FALSE;
	  }
	  else return FALSE;
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstPointsCmd::~PrtFstPointsCmd()
{
	if (NULL!=m_pDlg)
	{
		m_pDlg->RequestDelayedDestruction();
		m_pDlg=NULL;
	}

	if (NULL!=m_pCurveAgt)
	{
		m_pCurveAgt->RequestDelayedDestruction();
		m_pCurveAgt=NULL;
	}

	if (NULL!=m_pSurfAgt)
	{
		m_pSurfAgt->RequestDelayedDestruction();
		m_pSurfAgt=NULL;
	}

	if (NULL!=m_pCurveSLAgt)
	{
		m_pCurveSLAgt->RequestDelayedDestruction();
		m_pCurveSLAgt=NULL;
	}

	if (NULL!=m_pSurfSLAgt)
	{
		m_pSurfSLAgt->RequestDelayedDestruction();
		m_pSurfSLAgt=NULL;
	}
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void PrtFstPointsCmd::BuildGraph()
{
	//
	m_pDlg = new PrtFstPointsDlg();
	m_pDlg->Build();
	m_pDlg->SetVisibility(CATDlgShow); 

	// 主对话框的消息响应
	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaOKNotification(),
		(CATCommandMethod)&PrtFstPointsCmd::OkDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetWindCloseNotification(),
		(CATCommandMethod)&PrtFstPointsCmd::CloseDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaCANCELNotification(),
		(CATCommandMethod)&PrtFstPointsCmd::CloseDlgCB,
		NULL);

	//创建边线代理
	m_pCurveAgt = new CATFeatureImportAgent("选择边线");
	m_pCurveAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat );
	m_pCurveAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_pCurveAgt -> AddElementType (IID_CATIMfMonoDimResult);
	m_pCurveAgt -> AddElementType (IID_CATCurve);

	//创建安装面代理
	m_pSurfAgt = new CATFeatureImportAgent("选择安装面");
	m_pSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat );
	m_pSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_pSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_pSurfAgt -> AddElementType (IID_CATSurface);

	//Curve SL
	m_pCurveSLAgt = new CATDialogAgent("选择边线SL");
	m_pCurveSLAgt->SetBehavior(CATDlgEngRepeat);
	m_pCurveSLAgt->AcceptOnNotify(m_pDlg->_CurveSL,m_pDlg->_CurveSL->GetListSelectNotification());

	//Surf SL
	m_pSurfSLAgt = new CATDialogAgent("选择安装面SL");
	m_pSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_pSurfSLAgt->AcceptOnNotify(m_pDlg->_SurfSL,m_pDlg->_SurfSL->GetListSelectNotification());


	//Define the StateChart
	CATDialogState * StSelectCurve = GetInitialState("选择边线");
	StSelectCurve -> AddDialogAgent (m_pCurveAgt);
	StSelectCurve -> AddDialogAgent (m_pCurveSLAgt);
	StSelectCurve -> AddDialogAgent (m_pSurfSLAgt);

	CATDialogState * StSelectSurf = AddDialogState("选择安装面");
	StSelectSurf -> AddDialogAgent (m_pSurfAgt);
	StSelectSurf -> AddDialogAgent (m_pCurveSLAgt);
	StSelectSurf -> AddDialogAgent (m_pSurfSLAgt);

	//转换关系 线到线
	AddTransition(StSelectCurve, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ChooseCurve));
	//转换关系 线到线
	AddTransition(StSelectCurve, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveCurveSL));

	//转换关系 面到面
	AddTransition(StSelectSurf, StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ChooseSurf));
	//转换关系 面到面SL
	AddTransition(StSelectSurf, StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveSurfSL));

	//转换关系 面到线
	AddTransition(StSelectSurf, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveCurveSL));
	//转换关系 线到面
	AddTransition(StSelectCurve,StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveSurfSL));
	
}

//消息框响应函数
void PrtFstPointsCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	HRESULT rc = S_OK;
	//获得文档指针
	CATDocument * pDoc = PrtService::GetPrtDocument();
	CATIGSMFactory_var iospGSMFact = NULL_var;
	PrtService::GetGSMFactory(pDoc,iospGSMFact);

	//创建几何图形集
	CATISpecObject_var ospFatGSSpecObj = NULL_var;
	PrtService::ObtainGSMTool(pDoc,"过程元素",ospFatGSSpecObj);
	CATIPrtContainer *opiRootContainer = NULL;
	PrtService::ObtainRootContainer(pDoc,opiRootContainer);
	//获得part
	CATISpecObject_var spPart = opiRootContainer->GetPart();
	if (ospFatGSSpecObj == NULL_var)
	{
		//不存在则创建
		int oDiag = 0 ;
		PrtService::CAAGsiCreateGeometricFeatureSets(opiRootContainer,"过程元素",NULL_var,ospFatGSSpecObj,oDiag,1,0);
	}
	//创建几何图形集放置点集合
	CATISpecObject_var spPointGSMTool = NULL_var;
	int oDiag = 0 ;
	PrtService::CAAGsiCreateGeometricFeatureSets(opiRootContainer,"安装点集合",ospFatGSSpecObj,spPointGSMTool,oDiag,0,0);

	//创建偏移线
	CATISpecObject_var spInputCurve = NULL_var;
	if (m_lstSpecCurves.Size() >= 2)
	{
		spInputCurve = iospGSMFact->CreateAssemble(m_lstSpecCurves,NULL_var,TRUE);
		PrtService::CAAGsiInsertInProceduralView(spInputCurve,spPointGSMTool);
		PrtService::SetAlias(spInputCurve,"基线");
		PrtService::SetSpecObjShowAttr(spInputCurve,"Hide");
		rc = PrtService::ObjectUpdate(spInputCurve);
		if (FAILED(rc))
		{
			PrtService::ShowDlgNotify("错误提示","所选线集合非连通，请重新选择!");
			spInputCurve->GetFather()->Remove(spInputCurve);
			spPointGSMTool->GetFather()->Remove(spPointGSMTool);
			return;
		}
	}
	else if (m_lstSpecCurves.Size() == 1)
	{
		spInputCurve = m_lstSpecCurves[1];
	}

	//创建偏移线
	double dOffsetValue = m_pDlg->_DistanceSpinner->GetValue();
	dOffsetValue *= 1000.0;
	CATICkeParm_var spCkeOffset = NULL_var;
	spCkeOffset = PrtService::LocalInstLitteral(&dOffsetValue,1,"Length","Length");
	CATISpecObject_var spCurvePar = NULL_var;
	spCurvePar = iospGSMFact->CreateCurvePar(spInputCurve,m_SpecSurfs,spCkeOffset,FALSE);
	PrtService::CAAGsiInsertInProceduralView(spCurvePar,spPointGSMTool);
	PrtService::SetAlias(spCurvePar,"排布线");
	PrtService::SetSpecObjShowAttr(spCurvePar,"Hide");
	rc = PrtService::ObjectUpdate(spCurvePar);
	if (FAILED(rc))
	{
		CATIGSMCurvePar_var spGSMPar = spCurvePar;
		spGSMPar->SetInvertDirection(TRUE);
	}
	rc = PrtService::ObjectUpdate(spCurvePar);
	if (FAILED(rc))
	{
		PrtService::ShowDlgNotify("错误提示","所选线在算选安装面上无法生成平行线!");
		spCurvePar->GetFather()->Remove(spCurvePar);
		spPointGSMTool->GetFather()->Remove(spPointGSMTool);
		return;	
	}
	
	//获得交付设置的参数
	if (m_pDlg->_NumPointRB->GetState() == CATDlgCheck)
	{
		//如果选择 点数模式
		double odNumValue = 0;
		odNumValue = m_pDlg->_NumSpinner->GetValue();
		//
		if (odNumValue == 0)
		{
			PrtService::ShowDlgNotify("错误提示","所设置点数不能为0!");
			return;	
		}
		//获得长度值
		CATIMeasurableCurve_var spMeasCurve = NULL_var;
		spMeasCurve = spCurvePar;
		if (spMeasCurve != NULL_var)
		{
			double dCrvLength = 0;
			spMeasCurve->GetLength(dCrvLength);
			//
			double dDistanceV = dCrvLength/(odNumValue+1);
			//
			CATBoolean pointErrFlag = FALSE;
			//
			for (int i=1; i <= odNumValue; i ++)
			{
				double dDistValues = i*dDistanceV;
				CATICkeParm_var spCkedDistanceV = NULL_var;
				spCkedDistanceV = PrtService::LocalInstLitteral(&dDistValues,1,"Length","Length");
				//
				CATISpecObject_var spPoint = iospGSMFact->CreatePoint(spCurvePar,NULL_var,spCkedDistanceV,CATGSMSameOrientation);
				PrtService::CAAGsiInsertInProceduralView(spPoint,spPointGSMTool);
				//
				rc = PrtService::ObjectUpdate(spPoint);
				if (FAILED(rc))
				{
					spPoint->GetFather()->Remove(spPoint);
					pointErrFlag = TRUE;
				}
			}
			//
			if (pointErrFlag == TRUE)
			{
				PrtService::ShowDlgNotify("错误提示","所选线不能为闭合曲线，无法生存安装点，请重新选择!");
				return;
			}
			
		}
	} 
	else
	{
		//如果选择 间距模式
		double odGapValue = 0;
		odGapValue = m_pDlg->_PointDistSpinner->GetValue();
		odGapValue *= 1000.0;
		//
		if (odGapValue == 0)
		{
			PrtService::ShowDlgNotify("错误提示","所设置点间隙值不能为0!");
			return;	
		}
		//获得长度值
		CATIMeasurableCurve_var spMeasCurve = NULL_var;
		spMeasCurve = spCurvePar;
		if (spMeasCurve != NULL_var)
		{
			double dCrvLength = 0;
			spMeasCurve->GetLength(dCrvLength);
			//
			double odNumValue = (int)(dCrvLength/odGapValue)-1;
			//
			CATBoolean pointErrFlag = FALSE;
			//
			for (int i=1; i <= odNumValue; i ++)
			{
				double dDistValues = i*odGapValue;
				CATICkeParm_var spCkedDistanceV = NULL_var;
				spCkedDistanceV = PrtService::LocalInstLitteral(&dDistValues,1,"Length","Length");
				//
				CATISpecObject_var spPoint = iospGSMFact->CreatePoint(spCurvePar,NULL_var,spCkedDistanceV,CATGSMSameOrientation);
				PrtService::CAAGsiInsertInProceduralView(spPoint,spPointGSMTool);
				//
				rc = PrtService::ObjectUpdate(spPoint);
				if (FAILED(rc))
				{
					spPoint->GetFather()->Remove(spPoint);
					pointErrFlag = TRUE;
				}
			}
			//
			if (pointErrFlag == TRUE)
			{
				PrtService::ShowDlgNotify("错误提示","所选线不能为闭合曲线，无法生存安装点，请重新选择!");
				return;
			}
		}

	}
	PrtService::ObjectUpdate(spPart);

	//隐藏线
	for (int i = 1; i <= m_lstSpecCurves.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecCurves[i],"Hide");
	}

	//隐藏面
	PrtService::SetSpecObjShowAttr(m_SpecSurfs,"Hide");

	RequestDelayedDestruction();
}
void PrtFstPointsCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//隐藏线
	for (int i = 1; i <= m_lstSpecCurves.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecCurves[i],"Hide");
	}

	//隐藏面
	PrtService::SetSpecObjShowAttr(m_SpecSurfs,"Hide");

	RequestDelayedDestruction();
}

//
CATBoolean PrtFstPointsCmd::ChooseCurve( void *UsefulData)
{
	HRESULT hr = E_FAIL;

	CATBaseUnknown* piSelectElement =m_pCurveAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		//获得SUB PATH
		CATIMfBRep *piBrep = NULL;
		hr = piSelectElement->QueryInterface(IID_CATIMfBRep,(void**)&piBrep);
		//
		CATISpecObject_var spSpecOnSelection =NULL_var;
		if (SUCCEEDED(hr)&&(piBrep!=NULL))
		{
			spSpecOnSelection = piBrep->GetSupport();
			piBrep->Release();
			piBrep=NULL;
		}
		else
		{
			spSpecOnSelection = piSelectElement;
		}

		//根据情况判断
		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean existFlag = FALSE;
			for (int i = 1; i <= m_lstSpecCurves.Size(); i ++)
			{
				if (m_lstSpecCurves[i] == spSpecOnSelection)
				{
					m_lstSpecCurves.RemoveValue(spSpecOnSelection);
					PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Hide");
					PrtService::RemoveHSO(spSpecOnSelection);
					existFlag = TRUE;
					break;
				}
			}

			if (existFlag == FALSE)
			{		
				PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Show");
				m_lstSpecCurves.Append(spSpecOnSelection);
				PrtService::HighlightHSO(spSpecOnSelection);				
			}

			if (m_lstSpecCurves.Size()>=1)
			{
				CATUnicodeString strLineShow("共选择");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecCurves.Size());
				strLineShow += strNumber + "个线";
				m_pDlg->_CurveSL->SetLine(strLineShow,0,CATDlgDataModify);
			}
			if (m_lstSpecCurves.Size()==0)
			{
				m_pDlg->_CurveSL->SetLine("No Selection",0,CATDlgDataModify);
			}
		}
	}

	//
	m_pDlg->_SurfSL->ClearSelect();
	
	m_pCurveAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstPointsCmd::ChooseSurf( void *UsefulData)
{
	HRESULT hr = E_FAIL;

	CATBaseUnknown* piSelectElement =m_pSurfAgt->GetElementValue();//获得所选对象
	if (piSelectElement != NULL)
	{
		//获得SUB PATH
		CATIMfBRep *piBrep = NULL;
		hr = piSelectElement->QueryInterface(IID_CATIMfBRep,(void**)&piBrep);
		//
		CATISpecObject_var spSpecOnSelection =NULL_var;
		if (SUCCEEDED(hr)&&(piBrep!=NULL))
		{
			spSpecOnSelection = piBrep->GetSupport();
			piBrep->Release();
			piBrep=NULL;
		}
		else
		{
			spSpecOnSelection = piSelectElement;
		}

		//根据情况判断
		if ( spSpecOnSelection != NULL_var )
		{
			if (m_SpecSurfs == spSpecOnSelection)
			{
				PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Hide");
				PrtService::RemoveHSO(spSpecOnSelection);
				m_pDlg->_SurfSL->SetLine("No Selection",0,CATDlgDataModify);
				m_SpecSurfs = NULL_var;
			}	
			else
			{	
				PrtService::SetSpecObjShowAttr(m_SpecSurfs,"Hide");
				PrtService::RemoveHSO(m_SpecSurfs);
				PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Show");
				PrtService::HighlightHSO(spSpecOnSelection);
				m_SpecSurfs = spSpecOnSelection;
				//
				CATUnicodeString strShowPath("");
				CATPathElement *piPath = NULL;
				PrtService::GetPathElementFromSpecObject(piPath,spSpecOnSelection,NULL);
				PrtService::PathElementString(piPath,strShowPath,TRUE);
				m_pDlg->_SurfSL->SetLine(strShowPath,0,CATDlgDataModify);

				piPath->Release();
				piPath=NULL;
			}
		}
	}

	//
	m_pDlg->_CurveSL->ClearSelect();

	m_pSurfAgt->InitializeAcquisition();
	return TRUE;
}
//
CATBoolean PrtFstPointsCmd::ActiveCurveSL( void *UsefulData)
{
	//高亮所选线
	PrtService::ClearHSO();
	PrtService::HighLightObjLst(m_lstSpecCurves);

	//
	m_pDlg->_SurfSL->ClearSelect();

	m_pCurveAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstPointsCmd::ActiveSurfSL( void *UsefulData)
{
	//高亮所选面
	PrtService::ClearHSO();
	PrtService::HighlightHSO(m_SpecSurfs);

	//
	m_pDlg->_CurveSL->ClearSelect();

	m_pSurfAgt->InitializeAcquisition();
	return TRUE;
}
