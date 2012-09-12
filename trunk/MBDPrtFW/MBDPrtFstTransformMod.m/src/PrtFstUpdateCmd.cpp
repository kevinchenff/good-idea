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
#include "CATIBodyRequest.h"

//

#include "CATCreateExternalObject.h"
CATCreateClass( PrtFstUpdateCmd);

//螺栓螺丝高出部分必须 大于等于 2mm
const double cdBoltEndMinAllowence = 2;

//螺杆露出高度最小值
const double cdBoltStartMinAllowence = 0;
//螺杆露出高度最大值
const double cdBoltStartMaxAllowence = 1;


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstUpdateCmd::PrtFstUpdateCmd() :
  CATStateCommand ("PrtFstUpdateCmd", CATDlgEngOneShot, CATCommandModeExclusive) 
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
,m_pDlg(NULL),m_piDoc(NULL),m_piEditor(NULL),m_piHSO(NULL),m_piISO(NULL),m_strFilePath("")
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

   //获得并清空ISO
   m_piISO->Empty();
   m_piHSO->Empty();

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

	//增加对错误紧固件处理PB的响应
	AddAnalyseNotificationCB (m_pDlg->_ReportAndMarkPB, 
		m_pDlg->_ReportAndMarkPB->GetPushBActivateNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::ReportAndMarkCB,
		NULL);

	AddAnalyseNotificationCB (m_pDlg->_DeleteAllErrorPB, 
		m_pDlg->_DeleteAllErrorPB->GetPushBActivateNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::DeleteAllErrorCB,
		NULL);

	//
	//增加对 紧固件线列表的响应控制
	AddAnalyseNotificationCB (m_pDlg->_ErrorMultiList, 
		m_pDlg->_ErrorMultiList->GetListSelectNotification(),
		(CATCommandMethod)&PrtFstUpdateCmd::GetSeletedFSTLine,
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
	//
	//获得并清空ISO
	m_piISO->Empty();
	//清除数据列表
	m_alistSuccessfulSpec.RemoveAll();
	m_alistErrorSpec.RemoveAll();
	m_aliststrErrorInfo.RemoveAll();
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

			CATUnicodeString strTemp;strTemp.BuildFromNum(iolstspFoundResult04.Size());
			PrtService::ShowDlgNotify("iolstspFoundResult04",strTemp);

			//2.2 获得内部含有的线圈模型，得到其数量信息
			for (int m = 1; m <= iolstspFoundResult04.Size(); m++)
			{
				CATListValCATISpecObject_var iolstspFoundResult05;
				PrtService::SearchALLSonFromRootGSMTool(iolstspFoundResult04[m],iolstspFoundResult05,"CATISpecObject");
				//
				strTemp.BuildFromNum(iolstspFoundResult05.Size());
				PrtService::ShowDlgNotify("iolstspFoundResult05",strTemp);
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
				CheckFstLineLengthInfo(alistSpecLine,alistSpecCircle);	
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
		m_pDlg->_ErrorMultiList->SetColumnItem(2,m_aliststrErrorInfo[i]);
	}
}


