// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrdService.cpp
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
#include "PrdService.h"

// ObjetModelerBase Framework
#include "CATIDocRoots.h"         
#include "CATDocumentServices.h"  
#include "CATIRedrawEvent.h"

// Visualization 
#include "CATIModelEvents.h"
#include "CATModify.h"

#include "CATInit.h"
#include "CATIPrtContainer.h"
#include "CATIPrtPart.h"
#include "CATIPartRequest.h"
#include "CATIAlias.h"

#include <iostream>
using namespace std;
 
CATImplementClass( PrdService,
                   Implementation, 
                   CATBaseUnknown,
                   CATNull );
 
//-----------------------------------------------------------------------------
// PrdService : constructor
//-----------------------------------------------------------------------------
PrdService::PrdService():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// PrdService : destructor
//-----------------------------------------------------------------------------
PrdService::~PrdService()
{
}
 
//-----------------------------------------------------------------------------
// PrdService : copy constructor
//-----------------------------------------------------------------------------
PrdService::PrdService(PrdService& original):
   CATBaseUnknown(original)
{
}
 
//-----------------------------------------------------------------------------
// PrdService : equal operator
//-----------------------------------------------------------------------------
PrdService& PrdService::operator=(PrdService& original)
{
   CATBaseUnknown::operator=(original);
   return *this;
}

//-------------------------------------------------------------------------
//                Service to import an external component 
//-------------------------------------------------------------------------
HRESULT PrdService::AddExternalComponent(CATIProduct *iThisProd, CATDocument *iDocument, CATIProduct **oNewProduct ,CATIProduct_var &spRootProduct)
{
	if ( ! iThisProd ) return 1;

	HRESULT rc = E_FAIL;
	
	if ( NULL != iDocument)
	{
		// Get RootProduct of the document to import.
		CATIDocRoots *piDocRootsOnDoc = NULL;
		rc = iDocument->QueryInterface(IID_CATIDocRoots,
			                           (void**) &piDocRootsOnDoc);
		if ( FAILED(rc) )
		{
			cout << "** QI on CATIDocRoots failed " << endl<< flush;
			return rc;
		}
		
		CATListValCATBaseUnknown_var *pRootProducts = 
			piDocRootsOnDoc->GiveDocRoots();
//		CATIProduct_var spRootProduct = NULL_var;
		if ( NULL != pRootProducts)
			if (pRootProducts->Size())
			{  
				// the root product is first element of
				// the list of root elements.
				spRootProduct = (*pRootProducts)[1];
				delete pRootProducts;
				pRootProducts = NULL;
			}
			
		piDocRootsOnDoc->Release();
		piDocRootsOnDoc=NULL;
		
		CATIProduct_var spProduct = NULL_var;
		if (NULL_var != spRootProduct)
		{
		// We have the root product from which one
			// will be agregated in "this"
/** @anchor err_1 iThisProduct not tested before use */ 
		spProduct = iThisProd->AddProduct(spRootProduct);
		}
		else
		{
			CATUnicodeString docName = iDocument-> StorageName();
/** @anchor err_2 iThisProduct not tested before use */ 
			iThisProd->AddShapeRepresentation(CATUnicodeString("model"),
				                              docName);
			return 3;
		}

		rc = spProduct->QueryInterface(IID_CATIProduct, 
			                           (void**) &*oNewProduct);
		
	}
	return rc; 
} 



