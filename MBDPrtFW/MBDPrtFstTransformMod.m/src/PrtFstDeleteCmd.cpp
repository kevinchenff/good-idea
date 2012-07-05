// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstDeleteCmd.cpp
// The state chart based command: PrtFstDeleteCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstDeleteCmd.h"
#include "CATIndicationAgent.h"
#include "CATMathPlane.h"
#include "CATSO.h"
#include "CATIMeasurableLine.h"

#include "CATIMfMonoDimResult.h"
#include "CATIGSMCircleCenterAxis.h"

#include "CATCreateExternalObject.h"
CATCreateClass( PrtFstDeleteCmd);


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstDeleteCmd::PrtFstDeleteCmd() :
  CATStateCommand ("PrtFstDeleteCmd", CATDlgEngOneShot, CATCommandModeExclusive) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
 ,m_pDlg(NULL),m_piDoc(NULL),m_piEditor(NULL),m_piHSO(NULL),m_piISO(NULL),m_piFstLineAgt(NULL)
{
	//初始化获得当前文档及名称
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

	//判断是否为ZP模型;
	if (!IsThisZPPrt(m_strDocName))
	{
		PrtService::ShowDlgNotify("提示","该功能仅在装配ZP模型中操作，点击关闭！");
		RequestDelayedDestruction();
	}
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstDeleteCmd::~PrtFstDeleteCmd()
{
   if (m_pDlg != NULL) 
   {
      m_pDlg->RequestDelayedDestruction();
	  m_pDlg=NULL;
   }

   if (NULL!=m_piFstLineAgt)
   {
	   m_piFstLineAgt->RequestDelayedDestruction();
	   m_piFstLineAgt=NULL;
   }

   //高亮点清空
   m_piHSO->Empty();
   m_piISO->Empty();
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void PrtFstDeleteCmd::BuildGraph()
{
	//
	m_pDlg = new PrtFstDeleteDlg();
	m_pDlg->Build();
	m_pDlg->SetVisibility(CATDlgShow); 

	// 主对话框的消息响应
	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaOKNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::OkDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetWindCloseNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::CloseDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaCANCELNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::CloseDlgCB,
		NULL);

	//增加对 紧固件线列表的响应控制
	AddAnalyseNotificationCB (m_pDlg->_FSTLineSL, 
		m_pDlg->_FSTLineSL->GetListSelectNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::GetSeletedFSTLine,
		NULL);

	//移除所选按钮响应
	AddAnalyseNotificationCB (m_pDlg->_RemoveSelPB, 
		m_pDlg->_RemoveSelPB->GetPushBActivateNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::RemoveSelectedPBCB,
		NULL);

	//移除所有按钮响应
	AddAnalyseNotificationCB (m_pDlg->_RemoveAllPB, 
		m_pDlg->_RemoveAllPB->GetPushBActivateNotification(),
		(CATCommandMethod)&PrtFstDeleteCmd::RemoveAllPBCB,
		NULL);

	//
	//定义代理选择机制
	//创建安装点代理
	m_piFstLineAgt = new CATPathElementAgent("选择紧固件线");
	m_piFstLineAgt->SetBehavior( CATDlgEngWithPSOHSO | CATDlgEngWithPrevaluation | CATDlgEngMultiAcquisitionUserCtrl | CATDlgEngRepeat);
	m_piFstLineAgt->AddElementType(IID_CATIGSMLine);
	CATAcquisitionFilter * pFilterForFSTLine = Filter((FilterMethod) & PrtFstDeleteCmd::SeletedIsFSTLine,(void*)NULL);
	m_piFstLineAgt->SetFilter(pFilterForFSTLine);

	//
	//Define the StateChart
	CATDialogState * StSelectFSTLine = GetInitialState("选择紧固件线");
	StSelectFSTLine -> AddDialogAgent (m_piFstLineAgt);

	//
	//转换关系 点到点
	AddTransition(StSelectFSTLine, StSelectFSTLine, 
		IsLastModifiedAgentCondition(m_piFstLineAgt),
		Action ((ActionMethod) &PrtFstDeleteCmd::ChooseFSTLines));
}

//判断是否为ZP模型
BOOL PrtFstDeleteCmd::IsThisZPPrt(CATUnicodeString istrDocName)
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

void PrtFstDeleteCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	RequestDelayedDestruction();
}

void PrtFstDeleteCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	// 删除紧固件几何，并更新参数信息，所选列表
	for (int i=1; i <= m_alstSpecFSTLines.Size(); i++)
	{
		//删除之前先把原始定位点显示出来，方便后期重新定义
		//写入安装点特征，当删除特征时，可直接把该点恢复显示状态
		CATISpecObject_var spPosPoint=NULL_var;
		BOOL bIsExistKey = false; 
		CATUnicodeString strFSTPosPointKey("F_ATTEX_Point");
		PrtService::GetSepcObjectAttrEx(bIsExistKey,spPosPoint,strFSTPosPointKey,m_alstSpecFSTLines[i]);

		if (bIsExistKey && spPosPoint!=NULL_var)
		{
			PrtService::SetSpecObjShowAttr(spPosPoint,"Show");
		}

		//
		CATISpecObject_var spGSM03=m_alstSpecFSTLines[i]->GetFather()->GetFather();
		spGSM03->Remove(m_alstSpecFSTLines[i]->GetFather());
	}
	//
	//
	m_alstSpecFSTLines.RemoveAll();
	m_pDlg->_FSTLineSL->ClearLine();
	//
	m_piHSO->Empty();
	m_piISO->Empty();

	//更新所有信息，虽然耗时，但这样确保统计数字是准确的
	//更新ZP模型
	CATIPrtContainer *opiRootContainer = NULL;
	PrtService::ObtainRootContainer(m_piDoc,opiRootContainer);
	//获得part
	CATISpecObject_var spPart = opiRootContainer->GetPart();
	PrtService::ObjectUpdate(spPart);

	// 获取当前“紧固件连接”几何图形集，获得所有紧固件
	// 获取所有该几何集下面所有的二级子集
	CATISpecObject_var spLineDefGSMTool = NULL_var;
	PrtService::ObtainGSMTool(m_piDoc,"连接定义",spLineDefGSMTool);
	if (spLineDefGSMTool == NULL_var)
	{
		//输出错误信息
		PrtService::ShowDlgNotify("错误提示","未能找到“连接定义”几何图形集！");
		return;
	}

	//获取第二层 连接组件定义 Prd01|Prd02|Prd03
	CATListValCATISpecObject_var iolstspFoundResult02;
	PrtService::SearchALLSonFromRootGSMTool(spLineDefGSMTool,iolstspFoundResult02);

	//
	for (int i = 1; i <= iolstspFoundResult02.Size(); i++)
	{
		//获取每一个此层次的几何图形集内部的KEY，按照内容更新名称
		CATListValCATISpecObject_var alstSpecPrds;
		CATUnicodeString strKey("F_ATTEX_LINK_PRT");
		BOOL bIsExistKey = false; 
		PrtService::GetSepcObjectAttrEx(bIsExistKey,alstSpecPrds,strKey,iolstspFoundResult02[i]);
		//
		if (bIsExistKey)
		{
			CATListValCATUnicodeString ilstStrPartsInstName;
			for (int i1 =1; i1 <= alstSpecPrds.Size(); i1++)
			{
				CATIProduct_var spInsPrd = alstSpecPrds[i1];
				CATIProduct_var spRefPrd = spInsPrd->GetReferenceProduct();

				CATUnicodeString strPrtName;
				strPrtName = spRefPrd->GetPartNumber();
				ilstStrPartsInstName.Append(strPrtName);
			}

			//
			CATUnicodeString strPartsJointName;
			for (int i1=1; i1 <= ilstStrPartsInstName.Size(); i1++)
			{
				strPartsJointName += ilstStrPartsInstName[i1];
				if (i1 != ilstStrPartsInstName.Size())
				{
					strPartsJointName += "|";
				}
			}

			//
			PrtService::SetAlias(iolstspFoundResult02[i],strPartsJointName);
		}		

		//1 获得“紧固件描述”参数集
		CATISpecObject_var spJstDescripParmSet=NULL_var;
		PrtService::GetParmSetFromSpeObjt(iolstspFoundResult02[i],spJstDescripParmSet,"紧固件描述");
		//1.1 获得紧固件描述
		CATListValCATISpecObject_var iolstspParmSet;
		if (NULL_var != spJstDescripParmSet)
		{
			//检查是否存在
			PrtService::GetParmSetFromSpeObjt(spJstDescripParmSet,iolstspParmSet);
		}

		//2 获得 紧固件集合 第三层 XXX紧固件集合
		CATListValCATISpecObject_var iolstspFoundResult03;
		PrtService::SearchALLSonFromRootGSMTool(iolstspFoundResult02[i],iolstspFoundResult03);
		//
		CATListValCATUnicodeString alistStrFstName;
		CATListOfDouble alistDFstCount;

		// 
		for (int j = 1; j <= iolstspFoundResult03.Size(); j++)
		{
			//2.1 获得单个紧固件几何图形集，内部可能包含 一条线，多个圈模型
			CATListValCATISpecObject_var iolstspFoundResult04;
			PrtService::SearchALLSonFromRootGSMTool(iolstspFoundResult03[j],iolstspFoundResult04);

			//2.2 获得内部含有的线圈模型，得到其数量信息
			for (int m = 1; m <= iolstspFoundResult04.Size(); m++)
			{
				CATListValCATISpecObject_var iolstspFoundResult05;
				PrtService::SearchALLSonFromRootGSMTool(iolstspFoundResult04[m],iolstspFoundResult05,"CATISpecObject");
				//
				//每个几何图形集下面的线圈分类列表
				CATListValCATISpecObject_var alistSpecLine,alistSpecCircle;	

				//判断模型类型：线圈？对其进行处理，获得名称
				for (int n=1; n <= iolstspFoundResult05.Size(); n++)
				{
					//
					CATIMfMonoDimResult *piMonoDim = NULL;
					HRESULT rc = iolstspFoundResult05[n]->QueryInterface(IID_CATIMfMonoDimResult, (void**)&piMonoDim);

					//成功获取其为一维线圈信息，第一对个数进行重新统计，第二对线的长度信息进行重新计算统计
					if (SUCCEEDED(rc))
					{
						//
						CATIAlias_var spAlias = iolstspFoundResult05[n];
						CATUnicodeString strFstName = spAlias->GetAlias();
						//
						CATBoolean existFlag = FALSE;
						int dCount;
						for (int k=1; k<=alistStrFstName.Size(); k++)
						{
							//
							if (alistStrFstName[k] == strFstName)
							{
								dCount = k;
								existFlag = TRUE;
								//
								break;
							}							
						}

						//如果存在
						if (existFlag == TRUE)
						{
							alistDFstCount[dCount]++;
							//cout<<"数量为："<<alistDFstCount[dCount]<<endl;
						}
						else
						{
							alistStrFstName.Append(strFstName);
							alistDFstCount.Append(1.0);
						}

						//-------------------------------
						//判断是线还是圈，放入不同列表中
						//-------------------------------
						CATIGSMLinePtDir *piGSMLine = NULL;
						CATIGSMCircleCenterAxis *piCenterCircle = NULL;
						rc = iolstspFoundResult05[n]->QueryInterface(IID_CATIGSMLinePtDir, (void**)&piGSMLine);
						if (SUCCEEDED(rc))
						{
							alistSpecLine.Append(iolstspFoundResult05[n]);
							piGSMLine->Release();
							piGSMLine=NULL;
						}
						rc = iolstspFoundResult05[n]->QueryInterface(IID_CATIGSMCircleCenterAxis, (void**)&piCenterCircle);
						if (SUCCEEDED(rc))
						{
							alistSpecCircle.Append(iolstspFoundResult05[n]);
							piCenterCircle->Release();
							piCenterCircle=NULL;
						}				

						//				
						piMonoDim->Release();
						piMonoDim = NULL;
					}					
				}

			}

			//收起该层所有的几何图形结构树节点
			PrtService::CollapseAllNode(iolstspFoundResult03[j]);
		}

		//对比参数列表中的内容 和 重新统计后的内容
		CATListValCATISpecObject_var alistDeleteFstParam;
		for (int m=1; m<=iolstspParmSet.Size(); m++)
		{	
			//
			CATListValCATUnicodeString lststrResult;
			CATUnicodeString strExistName = PrtService::GetAlias(iolstspParmSet[m]);
			CHandleString::StringToVector(strExistName,"|",lststrResult);
			//
			CATBoolean existFlag = FALSE;
			//
			for (int n=1; n<=alistStrFstName.Size(); n++)
			{
				if (lststrResult[1] == alistStrFstName[n])
				{
					//更改名字
					CATUnicodeString stridCount;stridCount.BuildFromNum(alistDFstCount[n]);
					CATUnicodeString strJstSetName = alistStrFstName[n] + "|" + stridCount;
					//
					PrtService::SetAlias(iolstspParmSet[m],strJstSetName);
					existFlag = TRUE;
				}
			}

			//如果更新后已经不存在，则放入删除列表
			if (existFlag == FALSE)
			{
				alistDeleteFstParam.Append(iolstspParmSet[m]);
			}

		}

		//删除已经不存在紧固件的属性描述
		for (int m=1; m <= alistDeleteFstParam.Size(); m++)
		{
			alistDeleteFstParam[m]->GetFather()->Remove(alistDeleteFstParam[m]);
		}

		//收起参数几何集
		PrtService::ExpandCollapseNode(spJstDescripParmSet);
		PrtService::ExpandCollapseNode(spJstDescripParmSet);
	}

	//更新ZP模型
	PrtService::ObjectUpdate(spPart);		

}

