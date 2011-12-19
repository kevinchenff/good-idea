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
#include "CATISO.h"
#include "CAT3DAnnotationTextGP.h"
#include "CATIMeasurablePoint.h"
#include "CATModelForRep3D.h"
#include "CAT3DCustomRep.h"
#include "CATGraphicAttributeSet.h"
#include "CATIStructureAnalyse.h"
#include "CATIMmiMechanicalImportApplicative.h"
#include "CATIGSMIntersect.h"
#include "CATIGSMLineNormal.h"
#include "CAT3DMarkerGP.h"
#include "CAT3DFixedArrowGP.h"
#include "CATIMfBRep.h"
#include "CAT4x4Matrix.h"
//#include "CATIMmiInternalCopyWithLink.h"


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstDesignCmd::PrtFstDesignCmd() :
  CATStateCommand ("PrtFstDesignCmd", CATDlgEngOneShot, CATCommandModeShared) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
  ,m_pDlg(NULL),m_piDoc(NULL),m_piFirstSurfSLAgt(NULL),m_piSecSurfSLAgt(NULL),m_piPointSLAgt(NULL)
  ,m_piFirstSurfAgt(NULL),m_piSecSurfAgt(NULL),m_piPointsAgt(NULL),m_piPrdSLAgt(NULL),m_piPointGSMPBAgt(NULL),m_piPrdAgt(NULL)
  ,m_piPointGSMAgt(NULL),m_pi3DBagRep(NULL),m_piManipulator(NULL),m_piISO(NULL)
{
	//��ʼ����õ�ǰ�ĵ�������
	m_piDoc = PrtService::GetPrtDocument();
	PrtService::GetPrdNumberFormDoc(m_piDoc,m_strDocName);

	m_piEditor = CATFrmEditor::GetCurrentEditor();
	if (NULL != m_piEditor)
	{
		m_piHSO = m_piEditor->GetHSO();
		m_piHSO->Empty();

		m_piISO = m_piEditor->GetISO();
		m_piISO->Empty();
	}

	//�ж��Ƿ�ΪZPģ��;
	if (!IsThisZPPrt(m_strDocName))
	{
		PrtService::ShowDlgNotify("��ʾ","�ù��ܽ���װ�������Ļ�����ZPģ���в���������رգ�");
		RequestDelayedDestruction();
	}

	if (!PrdService::IsContextualPrd())
	{
		PrtService::ShowDlgNotify("��ʾ","�ù��ܽ���װ�������Ļ�����ZPģ���в���������رգ�");
		RequestDelayedDestruction();
	}
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstDesignCmd::~PrtFstDesignCmd()
{
	if (m_pDlg != NULL)
	{
		m_pDlg->RequestDelayedDestruction();
		m_pDlg = NULL;
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

	if (m_pi3DBagRep != NULL)
	{
		m_pi3DBagRep->Release();
		m_pi3DBagRep=NULL;
	}

	if (m_piManipulator != NULL)
	{
		m_piManipulator->Release();
		m_piManipulator=NULL;
	}

	//���������
	m_piHSO->Empty();
	m_piISO->Empty();
   
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void PrtFstDesignCmd::BuildGraph()
{
	m_pDlg = new PrtFstDesignDlg();
	m_pDlg->Build();
	m_pDlg->SetVisibility(CATDlgShow); 


	// ���Ի������Ϣ��Ӧ
	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaOKNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::OkDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetWindCloseNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::CloseDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaCANCELNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::CloseDlgCB,
		NULL);

	//ɾ�����е�
	AddAnalyseNotificationCB (m_pDlg->_DeletePointPB, 
		m_pDlg->_DeletePointPB->GetPushBActivateNotification(),
		(CATCommandMethod)&PrtFstDesignCmd::DeleteAllPointsCB,
		NULL);


	//������װ�����
	m_piPointsAgt = new CATFeatureImportAgent("ѡ��װ��");
	m_piPointsAgt->SetBehavior( CATDlgEngWithPSOHSO | CATDlgEngWithPrevaluation | CATDlgEngMultiAcquisitionUserCtrl | CATDlgEngRepeat);
	m_piPointsAgt->SetAgentBehavior(MfRelimitedFeaturization|MfPermanentBody); 
	m_piPointsAgt->AddElementType(IID_CATIMfZeroDimResult);

	//������һ��װ�����
	m_piFirstSurfAgt = new CATFeatureImportAgent("ѡ���һ��װ��");
	m_piFirstSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat );
	m_piFirstSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_piFirstSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_piFirstSurfAgt -> AddElementType (IID_CATSurface);

	//�����ڶ���װ�����
	m_piSecSurfAgt = new CATFeatureImportAgent("ѡ��ڶ���װ��");
	m_piSecSurfAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat  );
	m_piSecSurfAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_piSecSurfAgt -> AddElementType (IID_CATIMfBiDimResult);
	m_piSecSurfAgt -> AddElementType (IID_CATSurface);

	//����prd����
	m_piPrdAgt = new CATPathElementAgent("ѡ���������");
	m_piPrdAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSOHSO | CATDlgEngRepeat  );
	m_piPrdAgt -> AddElementType (IID_CATIProduct);
	CATAcquisitionFilter * pFilterForPrt = Filter((FilterMethod) & PrtFstDesignCmd::SeletedIsPart,(void*)NULL);
	m_piPrdAgt->SetFilter(pFilterForPrt);

	//����GSM����
	m_piPointGSMAgt = new CATFeatureImportAgent("ѡ��㼸��ͼ�μ�");
	m_piPointGSMAgt -> SetBehavior( CATDlgEngWithPrevaluation | CATDlgEngWithPSO | CATDlgEngRepeat  );
	m_piPointGSMAgt -> SetAgentBehavior( MfPermanentBody | MfLastFeatureSupport | MfRelimitedFeaturization);
	m_piPointGSMAgt -> AddElementType (IID_CATIGSMTool);

	//points SL
	m_piPointSLAgt = new CATDialogAgent("ѡ��װ��");
	m_piPointSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piPointSLAgt->AcceptOnNotify(m_pDlg->_PointsSL,m_pDlg->_PointsSL->GetListSelectNotification());

	//first Surf SL
	m_piFirstSurfSLAgt = new CATDialogAgent("ѡ���һ��װ��");
	m_piFirstSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piFirstSurfSLAgt->AcceptOnNotify(m_pDlg->_FirstSurfSL,m_pDlg->_FirstSurfSL->GetListSelectNotification());

	//second Surf SL
	m_piSecSurfSLAgt = new CATDialogAgent("ѡ��ڶ���װ��");
	m_piSecSurfSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piSecSurfSLAgt->AcceptOnNotify(m_pDlg->_SecondSurfSL,m_pDlg->_SecondSurfSL->GetListSelectNotification());

	//Prd SL
	m_piPrdSLAgt = new CATDialogAgent("ѡ���������");
	m_piPrdSLAgt->SetBehavior(CATDlgEngRepeat);
	m_piPrdSLAgt->AcceptOnNotify(m_pDlg->_PrdSL,m_pDlg->_PrdSL->GetListSelectNotification());

	//Choose Point GSM PB
	m_piPointGSMPBAgt = new CATDialogAgent("ѡ��㼸��ͼ�μ�");
	m_piPointGSMPBAgt->SetBehavior(CATDlgEngRepeat);
	m_piPointGSMPBAgt->AcceptOnNotify(m_pDlg->_ChoosePointGSMToolPB,m_pDlg->_ChoosePointGSMToolPB->GetPushBActivateNotification());


	//Define the StateChart
	CATDialogState * StSelectPrds = GetInitialState("ѡ���������");
	StSelectPrds -> AddDialogAgent (m_piPrdAgt);
	StSelectPrds -> AddDialogAgent (m_piPointSLAgt);
	StSelectPrds -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPrds -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPrds -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectPoints = AddDialogState("ѡ��װ��");
	StSelectPoints -> AddDialogAgent (m_piPointsAgt);
	StSelectPoints -> AddDialogAgent (m_piPointSLAgt);
	StSelectPoints -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPoints -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPoints -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPoints -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectPointGSM = AddDialogState("ѡ��㼸��ͼ�μ�");
	StSelectPointGSM -> AddDialogAgent (m_piPointGSMAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPointSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPrdSLAgt);
	StSelectPointGSM -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectFirstSurf = AddDialogState("ѡ���һ��װ��");
	StSelectFirstSurf -> AddDialogAgent (m_piFirstSurfAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPointSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPrdSLAgt);
	StSelectFirstSurf -> AddDialogAgent (m_piPointGSMPBAgt);

	CATDialogState * StSelectSecSurf = AddDialogState("ѡ��ڶ���װ��");
	StSelectSecSurf -> AddDialogAgent (m_piSecSurfAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPointSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piFirstSurfSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piSecSurfSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPrdSLAgt);
	StSelectSecSurf -> AddDialogAgent (m_piPointGSMPBAgt);

	//ת����ϵ �㵽��
	AddTransition(StSelectPoints, StSelectPoints, 
		IsLastModifiedAgentCondition(m_piPointsAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePoints));

	//ת����ϵ �㵽��
	AddTransition(StSelectPoints, StSelectPoints, 
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//ת����ϵ �㵽��1
	AddTransition(StSelectPoints, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	//ת����ϵ �㵽��2
	AddTransition(StSelectPoints, StSelectSecSurf, 
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//ת����ϵ ��1����
	AddTransition(StSelectFirstSurf,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//ת����ϵ ��2����
	AddTransition(StSelectSecSurf,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));

	//ת����ϵ ��1����1
	AddTransition(StSelectFirstSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChooseFirstSurfs));

	//ת����ϵ ��1����1
	AddTransition(StSelectFirstSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	//ת����ϵ ��2����2
	AddTransition(StSelectSecSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChooseSecSurfs));

	//ת����ϵ ��2����2
	AddTransition(StSelectSecSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//ת����ϵ ��1����2
	AddTransition(StSelectFirstSurf,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));

	//ת����ϵ ��2����1
	AddTransition(StSelectSecSurf,StSelectFirstSurf,
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));

	// [11/18/2011 zhangwenyang]
	//ת����ϵ Prd Prd
	AddTransition(StSelectPrds,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePrds));
	//ת����ϵ Prd Prd
	AddTransition(StSelectPrds,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//ת����ϵ GSM GSM
	AddTransition(StSelectPointGSM,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ChoosePointGSM));

	//ת����ϵ GSM GSM
	AddTransition(StSelectPointGSM,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//ת����ϵ Prd GSM
	AddTransition(StSelectPrds,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//ת����ϵ GSM Prd
	AddTransition(StSelectPointGSM,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	// [11/18/2011 zhangwenyang]
	//ת����ϵ Prd ��
	AddTransition(StSelectPrds,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));
	//ת����ϵ �� Prd 
	AddTransition(StSelectPoints,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//ת����ϵ Prd ��1
	AddTransition(StSelectPrds, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));
	//ת����ϵ ��1 Prd 
	AddTransition(StSelectFirstSurf,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	//ת����ϵ Prd ��2
	AddTransition(StSelectPrds,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));
	//ת����ϵ ��2 Prd 
	AddTransition(StSelectSecSurf,StSelectPrds,
		IsLastModifiedAgentCondition(m_piPrdSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePrdSL));

	// [11/18/2011 zhangwenyang]
	//ת����ϵ GSM ��
	AddTransition(StSelectPointGSM,StSelectPoints,
		IsLastModifiedAgentCondition(m_piPointSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointsSL));
	//ת����ϵ �� GSM 
	AddTransition(StSelectPoints,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));
	
	//ת����ϵ GSM ��1
	AddTransition(StSelectPointGSM, StSelectFirstSurf, 
		IsLastModifiedAgentCondition(m_piFirstSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveFirstSurfSL));
	//ת����ϵ ��1 GSM 
	AddTransition(StSelectFirstSurf,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	//ת����ϵ GSM ��2
	AddTransition(StSelectPointGSM,StSelectSecSurf,
		IsLastModifiedAgentCondition(m_piSecSurfSLAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActiveSecSurfSL));
	//ת����ϵ ��2 GSM 
	AddTransition(StSelectSecSurf,StSelectPointGSM,
		IsLastModifiedAgentCondition(m_piPointGSMPBAgt),
		Action ((ActionMethod) &PrtFstDesignCmd::ActivePointGSMPB));

	// [11/23/2011 zhangwenyang]
	/*AddAnalyseNotificationCB(m_piManipulator,CATManipulator::GetCATManipulate(),
		(CATCommandMethod)&PrtFstDesignCmd::CBManipulator,(void*)NULL);*/

}

void PrtFstDesignCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	if (NULL != m_pDlg)
	{
		m_pDlg->RequestDelayedDestruction();
		m_pDlg = NULL;
	}	


	//���ص�һ��װ��
	for (int i = 1; i <= m_lstSpecFirstSurfs.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecFirstSurfs[i],"Hide");
	}

	//���صڶ���װ��
	for (int i = 1; i <= m_lstSpecSecSurfs.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecSecSurfs[i],"Hide");
	}

	RequestDelayedDestruction();

}
void PrtFstDesignCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{

	if (NULL != m_pDlg)
	{
		m_pDlg->RequestDelayedDestruction();
		m_pDlg = NULL;
	}	

	//���ص�һ��װ��
	for (int i = 1; i <= m_lstSpecFirstSurfs.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecFirstSurfs[i],"Hide");
	}

	//���صڶ���װ��
	for (int i = 1; i <= m_lstSpecSecSurfs.Size(); i++)
	{
		PrtService::SetSpecObjShowAttr(m_lstSpecSecSurfs[i],"Hide");
	}

	RequestDelayedDestruction();
}

