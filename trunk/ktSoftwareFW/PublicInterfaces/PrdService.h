// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrdService.h
// Header definition of PrdService
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef PrdService_H
#define PrdService_H

#include "ktPubHeaders.h"
#include "ktPrdService.h"
#include "CATBaseUnknown.h"

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href PrdService constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new PrdService;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktPrdService PrdService: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     PrdService ();
     virtual ~PrdService ();

  // Copy constructor and equal operator
  // -----------------------------------
  PrdService (PrdService &);
  PrdService& operator=(PrdService&);


//**********************************************************************************************************************************************************************************************************************************************************
//添加装配节点操作
//**********************************************************************************************************************************************************************************************************************************************************
  /**
 * Service to import an existing document.
 * This services illustrates the way to have same 
 * fonctionnalities as AddExternalComponent of CATIAProducts.
 * iThisProduct
 *        product where the document has to be imported.
 * iDocument
 *        document to import.
 * oNewProduct
 *        product instance of the imported document.
 */
static
HRESULT AddExternalComponent(CATIProduct* iThisProd, CATDocument *iDocument, CATIProduct** oNewProduct,CATIProduct_var &spRootProduct);

/**
 * Service to create and import a document.
 * This services illustrates the way to have same 
 * fonctionnalities as AddNewComponent of CATIAProducts.
 * iThisProduct
 *        product where the document has to be imported.
 * iDocumentType
 *        type of the document to create. Only part and product documents are allowed.
 * iPartNumber
 *        part number to give to the created document. Has to be single.
 * oNewProduct
 *        product instance of the imported document.
 */
static
HRESULT AddNewExternalComponent(CATIProduct* iThisProd, const CATUnicodeString iDocumentType,const CATUnicodeString iPartNumber, CATIProduct** oNewProduct,CATDocument *&pNewDoc);

//添加新建自PART文件
static
HRESULT AddNewFromExternalComponent(CATIProduct* iThisProd,const CATUnicodeString iFullPath,const CATUnicodeString iPartNumber, CATIProduct** oNewProduct,CATDocument *&pNewDoc);


//**********************************************************************************************************************************************************************************************************************************************************
//装配节点操作
//**********************************************************************************************************************************************************************************************************************************************************
//获取当前装配环境下的根ROOT
static
HRESULT RetrieveRootProduct(CATIProduct *&oRootProduct);

//得到product模型的Root Product指针
static
HRESULT GetRootProduct(CATDocument *ipiDocument,CATIProduct *& opiProductOnRoot);

//得到product模型的Root Product智能指针
static
HRESULT GetRootProduct(CATDocument *ipDoc,CATIProduct_var &ospRootPrd);

// 刷新当前装配结构树
static
HRESULT RedrawSpecTree(CATIProduct* iNodeProd);

//获取文档当前Instance Prd文件类型
static
HRESULT GetInstPrdType(const CATIProduct_var &ispProduct,CATUnicodeString &iostrPrdType);

//获取文档当前Instance Prd文件Doc指针
static
HRESULT GetInstPrdDoc(const CATIProduct_var &ispProduct,CATDocument* &opiPrdDoc);

//获取文档当前Reference Prd文件Doc指针
static
HRESULT GetRefPrdDoc(const CATIProduct_var &ispProduct,CATDocument* &opiPrdDoc);

//修改实例名称，获得第一个Instance后才能SetPrdInstanceName
static
BOOL ChangePrdInstName(CATIProduct_var spPrd);

//判断当前DOCUMENT是否为PRD
static
BOOL IsPathProductDocument();

//判断设计上下文是否为PRD环境
static
BOOL IsContextualPrd();

//

//判读Prd父子关系
static
BOOL IsChildPrd(CATIProduct_var spChildPrd, CATIProduct_var spFathertPrd);



//**********************************************************************************************************************************************************************************************************************************************************
//装配环境pipe run操作
//**********************************************************************************************************************************************************************************************************************************************************
//创建PIPE RUN
static
int CreateTube(CATRawColldouble dLstPos, double dDiameter ,  CATIProduct_var spRootPrdOnTubePrd );

//删除RUN
static
int RemoveRun(CATIProduct_var spRootPrdOnTubePrd);

//如果为圆管 oType = 1，方管 oType = 2，其它 oType = 3
static
BOOL IsThisPrdATube(CATIProduct_var spPrd,int &oType);


//**********************************************************************************************************************************************************************************************************************************************************
//装配环境碰撞检查操作
//**********************************************************************************************************************************************************************************************************************************************************

//结构体
typedef struct
{
	BOOL bIsInter;
	BOOL bExistPt;
	CATIProduct_var spPrd1;
	CATIProduct_var spPrd2;
	CATMathPoint    MathPoint;
	CATMathPoint    VectPoint;
}ClashStru;
//通过ClashFactory判断product列表内是否干涉
static BOOL  IsProductsClashByClashFct(CATListPV &pPVClashList, CATLISTV(CATISpecObject_var) iPrdLst, BOOL bIsCheckInter, int iType);



};

//-----------------------------------------------------------------------

#endif
