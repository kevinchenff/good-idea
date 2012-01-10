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






//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstPointsCmd::PrtFstPointsCmd() :
  CATStateCommand ("PrtFstPointsCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_pDlg(NULL),m_pCurveAgt(NULL),m_pSurfAgt(NULL),m_pCurveSLAgt(NULL),m_pSurfSLAgt(NULL)
  ,m_SpecSurfs(NULL_var)
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

	// ���Ի������Ϣ��Ӧ
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

	//�������ߴ���
	m_pCurveAgt = new CATFeatureImportAgent("ѡ�����");
	m_pCurveAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat );
	m_pCurveAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_pCurveAgt -> AddElementType (IID_CATIMfMonoDimResult);
	m_pCurveAgt -> AddElementType (IID_CATCurve);

	//������װ�����
	m_pSurfAgt = new CATFeatureImportAgent("ѡ��װ��");
	m_pSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat );
	m_pSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_pSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_pSurfAgt -> AddElementType (IID_CATSurface);

	//Curve SL
	m_pCurveSLAgt = new CATDialogAgent("ѡ�����SL");
	m_pCurveSLAgt->SetBehavior(CATDlgEngRepeat);
	m_pCurveSLAgt->AcceptOnNotify(m_pDlg->_CurveSL,m_pDlg->_CurveSL->GetListSelectNotification());

	//Surf SL
	m_pSurfSLAgt = new CATDialogAgent("ѡ��װ��SL");
	m_pSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_pSurfSLAgt->AcceptOnNotify(m_pDlg->_SurfSL,m_pDlg->_SurfSL->GetListSelectNotification());


	//Define the StateChart
	CATDialogState * StSelectCurve = GetInitialState("ѡ�����");
	StSelectCurve -> AddDialogAgent (m_pCurveAgt);
	StSelectCurve -> AddDialogAgent (m_pCurveSLAgt);
	StSelectCurve -> AddDialogAgent (m_pSurfSLAgt);

	CATDialogState * StSelectSurf = AddDialogState("ѡ��װ��");
	StSelectSurf -> AddDialogAgent (m_pSurfAgt);
	StSelectSurf -> AddDialogAgent (m_pCurveSLAgt);
	StSelectSurf -> AddDialogAgent (m_pSurfSLAgt);

	//ת����ϵ �ߵ���
	AddTransition(StSelectCurve, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ChooseCurve));
	//ת����ϵ �ߵ���
	AddTransition(StSelectCurve, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveCurveSL));

	//ת����ϵ �浽��
	AddTransition(StSelectSurf, StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ChooseSurf));
	//ת����ϵ �浽��SL
	AddTransition(StSelectSurf, StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveSurfSL));

	//ת����ϵ �浽��
	AddTransition(StSelectSurf, StSelectCurve, 
		IsLastModifiedAgentCondition(m_pCurveSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveCurveSL));
	//ת����ϵ �ߵ���
	AddTransition(StSelectCurve,StSelectSurf, 
		IsLastModifiedAgentCondition(m_pSurfSLAgt),
		Action ((ActionMethod) &PrtFstPointsCmd::ActiveSurfSL));
	
}