//-------------------------------------------------------------------------
//       Creates a CATProduct or CATPart document and then imports it 
//-------------------------------------------------------------------------
HRESULT PrdService::AddNewExternalComponent(CATIProduct* iThisProd, const CATUnicodeString iDocumentType,const CATUnicodeString iPartNumber, CATIProduct** oNewProduct,CATDocument *&pNewDoc)
{
	if ( ! iThisProd ) return 1;

	HRESULT rc = E_FAIL;
	*oNewProduct = NULL;
	
	CATUnicodeString product = "Product";
	CATUnicodeString part = "Part";

	if ( (iDocumentType != product) &&  (iDocumentType != part) )
	{
		cout << " ERROR in AddNewExternalComponent : document type : " << iDocumentType.CastToCharPtr() << " is not allowed "<< endl << flush;
		return rc;
	}

	// Creation of document CATProduct/CATPart
	rc = CATDocumentServices::New(iDocumentType,pNewDoc);
	if ( FAILED(rc) || (NULL==pNewDoc) )
	{
		cout << "ERROR : document Creation Failed" << endl<< flush;
		return rc;
	}

	
	//cout << endl << "CAAPstAddServices.m:	document of type " <<  iDocumentType.CastToCharPtr() << " created " << endl << flush;
	

	// Import document in this product
	if ( SUCCEEDED( rc ) )
	{
		// Get RootProduct of the created document.
		CATIDocRoots *piDocRootsOnNewDoc = NULL;
		rc = pNewDoc->QueryInterface(IID_CATIDocRoots,
			                         (void**) &piDocRootsOnNewDoc);
		if ( SUCCEEDED( rc ) )
		{			
			CATListValCATBaseUnknown_var *pRootProducts =
				piDocRootsOnNewDoc->GiveDocRoots();
			CATIProduct_var spRootProduct;
			if (NULL != pRootProducts)
				if (pRootProducts->Size())
				{  
					// the root product is first element of
					// the list of root elements.
					spRootProduct = (*pRootProducts)[1];
					delete pRootProducts;
					pRootProducts = NULL;
				}
				
				piDocRootsOnNewDoc->Release();
				piDocRootsOnNewDoc=NULL;
			
				if (NULL_var != spRootProduct)
					{
					// Set PartNumber to the created root
					// ATTENTION : be sure that the part number is single
					// in a document .
					spRootProduct -> SetPartNumber(iPartNumber);
	
					// We have the root product from which one
					// will be agregated in "this"
/** @anchor err_3 spRootProduct : tester la valeur du pointeur ( !! ) */ 
					CATIProduct_var spProduct;
/** @anchor err_4 iThisProduct not tested before use */ 
					spProduct = iThisProd->AddProduct   (spRootProduct);
					if (NULL_var ==  spProduct ) return 2;
					rc = spProduct->QueryInterface(IID_CATIProduct, 
						                           (void**) &*oNewProduct);

				}
		}
	}
	return rc; 

}

