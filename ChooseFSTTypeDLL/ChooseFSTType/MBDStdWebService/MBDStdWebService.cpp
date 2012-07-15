// MBDStdWebService.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "MBDStdWebService.h"
#include "MBDStdWebReference.h"

//
#include <iostream>
#include <fstream>
using namespace std;

#include <string.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "comutil.h"
#include<stdio.h>
//

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#ifdef _DEBUG

# pragma comment(lib, "comsuppwd.lib")

#else

# pragma comment(lib, "comsuppw.lib")

#endif

# pragma comment(lib, "wbemuuid.lib")


//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//


// CMBDStdWebServiceApp

BEGIN_MESSAGE_MAP(CMBDStdWebServiceApp, CDialog)
END_MESSAGE_MAP()


// CMBDStdWebServiceApp construction

CMBDStdWebServiceApp::CMBDStdWebServiceApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMBDStdWebServiceApp object

CMBDStdWebServiceApp theApp;


//传入传出参数
HRESULT CMBDStdWebServiceApp::MBDQuery(BSTR* iStrQuery,int in0_nSizeIs,BSTR *&ioQueryResult,int &out_nSizeIs)
{
	// 因为生成的代码是基于ATL的，所以要初始化COM
	CoInitialize(NULL);

	HRESULT hr = S_OK;
	CService* MyMBDService;

	MyMBDService = new CService;	// 实例化代理对象

	// 可以调用SetUrl动态设置Web服务地址
	// MyMBDService->SetUrl(L"http://avicitzhoujie:8080/MBDDatabase/services/MBDService");
	MyMBDService->SetUrl(L"http://192.168.100.120:80/StdPartMS/services/Service");

	/*
	char * strURLAddress = NULL;
	hr = GetURLAddress(strURLAddress);

	//检验配置文件状态
	if(hr == S_FALSE)
	{
		AfxMessageBox(_T("网络连接失败！请检查AVICIT-MBD软件配置信息状态..."));

		return hr;
	}

	//调用MBDWebService实例
	LPCTSTR lstr =	MCBS_2_LOCAL(strURLAddress);
	hr = MyMBDService->SetUrl(lstr);
	*/
	hr = MyMBDService->Query(iStrQuery,in0_nSizeIs,&ioQueryResult,&out_nSizeIs); //注意，返回值是以指针形式返回

	//检验调用情况
	if( hr == E_FAIL)
	{
		AfxMessageBox(_T("网络连接失败！请检查您的电脑网络连接状态..."));

		delete MyMBDService;
		CoUninitialize();

		ioQueryResult = NULL;
		return hr;
	}

	delete MyMBDService;
	CoUninitialize();

	return hr;
}


HRESULT CMBDStdWebServiceApp::MBDInsert(BSTR* in0, int in0_nSizeIs, BSTR* &out, int &out_nSizeIs)
{
	// 因为生成的代码是基于ATL的，所以要初始化COM
	CoInitialize(NULL);

	HRESULT hr = S_OK;
	CService* MyMBDService;

	MyMBDService = new CService;	// 实例化代理对象

	// 可以调用SetUrl动态设置Web服务地址
	// MyMBDService->SetUrl(L"http://avicitzhoujie:8080/MBDDatabase/services/MBDService");
	MyMBDService->SetUrl(L"http://192.168.100.120:80/StdPartMS/services/Service");

	/*char * strURLAddress = NULL;
	hr = GetURLAddress(strURLAddress);

	//检验配置文件状态
	if(FAILED(hr))
	{
		AfxMessageBox(_T("网络连接失败！请检查您的电脑网络连接状态或者检查AVICIT-MBD软件AVICITMBD-config配置信息是否正确..."));
		return hr;
	}
	
	//调用MBDWebService实例
	LPCTSTR lstr =	MCBS_2_LOCAL(strURLAddress);
	hr = MyMBDService->SetUrl(lstr);
	*/

	hr = MyMBDService->Insert(in0, in0_nSizeIs, &out, &out_nSizeIs); //注意，返回值是以指针形式返回

	if(FAILED(hr))
	{
		AfxMessageBox(_T("网络连接失败！请检查您的电脑网络连接状态或者检查AVICIT-MBD软件配置状态..."));

		delete MyMBDService;
		CoUninitialize();

		out = NULL;
		return hr;
	}

	delete MyMBDService;
	CoUninitialize();

	return hr;
}



HRESULT CMBDStdWebServiceApp::GetURLAddress(char *& strURLAddress)
{

	BSTR strBSTR = GetCurrentDataPath();
	CStringA str(strBSTR);
	str += "\\KTCustomConfig\\STDDBSetting\\DatabaseWebservice.config";
		
	const int BUF_SIZE = 1024;
	char* buf = new char[BUF_SIZE];
	memset(buf, 0, BUF_SIZE);
	
	ifstream fin1(str, ios::in);
	if(!fin1) return S_FALSE;

	fin1.getline(buf,BUF_SIZE);
	strURLAddress = buf;
	
	//清除工作
	fin1.close();
	//delete[] lpszText; 

	return S_OK;
}


inline const char * CMBDStdWebServiceApp::LOCAL_2_MCBS(LPCTSTR lpstr)
{
#ifdef _UNICODE
	const size_t len = wcslen(lpstr);
	static std::string strRet;
	strRet.resize(len + len + 2, '\0');
	wcstombs(&*strRet.begin(), lpstr, strRet.length());
	return strRet.c_str();
#else
	return lpstr;
#endif
}

inline LPCTSTR CMBDStdWebServiceApp::MCBS_2_LOCAL(const char *lpstr)
{
#ifdef _UNICODE
	std::string str;
	const size_t len = strlen(lpstr);
	static std::wstring strRet;
	strRet.resize(len + 2, 0);
	mbstowcs(&*strRet.begin(), lpstr, strRet.length());
	return strRet.c_str();
#else
	return lpstr;
#endif
}


BSTR CMBDStdWebServiceApp::GetCurrentDataPath()
{
	//获取主程序所在路径,存在sPath中
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
	int nPos;

	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left (nPos);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left (nPos);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left (nPos);
	/*nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left (nPos);*/

	BSTR path=sPath.AllocSysString();
	return path;
}

