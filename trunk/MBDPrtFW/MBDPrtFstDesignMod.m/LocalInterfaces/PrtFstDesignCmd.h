// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignCmd.h
// The state chart based command: PrtFstDesignCmd
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
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstDesignCmd_H
#define PrtFstDesignCmd_H

#include "ktPubHeaders.h"
#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "PrtFstDesignDlg.h"
#include "CATFeatureImportAgent.h"
#include "CATPathElementAgent.h"
#include "CATHSO.h"
#include "CAT3DBagRep.h"
#include "CAT3DManipulator.h"



//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class PrtFstDesignCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstDesignCmd, CATStateCommand )

  public:

  PrtFstDesignCmd();
  virtual ~PrtFstDesignCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();

  //消息框响应函数
  void OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void ApplyDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //判断是否为ZP模型
  BOOL IsThisZPPrt(CATUnicodeString istrDocName);

  //各种转换消息响应函数
  CATBoolean ChoosePoints( void *UsefulData);
  CATBoolean ChooseFirstSurfs( void *UsefulData);
  CATBoolean ChooseSecSurfs( void *UsefulData);
  //
  CATBoolean ActivePointsSL( void *UsefulData);
  CATBoolean ActiveFirstSurfSL( void *UsefulData);
  CATBoolean ActiveSecSurfSL( void *UsefulData);
  //
  CATBoolean ChoosePrds( void *UsefulData);
  CATBoolean ActivePrdSL( void *UsefulData);  
  CATBoolean ChoosePointGSM( void *UsefulData);  
  CATBoolean ActivePointGSMPB( void *UsefulData);  
  //
  //过滤函数
  CATBoolean SeletedIsPart(CATDialogAgent * iAgent, void * iUsefulData);
  //高亮显示当前所选行
  void ShowSeletedLine(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs);
  //删除所有点
  void DeleteAllPointsCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //反向安装方向
  void ReverseDirCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);  
  //在IOS中显示标记点
  void ShowPointInfoInISO(CATDlgSelectorList* opiSL,CATListValCATISpecObject_var olstSpecs);
  //判断一个曲面特征是否在另一个数组中
  BOOL IsTheSpecInLstSpec(CATISpecObject_var iSpec, CATListValCATISpecObject_var iLstSpec);
  //获得传入特征的的父级节点
  HRESULT GetLinkImportPrd(CATISpecObject_var& ispFeature,CATIProduct_var &ospSourcePrd);
  //箭头的回调函数
  void CBManipulator(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  //根据输入条件创建点线模型
  void CreateFstLineAndCircle();
  //获取放置点线模型的零件几何图形集
  void GetPartsJointGSMTool(CATISpecObject_var &iospJointGSMTool,CATListValCATUnicodeString ilstStrPartsInstName);
  //按照参数信息创建点线模型
  void CreateFstPointAndLines(CATISpecObject_var ispPoint01,CATISpecObject_var ispPoint02,CATISpecObject_var ispJointTypeGSMTool,CATUnicodeString strFstType,double iDistance,double iLength,double iPointSym,double iLineWidth);
  //计算安装方向及夹持厚度，为紧固件选择提供依据
  void CalculateJoinThickInTop(CATListValCATISpecObject_var ilstspSurf01,CATListValCATISpecObject_var ilstspSurf02, CATListValCATISpecObject_var ilstspPoints);
  //转变OK APPLY按钮的显示状态
  void ChangeOKApplyState();

private:
	PrtFstDesignDlg *m_pDlg;

	//文档指针
	CATDocument *m_piDoc;
	CATUnicodeString m_strDocName;
	CATFrmEditor *m_piEditor;
	CATHSO *m_piHSO;
	CATISO *m_piISO;

	//定义代理
	CATFeatureImportAgent *m_piFirstSurfAgt,*m_piSecSurfAgt,*m_piPointsAgt,*m_piPointGSMAgt;
	CATPathElementAgent *m_piPrdAgt;
	CATDialogAgent *m_piPointSLAgt,*m_piFirstSurfSLAgt,*m_piSecSurfSLAgt,*m_piPrdSLAgt,*m_piPointGSMPBAgt;

	//存储中间数据变量
	CATListValCATISpecObject_var m_lstSpecPoints,m_lstSpecPrds;
	CATListValCATISpecObject_var m_lstSpecFirstSurfs,m_lstSpecSecSurfs;

	//夹持厚度最大值及最小值
	double m_dJstThickMax,m_dJstThickMin;
};

//----------------------------------------------------------------------

#endif
