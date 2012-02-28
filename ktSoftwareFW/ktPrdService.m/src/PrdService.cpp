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

		rc = spProduct->QueryInterface(IID_CATIProduct, (void**) &*oNewProduct);
		
		//���½ṹ��
		PrdService::RedrawSpecTree(iThisProd);
		
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
					rc = spProduct->QueryInterface(IID_CATIProduct,(void**) &*oNewProduct);

					//���½ṹ��
					PrdService::RedrawSpecTree(iThisProd);

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
		PrtService::ktErrorMsgBox("δ���ҵ������ļ�·���� \\KTCustomConfig\\MBDSTDDoc\\ARM.CATPart��");
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
					// ͨ����һ����FrmEditor����ĵ���Document
					CATInit_var spInitOnDoc(pNewDoc);
					// �����Ӧ��������
					CATIPrtContainer * piPrtCont =  (CATIPrtContainer*) spInitOnDoc->GetRootContainer("CATIPrtContainer");
					CATIPrtPart_var spPart = piPrtCont->GetPart();
					piPrtCont->Release();
					piPrtCont=NULL;
					CATISpecObject_var spSpecOnPart = spPart;

					// ���Product������������
					spRootProduct -> SetPartNumber(iPartNumber);

					// ����PartBody����
					CATIPartRequest_var spPrtRequst = spPart;
					CATBaseUnknown_var  oPartBody;
					spPrtRequst->GetMainBody("MfDefault3DView",oPartBody );

					CATIAlias_var spMainBodyAlias = oPartBody;
					spMainBodyAlias->SetAlias(iPartNumber);

					CATIProduct_var spProduct;
					spProduct = iThisProd->AddProduct   (spRootProduct);
					if (NULL_var ==  spProduct ) return 2;
					rc = spProduct->QueryInterface(IID_CATIProduct, (void**) &*oNewProduct);

					//���½ṹ��
					PrdService::RedrawSpecTree(iThisProd);
				}
		}
	}
	return rc; 

}