//�ж��Ƿ�ΪZPģ��
BOOL PrtFstDesignCmd::IsThisZPPrt(CATUnicodeString istrDocName)
{
	if (istrDocName != "")
	{
		int istart=istrDocName.SearchSubString("-ZP",0,CATUnicodeString::CATSearchModeBackward);
		if (istart == (istrDocName.GetLengthInChar()-3) || istart == (istrDocName.GetLengthInChar()-4))
		{
			return TRUE;
		}
		else return FALSE;
	}
	else return FALSE;
}

CATBoolean PrtFstDesignCmd::SeletedIsPart(CATDialogAgent * iAgent, void * iUsefulData)
{
	CATBoolean rc = FALSE ;
	if ( NULL == iAgent ) return rc ;

	CATBaseUnknown* piSelectElement =m_piPrdAgt->GetElementValue();//�����ѡ����
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

//����ת����Ϣ��Ӧ����
CATBoolean PrtFstDesignCmd::ChoosePoints( void *UsefulData)
{
	//���弯Ⱥ
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
					if (m_pDlg->_SeleDeleteCheckB->GetState() == CATDlgCheck)
					{
						m_lstSpecPoints.RemoveValue(spLeaf);
						PrtService::RemoveHSO(spLeaf);
						
						//�б�����
						m_pDlg->_PointsSL->ClearLine();
						for (int i = 1; i <= m_lstSpecPoints.Size(); i ++)
						{
							CATUnicodeString strShowPath("");
							CATPathElement *piPath = NULL;
							PrtService::GetPathElementFromSpecObject(piPath,m_lstSpecPoints[i],NULL);
							PrtService::PathElementString(piPath,strShowPath,TRUE);
							m_pDlg->_PointsSL->SetLine(strShowPath);

							piPath->Release();
							piPath=NULL;
						}
						if (m_lstSpecPoints.Size()==0)
						{
							m_pDlg->_PointsSL->SetLine("��ѡ��װ��",0,CATDlgDataModify);
						}
					}

					existFlag = TRUE;
					break;
				}
			}

			//���Ϊ�Ƴ�ģʽ����£��Ƴ�HSO
			if (!existFlag && (m_pDlg->_SeleDeleteCheckB->GetState() == CATDlgCheck)) //�����ڷ���
			{
				PrtService::RemoveHSO(spLeaf);
			}


			//���Ϊ����ģʽ�����
			if (!existFlag && (m_pDlg->_SeleDeleteCheckB->GetState() == CATDlgUncheck)) //�����ڷ���
			{
				//������б�
				if (m_lstSpecPoints.Size() == 0)
				{
					m_pDlg->_PointsSL->ClearLine();
				}
				//
				m_lstSpecPoints.Append(spLeaf);

				//
				CATUnicodeString strShowPath("");
				strShowPath = spLeaf->GetDisplayName();
				PrtService::PathElementString(pSubPath,strShowPath,TRUE);
				m_pDlg->_PointsSL->SetLine(strShowPath);
			}

		}
	}

	//��ʾ��װ�����
	CATUnicodeString strCount("");
	strCount.BuildFromNum(m_lstSpecPoints.Size());
	strCount += " ��";
	m_pDlg->_PointCountEditor->SetText(strCount);

	//����б�ѡ��״̬
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	m_piPointsAgt->InitializeAcquisition();
	return TRUE;

}

