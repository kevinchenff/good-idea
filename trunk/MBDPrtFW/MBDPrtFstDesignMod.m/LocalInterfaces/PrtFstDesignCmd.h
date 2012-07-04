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
  //选择紧固件类型
  void ChooseFstCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data); 
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
  void CreateFstLinesAndCircles(CATISpecObject_var ispPoint01,CATISpecObject_var ispPoint02,CATISpecObject_var ispJointTypeGSMTool,CATISpecObject_var ispPosPoint);
  //计算安装方向及夹持厚度，为紧固件选择提供依据
  void CalculateJoinThickInTop(CATListValCATISpecObject_var ilstspSurf01,CATListValCATISpecObject_var ilstspSurf02, CATListValCATISpecObject_var ilstspPoints);
  //转变OK APPLY按钮的显示状态
  void ChangeOKApplyState();
  //设置或者修改 紧固件描述 中的类型信息
  void SetOrChangeJstTypeInfo(CATISpecObject_var iospJointGSMTool,CATUnicodeString strChooseFstType,double idCount,CATListValCATUnicodeString ilststrJstTypeInfoName, CATListValCATUnicodeString ilststrJstTypeInfoValue);

  //从PV列表中获得指定的字符串
  void GetStrlistFromListPV(int iCount,CATListPV ipListStrName,CATListValCATUnicodeString &ioalstName);

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

	//定义字符串列表指针，从动态DLL中获取这些信息，此值将直接写入特征属性中
	//---------------------------------------------------------
	CATListPV  m_pListStrPropertyName,m_pListStrPropertyValue;
	CATListPV  m_pListStrSpecialName,m_pListStrSpecialValue;
	CATListValCATUnicodeString m_alistStrFSTType; //存储紧固件类型：螺栓，螺钉，铆钉，螺母，垫片
	CATListValCATUnicodeString m_lststrCirclePositions; //螺母、垫片的安装位置，需要写入特征属性中

	//
	//从交互选择中获取如下信息
	CATListValCATUnicodeString m_alistStrFSTName; //存储紧固件规格号
	double m_dMainFstLength, m_dMainFstThickLimit;
	CATListOfDouble m_lstCircleRadiusValues,m_lstCircleThicks;

	//定义标识，确认是否已经选择了紧固件
	CATBoolean m_userChoosedFlag;


};

//----------------------------------------------------------------------

#endif
