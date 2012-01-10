// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtService.h
// Header definition of PrtService
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef PrtService_H
#define PrtService_H

#include "ktPrtService.h"
#include "CATBaseUnknown.h"
#include "ktPubHeaders.h"
#include "CATListOfCATPathElement.h"
#include "CATMathDirectionf.h"
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"


//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href PrtService constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new PrtService;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktPrtService PrtService: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     PrtService ();
     virtual ~PrtService ();

  // Copy constructor and equal operator
  // -----------------------------------
  PrtService (PrtService &);
  PrtService& operator=(PrtService&);


//**********************************************************************************************************************************************************************************************************************************************************
//������������
//**********************************************************************************************************************************************************************************************************************************************************
  
  //��ȡCATIA�����ļ��е�ĳ������ֵ
  //����˵����iKey ��������oValue����ֵ
  static
  HRESULT GetEnvValue(const CATUnicodeString& iKey, CATUnicodeString& oValue);


//**********************************************************************************************************************************************************************************************************************************************************
//����ͼ�μ���������
//**********************************************************************************************************************************************************************************************************************************************************

  //���켰��ȡ����ͼ�μ���
  static HRESULT CreateGSMTool(CATDocument* piDocument,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);
  static HRESULT ObtainGSMTool(CATDocument* piDocument,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //��ȡ���ߴ���GSMTool
  static HRESULT CreateOrRetrieveGS(CATISpecObject_var iParentGS,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //��ѯ����ͼ�μ�
  //����˵����
  static 
  void CAAGsiSearchFeatureFromName(CATDocument * ipDoc, CATListValCATUnicodeString  &ListStrSearchedFeatName,CATListValCATISpecObject_var &ListValOfspSearchGSMTool);

  //��������ͼ�μ�
  // -------------------------------------------------------------
  // iTopLevel = 1 / UNDER Part 
  // iTopLevel = 0 / UNDER Current feature  if spParentForTool not specify 
  // iTopLevel = 0 / UNDER  spParentForTool if spParentForTool  is specify
  // iDiag = 0 or -1  OK 
  // iDiag = 1  A GS  can only be inserted under another GS or directly under the part
  // iDiag = 2  A Body or an OGS can only be inserted under another Body or OGS  or directly under the part
  // iDiag = 3  Input Parent for tool is not a GS, OGS or Body
  // -------------------------------------------------------------
  static 
  HRESULT CAAGsiCreateGeometricFeatureSets (const CATIContainer_var &ispCont, const CATUnicodeString& iName,  const CATISpecObject_var & spInputParentTool ,CATISpecObject_var  & spSpecTool,  int & oDiag, int iTopLevel=1, int iType=0);

  //����������ĳ�����ڵ㿪ʼ��CATIA�ṹ���ϼ�������ͼ�μ�������ָ���ڵ���һ��
  static
  HRESULT SearchGSMToolByName(CATISpecObject_var spGSMToolRoot,CATUnicodeString strSearchName,CATISpecObject_var &spFoundResult);

  //VBA��ʽ �򵥸�����ͼ�μ����ò���
  static 
  void AddMBDGSMToolParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,CATISpecObject_var spSearchedGSMTool);

  //VBA��ʽ �޸ļ��μ���ĳЩ��������������������Զ�����
  static
  void ModifyGSMToolsCertainParameters(CATDocument * piDoc,CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  //�������ģ��GSMTools�а��������в�����Ӧ���� CATIA��LCA����ʱ��
  static 
  void ExportMBDGSMToolsParameters(CATListValCATISpecObject_var const &ListOfspGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // ��ѯ�õ�ĳ����ͼ�μ��������в���
  static 
  void GetGSMToolsParameters(CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // ��ѯ�õ�ĳ����ͼ�μ�����ĳЩ����
  static 
  void GetGSMToolCertainParams(CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  // ����ĳ������ͼ�μ������ĳЩ���������ֵ
  static
  void SetGSMToolsCertainParams(CATDocument * piDoc,CATISpecObject_var const &spGSMTool,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  //VBA��ʽ ������MBD����ͼ�μ����ò�����Ӧ����LCA��CATIA��������ʱ����
  static 
  void ExportMBDPartParamToGSMTool(CATDocument * ipDoc,CATListValCATISpecObject_var const &ListOfspMBDGSMTools);

  //VBA��ʽ �򵥸�����ͼ�μ����ò���,���ð��������ǰ�����ݣ��������µ����� 
  static 
  void ModifyMBDParamToGSMTool(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,CATISpecObject_var spGSMTool);







//**********************************************************************************************************************************************************************************************************************************************************
//CATPart�ļ�����
//**********************************************************************************************************************************************************************************************************************************************************

  // ��õ�ǰpart�ļ���prtContainer
  static
  CATDocument * GetPrtDocument();

  //���ݴ����Spec IID���ĵ�DOC�л�ȡ����Spec
  static void GetContentSpecsByNameFromDoc(CATDocument *piDoc, CATUnicodeString strSpecIID, CATListValCATISpecObject_var &iolistSpecs);

  //���ݴ����Spec IID���ĵ�Father GSMTool�л�ȡ����Spec
  static void GetContentSpecsByNameFromGSMTool(CATISpecObject_var spFatherGSMTool,CATUnicodeString strSpecIID, CATListValCATISpecObject_var &iolistSpecs);

  //���������Լ��������ƴ������л�ȡ ĳ����ָ��
  static CATBoolean ObtainChild(CATIPrtContainer* iPrtContainer,CATUnicodeString iType,CATUnicodeString iName,CATISpecObject_var &oGSSpecObj);

  //������ɫ��͸����
  static HRESULT SetSpecObjColor(CATISpecObject_var iSpecObj,int iColor);
  static HRESULT SetSpecObjOpacityAttr(CATISpecObject_var iSpecObj,CATUnicodeString iOpacityOrNoOpacity);

  //���ĵ�ָ����PrdNumber
  static void GetPrdNumberFormDoc(CATDocument * ipiDocument,CATUnicodeString &iostrPrdNumber);




//**********************************************************************************************************************************************************************************************************************************************************
//��������
//**********************************************************************************************************************************************************************************************************************************************************

  //��ȡ����������ALIAS
  static CATUnicodeString GetAlias(IUnknown* iObj);
  static HRESULT SetAlias(IUnknown* iObj,CATUnicodeString iName);

  //��������������ͼ�μ�
  static 
  HRESULT CAAGsiInsertInProceduralView(const CATISpecObject_var  ispObjectToAppend, CATISpecObject_var  ispInputParent);

  //����ͼ�μ�����������
  static 
  HRESULT ObjectUpdate(const CATISpecObject_var & ispSpec);

  //�����������ԣ���ɫ����ʾ״̬��
  static
  HRESULT SetSpecGraphProperty(CATISpecObject_var spSpecOnObject,CATVisPropertiesValues Attribut,CATVisPropertyType VisPropertyType, CATVisGeomType VisGeomType);

  // -------------------------------------------------------------
  // Manage Litteral 
  // -------------------------------------------------------------
  //
  //Instanciate Litteral
  // --------------------------------
  // NomLitteral = 
  // "Length"
  // "Angle"
  // "Integer" 
  // "Real"
  // "Booleen" 
  static 
  CATICkeParm_var CAAGsiInstanciateLitteral (CATUnicodeString  NomLitteral,CATUnicodeString Name);

  //��������
  static 
  CATICkeParm_var LocalInstLitteral (void * Value, int IsValuate, CATUnicodeString NomLitteral,CATUnicodeString Name);

  //��������Ϊ���ػ���ʾ
  static
  HRESULT SetSpecObjShowAttr(CATISpecObject_var iSpecObj,CATUnicodeString iShowOrHide);

  //���������б�Ϊ���ػ���ʾ
  static
  HRESULT SetListSpecObjShowAttr(CATListValCATISpecObject_var &iListSpecObj,CATUnicodeString iShowOrHide);

  //��ȡ����Ϊ���ػ���ʾ
  static
  HRESULT GetSpecObjShowAttr(CATISpecObject_var iSpecObj,CATBoolean &iShowOrHide);

  //����int ����
  static BOOL SetSepcObjectAttrEx(const int iValue, const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //��ȡint ����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,int &iValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //���long����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,long &lValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //����double����
  static BOOL SetSepcObjectAttrEx(const double dbValue,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);
  //��ȡdouble����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,double &dbValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //����CATUnicodeString����
  static BOOL SetSepcObjectAttrEx(const CATUnicodeString strValue,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //��ȡCATUnicodeString����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATUnicodeString &strValue,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //����CATLISTV(CATUnicodeString)����
  static BOOL SetSepcObjectAttrEx(CATLISTV(CATUnicodeString) lstStrings,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);
  
  //��ȡCATLISTV(CATUnicodeString)����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATLISTV(CATUnicodeString) &lstStrings,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //����doubl list����
  static BOOL SetSepcObjectAttrEx( CATRawColldouble doubleList,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //��ȡdouble list����
  static BOOL GetSepcObjectAttrEx( BOOL &bIsExistKey,CATRawColldouble *&doubleList,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //����CATISpecObject_var����
  static BOOL SetSepcObjectAttrEx(CATISpecObject_var spObject,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //��ȡCATISpecObject_var����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATISpecObject_var &spObject,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //���� CATLISTV(CATISpecObject_var)����
  static BOOL SetSepcObjectAttrEx(CATLISTV(CATISpecObject_var) lstSpecObjects,const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //��ȡCATLISTV(CATISpecObject_var)����
  static BOOL GetSepcObjectAttrEx(BOOL &bIsExistKey,CATLISTV(CATISpecObject_var) &lstSpecObjects,const CATUnicodeString &strKey,const CATISpecObject_var spSpecObject);

  //���������չ����
  static BOOL ClearSpecObjectAttEx(const CATISpecObject_var spSpecObject);

  //����ض�key����չ����
  static BOOL ClearSpecObjectAttEx(const CATISpecObject_var spSpecObject,CATListValCATUnicodeString lstStrKeys);

  //�Ƿ�����ض���չ����
  static BOOL IsExistSpecObjectAttEx(const CATUnicodeString strKey,const CATISpecObject_var spSpecObject);

  //���ܣ���������
  static BOOL CopyFeatureToPartDocument(CATISpecObject_var &spSpecCopyResult, const CATISpecObject_var spObjectToCopy, const CATISpecObject_var spTarget,CATIProduct *piSourceInst,CATIProduct *piTargetInst, CATBoolean LinkMode,int iAttributeMode=3);







//**********************************************************************************************************************************************************************************************************************************************************
//PART�ļ��Զ������Բ�������
//**********************************************************************************************************************************************************************************************************************************************************
  
  //���ܣ���part�ļ������������ԣ�����գ���ֵ
  static
  void AddMBDPartUserParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType=1,CATBoolean clearOrKeep = TRUE,CATBoolean readOrWrite =TRUE);

  //���ܣ���part�ļ����ø�������
  static
  void ModifyMBDPartUserParameters(CATDocument * ipDoc,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue);

  //���ܣ�����ĵ�User Property�������в�����Ϣ
  static
  void GetMBDPartUserParams(CATDocument * ipDoc,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // ���ܣ�����ĵ�User Property����ĳЩ������Ϣ
  static
  void GetMBDPartUserCertainParams(CATDocument * ipDoc,CATListValCATUnicodeString  iListStrName,CATListValCATUnicodeString  &ioListStrNameValue);

  //���û��Զ�������������ö�����Ͳ���
  static 
  void SetUserPropertyParamEnum(CATDocument *piDocument,CATListValCATUnicodeString listStrParamName,CATListOfInt countNode,CATListValCATUnicodeString listStrParamValue);

  //���ü��μ��������û��Զ�������֮��Ĺ�����ϵ
  static 
  void SetGSMToolUserPropertyRelations(CATDocument *piDocument,CATListValCATISpecObject_var listOfspGSMTools);

  //����Datum����
  static HRESULT ConvertToDatum(CATIGSMFactory_var  & ispGsmFact , const CATISpecObject_var & ispSpec,CATISpecObject_var iSpecParent,CATListValCATISpecObject_var& oAllDatums);







//**********************************************************************************************************************************************************************************************************************************************************
//������ʾ��������
//**********************************************************************************************************************************************************************************************************************************************************
  //���Ӹ�����ʾ����
  static
  void HighlightHSO(CATISpecObject_var spHSOSpec);

  //ȥ��������ʾԪ��
  static
  void RemoveHSO(CATISpecObject_var spHSOSpec);

  //��ո�����
  static 
  BOOL ClearHSO();

  //������ʾһ�鼸�ζ���
  static 
  BOOL HighLightObjLst(CATLISTV(CATISpecObject_var) pObjLst);


//**********************************************************************************************************************************************************************************************************************************************************
//��������������������
//**********************************************************************************************************************************************************************************************************************************************************

  // ���ܣ��򵥸��������ò���
  static 
  void AddSpecObjParams(CATDocument * ipDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType = 0);

  // ���ܣ��޸�������ĳЩ������������������ڽ��Զ�����
  static
  void ModifySpecObjCertainParams(CATDocument * piDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue);

  // ���ܣ��޸�������ĳЩ����״̬
  static
  void ModifySpecObjCertainParamsStatus(CATDocument * piDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName);

  // ���ܣ��򵥸��������ò����������ǰ�����ݣ��������µ����ݣ�������ѡ������
  static 
  void ClearAndAddSpecObjParams(CATDocument * ipDoc,CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  ListStrName,CATListValCATUnicodeString  ListStrNameValue,int iType = 0);

  // ��ѯ�õ�ĳ�����������в�����������ѡ������
  static 
  void GetSpecObjAllParams(CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &ListStrName,CATListValCATUnicodeString  &ListStrNameValue,int iType=0);

  // ��ѯ�õ�ĳ��������ĳЩ������������ѡ������
  static 
  void GetSpecObjCertainParams(CATISpecObject_var const &spSpecObj,CATListValCATUnicodeString  &iListStrName,CATListValCATUnicodeString  &ioListStrNameValue,int iType=0);

  //�ڼ���ͼ�μ�������ö�����ͣ�ͬ���������������´���
  static 
  void SetGSMToolParamEnum(CATDocument *piDocument,CATISpecObject_var spGSMTool,CATListValCATUnicodeString listStrParamName,CATListOfInt countNode,CATListValCATUnicodeString listStrParamValue);



  


//**********************************************************************************************************************************************************************************************************************************************************
//��������������
//**********************************************************************************************************************************************************************************************************************************************************

  //���ĵ���ȡCATICkeParmFactory
  static HRESULT GetParamFactory(CATDocument *piDocument,CATICkeParmFactory_var &iospParmFact);

  //���ĵ���ȡCATIGSMFactory
  static HRESULT GetGSMFactory(CATDocument *piDocument,CATIGSMFactory_var &iospGSMFact);

  //��ȡ��ǰPart�ĵ�Root Container
  static HRESULT ObtainCurrentRootContainer(CATIPrtContainer *&oRootContainer);

  //��ȡĳPart�ĵ�Root Container
  static HRESULT ObtainRootContainer(CATDocument* iDoc,CATIPrtContainer *&oRootContainer);






//**********************************************************************************************************************************************************************************************************************************************************
//���ڲ�������
//**********************************************************************************************************************************************************************************************************************************************************

  //��ȡ��ǰ�������ֵ
  static void GetWindowMaxSize(int*  oHeight,int*  oWidth );

  //��Ϣ��ʾ������ģʽ����
  static void ShowDlgNotify(CATUnicodeString strTitle, CATUnicodeString strValue);

  //������Ϣ��
  static void ktErrorMsgBox(const char* pMsg);
  static void ktErrorMsgBox(const int iNum);
  static void ktErrorMsgBox(const double dValue);

  //������Ϣ
  static void ktWarningMsgBox(const char* pMsg);

  //��ʾ��Ϣ
  static void ktInfoMsgBox(const char* pMsg);





//**********************************************************************************************************************************************************************************************************************************************************
//PATHELEMENT��������
//**********************************************************************************************************************************************************************************************************************************************************

  //��ȡ����·�����ַ���
  static void PathElementString(CATPathElement * ipPath,CATUnicodeString & oPathName,BOOL bIsBackward);

  //��ȡ������CATPathElement
  static CATPathElement* ExtractPathElement(CATBaseUnknown* pObject);

  //��ȡ����·�����ַ���
  static void GetPathElementString(CATPathElement * ipPath ,CATUnicodeString & oPathName, BOOL bIsBackward, int iLength);
  //---------------------------------------------------------------------------

  //=====================================================================================================================================
  //����˵��:��һ������������CATPathElement��������Release�ͷ�pPathElementָ��
  //����˵��:pPathElement--[out]���ص�·��ָ��
  //         spSpecObject--[in]���ڼ���Ķ���
  //         pFatherPathElement--[in]���ڼ���ĸ�·�������ΪNULL��ʹ�õ�ǰ����·��
  //����ֵ:����ɹ�����TRUE,���򷵻�FALSE��
  static BOOL GetPathElementFromSpecObject(CATPathElement* &pPathElement,const CATISpecObject_var spSpecObject,CATPathElement* pFatherPathElement=NULL);
  //=====================================================================================================================================
  //����˵��:��һ������������CATPathElement��������Release�ͷ�pPathElementָ��
  //����˵��:pPathElement--[out]���ص�·��ָ��
  //         spSpecObject--[in]���ڼ���Ķ���
  //         spPrdInstance--[in]���ڼ���ĸ���Ʒʵ��������ΪNULL_var
  //����ֵ:����ɹ�����TRUE,���򷵻�FALSE��
  static BOOL GetPathElementFromSpecObject(CATPathElement* &pPathElement,const CATISpecObject_var spSpecObject,CATIProduct_var spPrdInstance);
  //=====================================================================================================================================
  //����˵��:�ͷ�PathElement�б�
  //����˵��:lstPathElem--[in\out]�ͷŶ���
  //����ֵ:��
  static void FreePathElementLst(CATLISTP(CATPathElement) &lstPathElem);
  //=====================================================================================================================================
  //����˵��:���ȫ·���е����һ��Productʵ��
  //����˵��:pPathElement--[in]·������
  //����ֵ:�������һProductʵ��
  static CATIProduct_var GetLastProductInstance(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //����˵��:���ȫ·���е����һ��Productʵ����ȫ·��,�������ͷŷ��ص�·��ָ��
  //����˵��:pPathElement--[in]·������
  //����ֵ:�������һProductʵ����ȫ·��
  static CATPathElement* GetLastPrdInstPathElement(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //����˵��:���ȫ·���е�CATIPrtPart����
  //����˵��:pPathElement--[in]·������
  //����ֵ:����ȫ·���е�CATIPrtPart����
  static CATIPrtPart_var GetPrtPartObject(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //����˵��:���ȫ·���е�PrtPart��ȫ·��,�������ͷŷ��ص�·��ָ��
  //����˵��:pPathElement--[in]·������
  //����ֵ:����ȫ·���е�PrtPart��ȫ·��
  static CATPathElement* GetPrtPartPathElement(CATPathElement* pPathElement);
  //=====================================================================================================================================
  //����˵��:���ȫ·�������һ������
  //����˵��:pPathElement--[in]·������
  //����ֵ:����ȫ·�������һ������
  static CATISpecObject_var GetLastSpecObject(CATPathElement* pPathElement);


//**********************************************************************************************************************************************************************************************************************************************************
//��ͼ��������
//**********************************************************************************************************************************************************************************************************************************************************
  //ģ�;���
  static BOOL RollCameraToTopView(CATMathDirectionf  SightDir,CATMathDirectionf  upDir);

  //ģ�ͽṹ����������
  static void CenterSpecGraph(CATPathElement* piPathEle);

  //��ͼ���и��������
  static BOOL CenterViewPoints(const CATLISTV(CATMathPoint) lstMathPoints);


};

//-----------------------------------------------------------------------

#endif