CATBoolean PrtFstDesignCmd::ChooseFirstSurfs( void *UsefulData)
{
	HRESULT hr = E_FAIL;
	
	CATBaseUnknown* piSelectElement =m_piFirstSurfAgt->GetElementValue();//�����ѡ����
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
			for (int i = 1; i <= m_lstSpecFirstSurfs.Size(); i ++)
			{
				if (m_lstSpecFirstSurfs[i] == spSpecOnSelection)
				{
					m_lstSpecFirstSurfs.RemoveValue(spSpecOnSelection);
					PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Hide");
					PrtService::RemoveHSO(spSpecOnSelection);
					existFlag = TRUE;
					break;
				}
			}

			if (existFlag == FALSE)
			{
				//�ж��Ƿ�����һ������������
				if (IsTheSpecInLstSpec(spSpecOnSelection,m_lstSpecSecSurfs))
				{
					PrtService::ktWarningMsgBox("������ѡ������ֹ����ͬ���棬������ѡ��");
				}
				else
				{
					//�ж�ȷ�������õ�����������������ڶ�����������
					CATIProduct_var spRefPrd;
					GetLinkImportPrd(spSpecOnSelection,spRefPrd);
					if (m_lstSpecPrds.Size() >= 2)
					{
						if (IsTheSpecInLstSpec(spRefPrd,m_lstSpecPrds))
						{
							PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Show");
							m_lstSpecFirstSurfs.Append(spSpecOnSelection);
							PrtService::HighlightHSO(spSpecOnSelection);
						}
						else
						{
							PrtService::ktErrorMsgBox("��ǰ��ѡԪ������������ڡ���������ġ��б��У�������ѡ��");
						}
					}
					else //��ǰ����������ġ�Ԫ��С�ڶ���
					{
						PrtService::ktWarningMsgBox("����������ġ�����б�������ڵ���2��������ѡ����������������");
					}
				}
				
			}

			if (m_lstSpecFirstSurfs.Size()>=1)
			{
				CATUnicodeString strLineShow("��ѡ��");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecFirstSurfs.Size());
				strLineShow += strNumber + "����";
				m_pDlg->_FirstSurfSL->SetLine(strLineShow,0,CATDlgDataModify);
			}
			if (m_lstSpecFirstSurfs.Size()==0)
			{
				m_pDlg->_FirstSurfSL->SetLine("δѡ��",0,CATDlgDataModify);
			}
		}
	}

	//
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();
	int firstRom = 0;
	m_pDlg->_FirstSurfSL->SetSelect(&firstRom,1,0);

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;	
}

