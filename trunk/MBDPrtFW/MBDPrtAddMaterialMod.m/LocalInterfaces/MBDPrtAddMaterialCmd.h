// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDPrtAddMaterialCmd.h
// The state chart based command: MBDPrtAddMaterialCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   STATECOMMAND
//End CAA2 Wizard Generation Report
//
//  Feb 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDPrtAddMaterialCmd_H
#define MBDPrtAddMaterialCmd_H

// ktsoftware module
#include "ktKerExcel.h"

//ktsoftware PubHeader
#include "ktPubHeaders.h"

//Material Framework
#include "CATMaterialServices.h"

// CATMatInterfaces Framework
#include "CATIMaterialDocument.h" 
#include "CATIMaterialSupport.h" 
#include "CATILibraryFeature.h" 
#include "CATIMaterialFeature.h" 
#include "CATIFamilyFeature.h"

//
#include "MBDPrtAddMaterialDlg.h"
#include "MBDPrtMainMaterialParamDlg.h"


//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class MBDPrtAddMaterialCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDPrtAddMaterialCmd, CATStateCommand )

  public:

  MBDPrtAddMaterialCmd();
  virtual ~MBDPrtAddMaterialCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();
  //
  //消息框响应函数
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //
  void SearchMaterialCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void SearchResultMLSelectedCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void AddMainMaterialCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void AddAuxiliaryMaterialCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //
  //判断是否为ZP模型
  BOOL IsThisZPPrt(CATUnicodeString istrDocName);
  //获取材料catalog文件
  HRESULT CreateMaterialCatalog(CATUnicodeString istrMainCategory,CATUnicodeString istrMatTypeName,CATUnicodeString istrMatIdenCode,double idDensity,double idPoissonRatio,double idYieldStrength);
  //赋材料
  HRESULT ApplyMaterial(CATIMaterialFeature *pIMaterialFeature);
  //更改材料属性
  HRESULT SetMaterialProperty(CATIMaterialFeature * &pIMaterialFeature,CATUnicodeString istrMatIdenCode,double idDensity,double idPoissonRatio,double idYieldStrength);
  //初始化列表
  void ClearListStrMaterialDetailInfo();
  //获得材料所选信息
  HRESULT GetSelectedMaterialInfo();

  //
  //辅助框响应函数
  void CloseMatParamDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void OkMatParamDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);


  private:

	  //文档指针
	  CATDocument *m_piDoc;
	  CATUnicodeString m_strDocName;

	  //主对话框
	  MBDPrtAddMaterialDlg *m_pDlg;

	  //所选行
	  int m_selectResultLine;

	  //查询结果数组的指针
	  CATListPV  m_pListStrMaterialDetailInfo;

	  //主材辅助参数对话框
	  MBDPrtMainMaterialParamDlg *m_pMatParamDlg;

	  //所选行号
	  int m_iSelectedIndex;
	  //材料选择所要获得的属性值
	  CATListValCATUnicodeString m_alsStrMatInfoCATIAName,m_alsStrMatInfoCATIAValue;
	  //材质颜色
	  unsigned int m_iValuePrtColor[3];
	  //密度(Density)、伸长率(Poisson Ratio)、抗拉强度(Yield Strength)
	  double m_dDensity,m_dPoissonRatio,m_dYieldStrength;

	  //获取材料大类名称
	  CATUnicodeString m_strMatMainCatalog;

};

//----------------------------------------------------------------------

#endif
