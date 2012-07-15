// stdafx.cpp : source file that includes just the standard includes
// MBDStdWebService.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "MBDStdWebService.h"


//  定义函数导出接口
extern "C" __declspec(dllexport) HRESULT MBDQuery(BSTR* iStrQuery,int in0_nSizeIs,BSTR *&ioQueryResult,int &out_nSizeIs)
{

	HRESULT hr = S_OK;
	// 实例化一个类对象
	CMBDStdWebServiceApp DllExport;
	hr = DllExport.MBDQuery(iStrQuery,in0_nSizeIs,ioQueryResult,out_nSizeIs);

	return hr;

}

//  定义函数导出接口
extern "C" __declspec(dllexport) HRESULT MBDInsert(BSTR* in0, int in0_nSizeIs, BSTR* &out, int &out_nSizeIs)
{

	HRESULT hr = S_OK;
	// 实例化一个类对象
	CMBDStdWebServiceApp DllExport;
	hr = DllExport.MBDInsert(in0,in0_nSizeIs,out,out_nSizeIs);

	return hr;

}