CATBoolean PrtFstDesignCmd::ChooseSecSurfs( void *UsefulData)
{
	HRESULT hr = E_FAIL;
	CATBaseUnknown* piSelectElement =m_piSecSurfAgt->GetElementValue();//�����ѡ����
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

		//
		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean existFlag = FALSE;
			for (int i = 1; i <= m_lstSpecSecSurfs.Size(); i ++)
			{
				if (m_lstSpecSecSurfs[i] == spSpecOnSelection)
				{
					m_lstSpecSecSurfs.RemoveValue(spSpecOnSelection);
					PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Hide");
					PrtService::RemoveHSO(spSpecOnSelection);
					existFlag = TRUE;
					break;
				}
			}

			if (existFlag == FALSE)
			{
				//�ж��Ƿ�����һ������������
				if (IsTheSpecInLstSpec(spSpecOnSelection,m_lstSpecFirstSurfs))
				{
					PrtService::ktWarningMsgBox("������ѡ������ʼ����ͬ���棬������ѡ��");
				}
				else
				{
					//�ж��Ƿ�����һ������������
					if (IsTheSpecInLstSpec(spSpecOnSelection,m_lstSpecSecSurfs))
					{
						PrtService::ktWarningMsgBox("������ѡ������ֹ����ͬ���棬������ѡ��");
					}
					else
					{
						//�ж�ȷ�������õ�����������������ڶ�����������
						CATIProduct_var spRefPrd;
						GetLinkImportPrd(spSpecOnSelection,spRefPrd);
						if (m_lstSpecPrds.Size() >= 2)
						{
							if (IsTheSpecInLstSpec(spRefPrd,m_lstSpecPrds))
							{
								PrtService::SetSpecObjShowAttr(spSpecOnSelection,"Show");
								m_lstSpecSecSurfs.Append(spSpecOnSelection);
								PrtService::HighlightHSO(spSpecOnSelection);

								//���Դ����ȡ����
								if ((m_lstSpecPoints.Size()>=1) && (m_lstSpecFirstSurfs.Size()>=1) && (m_lstSpecSecSurfs.Size()>=1))
								{
									GetInitialArrow(m_lstSpecPoints[1],m_lstSpecFirstSurfs,m_lstSpecSecSurfs);
								}
							}
							else
							{
								PrtService::ktErrorMsgBox("��ǰ��ѡԪ������������ڡ���������ġ��б��У�������ѡ��");
							}
						}
						else //��ǰ����������ġ�Ԫ��С�ڶ���
						{
							PrtService::ktWarningMsgBox("����������ġ�����б�������ڵ���2��������ѡ����������������");
						}
					}
				}
			}
			
			if (m_lstSpecSecSurfs.Size()>=1)
			{
				CATUnicodeString strLineShow("��ѡ��");
				CATUnicodeString strNumber;
				strNumber.BuildFromNum(m_lstSpecSecSurfs.Size());
				strLineShow += strNumber + "����";
				m_pDlg->_SecondSurfSL->SetLine(strLineShow,0,CATDlgDataModify);
			}
			if (m_lstSpecSecSurfs.Size()==0)
			{
				m_pDlg->_SecondSurfSL->SetLine("δѡ��",0,CATDlgDataModify);
			}
		}
	}

	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	int firstRom = 0;
	m_pDlg->_SecondSurfSL->SetSelect(&firstRom,1,0);

	//���³�ʼ������
	m_piSecSurfAgt->InitializeAcquisition();
	return TRUE;	

}