HRESULT PrdService::AddNewFromExternalComponent(CATIProduct* iThisProd,const CATUnicodeString iFullPath,const CATUnicodeString iPartNumber, CATIProduct** oNewProduct,CATDocument *&pNewDoc)
{

	if ( ! iThisProd ) return 1;

	HRESULT rc = E_FAIL;
	*oNewProduct = NULL;
	
	// Creation of document CATProduct/CATPart
	CATLISTP(CATDocument)  oListOfDocuments;
    CATLISTV(CATUnicodeString)  iListOfPaths;
	iListOfPaths.Append(iFullPath);

	rc = CATDocumentServices::NewFrom(&iListOfPaths,&oListOfDocuments);

	if (SUCCEEDED(rc))
	{
		pNewDoc = oListOfDocuments[1];	
	}
	else
	{
		pNewDoc = NULL;
		PrtService::ktErrorMsgBox("未能找到配置文件路径下 \\KTCustomConfig\\MBDSTDDoc\\ARM.CATPart！");
		return E_FAIL;
	}
	
	// Import document in this product
	if ( SUCCEEDED( rc ) )
	{
		// Get RootProduct of the created document.
		CATIDocRoots *piDocRootsOnNewDoc = NULL;
		rc = pNewDoc->QueryInterface(IID_CATIDocRoots,
			                         (void**) &piDocRootsOnNewDoc);
		if ( SUCCEEDED( rc ) )
		{			
			CATListValCATBaseUnknown_var *pRootProducts =
				piDocRootsOnNewDoc->GiveDocRoots();
			CATIProduct_var spRootProduct;
			if (NULL != pRootProducts)
				if (pRootProducts->Size())
				{  
					// the root product is first element of
					// the list of root elements.
					spRootProduct = (*pRootProducts)[1];
					delete pRootProducts;
					pRootProducts = NULL;
				}
				
				piDocRootsOnNewDoc->Release();
				piDocRootsOnNewDoc=NULL;
			
				if (NULL_var != spRootProduct)
				{
					// 通过上一步的FrmEditor获得文档的Document
					CATInit_var spInitOnDoc(pNewDoc);
					// 获得相应的容器类
					CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
					CATIPrtPart_var spPart = piPrtCont->GetPart();
					piPrtCont->Release();
					piPrtCont=NULL;
					CATISpecObject_var spSpecOnPart = spPart;

					// 获得Product，更改零件编号
					spRootProduct -> SetPartNumber(iPartNumber);

					// 更改PartBody命名
					CATIPartRequest_var spPrtRequst = spPart;
					CATBaseUnknown_var  oPartBody;
					spPrtRequst->GetMainBody("MfDefault3DView",oPartBody );

					CATIAlias_var spMainBodyAlias = oPartBody;
					spMainBodyAlias->SetAlias(iPartNumber);

					CATIProduct_var spProduct;
					spProduct = iThisProd->AddProduct   (spRootProduct);
					if (NULL_var ==  spProduct ) return 2;
					rc = spProduct->QueryInterface(IID_CATIProduct, 
						(void**) &*oNewProduct);
				}
		}
	}
	return rc; 

}


//获取当前装配环境下的ROOT
HRESULT PrdService::RetrieveRootProduct(CATIProduct *&oRootProduct)
{
	// 获取editor
	CATFrmEditor * piEditor =CATFrmEditor::GetCurrentEditor();
	CATDocument *piDocument = NULL;
	piDocument = piEditor->GetDocument();

	CATIDocRoots *piDocRootsOnDoc = NULL;
	HRESULT rc = piDocument->QueryInterface(IID_CATIDocRoots,(void**) &piDocRootsOnDoc);
	CATListValCATBaseUnknown_var *pRootProducts = piDocRootsOnDoc->GiveDocRoots();
	piDocRootsOnDoc->Release();
	piDocRootsOnDoc=NULL;

	if(pRootProducts==NULL)	return E_FAIL;
	CATIProduct_var spRootProduct = NULL_var;	
	if (pRootProducts->Size()==0) return E_FAIL;
	spRootProduct = (*pRootProducts)[1];
	delete pRootProducts;
	pRootProducts = NULL;

	// Get CATIProduct handle on the root product.
	CATIProduct *piProductOnRoot = NULL;
	if ( NULL_var == spRootProduct ) return E_FAIL;
	rc = spRootProduct->QueryInterface(IID_CATIProduct,(void**) &piProductOnRoot);
	if (FAILED(rc) || piProductOnRoot == NULL) return E_FAIL;

	oRootProduct=piProductOnRoot;
	piProductOnRoot->Release();
	piProductOnRoot = NULL;

	return rc;
}

//
HRESULT PrdService::GetRootProduct(CATDocument *ipiDocument,CATIProduct *& opiProductOnRoot)
{
	HRESULT rc = S_OK;
	//-----------------------------------------------------------
	// 1 得到选中Product文档的Root Product
	//-----------------------------------------------------------
	CATIDocRoots* piDocRootsOnDoc = NULL;
	rc = ipiDocument->QueryInterface(IID_CATIDocRoots,
		(void**) &piDocRootsOnDoc);
	if ( FAILED(rc) ) return rc;

	// get the root product which is the first element of root elements
	CATListValCATBaseUnknown_var* pRootProducts = 
		piDocRootsOnDoc->GiveDocRoots();
	CATIProduct_var spRootProduct = NULL_var;

	if (pRootProducts->Size())
	{  
		spRootProduct = (*pRootProducts)[1];
		delete pRootProducts;
		pRootProducts = NULL;
	}
	piDocRootsOnDoc->Release();

	// 2 Get CATIProduct handle on the root product.
	rc = spRootProduct->QueryInterface(IID_CATIProduct,(void**) &opiProductOnRoot);
	if ( FAILED(rc) ) return rc;

	return rc;
}