//
//过滤函数
CATBoolean PrtFstDeleteCmd::SeletedIsFSTLine(CATDialogAgent * iAgent, void * iUsefulData)
{
	CATBoolean rc = FALSE ;
	if ( NULL == iAgent ) return rc ;

	//定义集群
	CATSO * pSO = NULL ;
	pSO = m_piFstLineAgt->GetListOfValues();
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

			if (spLeaf != NULL_var)
			{
				CATISpecObject_var spChoosedLine = spLeaf;
				//校验是否为 主紧固件
				BOOL bIsExistKey = false;
				CATUnicodeString strFSTMainKey("F_ATTEX_SIGN");
				CATUnicodeString strFSTMainKeyValue;
				PrtService::GetSepcObjectAttrEx(bIsExistKey,strFSTMainKeyValue,strFSTMainKey,spChoosedLine);
				//

				if (bIsExistKey && strFSTMainKeyValue=="YES")
				{
					return TRUE;
				}

			}
		}
	}
	

	return rc;
}

//各种转换消息响应函数
CATBoolean PrtFstDeleteCmd::ChooseFSTLines( void *UsefulData)
{
	//定义集群
	CATSO * pSO = NULL ;
	pSO = m_piFstLineAgt->GetListOfValues();
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

			if (spLeaf != NULL_var)
			{
				CATISpecObject_var spChoosedLine = spLeaf;
				//添加到列表中，对于重复的直接删除

				BOOL existFlag = FALSE;
				for (int j = 1; j <= m_alstSpecFSTLines.Size(); j++)
				{
					if (m_alstSpecFSTLines[j] == spLeaf)
					{						
						m_alstSpecFSTLines.RemoveValue(spLeaf);
						PrtService::RemoveHSO(spLeaf);

						//列表更新
						m_pDlg->_FSTLineSL->ClearLine();
						for (int i = 1; i <= m_alstSpecFSTLines.Size(); i ++)
						{
							CATUnicodeString strShowPath("");
							CATPathElement *piPath = NULL;
							PrtService::GetPathElementFromSpecObject(piPath,m_alstSpecFSTLines[i],NULL);
							PrtService::PathElementString(piPath,strShowPath,TRUE);
							m_pDlg->_FSTLineSL->SetLine(strShowPath);

							piPath->Release();
							piPath=NULL;
						}
						
						existFlag = TRUE;
						break;
					}
				}

				//不存在放入
				if (!existFlag) //
				{
					//先清空列表
					if (m_alstSpecFSTLines.Size() == 0)
					{
						m_pDlg->_FSTLineSL->ClearLine();
					}
					//
					m_alstSpecFSTLines.Append(spLeaf);

					//
					CATUnicodeString strShowPath("");
					strShowPath = spLeaf->GetDisplayName();
					PrtService::PathElementString(pSubPath,strShowPath,TRUE);
					m_pDlg->_FSTLineSL->SetLine(strShowPath);
				}

			}
		}
	}

	//
	m_pDlg->_FSTLineSL->ClearSelect();
	m_piFstLineAgt->InitializeAcquisition();
	return TRUE;
}