//检查线模型的更新情况，是否超出安装长度要求，检验规则：长度-夹层厚度-n垫圈厚度-n螺母厚度
HRESULT PrtFstUpdateCmd::CheckFstLineLengthInfo(CATListValCATISpecObject_var &alistSpecLine,CATListValCATISpecObject_var &alistSpecCircle)
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

	//所要获得的所有长度信息: 总长度，夹持厚度，夹层厚度，螺母垫片总厚度
	double dLength = 0, dThickLimit = 0,dThick = 0,dNutsThick = 0;
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
	
	//3 计算螺母垫片总厚度
	for (int i = 1; i <= alistDNutThick.Size(); i ++)
	{
		dNutsThick += alistDNutThick[i];
	}

	//4 需要按照主紧固件类型 螺栓 螺钉 铆钉不同进行不同的处理
	CATUnicodeString strFSTTypeKey("F_ATTEX_FSTTYPE");
	CATUnicodeString iostrFSTType;
	BOOL bIsExistKey;
	PrtService::GetSepcObjectAttrEx(bIsExistKey,iostrFSTType,strFSTTypeKey,spLine);

	//5 拆分字符串 "F_ATTEX_FSTTYPE" ，获得其类型信息
	CATListValCATUnicodeString alststrDetailType;
	CHandleString::StringToVector(iostrFSTType,"|",alststrDetailType);
	//5.1 分情况判断
	CATUnicodeString strErrorDetailInfo("");
	CATListValCATUnicodeString alstErrorInfoItems;

	//----------------------------------------------------
	//螺栓
	//----------------------------------------------------
	if (alststrDetailType[1] == "螺栓")
	{
		//光杆应凸出夹层最大至1mm，不允许螺纹进入夹层
		if (dThickLimit >= dThick && dThickLimit <= (dThick+1) && dLength >= (dThick+dNutsThick+2))
		{
			m_alistSuccessfulSpec.Append(spLine);
		}
		else
		{
			m_alistErrorSpec.Append(spLine);
		}
		
		//生成错误信息
		if (dThickLimit < dThick)
		{
			CATUnicodeString strInfo(""),strTemp("");
			strTemp.BuildFromNum(dThick-dThickLimit,"%lf");
			strInfo += CATUnicodeString("螺栓光杆凹入夹层中，凹入尺寸量为：") + strTemp + CATUnicodeString("mm");
			
			alstErrorInfoItems.Append(strInfo);
		}

		if (dThickLimit > (dThick+1))
		{
			CATUnicodeString strInfo(""),strTemp("");
			strTemp.BuildFromNum(dThickLimit-dThick,"%lf");
			strInfo += CATUnicodeString("螺栓光杆凸出夹层值超过1mm，凸出尺寸量为：") + strTemp + CATUnicodeString("mm");

			alstErrorInfoItems.Append(strInfo);
		}

		if (dLength < (dThick+dNutsThick+2))
		{
			CATUnicodeString strInfo(""),strTemp("");
			strTemp.BuildFromNum((dThick+dNutsThick+2)-dLength,"%lf");
			strInfo += CATUnicodeString("螺栓尾端凸出螺母的高度H不得小于2mm，凸出尺寸量为：") + strTemp + CATUnicodeString("mm");

			alstErrorInfoItems.Append(strInfo);
		}

		//生成错误报告字符串
		for (int i=1; i<= alstErrorInfoItems.Size(); i++)
		{
			if (i!=alstErrorInfoItems.Size())
			{
				strErrorDetailInfo += alstErrorInfoItems[i]+"|";
			}
			else
			{
				strErrorDetailInfo += alstErrorInfoItems[i];
			}
		}
		//
		if (alstErrorInfoItems.Size()!=0)
		{
			//挂载错误信息
			m_aliststrErrorInfo.Append(strErrorDetailInfo);
			//
		}
		alstErrorInfoItems.RemoveAll();
	}

	//----------------------------------------------------
	//铆钉
	//----------------------------------------------------
	if (alststrDetailType[1] == "铆钉")
	{
		//再细分情况
		if (alststrDetailType[3] == "1") //平墩头铆钉
		{
			//
			CATListValCATUnicodeString lststrJstSpecialName,lststrJstSpecialValue;
			CATUnicodeString strSpecialNameKey("F_ATTEX_SpecialNameList");
			CATUnicodeString strSpecialValueKey("F_ATTEX_SpecialValueList");
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialName,strSpecialNameKey,spLine);
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialValue,strSpecialValueKey,spLine);
			//
			if (bIsExistKey)
			{
				CATUnicodeString strDiameterValue;
				for (int i=1; i<=lststrJstSpecialName.Size(); i++)
				{
					if (lststrJstSpecialName[i] == "公称直径")
					{
						strDiameterValue = lststrJstSpecialValue[i];
						break;
					}
				}
				//
				double dSTDLength=0,dvalue=0;
				strDiameterValue.ConvertToNum(&dvalue,"%lf");
				if (dvalue >= 4)
				{
				   dSTDLength = dvalue + 1.1*dThick;
				}
				else
				{
					dSTDLength = dvalue + 1.3*dThick;
				}

				//进行判断
				if (dLength >= dSTDLength)
				{
					m_alistSuccessfulSpec.Append(spLine);
				}
				else
				{
					m_alistErrorSpec.Append(spLine);

					CATUnicodeString strInfo,strTemp;
					strTemp.BuildFromNum(dSTDLength-dLength,"%lf");
					strErrorDetailInfo += "平墩头铆钉长度小于安装规范要求，尺寸差量为：" + strTemp + "mm";					
				}
			}
		}

		//
		else if (alststrDetailType[3] == "2") //压窝铆接平墩头铆钉
		{
			//
			//进行判断
			if (dLength <= dThick)
			{
				m_alistErrorSpec.Append(spLine);

				CATUnicodeString strInfo,strTemp;
				strTemp.BuildFromNum(dThick-dLength,"%lf");
				strErrorDetailInfo += "压窝铆接平墩头铆钉长度小于夹层厚度，尺寸差量为：" + strTemp + "mm";					
			}
			else
			{
				//
				CATListValCATUnicodeString lststrJstSpecialName,lststrJstSpecialValue;
				CATUnicodeString strSpecialNameKey("F_ATTEX_SpecialNameList");
				CATUnicodeString strSpecialValueKey("F_ATTEX_SpecialValueList");
				PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialName,strSpecialNameKey,spLine);
				PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialValue,strSpecialValueKey,spLine);
				//
				if (bIsExistKey)
				{
					//计算第一安装面的高度信息
					//1 获得第一个安装零件的实体特征，该特征只从PARTBODY中获取，其它的均不识别
					CATUnicodeString strPrdLinkKey("F_ATTEX_LINK_PRT");
					CATLISTV(CATISpecObject_var) lstSpecPrds;
					PrtService::GetSepcObjectAttrEx(bIsExistKey,lstSpecPrds,strPrdLinkKey,spLine);
					//
					CATIProduct_var spInstPrd = lstSpecPrds[1];
					CATISpecObject_var spPart=NULL_var;
					HRESULT rc = PrdService::GetPartFromPrd(spInstPrd,spPart);
					if (FAILED(rc))
					{
						PrtService::ShowDlgNotify("更新错误提示","当前模式下未加载第一安装零件模型，请检查是否加载或者模型未处于设计模式！");
						RequestDelayedDestruction();
					}

					//获取第一个安装面实体MainBody中所有实体特征
					CATListValCATISpecObject_var alstSpecInMainBody;
					//
					if (spPart != NULL_var)
					{
						CATIPartRequest_var spPrtRequest(spPart);

						//获取main body
						CATISpecObject_var spMainBody ;
						spPrtRequest->GetMainBody("MfDefault3DView",spMainBody);

						//
						CATIBodyRequest_var spBodyRequest = spMainBody;
						//获取Body Results
						CATListValCATBaseUnknown_var  oResults;
						spBodyRequest->GetResults("MfDefault3DView", oResults);

						for (int j=1; j<=oResults.Size(); j++)
						{
							CATIMf3DBehavior_var sp3DBehavor = oResults[j];
							CATISpecObject_var spSoildObj = oResults[j];
							//
							if(sp3DBehavor!=NULL_var)
							{
								if(sp3DBehavor->IsASolid()==S_OK)
								{
									alstSpecInMainBody.Append(spSoildObj);
								}
							}
						}

					}
					//
					// defines an open configuration for the operator
					CATSoftwareConfiguration * pConfig = new CATSoftwareConfiguration();
					// defines the data of the operator: configuration + journal
					CATTopData topdata(pConfig,NULL);
					//获得当前安装线的拓扑几何
					CATIGeometricalElement_var spGeomEleLine = spLine;
					CATBody_var spBodyLine = spGeomEleLine->GetBodyResult();
					//计算投影
					CATGeoFactory* iFactory = spBodyLine->GetFactory();
					//2 创建给第一安装面模型的交集
					double dDistance=0;
					//
					for (int j=1; j <= alstSpecInMainBody.Size(); j ++)
					{
						CATIGeometricalElement_var spGeomEleBody = alstSpecInMainBody[j];
						CATBody_var spBody = spGeomEleBody->GetBodyResult();
						//把特征拷贝到现在的PRT文件中
						CATBody_var spResultBody=NULL_var;
						PrtService::CopyTopoBody(iFactory,spBody,lstSpecPrds[1],spResultBody);
						//
						CATHybIntersect* pIntersect = CATCreateTopIntersect(iFactory, &topdata, spBodyLine,spResultBody);
						pIntersect->Run();
						CATBody* pBodyInters = pIntersect->GetResult();
						delete pIntersect;
						pIntersect = NULL;

						//
						if (pBodyInters != NULL)
						{
							//
							CATLISTP(CATCell) ioResult01;
							//
							pBodyInters->GetAllCells(ioResult01,0);
							//如果交点不是两个，跳过去继续
							if (ioResult01.Size() != 2)
							{
								continue;
							}
							//
							CATMathPoint mathPoint1,mathPoint2;
							//
							CATVertex* pVertex01 = (CATVertex*)ioResult01[1];
							CATVertex* pVertex02 = (CATVertex*)ioResult01[2];
							//
							CATPoint* pPoint01=pVertex01->GetPoint();
							CATPoint* pPoint02=pVertex02->GetPoint();
							//
							pPoint01->GetMathPoint(mathPoint1);
							pPoint02->GetMathPoint(mathPoint2);
							//获得两点之间的距离
							dDistance = mathPoint1.DistanceTo(mathPoint2);
						}

						//
						iFactory->Remove(spResultBody,CATICGMContainer::RemoveDependancies);

					}

					//
					CATUnicodeString strDiameterValue;
					for (int i=1; i<=lststrJstSpecialName.Size(); i++)
					{
						if (lststrJstSpecialName[i] == "公称直径")
						{
							strDiameterValue = lststrJstSpecialValue[i];
							break;
						}
					}
					//
					double dSTDLength=0,dvalue=0;
					strDiameterValue.ConvertToNum(&dvalue,"%lf");
					dSTDLength = 1.3*dvalue + dThick + dDistance;

					//进行判断
					if (dLength >= dSTDLength)
					{
						m_alistSuccessfulSpec.Append(spLine);
					}
					else
					{
						m_alistErrorSpec.Append(spLine);

						CATUnicodeString strInfo,strTemp;
						strTemp.BuildFromNum(dSTDLength-dLength,"%lf");
						strErrorDetailInfo += "压窝铆接平墩头铆钉长度小于安装规范要求，尺寸差量为：" + strTemp + "mm";				
					}
				}
			}			
		}

		//
		else if (alststrDetailType[3] == "3") //双面沉头铆钉
		{
			//
			CATListValCATUnicodeString lststrJstSpecialName,lststrJstSpecialValue;
			CATUnicodeString strSpecialNameKey("F_ATTEX_SpecialNameList");
			CATUnicodeString strSpecialValueKey("F_ATTEX_SpecialValueList");
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialName,strSpecialNameKey,spLine);
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialValue,strSpecialValueKey,spLine);
			//
			if (bIsExistKey)
			{
				CATUnicodeString strDiameterValue;
				for (int i=1; i<=lststrJstSpecialName.Size(); i++)
				{
					if (lststrJstSpecialName[i] == "公称直径")
					{
						strDiameterValue = lststrJstSpecialValue[i];
						break;
					}
				}
				//
				double dSTDLength=0,dvalue=0;
				strDiameterValue.ConvertToNum(&dvalue,"%lf");
				dSTDLength = 0.6*dvalue + dThick;
				
				//进行判断
				if (dLength >= dSTDLength)
				{
					m_alistSuccessfulSpec.Append(spLine);
				}
				else
				{
					m_alistErrorSpec.Append(spLine);

					CATUnicodeString strInfo,strTemp;
					strTemp.BuildFromNum(dSTDLength-dLength,"%lf");
					strErrorDetailInfo += "双面沉头铆钉长度小于安装规范要求，尺寸差量为：" + strTemp + "mm";					
				}
			}
		}

		//
		else if (alststrDetailType[3] == "4") //平头大圆角铆钉
		{
			//
			CATListValCATUnicodeString lststrJstSpecialName,lststrJstSpecialValue;
			CATUnicodeString strSpecialNameKey("F_ATTEX_SpecialNameList");
			CATUnicodeString strSpecialValueKey("F_ATTEX_SpecialValueList");
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialName,strSpecialNameKey,spLine);
			PrtService::GetSepcObjectAttrEx(bIsExistKey,lststrJstSpecialValue,strSpecialValueKey,spLine);
			//
			if (bIsExistKey)
			{
				CATUnicodeString strDiameterValue;
				for (int i=1; i<=lststrJstSpecialName.Size(); i++)
				{
					if (lststrJstSpecialName[i] == "公称直径")
					{
						strDiameterValue = lststrJstSpecialValue[i];
						break;
					}
				}
				//
				double dSTDLength=0,dvalue=0;
				strDiameterValue.ConvertToNum(&dvalue,"%lf");
				dSTDLength = 0.7*dvalue + dThick;

				//进行判断
				if (dLength >= dSTDLength)
				{
					m_alistSuccessfulSpec.Append(spLine);
				}
				else
				{
					m_alistErrorSpec.Append(spLine);

					CATUnicodeString strInfo,strTemp;
					strTemp.BuildFromNum(dSTDLength-dLength,"%lf");
					strErrorDetailInfo += "平头大圆角铆钉长度小于安装规范要求，尺寸差量为：" + strTemp + "mm";					
				}
			}
		}

		else
		{
			//进行判断
			if (dLength <= dThick)
			{
				m_alistErrorSpec.Append(spLine);

				CATUnicodeString strInfo,strTemp;
				strTemp.BuildFromNum(dThick-dLength,"%lf");
				strErrorDetailInfo += "铆钉长度小于夹层厚度，尺寸差量为：" + strTemp + "mm";					
			}

			else
			{
				m_alistSuccessfulSpec.Append(spLine);
			}
		}

	}

	//挂载错误信息
	m_aliststrErrorInfo.Append(strErrorDetailInfo);
	//	

	return rc;
}


