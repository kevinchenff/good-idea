// stdafx.cpp : source file that includes just the standard includes
// MBDStdWebService.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "MBDStdWebService.h"


//  ���庯�������ӿ�
extern "C" __declspec(dllexport) HRESULT MBDQuery(BSTR* iStrQuery,int in0_nSizeIs,BSTR *&ioQueryResult,int &out_nSizeIs)
{

	HRESULT hr = S_OK;
	// ʵ����һ�������
	CMBDStdWebServiceApp DllExport;
	hr = DllExport.MBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

	return hr;

}

//  ���庯�������ӿ�
extern "C" __declspec(dllexport) HRESULT MBDInsert(BSTR* in0, int in0_nSizeIs, BSTR* &out, int &out_nSizeIs)
{

	HRESULT hr = S_OK;
	// ʵ����һ�������
	CMBDStdWebServiceApp DllExport;
	hr = DllExport.MBDInsert(in0,in0_nSizeIs,out,out_nSizeIs);

	return hr;

}