//
void PrtFstDeleteCmd::GetSeletedFSTLine(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//获得并清空ISO
	m_piISO->Empty();

	//获取所选信息
	int  iSize = m_pDlg->_FSTLineSL->GetSelectCount();
	if (iSize != 0 )
	{
		//得到当前所选行的具体信息：行号
		int * ioTabRow = new int[iSize];
		m_pDlg->_FSTLineSL->GetSelect(ioTabRow,iSize);

		//获得线对应的端点
		CATISpecObject_var spLine = m_alstSpecFSTLines[ioTabRow[0]+1];
		CATIMeasurableLine_var spMeasLine = spLine;
		CATMathPoint  ioOrigin;
		spMeasLine->GetOrigin(ioOrigin);
		//
		CATLISTV(CATMathPoint) lstMathPoints;
		lstMathPoints.Append(ioOrigin);

		//使其居中，高亮显示模型信息
		PrtService::CenterViewPoints(lstMathPoints);
		PrtService::HighlightHSO(spLine);

		//
		CATIAlias_var spAliasOnPt = spLine;
		CATUnicodeString StrTextValue = spAliasOnPt->GetAlias();

		CATMathPointf TextPosNode;
		TextPosNode.x = (float)(ioOrigin.GetX());
		TextPosNode.y = (float)(ioOrigin.GetY());
		TextPosNode.z = (float)(ioOrigin.GetZ());

		CAT3DCustomRep * pRepForTextStart= new CAT3DCustomRep();
		CATGraphicAttributeSet   TextGaNode ;
		TextGaNode.SetColor(RED);
		CAT3DAnnotationTextGP   *pTextGPSrart = new CAT3DAnnotationTextGP(TextPosNode,StrTextValue);
		pRepForTextStart->AddGP(pTextGPSrart,TextGaNode);
		CATModelForRep3D *piRepPtAlias = new CATModelForRep3D() ;
		piRepPtAlias->SetRep(pRepForTextStart) ;
		m_piISO->AddElement(piRepPtAlias);

		piRepPtAlias->Release();
		piRepPtAlias=NULL;

		//  [7/5/2012 xyuser]
		//显示信息
		m_pDlg->_ExternalInfoML->ClearLine();
		m_pDlg->_InstanceInfoML->ClearLine();
		//标准号信息
		CATListValCATUnicodeString lststrJstPropertyName,lststrJstPropertyValue;
		CATUnicodeString strProNameKey("F_ATTEX_PropertyNameList");
		CATUnicodeString strProValueKey("F_ATTEX_PropertyValueList");
		//
		BOOL bIsExistKey = false;
		PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstPropertyName,strProNameKey,spLine);
		PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstPropertyValue,strProValueKey,spLine);
		//
		for (int i=1; i<=lststrJstPropertyName.Size(); i++)
		{
			m_pDlg->_ExternalInfoML->SetColumnItem(0,lststrJstPropertyName[i]);
			m_pDlg->_ExternalInfoML->SetColumnItem(1,lststrJstPropertyValue[i]);
		}

		//规格信息
		CATListValCATUnicodeString lststrJstSpecialName,lststrJstSpecialValue;
		CATUnicodeString strSpecialNameKey("F_ATTEX_SpecialNameList");
		CATUnicodeString strSpecialValueKey("F_ATTEX_SpecialValueList");
		//
		PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialName,strSpecialNameKey,spLine);
		PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialValue,strSpecialValueKey,spLine);	

		for (int i=1; i<=lststrJstPropertyName.Size(); i++)
		{
			m_pDlg->_InstanceInfoML->SetColumnItem(0,lststrJstSpecialName[i]);
			m_pDlg->_InstanceInfoML->SetColumnItem(1,lststrJstSpecialValue[i]);
		}
	}
	
}