//��ȡ��ǰװ�价���µ�ROOT
HRESULT PrdService::RetrieveRootProduct(CATIProduct *&oRootProduct)
{
	// ��ȡeditor
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

//���ĵ��ϻ�ȡCATIProduct *
HRESULT PrdService::GetRootProductFromDoc(CATDocument *ipiDocument,CATIProduct *& opiProductOnRoot)
{
	HRESULT rc = S_OK;
	//-----------------------------------------------------------
	// 1 �õ�ѡ��Product�ĵ���Root Product
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


//���ĵ��ϻ�ȡCATIProduct_var
HRESULT PrdService::GetRootProductFromDoc(CATDocument *ipDoc,CATIProduct_var &ospRootPrd)
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

//ˢ�µ�ǰװ��ṹ��
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


//��ȡ�ĵ���ǰInstance Prd�ļ�����
HRESULT PrdService::GetInstPrdType(const CATIProduct_var &ispProduct,CATUnicodeString &iostrPrdType)
{
	//��ʼ��
	HRESULT hr = S_OK;
	iostrPrdType = "";

	//��ȡ
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

//��ȡ�ĵ���ǰInstance Prd�ļ�ָ��
HRESULT PrdService::GetInstPrdDoc(const CATIProduct_var &ispProduct,CATDocument* &opiPrdDoc)
{
	//��ʼ��
	HRESULT hr = S_OK;
	opiPrdDoc = NULL;

	//��ȡ
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

//�޸�ʵ�����ƣ���õ�һ��Instance�����SetPrdInstanceName
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

//��Instance Prd�л�ȡPart
HRESULT PrdService::GetPartFromPrd(CATIProduct_var spInsProduct,CATISpecObject_var &ospPart)
{
	HRESULT rc=S_OK;

	if (spInsProduct==NULL_var) return E_FAIL;

	CATIProduct_var spRefPrd=NULL_var;
	spRefPrd=spInsProduct->GetReferenceProduct();
	if(spRefPrd!=NULL_var)
	{
		CATIPrtContainer *piPrtContainerOnRoot =NULL;
		CATILinkableObject_var spLinkObj=spRefPrd;
		if(spLinkObj!=NULL_var)
		{
			CATDocument * piDocument=spLinkObj->GetDocument();
			CATInit * piInitOnDoc = NULL;
			rc = piDocument->QueryInterface(IID_CATInit, (void**)&piInitOnDoc);
			if(SUCCEEDED(rc)&&piInitOnDoc!=NULL) 
			{
				CATIPrtContainer *piPrtContainerOnRoot =(CATIPrtContainer*)piInitOnDoc->GetRootContainer("CATIPrtContainer");
				piInitOnDoc->Release();
				piInitOnDoc=NULL;

				ospPart = piPrtContainerOnRoot->GetPart() ;
				piPrtContainerOnRoot->Release();piPrtContainerOnRoot=NULL;
			}
		}
	}

	return S_OK;
}


//�жϵ�ǰDOCUMENT�Ƿ�ΪPRD
BOOL PrdService::IsPathProductDocument()
{
	//�õ��ǵ�ǰ�༭��document
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

//�ж�����������Ƿ�ΪPRD����
BOOL PrdService::IsContextualPrd()
{
	// ��ȡeditor
	//�õ��ǵ�ǰ�༭��document
	CATFrmEditor * pEditor =CATFrmEditor::GetCurrentEditor();
	CATPathElement spPath = pEditor->GetUIActiveObject( );
	spPath.Reverse();
	void*  oPtr = NULL;
	HRESULT rc = spPath.Search(IID_CATIProduct,&oPtr);

	//
	if (SUCCEEDED(rc))
	{
		return TRUE;
	}
	else 
		return FALSE;
}


//�ж�Prd���ӹ�ϵ
BOOL PrdService::IsChildPrd(CATIProduct_var spChildPrd, CATIProduct_var spFathertPrd)
{
	if(spChildPrd->IsEqual(spFathertPrd)==1)
	{
		return TRUE;
	}
	CATIProduct_var spTempPrd = NULL_var;
	while(1)
	{
		spTempPrd = spChildPrd ->GetFatherProduct( ) ;
		if(NULL_var==spTempPrd)
		{
			return FALSE;
		}
		if(1==spTempPrd->IsEqual(spFathertPrd))
		{
			return TRUE;
		}
		else
		{
			spChildPrd = spTempPrd;
		}
	}
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

	//���run����
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

//���ΪԲ�� oType = 1������ oType = 2������ oType = 3
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


//**********************************************************************************************************************************************************************************************************************************************************
//װ�价����ײ������
//**********************************************************************************************************************************************************************************************************************************************************

//ͨ��ClashFactory�ж�product�б����Ƿ����
//----------------------------------------------------------------------------
//iTypeΪ������� 1--�Ӵ��� 2---��ײ�� 3---�Ӵ�+��ײ
//----------------------------------------------------------------------------
BOOL PrdService::IsProductsClashByClashFct(CATListPV &pPVClashList, CATLISTV(CATISpecObject_var) iPrdLst, BOOL bIsCheckInter, int iType)
{
	CATFrmEditor * pEditor = CATFrmEditor::GetCurrentEditor();
	if(NULL==pEditor)
		return FALSE;

	CATDocument *pDoc = pEditor->GetDocument( );
	if(NULL==pDoc)
		return FALSE;
	//
	CATIDocRoots *piRootOnDoc = NULL;
	HRESULT hr = pDoc->QueryInterface(IID_CATIDocRoots,(void**)&piRootOnDoc);
	if (FAILED(hr))
		return FALSE;

	CATListValCATBaseUnknown_var *pRootProducts = piRootOnDoc->GiveDocRoots();
	piRootOnDoc->Release(); 
	piRootOnDoc = NULL;
	CATIProduct_var spRootPrd = (*pRootProducts)[1];
	delete pRootProducts; 
	pRootProducts=NULL;

	// ��ȡCATIClashFactory�ӿڣ��������ɸ������
	CATIClashFactory * spClashFac = NULL;
	hr = pDoc->QueryInterface(IID_CATIClashFactory,(void**) &spClashFac);
	if (FAILED(hr))
		return FALSE;

	// ������а����Ķ����������
	CATListValCATBaseUnknown_var oObjectsList;
	spClashFac->List(CATClashInstance,oObjectsList);
	for (int i = 1; i <= oObjectsList.Size(); i ++)
	{
		CATISpecObject_var spClashFeature = oObjectsList[i];
		CATIAlias_var spAlias = spClashFeature;
		CATUnicodeString ustrAlias = spAlias->GetAlias();
		CATISpecObject_var spFather = NULL_var;
		spFather = spRootPrd;
		if (NULL_var != spFather)
			spFather->Remove(spClashFeature);
		else
			return FALSE;
	}

	CATIClash * pioGeneratedClash;
	spClashFac->Create (pioGeneratedClash);
	spClashFac->Release();
	spClashFac = NULL;

	//���㲢��ȡ���������
	pioGeneratedClash->Compute();
	CATIClashResult * pioClashResult = NULL;
	pioGeneratedClash->GetResult(pioClashResult);

	//�жϽ�����
	int oNumberOfConflicts = 0;
	pioClashResult->CountConflicts (oNumberOfConflicts );

	for (int i = 0; i < oNumberOfConflicts; i ++)
	{
		CATIConflict *pioConflict = NULL;
		pioClashResult->GetConflict(i,pioConflict);
		CATResultType oType;
		pioConflict->GetResultType(oType);

		if ((CATTypeContact == oType&&iType==1)||(CATTypeClash == oType&&iType==2)||((CATTypeContact == oType||CATTypeClash == oType)&&iType==3))
		{
			//
			CATMathPoint mPoint;
			CATMathPoint mVecPoint;

			CATIProduct * firstProduct = NULL ;
			CATUnicodeString FirstshapeName ;
			CATIProduct * secondProduct = NULL ;
			CATUnicodeString SecshapeName ;
			pioConflict->GetFirstProduct(firstProduct,FirstshapeName);
			pioConflict->GetSecondProduct(secondProduct,SecshapeName);

			double * padFirstArr = new double[ 3 ];
			double * padSecArr = new double[ 3 ];
			for (int j=0;j <=2; j ++)
			{
				padSecArr[j]=0;
				padFirstArr[j]=0;
			}

			pioConflict->GetMinOrExtractionVectorCoordinates(padFirstArr,padSecArr);
			cout<<"Get firstPoints RESULT: "<<padFirstArr[0]<<" "<<padFirstArr[1]<<" "<<padFirstArr[2]<<" "<<endl;
			cout<<"Get SecPoints RESULT: "<<padSecArr[0]<<" "<<padSecArr[1]<<" "<<padSecArr[2]<<" "<<endl;

			mPoint.SetX(padFirstArr[0]);
			mPoint.SetY(padFirstArr[1]);
			mPoint.SetZ(padFirstArr[2]);
			delete[] padFirstArr, padFirstArr = NULL;

			mVecPoint.SetX(padSecArr[0]);
			mVecPoint.SetY(padSecArr[1]);
			mVecPoint.SetZ(padSecArr[2]);
			delete[] padSecArr, padSecArr = NULL;

			//�ж���ײ�Ƿ��ڷ����ڼ���prd�б��ڲ�, ������continue
			BOOL bIsPrd1In = FALSE;
			BOOL bIsPrd2In = FALSE;
			for(int k=1; k<=iPrdLst.Size(); k++)
			{
				CATIProduct_var spCurPrd = iPrdLst[k];

				if(IsChildPrd(firstProduct,spCurPrd))
				{
					bIsPrd1In = TRUE;
				}
				if(IsChildPrd(secondProduct,spCurPrd))
				{
					bIsPrd2In = TRUE;
				}
			}
			if(FALSE==bIsPrd1In||FALSE==bIsPrd2In)
			{
				continue ;
			}


			//�Ƿ����ڲ���ײ
			BOOL bIsInOnePrd = FALSE;
			for(int j=1; j<=iPrdLst.Size(); j++)
			{
				CATIProduct_var spCurrentPrd = iPrdLst[j];
				if(IsChildPrd(firstProduct, spCurrentPrd)&&IsChildPrd(secondProduct, spCurrentPrd))
				{
					bIsInOnePrd = TRUE;
					break;
				}
			}
			if(FALSE == bIsCheckInter) //���������ڲ��� ��ײ�������ڲ��� ����
			{
				if(TRUE==bIsInOnePrd)
					continue ;
			}


			//
			ClashStru *pClashStru = new ClashStru();
			if(bIsInOnePrd)
				pClashStru->bIsInter = TRUE;
			else
				pClashStru->bIsInter = FALSE;

			if (CATTypeContact == oType)
				pClashStru->bExistPt = FALSE;
			else
				pClashStru->bExistPt = TRUE;

			pClashStru->spPrd1 = firstProduct;
			pClashStru->spPrd2 = secondProduct;
			pClashStru->MathPoint = mPoint;
			pClashStru->VectPoint = mVecPoint;

			pPVClashList.Append(pClashStru);
		}
	}
	return TRUE;
}


 