void PrtFstUpdateCmd::ReportAndMarkCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//标识颜色所有错误紧固件
	for (int i=1; i <= m_alistErrorSpec.Size(); i++)
	{
		PrtService::SetSpecObjColor(m_alistErrorSpec[i],0,6,1);
	}

	//
	m_pFileDlg = new CATDlgFile(m_pDlg,"选择目录",CATDlgFolderChooser);
	m_pFileDlg->SetVisibility(CATDlgShow);
	AddAnalyseNotificationCB (m_pFileDlg,m_pFileDlg->GetDiaOKNotification(),(CATCommandMethod)&PrtFstUpdateCmd::OpenOK,NULL);
}

//
void PrtFstUpdateCmd::OpenOK(CATCommand * iSendingCommand, CATNotification * iSentNotification,CATCommandClientData iUsefulData)
{
	//导出EXCEL文件
	m_pFileDlg->GetDirectory(m_strFilePath);
	m_pFileDlg->RequestDelayedDestruction();
	m_pFileDlg = NULL;
	//
	char cTmp[512];
	CHandleString::myGetTime2(cTmp);
	//
	CATUnicodeString StrPath = m_strFilePath+"\\"+CATUnicodeString(cTmp)+"_"+"ErrorReportInfo.xls";
	StrPath.ReplaceSubString("\\\\","\\");
	CKerExcel  CEEndExcel;
	//
	CEEndExcel.Open();
	CEEndExcel.OpenSheet("Sheet1");
	//
	//输出EXCEL头
	CEEndExcel.SetItemText(1,1,"紧固件规格号");
	CEEndExcel.SetItemText(1,2,"紧固件ID");
	CEEndExcel.SetItemText(1,3,"总长度mm");	
	CEEndExcel.SetItemText(1,4,"夹持厚度mm");
	CEEndExcel.SetItemText(1,5,"夹层厚度mm");
	CEEndExcel.SetItemText(1,6,"更改时间");
	CEEndExcel.SetItemText(1,7,"错误信息");
	
	//
	for(int i=1;i<=m_alistErrorSpec.Size();i++)
	{
		//
		CATListValCATUnicodeString iListStrName;
		iListStrName.Append("ID");
		iListStrName.Append("总长度");
		iListStrName.Append("夹持厚度");
		iListStrName.Append("夹层厚度");
		iListStrName.Append("更改时间");
		CATListValCATUnicodeString ioListStrNameValue;
		PrtService::GetSpecObjCertainParams(m_alistErrorSpec[i],iListStrName,ioListStrNameValue);
		//
		CATUnicodeString strName;
		CATIAlias_var spAlias = m_alistErrorSpec[i];
		strName = spAlias->GetAlias();
		//
		
		//
		CEEndExcel.SetItemText(i+1,1,strName);
		for (int j=1; j<=ioListStrNameValue.Size(); j++)
		{
			CEEndExcel.SetItemText(i+1,j+1,ioListStrNameValue[j]);
		}
		CEEndExcel.SetItemText(i+1,7,m_aliststrErrorInfo[i]);
	}
	//
	CEEndExcel.SaveAs(StrPath);
	CEEndExcel.Exit();
}


