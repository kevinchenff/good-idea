// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstUpdateCmd.cpp
// The state chart based command: PrtFstUpdateCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstUpdateCmd.h"
#include "CATIndicationAgent.h"
#include "CATMathPlane.h"

//
#include "CATListOfDouble.h"
#include "CATIMfMonoDimResult.h"
#include "CATIGSMCircleCenterAxis.h"
#include "CATIMeasurableLine.h"
//

#include "CATCreateExternalObject.h"
CATCreateClass( PrtFstUpdateCmd);

const double cdBoltAllowence = 2;


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstUpdateCmd::PrtFstUpdateCmd() :
  CATStateCommand ("PrtFstUpdateCmd", CATDlgEngOneShot, CATCommandModeExclusive) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
,m_pDlg(NULL),m_piDoc(NULL),m_piEditor(NULL),m_piHSO(NULL),m_piISO(NULL)
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
PrtFstUpdateCmd::~PrtFstUpdateCmd()
{
   if (m_pDlg != NULL) 
   {
      m_pDlg->RequestDelayedDestruction();
	  m_pDlg=NULL;
   }
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void PrtFstUpdateCmd::BuildGraph()
{
	//
	m_pDlg = new PrtFstUpdateDlg();
	m_pDlg->Build();
	m_pDlg->SetVisibility(CATDlgShow); 

	// 主对话框的消息响应
	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaOKNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::OkDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetWindCloseNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::CloseDlgCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg, 
		m_pDlg->GetDiaCANCELNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::CloseDlgCB,
		NULL);
}


//判断是否为ZP模型
BOOL PrtFstUpdateCmd::IsThisZPPrt(CATUnicodeString istrDocName)
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

void PrtFstUpdateCmd::CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	RequestDelayedDestruction();
}

void PrtFstUpdateCmd::OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//清除数据列表
	m_alistSuccessfulSpec.RemoveAll();
	m_alistErrorSpec.RemoveAll();
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

				//调用更新函数，计算业务层次，线模型更新后是否失效
				double dAllowance = 0;
				CheckFstLineLengthInfo(alistSpecLine,alistSpecCircle,dAllowance);	
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

	//显示信息到列表框中
	m_pDlg->_SuccessMultiList->ClearLine();
	m_pDlg->_ErrorMultiList->ClearLine();

	//
	for (int i=1; i <= m_alistSuccessfulSpec.Size(); i ++)
	{
		CATUnicodeString IndexNum;
		IndexNum.BuildFromNum(i);
		m_pDlg->_SuccessMultiList->SetColumnItem(0,IndexNum);
		m_pDlg->_SuccessMultiList->SetColumnItem(1,PrtService::GetAlias(m_alistSuccessfulSpec[i]));
		m_pDlg->_SuccessMultiList->SetColumnItem(2,"夹持长度更新成功");

	}
	

	//
	for (int i=1; i <= m_alistErrorSpec.Size(); i ++)
	{
		CATUnicodeString IndexNum;
		IndexNum.BuildFromNum(i);
		m_pDlg->_ErrorMultiList->SetColumnItem(0,IndexNum);
		m_pDlg->_ErrorMultiList->SetColumnItem(1,PrtService::GetAlias(m_alistErrorSpec[i]));
		m_pDlg->_ErrorMultiList->SetColumnItem(2,"更新后紧固件夹持厚度失效");
	}	
}


//检查线模型的更新情况，是否超出安装长度要求，检验规则：长度-夹层厚度-n垫圈厚度-n螺母厚度
HRESULT PrtFstUpdateCmd::CheckFstLineLengthInfo(CATListValCATISpecObject_var &alistSpecLine,CATListValCATISpecObject_var &alistSpecCircle,double dAllowance)
{

	HRESULT rc = S_OK;
	//1 获取线模型特征的“夹持线”，得到其长度，如果发生变化更新“夹层厚度”，同时更新“更改时间”
	CATIGSMLinePtDir_var spLine = alistSpecLine[1];
	CATIGSMDirection_var spDirection = NULL_var;
	spLine->GetDirection(spDirection);
	CATISpecObject_var spIntersectionLine = spDirection->GetDirectionElement();
	
	//获得参数“夹层厚度”
	CATListValCATUnicodeString iListStrName;
	//iListStrName.Append("Start");
	iListStrName.Append("总长度");
	iListStrName.Append("夹持厚度");
	iListStrName.Append("夹层厚度");
	iListStrName.Append("更改时间");
	CATListValCATUnicodeString ioListStrNameValue;
	PrtService::GetSpecObjCertainParams(spLine,iListStrName,ioListStrNameValue);

	//计算夹层厚度
	double dJstLength = 0;
	CATIMeasurableLine_var spMeasLine = spIntersectionLine;
	spMeasLine->GetLength(dJstLength);

	//
	double dLength = 0, dThickLimit = 0,dThick = 0;
	//
	ioListStrNameValue[1].ConvertToNum(&dLength,"%lf");
	ioListStrNameValue[2].ConvertToNum(&dThickLimit,"%lf");
	ioListStrNameValue[3].ConvertToNum(&dThick,"%lf");

	iListStrName.RemovePosition(1);
	ioListStrNameValue.RemovePosition(1);
	iListStrName.RemovePosition(1);
	ioListStrNameValue.RemovePosition(1);

	//比较
	if (dJstLength != dThick)
	{
		//如果夹持厚度已经发生变化，更新信息
		//
		CATUnicodeString strTemp;
		strTemp.BuildFromNum(dJstLength);
		ioListStrNameValue[1]=strTemp;
		//
		char str[20];
		CHandleString::myGetTime(str);
		ioListStrNameValue[2]=CATUnicodeString(str);		
		//
		PrtService::ModifySpecObjCertainParams(m_piDoc,spLine,iListStrName,ioListStrNameValue);
	}

	
	//2 获取垫圈及螺母的“厚度值”
	iListStrName.RemoveAll(); ioListStrNameValue.RemoveAll();
	iListStrName.Append("厚度值");
	//
	CATListOfDouble alistDNutThick;
	//
	for (int i=1; i <= alistSpecCircle.Size(); i ++)
	{
		PrtService::GetSpecObjCertainParams(alistSpecCircle[i],iListStrName,ioListStrNameValue);
		double dTemp=0;
		ioListStrNameValue[1].ConvertToNum(&dTemp,"%lf");
		alistDNutThick.Append(dTemp);
	}
	
	//3 计算并与余量信息做对比
	//需要按照主紧固件类型 螺栓 螺钉 铆钉不同进行不同的处理
	double dCompareValue = dThickLimit-dThick;
	for (int i = 1; i <= alistDNutThick.Size(); i ++)
	{
		dCompareValue -= alistDNutThick[i];
	}

	if (dCompareValue >= dAllowance)
	{
		m_alistSuccessfulSpec.Append(alistSpecLine);
	}
	else
	{
		m_alistErrorSpec.Append(alistSpecLine);
	}

	return rc;
}