//��Ϣ����Ӧ����
void PrtFstPointsCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	HRESULT rc = S_OK;
	//����ĵ�ָ��
	CATDocument * pDoc = PrtService::GetPrtDocument();
	CATIGSMFactory_var iospGSMFact = NULL_var;
	PrtService::GetGSMFactory(pDoc,iospGSMFact);

	//��������ͼ�μ�
	CATISpecObject_var ospFatGSSpecObj = NULL_var;
	PrtService::ObtainGSMTool(pDoc,"����Ԫ��",ospFatGSSpecObj);
	CATIPrtContainer *opiRootContainer = NULL;
	PrtService::ObtainRootContainer(pDoc,opiRootContainer);
	if (ospFatGSSpecObj == NULL_var)
	{
		//�������򴴽�
		int oDiag = 0 ;
		PrtService::CAAGsiCreateGeometricFeatureSets(opiRootContainer,"����Ԫ��",NULL_var,ospFatGSSpecObj,oDiag,1,0);
	}
	//��������ͼ�μ����õ㼯��
	CATISpecObject_var spPointGSMTool = NULL_var;
	int oDiag = 0 ;
	PrtService::CAAGsiCreateGeometricFeatureSets(opiRootContainer,"��װ�㼯��",ospFatGSSpecObj,spPointGSMTool,oDiag,0,0);

	//����ƫ����
	CATISpecObject_var spInputCurve = NULL_var;
	if (m_lstSpecCurves.Size() >= 2)
	{
		spInputCurve = iospGSMFact->CreateAssemble(m_lstSpecCurves,NULL_var,TRUE);
		PrtService::CAAGsiInsertInProceduralView(spInputCurve,spPointGSMTool);
		PrtService::SetAlias(spInputCurve,"����");
		PrtService::SetSpecObjShowAttr(spInputCurve,"Hide");
		rc = PrtService::ObjectUpdate(spInputCurve);
		if (FAILED(rc))
		{
			PrtService::ShowDlgNotify("������ʾ","��ѡ�߼��Ϸ���ͨ��������ѡ��!");
			spInputCurve->GetFather()->Remove(spInputCurve);
			spPointGSMTool->GetFather()->Remove(spPointGSMTool);
			return;
		}
	}
	else if (m_lstSpecCurves.Size() == 1)
	{
		spInputCurve = m_lstSpecCurves[1];
	}

	//����ƫ����
	double dOffsetValue = m_pDlg->_DistanceSpinner->GetValue();
	dOffsetValue *= 1000.0;
	CATICkeParm_var spCkeOffset = NULL_var;
	spCkeOffset = PrtService::LocalInstLitteral(&dOffsetValue,1,"Length","Length");
	CATISpecObject_var spCurvePar = NULL_var;
	spCurvePar = iospGSMFact->CreateCurvePar(spInputCurve,m_SpecSurfs,spCkeOffset,FALSE);
	PrtService::CAAGsiInsertInProceduralView(spCurvePar,spPointGSMTool);
	PrtService::SetAlias(spCurvePar,"�Ų���");
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
		PrtService::ShowDlgNotify("������ʾ","��ѡ������ѡ��װ�����޷�����ƽ����!");
		spCurvePar->GetFather()->Remove(spCurvePar);
		spPointGSMTool->GetFather()->Remove(spPointGSMTool);
		return;	
	}
	
	//��ý������õĲ���
	//if (m_pDlg->_NumPointRB->GetState() == CATDlgCheck)
	//{
	//	//���ѡ�� ����ģʽ
	//	double odNumValue = 0;
	//	odNumValue = m_pDlg->_NumSpinner->GetValue();
	//	//��ó���ֵ
	//	CATIMeasurableCurve_var spMeasCurve = NULL_var;
	//	spMeasCurve = spInputCurve;
	//	if (spMeasCurve != NULL_var)
	//	{
	//		double dCrvLength = 0;
	//		spMeasCurve->GetLength(dCrvLength);
	//	}
	//} 
	//else
	//{
	//	//���ѡ�� ���ģʽ
	//}



	//������
	for (int i = 1; i <= m_lstSpecCurves.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecCurves[i],"Hide");
	}

	//������
	PrtService::SetSpecObjShowAttr(m_SpecSurfs,"Hide");

	RequestDelayedDestruction();
}
void PrtFstPointsCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//������
	for (int i = 1; i <= m_lstSpecCurves.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecCurves[i],"Hide");
	}

	//������
	PrtService::SetSpecObjShowAttr(m_SpecSurfs,"Hide");

	RequestDelayedDestruction();
}

//
CATBoolean PrtFstPointsCmd::ChooseCurve( void *UsefulData)
{
	HRESULT hr = E_FAIL;

	CATBaseUnknown* piSelectElement =m_pCurveAgt->GetElementValue();//�����ѡ����
	if (piSelectElement != NULL)
	{
		//���SUB PATH
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

		//��������ж�
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
				CATUnicodeString strLineShow("��ѡ��");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecCurves.Size());
				strLineShow += strNumber + "����";
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

	CATBaseUnknown* piSelectElement =m_pSurfAgt->GetElementValue();//�����ѡ����
	if (piSelectElement != NULL)
	{
		//���SUB PATH
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

		//��������ж�
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
	//������ѡ��
	PrtService::ClearHSO();
	PrtService::HighLightObjLst(m_lstSpecCurves);

	//
	m_pDlg->_SurfSL->ClearSelect();

	m_pCurveAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstPointsCmd::ActiveSurfSL( void *UsefulData)
{
	//������ѡ��
	PrtService::ClearHSO();
	PrtService::HighlightHSO(m_SpecSurfs);

	//
	m_pDlg->_CurveSL->ClearSelect();

	m_pSurfAgt->InitializeAcquisition();
	return TRUE;
}