void PrtFstUpdateCmd::DeleteAllErrorCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//
	//获得并清空ISO
	m_piISO->Empty();

	// 删除紧固件几何，并更新参数信息，所选列表
	for (int i=1; i <= m_alistErrorSpec.Size(); i++)
	{
		//删除之前先把原始定位点显示出来，方便后期重新定义
		//写入安装点特征，当删除特征时，可直接把该点恢复显示状态
		CATISpecObject_var spPosPoint=NULL_var;
		BOOL bIsExistKey = false; 
		CATUnicodeString strFSTPosPointKey("F_ATTEX_Point");
		PrtService::GetSepcObjectAttrEx(bIsExistKey,spPosPoint,strFSTPosPointKey,m_alistErrorSpec[i]);

		if (bIsExistKey && spPosPoint!=NULL_var)
		{
			PrtService::SetSpecObjShowAttr(spPosPoint,"Show");
		}

		//
		//写入紧固件辅助元素，删除的时候直接获取后删除该辅助元素
		CATUnicodeString strProcessPointKey("F_ATTEX_ProcessPoint");
		CATListValCATISpecObject_var alstProcessPoint;
		PrtService::GetSepcObjectAttrEx(bIsExistKey,alstProcessPoint,strProcessPointKey,m_alistErrorSpec[i]);
		for (int k=1; k<=alstProcessPoint.Size(); k++)
		{
			CATISpecObject_var spFather = alstProcessPoint[k]->GetFather();
			spFather->Remove(alstProcessPoint[k]);
			//
			//检查几何图形集是否已经不包含元素了
			CATListValCATISpecObject_var iolstspFoundResult;
			CATIDescendants_var spDescendants = spFather;
			spDescendants->GetDirectChildren("CATISpecObject",iolstspFoundResult);
			if (iolstspFoundResult.Size()==0)
			{
				spFather->GetFather()->Remove(spFather);
			}
		}

		//
		CATISpecObject_var spGSM03=m_alistErrorSpec[i]->GetFather()->GetFather();
		spGSM03->Remove(m_alistErrorSpec[i]->GetFather());
	}
	//
	//
	m_alistErrorSpec.RemoveAll();
	m_pDlg->_ErrorMultiList->ClearLine();
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
void PrtFstUpdateCmd::GetSeletedFSTLine(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	//获得并清空ISO
	m_piISO->Empty();
	m_piHSO->Empty();

	//获取所选信息
	int  iSize = m_pDlg->_ErrorMultiList->GetSelectCount();
	if (iSize != 0 )
	{
		//得到当前所选行的具体信息：行号
		int * ioTabRow = new int[iSize];
		m_pDlg->_ErrorMultiList->GetSelect(ioTabRow,iSize);

		//获得线对应的端点
		CATISpecObject_var spLine = m_alistErrorSpec[ioTabRow[0]+1];
		CATIMeasurableLine_var spMeasLine = spLine;
		CATMathPoint  ioOrigin, ioTopPoint;
		spMeasLine->GetOrigin(ioOrigin);
		//
		CATLISTV(CATMathPoint) lstMathPoints;
		lstMathPoints.Append(ioOrigin);

		//获得顶点信息
		CATIGSMLinePtDir_var spGSMLine = spLine;
		CATISpecObject_var spTopPoint;
		spGSMLine->GetStartingPoint(spTopPoint);
		CATIMeasurablePoint_var spMeasPoint = spTopPoint;
		spMeasPoint->GetPoint(ioTopPoint);


		//使其居中，高亮显示模型信息
		PrtService::CenterViewPoints(lstMathPoints,100);
		PrtService::HighlightHSO(spLine);

		//
		//
		CATListValCATUnicodeString iListStrName;
		iListStrName.Append("ID");
		CATListValCATUnicodeString ioListStrNameValue;
		PrtService::GetSpecObjCertainParams(spLine,iListStrName,ioListStrNameValue);
		//
		CATUnicodeString StrTextValue(""); StrTextValue += "ID = " + ioListStrNameValue[1];
		//

		CATMathPointf TextPosNode;
		TextPosNode.x = (float)(ioTopPoint.GetX());
		TextPosNode.y = (float)(ioTopPoint.GetY());
		TextPosNode.z = (float)(ioTopPoint.GetZ());

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
	}
}