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


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstPointsCmd::PrtFstPointsCmd() :
  CATStateCommand ("PrtFstPointsCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_pDlg(NULL),m_pCurveAgt(NULL),m_pSurfAgt(NULL),m_pCurveSLAgt(NULL),m_pSurfSLAgt(NULL)
{
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
	RequestDelayedDestruction();
}
void PrtFstPointsCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	RequestDelayedDestruction();
}

//
CATBoolean PrtFstPointsCmd::ChooseCurve( void *UsefulData)
{

	m_pCurveAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstPointsCmd::ChooseSurf( void *UsefulData)
{

	m_pSurfAgt->InitializeAcquisition();
	return TRUE;
}
//
CATBoolean PrtFstPointsCmd::ActiveCurveSL( void *UsefulData)
{
	m_pCurveAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstPointsCmd::ActiveSurfSL( void *UsefulData)
{
	m_pSurfAgt->InitializeAcquisition();
	return TRUE;
}