//刷新当前装配结构树
HRESULT PrdService::RedrawSpecTree(CATIProduct* iNodeProd)
{
	if(iNodeProd==NULL)return E_FAIL;

	CATIModelEvents_var spModelEventOnProduct(iNodeProd);
	CATModify event((CATBaseUnknown*)iNodeProd);
	spModelEventOnProduct->Dispatch(event);	 
	CATIRedrawEvent_var spRedrawEventOnProduct(iNodeProd);
	spRedrawEventOnProduct->Redraw();

	return S_OK;
}


//获取文档当前Instance Prd文件类型
HRESULT PrdService::GetInstPrdType(const CATIProduct_var &ispProduct,CATUnicodeString &iostrPrdType)
{
	//初始化
	HRESULT hr = S_OK;
	iostrPrdType = "";

	//获取
	CATIProduct_var spRefPrd=NULL_var;
	spRefPrd = ispProduct->GetReferenceProduct();
	if(spRefPrd!=NULL_var)
	{
		CATILinkableObject_var spLinkObj=spRefPrd;
		if(spLinkObj!=NULL_var)
		{
			CATDocument * piDocument=spLinkObj->GetDocument();

			CATIDocId*  oDocId = NULL;
			piDocument->GetDocId(&oDocId);
			oDocId->GetType(iostrPrdType);
		}
		else
		{
			hr = E_FAIL;
			return hr;
		}
	} 
	else
	{
		hr = E_FAIL;
		return hr;
	}
	return hr;
}

//获取文档当前Instance Prd文件指针
HRESULT PrdService::GetInstPrdDoc(const CATIProduct_var &ispProduct,CATDocument* &opiPrdDoc)
{
	//初始化
	HRESULT hr = S_OK;

	//获取
	CATIProduct_var spRefPrd=NULL_var;
	spRefPrd = ispProduct->GetReferenceProduct();
	if(spRefPrd!=NULL_var)
	{
		CATILinkableObject_var spLinkObj=spRefPrd;
		if(spLinkObj!=NULL_var)
		{
			opiPrdDoc=spLinkObj->GetDocument();
		}
		else
		{
			hr = E_FAIL;
			return hr;
		}
	} 
	else
	{
		hr = E_FAIL;
		return hr;
	}
	return hr;
}

//从文档上获取CATIProduct
HRESULT PrdService::GetRootProduct(CATDocument *ipDoc,CATIProduct_var &ospRootPrd)
{
	CATIDocRoots_var spDocRoot = ipDoc;
	if(NULL_var==spDocRoot)
	{
		return E_FAIL;
	}
	CATListValCATBaseUnknown_var* pRootProducts = spDocRoot->GiveDocRoots( );
	if(NULL==pRootProducts)
	{
		return E_FAIL;
	}
	if(pRootProducts->Size())
	{
		ospRootPrd = (* pRootProducts)[1];
		delete pRootProducts;
		pRootProducts = NULL;
	}
	return S_OK;
}

HRESULT PrdService::GetRefPrdDoc(const CATIProduct_var &ispProduct,CATDocument* &opiPrdDoc)
{
	if(NULL_var==ispProduct)
	{
		return E_FAIL;
	}

	CATILinkableObject_var  spLinkShape  = ispProduct;
	if(NULL_var==spLinkShape)
	{
		return E_FAIL;
	}

	opiPrdDoc = spLinkShape-> GetDocument( );
	if(NULL==opiPrdDoc)
	{
		return E_FAIL;
	}
	return S_OK;
}