//��Ӧ
CATBoolean PrtFstDesignCmd::ChoosePrds( void *UsefulData)
{
	HRESULT hr = E_FAIL;

	CATPathElement* piSelectElement =m_piPrdAgt->GetValue();//�����ѡ����
	if (piSelectElement != NULL)
	{
		//���SUB PATH
		CATBaseUnknown * pLeaf =NULL ;
		//���·���µ�һ������spec����
		pLeaf = (*piSelectElement)[piSelectElement->GetSize()-1];
		CATISpecObject_var spSpecOnSelection = NULL_var;
		spSpecOnSelection = pLeaf;

		if ( spSpecOnSelection != NULL_var )
		{
			CATBoolean existFlag = FALSE;
			for (int i = 1; i <= m_lstSpecPrds.Size(); i ++)
			{
				if (m_lstSpecPrds[i] == spSpecOnSelection)
				{
					m_lstSpecPrds.RemoveValue(spSpecOnSelection);
					existFlag = TRUE;
					break;
				}
			}

			if (existFlag == FALSE)
			{
				CATDocument* opiPrdDoc = NULL;
				PrdService::GetInstPrdDoc(spSpecOnSelection,opiPrdDoc);
				CATUnicodeString strPrdName;
				PrtService::GetPrdNumberFormDoc(opiPrdDoc,strPrdName);
				
				if (IsThisZPPrt(strPrdName))
				{
					PrtService::ktWarningMsgBox("����ѡ��ZPģ��Ϊ��װ�����������ѡ��");
					PrtService::RemoveHSO(spSpecOnSelection);
				}
				else
					m_lstSpecPrds.Append(spSpecOnSelection);				
			}

			m_pDlg->_PrdSL->ClearLine();
			for (int i = 1; i <= m_lstSpecPrds.Size(); i ++)
			{
				//
				CATUnicodeString strShowPath("");
				CATPathElement *piPath = NULL;
				PrtService::GetPathElementFromSpecObject(piPath,m_lstSpecPrds[i],NULL);
				PrtService::PathElementString(piPath,strShowPath,TRUE);
				m_pDlg->_PrdSL->SetLine(strShowPath);

				piPath->Release();
				piPath=NULL;
			}

			if (m_lstSpecPrds.Size()==0)
			{
				m_pDlg->_PrdSL->SetLine("��ѡ���������");
			}
		}
	}

	//
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;	
}