//
void PrtFstDeleteCmd::RemoveSelectedPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//获取所选信息
	int  iSize = m_pDlg->_FSTLineSL->GetSelectCount();
	if (iSize != 0 )
	{
		//得到当前所选行的具体信息：行号
		int * ioTabRow = new int[iSize];
		m_pDlg->_FSTLineSL->GetSelect(ioTabRow,iSize);
		//
		
		//
		CATISpecObject_var spLine = m_alstSpecFSTLines[ioTabRow[0]+1];
		PrtService::RemoveHSO(spLine);
		m_piISO->Empty();
		m_alstSpecFSTLines.RemoveValue(spLine);
		//

		//列表更新
		m_pDlg->_FSTLineSL->ClearLine();
		for (int i = 1; i <= m_alstSpecFSTLines.Size(); i ++)
		{
			CATUnicodeString strShowPath("");
			CATPathElement *piPath = NULL;
			PrtService::GetPathElementFromSpecObject(piPath,m_alstSpecFSTLines[i],NULL);
			PrtService::PathElementString(piPath,strShowPath,TRUE);
			m_pDlg->_FSTLineSL->SetLine(strShowPath);

			piPath->Release();
			piPath=NULL;
		}

		//
		//删除显示信息
		m_pDlg->_ExternalInfoML->ClearLine();
		m_pDlg->_InstanceInfoML->ClearLine();

	}

}
void PrtFstDeleteCmd::RemoveAllPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	m_alstSpecFSTLines.RemoveAll();
	m_pDlg->_FSTLineSL->ClearLine();
	//
	//删除显示信息
	m_pDlg->_ExternalInfoML->ClearLine();
	m_pDlg->_InstanceInfoML->ClearLine();	
	//
	m_piHSO->Empty();
	m_piISO->Empty();
	//
}