//修改实例名称，获得第一个Instance后才能SetPrdInstanceName
BOOL PrdService::ChangePrdInstName(CATIProduct_var spPrd)
{
	if(NULL_var==spPrd)
		return FALSE;

	//	
	CATIProduct_var spRefPrd =  spPrd->GetReferenceProduct( );
	if(NULL_var==spRefPrd)
		return FALSE;

	CATUnicodeString StrInstName;
	StrInstName = spPrd->GetPartNumber();

	//	
	CATIProduct_var spFatherPrd = spPrd->GetFatherProduct();
	if(NULL_var==spFatherPrd)
		return FALSE;

	CATIProduct_var spFatherRefPrd = spFatherPrd->GetReferenceProduct();
	if(NULL_var==spFatherRefPrd)
		return FALSE;

	CATIProduct_var spFirstInstPrd = spPrd->FindInstance(spFatherRefPrd); 
	if(NULL_var==spFirstInstPrd)
		return FALSE;

	spFirstInstPrd->SetPrdInstanceName(StrInstName);

	return FALSE;
}


//判断当前DOCUMENT是否为PRD
BOOL PrdService::IsProductDocument()
{
	//得到是当前编辑的document
	CATFrmEditor * pEditor =CATFrmEditor::GetCurrentEditor();
	CATPathElement spPath = pEditor->GetUIActiveObject( );
	CATBaseUnknown* pcurrbase = spPath.CurrentElement( );
	CATILinkableObject *piLinkableObject = NULL;
	HRESULT rc = pcurrbase->QueryInterface( IID_CATILinkableObject, (void**)& piLinkableObject );
	if (SUCCEEDED(rc))
	{
		CATDocument * pDocument = NULL ;
		pDocument = piLinkableObject->GetDocument();
		piLinkableObject->Release();
		piLinkableObject=NULL;

		if (pDocument->IsAKindOf("CATProduct"))
		{
			return TRUE;
		}		
	} 

	return FALSE;
}







int PrdService::CreateTube(CATRawColldouble dLstPos, double dDiameter ,  CATIProduct_var spRootPrdOnTubePrd )
{
	CATIAProduct *pCatiaPrd = NULL;
	spRootPrdOnTubePrd->QueryInterface(IID_CATIAProduct,(void**)&pCatiaPrd);
	if (pCatiaPrd==NULL)
	{
		cout<<"QueryInterface IID_CATIAProduct failed"<<endl;
		return 0;
	}


	CATBaseDispatch *pBase = NULL;
	pCatiaPrd->GetTechnologicalObject(L"ArrangementProduct", pBase);

	if (pBase==NULL)
	{
		cout<<"pBase IS NULL"<<endl;
		return 0;
	}	
	CATIAArrangementProduct *pArrProduct = NULL;
	pBase->QueryInterface(IID_CATIAArrangementProduct,(void**)&pArrProduct);
	if (pArrProduct==NULL)
	{
		cout<<"pArrProduct IS NULL"<<endl;
		return 0;
	}	

	CATIAArrangementRuns *pArrRunS=NULL;
	pArrProduct->get_ArrangementRuns(pArrRunS);
	pArrProduct->Release(); pArrProduct=NULL;
	if (pArrRunS==NULL)
	{
		cout<<"pArrRunS IS NULL"<<endl;
		return 0;
	}

	double * iDoubleArray = new double[dLstPos.Size()];
	for (int i = 0; i < dLstPos.Size(); i ++)
	{
		iDoubleArray[i] = dLstPos[i+1];
	}
	CATSafeArrayVariant* dblRunPoints  = BuildSafeArrayVariant(iDoubleArray,dLstPos.Size()); 
	double iDoubleDirectionArray[3] = {1,0,0};
	CATSafeArrayVariant* dblMathDirection  = BuildSafeArrayVariant(iDoubleDirectionArray,3); 

	CATIAMove *pMoveAble = NULL;
	pCatiaPrd->get_Move(pMoveAble);
	pCatiaPrd->Release(); pCatiaPrd = NULL;

	CATIAArrangementRun *oArrRun =NULL;
	pArrRunS->AddRun(pMoveAble, *dblRunPoints, *dblMathDirection, oArrRun);

	FreeVariantSafeArray (dblRunPoints);
	FreeVariantSafeArray (dblMathDirection);
	delete [] iDoubleArray;

	CATArrangementRouteVisuMode VisuMode  = CatArrangementRouteVisuModeSolid;
	CATArrangementRouteSection  RouteSection = CatArrangementRouteSectionRound;
	oArrRun->put_VisuMode(VisuMode);
	oArrRun->put_SectionType(RouteSection);
	oArrRun->put_SectionDiameter(dDiameter);

	return 1;
}