//������ش���
CATBoolean PrtFstDesignCmd::ActivePointsSL( void *UsefulData)
{
	//���ѡ��
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	//�������
	PrtService::ClearHSO();
	//������Ҫ����������
	PrtService::HighLightObjLst(m_lstSpecPoints);
	//��ʾISO POINTS
	ShowPointInfoInISO(m_pDlg->_PointsSL,m_lstSpecPoints);

	m_piPointsAgt->InitializeAcquisition();
	return TRUE;	
}
CATBoolean PrtFstDesignCmd::ActiveFirstSurfSL( void *UsefulData)
{
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	//�������
	PrtService::ClearHSO();
	//������Ҫ����������
	PrtService::HighLightObjLst(m_lstSpecFirstSurfs);

	m_piFirstSurfAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstDesignCmd::ActiveSecSurfSL( void *UsefulData)
{
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	//�������
	PrtService::ClearHSO();
	//������Ҫ����������
	PrtService::HighLightObjLst(m_lstSpecSecSurfs);

	m_piSecSurfAgt->InitializeAcquisition();
	return TRUE;
}

CATBoolean PrtFstDesignCmd::ActivePrdSL( void *UsefulData)
{
	m_pDlg->_PointsSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();

	//�������
	PrtService::ClearHSO();
	//������Ҫ����������
	ShowSeletedLine(m_pDlg->_PrdSL,m_lstSpecPrds);

	m_piPrdAgt->InitializeAcquisition();
	return TRUE;
}
CATBoolean PrtFstDesignCmd::ActivePointGSMPB( void *UsefulData)
{
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();
	m_pDlg->_PrdSL->ClearSelect();

	m_piPointGSMAgt->InitializeAcquisition();
	return TRUE;
}

CATBoolean PrtFstDesignCmd::ChoosePointGSM( void *UsefulData)
{

	CATPathElement* piSelectElement =m_piPointGSMAgt->GetValue();//�����ѡ����
	if (piSelectElement != NULL)
	{
		//���SUB PATH
		CATBaseUnknown * pLeaf =NULL ;
		//���·���µ�һ������spec����
		pLeaf = (*piSelectElement)[piSelectElement->GetSize()-1];
		CATISpecObject_var spSpecOnSelection = NULL_var;
		spSpecOnSelection = pLeaf;
		//
		if ( spSpecOnSelection != NULL_var )
		{
			//��ü���ͼ�μ��������еĵ�
			PrtService::GetContentSpecsByNameFromGSMTool(spSpecOnSelection,"CATIMfZeroDimResult",m_lstSpecPoints);

			m_pDlg->_PointsSL->ClearLine();
			for (int i = 1; i <= m_lstSpecPoints.Size(); i ++)
			{
				//
				CATUnicodeString strShowPath("");
				CATPathElement *piPath = NULL;
				PrtService::GetPathElementFromSpecObject(piPath,m_lstSpecPoints[i],NULL);
				PrtService::PathElementString(piPath,strShowPath,TRUE);
				m_pDlg->_PointsSL->SetLine(strShowPath);

				piPath->Release();
				piPath=NULL;

				PrtService::HighlightHSO(m_lstSpecPoints[i]);
			}

			if (m_lstSpecPoints.Size()==0)
			{
				m_pDlg->_PointsSL->SetLine("��ѡ��װ��");
			}

			//��ʾ��װ�����
			CATUnicodeString strCount("");
			strCount.BuildFromNum(m_lstSpecPoints.Size());
			strCount += " ��";
			m_pDlg->_PointCountEditor->SetText(strCount);
		}
	}
	
	m_pDlg->_PrdSL->ClearSelect();
	m_pDlg->_FirstSurfSL->ClearSelect();
	m_pDlg->_SecondSurfSL->ClearSelect();

	m_piPointGSMAgt->InitializeAcquisition();
	return TRUE;
}


//������ʾ��ǰ��ѡ��
void PrtFstDesignCmd::ShowSeletedLine(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs)
{
	//���Ϊ�գ�ֱ���˳�
	if (olstSpecs.Size() == 0)
	{
		return;
	}
	//��ȡ��ѡ��
	int NumberOfRowsSelected;
	NumberOfRowsSelected = opiSL->GetSelectCount();

	int *iSelectedRows = new int[NumberOfRowsSelected];
	opiSL->GetSelect(iSelectedRows,NumberOfRowsSelected);

	//�������Ӹ���
	for (int i = 0; i < NumberOfRowsSelected; i ++)
	{
		PrtService::HighlightHSO(olstSpecs[iSelectedRows[i]+1]);
	}
}


//ɾ�����е�
void PrtFstDesignCmd::DeleteAllPointsCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	PrtService::ClearHSO();
	m_lstSpecPoints.RemoveAll();
	m_pDlg->_PointsSL->ClearLine();
	m_pDlg->_PointsSL->SetLine("��ѡ��װ��");

	//��ʾ��װ�����
	CATUnicodeString strCount("");
	strCount.BuildFromNum(m_lstSpecPoints.Size());
	strCount += " ��";
	m_pDlg->_PointCountEditor->SetText(strCount);

	//��ò����ISO
	m_piISO->Empty();
}

//��IOS����ʾ��ǵ�
void PrtFstDesignCmd::ShowPointInfoInISO(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs)
{
	//���Ϊ�գ�ֱ���˳�
	if (olstSpecs.Size() == 0)
	{
		return;
	}
	//��ȡ��ѡ��
	int NumberOfRowsSelected;
	NumberOfRowsSelected = opiSL->GetSelectCount();

	int *iSelectedRows = new int[NumberOfRowsSelected];
	opiSL->GetSelect(iSelectedRows,NumberOfRowsSelected);

	//��ò����ISO
	m_piISO->Empty();

	//�������Ӹ���
	for (int i = 0; i < NumberOfRowsSelected; i ++)
	{
		CATIMeasurablePoint_var spMeasurablePt = olstSpecs[iSelectedRows[i]+1];
		if (spMeasurablePt==NULL_var)
		{
			return ;
		}
		CATMathPoint mPrjPt;
		spMeasurablePt->GetPoint(mPrjPt);

		CATIAlias_var spAliasOnPt = olstSpecs[iSelectedRows[i]+1];
		CATUnicodeString StrTextValue = spAliasOnPt->GetAlias();
		
		CATMathPointf TextPosNode;
		TextPosNode.x = (float)(mPrjPt.GetX());
		TextPosNode.y = (float)(mPrjPt.GetY());
		TextPosNode.z = (float)(mPrjPt.GetZ());

		CAT3DCustomRep * pRepForTextStart= new CAT3DCustomRep();
		CATGraphicAttributeSet   TextGaNode ;
		TextGaNode.SetColor(RED);
		TextGaNode.SetHighlightMode (0);
		CAT3DAnnotationTextGP   *pTextGPSrart = new CAT3DAnnotationTextGP(TextPosNode,StrTextValue);
		pRepForTextStart->AddGP(pTextGPSrart,TextGaNode);
		CATModelForRep3D *piRepPtAlias = new CATModelForRep3D() ;
		piRepPtAlias->SetRep(pRepForTextStart) ;
		m_piISO->AddElement(piRepPtAlias);

		piRepPtAlias->Release();
		piRepPtAlias=NULL;
	}
}

//�ж�һ�����������Ƿ�����һ��������
BOOL PrtFstDesignCmd::IsTheSpecInLstSpec(CATISpecObject_var iSpec, CATListValCATISpecObject_var iLstSpec)
{
	for (int i = 1; i <= iLstSpec.Size(); i ++)
	{
		if (iSpec == iLstSpec[i])
		{
			return TRUE;
		}
	}

	return FALSE;		
}

//��ô��������ĵĸ����ڵ�
HRESULT PrtFstDesignCmd::GetLinkImportPrd(CATISpecObject_var& ispFeature,CATIProduct_var &ospSourcePrd)
{
	HRESULT rc = S_OK;
	ospSourcePrd=NULL_var;
	CATIMmiMechanicalImportApplicative* piLinkImport = NULL;
	//
	rc = ispFeature->QueryInterface(IID_CATIMmiMechanicalImportApplicative,(void**)&piLinkImport);
	//
	if (SUCCEEDED(rc) && (piLinkImport!=NULL))
	{
		CATIProduct_var spSourcePrd = NULL_var;
		piLinkImport->GetSourceProduct(ospSourcePrd);
		//
		piLinkImport->Release();
		piLinkImport=NULL;
		
		//���·������
		/*if (ospSourcePrd!=NULL_var)
		{
			CATUnicodeString strShowPath("");
			CATPathElement *piPath = NULL;
			PrtService::GetPathElementFromSpecObject(piPath,ospSourcePrd,NULL);
			PrtService::PathElementString(piPath,strShowPath,TRUE);
			PrtService::ktInfoMsgBox(strShowPath);
		}*/
	}
	
	return rc;
}