int PrdService::RemoveRun(CATIProduct_var spRootPrdOnTubePrd)
{
	if (spRootPrdOnTubePrd == NULL_var)
	{
		return 0;
	}

	CATIAProduct *pCatiaPrd = NULL;
	spRootPrdOnTubePrd->QueryInterface(IID_CATIAProduct,(void**)&pCatiaPrd);
	if (pCatiaPrd==NULL)
	{
		cout<<"QueryInterface IID_CATIAProduct failed"<<endl;
		return 0;
	}


	CATBaseDispatch *pBase = NULL;
	pCatiaPrd->GetTechnologicalObject(L"ArrangementProduct", pBase);

	if (pBase==NULL)
	{
		cout<<"pBase IS NULL"<<endl;
		return 0;
	}	
	CATIAArrangementProduct *pArrProduct = NULL;
	pBase->QueryInterface(IID_CATIAArrangementProduct,(void**)&pArrProduct);
	if (pArrProduct==NULL)
	{
		cout<<"pArrProduct IS NULL"<<endl;
		return 0;
	}	

	CATIAArrangementRuns *pArrRunS=NULL;
	pArrProduct->get_ArrangementRuns(pArrRunS);
	pArrProduct->Release(); pArrProduct=NULL;
	if (pArrRunS==NULL)
	{
		cout<<"pArrRunS IS NULL"<<endl;
		return 0;
	}

	//获得run个数
	int ccount = spRootPrdOnTubePrd->GetChildrenCount();
	CATVariant iIndex;
	long ReturnValue = 1;
	BuildVariant((const long)ReturnValue,iIndex);

	for (int i = 1; i <= ccount ; i ++)
	{
		pArrRunS->Remove(iIndex);
	}

	return 1;
}

//如果为圆管 oType = 1，方管 oType = 2，其它 oType = 3
BOOL PrdService::IsThisPrdATube(CATIProduct_var spPrd,int &oType)
{
	if(NULL_var==spPrd)
	{
		return FALSE;
	}

	CATIArrSegmentsString   *pArrSegmentsString = NULL;
	HRESULT rc = spPrd->QueryInterface(IID_CATIArrSegmentsString,(void**)&pArrSegmentsString);
	if(SUCCEEDED(rc)&&(NULL!=pArrSegmentsString))
	{
		CATIRouSection_var oSection = NULL_var;
		pArrSegmentsString->GetSection(oSection);
		CATRouSectionTypes oSecType;
		oSection->GetSectionType(oSecType);
		if (oSecType == CatRouSectionRound)
		{
			oType = 1;
		}
		else if (oSecType == CatRouSectionRect)
		{
			oType = 2;
		}
		else
		{
			oType = 3;
		}

		pArrSegmentsString->Release();
		pArrSegmentsString=NULL;
		return TRUE;
	}

	return FALSE;
}

 