//��ó�ʼ���ķ��߷���
HRESULT PrtFstDesignCmd::GetInitialArrow(CATISpecObject_var ispPoint, CATListValCATISpecObject_var ilstFirstSurf,CATListValCATISpecObject_var ilstSecSurf)
{
	HRESULT rc =S_OK;
	CATIGSMFactory_var spGSMFac = NULL_var;
	PrtService::GetGSMFactory(m_piDoc,spGSMFac);

	//���㷨�߷���
	double iLength1 = 100.0;
	double iLength2 = -100.0;
	CATICkeParm_var spCkeParm1 = PrtService::LocalInstLitteral(&iLength1, 1, "Length","Length"); 
	CATICkeParm_var spCkeParm2 = PrtService::LocalInstLitteral(&iLength2, 1, "Length", "Length"); 
	CATISpecObject_var spNormalLine = spGSMFac->CreateLineNormal(ilstFirstSurf[1],ispPoint,spCkeParm1,spCkeParm2,CATGSMSameOrientation);

	if (spNormalLine != NULL_var)
	{
		//�õ���������
		CATISpecObject_var spIntersect01 = spGSMFac->CreateIntersect(spNormalLine,ilstFirstSurf[1]); 
		CATISpecObject_var spIntersect02 = spGSMFac->CreateIntersect(spNormalLine,ilstSecSurf[1]);

		CATISpecObject_var spGSMTool = NULL_var;
		PrtService::ObtainGSMTool(m_piDoc,"����Ԫ��",spGSMTool);

		CATTry{
			PrtService::CAAGsiInsertInProceduralView(spIntersect01,spGSMTool);
			spIntersect01->Update();
		}

		// This block is specific for Update Errors
		CATCatch( CATMfErrUpdate, pError ){	
			// 			cerr << " Update Error: " << (pError-> GetDiagnostic()).ConvertToChar() << endl; 
			Flush(pError) ; 
			// When error happens, what to do 
			spIntersect01->GetFather()->Remove(spIntersect01);
			spIntersect01 = NULL_var;
		}
		CATEndTry;  	

		CATTry{
			PrtService::CAAGsiInsertInProceduralView(spIntersect02,spGSMTool);
			spIntersect02->Update();
		}

		// This block is specific for Update Errors
		CATCatch( CATMfErrUpdate, pError ){	
			// 			cerr << " Update Error: " << (pError-> GetDiagnostic()).ConvertToChar() << endl; 
			Flush(pError) ; 
			// When error happens, what to do 
			spIntersect02->GetFather()->Remove(spIntersect02);
			spIntersect02 = NULL_var;
		}
		CATEndTry; 

		//�����������Ϊ�գ����ص��ṹ��
		if (spIntersect01!=NULL_var && spIntersect02!=NULL_var)
		{		
			CATIMeasurablePoint_var spMeasurePoint1=spIntersect01;
			CATIMeasurablePoint_var spMeasurePoint2=spIntersect02;
			//
			CATMathPoint mathPoint1,mathPoint2;
			spMeasurePoint1->GetPoint(mathPoint1);
			spMeasurePoint2->GetPoint(mathPoint2);
			//
			spIntersect01->GetFather()->Remove(spIntersect01);
			spIntersect02->GetFather()->Remove(spIntersect02);
			//��ò����ISO
			m_piISO->Empty();
			//
			CATMathDirectionf oArrowVector(mathPoint1,mathPoint2);
			//��OriginPoint������3D fixed arrow.
			CAT3DFixedArrowGP *pArrowGP = new CAT3DFixedArrowGP(mathPoint1,oArrowVector,20,5);
			//����ͼ�����ԣ�����Color��Thickness
			CATGraphicAttributeSet AttributsDir;
			AttributsDir.SetColor(GREEN);
			AttributsDir.SetThickness(2);
			//
			CAT3DCustomRep * pRepForArrow= new CAT3DCustomRep(pArrowGP,AttributsDir);
			//
			CATModelForRep3D *piRepPtAlias = new CATModelForRep3D();
			piRepPtAlias->SetRep(pRepForArrow);		
			//
			m_piISO->AddElement(piRepPtAlias);
			if( m_pi3DBagRep!=NULL)
			{
				m_pi3DBagRep->Release();
				m_pi3DBagRep=NULL;
			}
			m_pi3DBagRep = new CAT3DBagRep();m_pi3DBagRep->AddChild(*pRepForArrow);
			//
			CATFrmLayout *pFrmLayout = CATFrmLayout::GetCurrentLayout();
			CATFrmWindow *pFrmWindow = pFrmLayout->GetCurrentWindow();
			CATViewer *pViewer = pFrmWindow->GetViewer();
			pViewer->AddRep(m_pi3DBagRep);pViewer->Draw();
			//pISO->AddElement(piRepPtAlias);

			//
			if (m_piManipulator!=NULL)
			{
				m_piManipulator->Release();
				m_piManipulator=NULL;
			}
			m_piManipulator = new CAT3DManipulator(this,"Manip",m_pi3DBagRep,CAT3DManipulator::DirectionTranslation);
			//CATMathPoint P(0,0,0);
			CATMathVector I(1,0,0),J(0,1,0),K(0,0,1);
			CATMathAxis Axis(mathPoint1,I,J,K);
			m_piManipulator->SetPosition(Axis);
			CATMathDirection D(0,1,0);
			m_piManipulator->SetTranslationDirection(D);
		}
	}

	return rc;	
}

//��ͷ�Ļص�����
void PrtFstDesignCmd::CBManipulator(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	cout<<"CBManipulator(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)!"<<endl;
	CATMathAxis Position=((CAT3DManipulator *)cmd)->GetPosition();
	CAT4x4Matrix initialisationMatrix(Position);
	m_pi3DBagRep->SetMatrix(initialisationMatrix);
	//
	CATFrmLayout *pFrmLayout = CATFrmLayout::GetCurrentLayout();
	CATFrmWindow *pFrmWindow = pFrmLayout->GetCurrentWindow();
	CATViewer *pViewer = pFrmWindow->GetViewer();
	pViewer->Draw();
}