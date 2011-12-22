// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// ktSoftwareLic.cpp
// Header definition of ktSoftwareLic
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2010  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#include "ktSoftwareLic.h"
#include "CATApplicationFrame.h"
#include "CATDlgWindow.h"
#include "CATDlgNotify.h"
#include "CATUnicodeString.h"
#include "CATListofCATUnicodeString.h"

#include "CATAfrCommandHeaderServices.h"
#include "CATCommandHeader.h"

// c++ header
#include "atlstr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "stdio.h"
#include "iostream"
using namespace std;


// �ַ���ת��
CATUnicodeString CStringToUS(CString iCString);

// ��Ȩ��֤����
HRESULT ktGetSoftwareLic(CATListOfCATUnicodeString &listustrLic);
HRESULT ktGetMacInfo(CATListValCATUnicodeString &alistMac);
HRESULT ktGetCurrentTime(CATUnicodeString &strUserTime);


//------------------------------------------------------------------------------
//convert CString to CATUnicodeString
//------------------------------------------------------------------------------
CATUnicodeString CStringToUS(CString iCString)
{
	if ("" == iCString) return FALSE;
	CATUnicodeString StrBSTR ;
	BSTR bstrText = iCString.AllocSysString();
	StrBSTR.BuildFromBSTR(bstrText);
	SysFreeString(bstrText); // �����ͷ�

	return StrBSTR;
}


 
//  [3/19/2010 ev5adm]
//
void ShowDlgNotify(CATUnicodeString strTitle, CATUnicodeString strValue)
{
	CATApplicationFrame *pApplication = CATApplicationFrame::GetFrame(); 
	if (NULL != pApplication) 
	{ 
		CATDlgWindow * pMainWindow = pApplication->GetMainWindow();
		CATDlgNotify *pNotifyDlg = new CATDlgNotify (pMainWindow, "MBD Notify", CATDlgNfyInformation|CATDlgNfyOK);
		pNotifyDlg->SetVisibility(CATDlgShow);
		pNotifyDlg->SetOKTitle("OK");

		if (NULL != pNotifyDlg) 
		{
			pNotifyDlg->DisplayBlocked(strValue,strTitle);
			pNotifyDlg->RequestDelayedDestruction(); 
		}
	}
}

// ��Ȩ��֤����
HRESULT ktGetSoftwareLic(CATListOfCATUnicodeString &listustrLic)
{
	HRESULT hr = S_OK;

	//����DLL
	//////////////////////////////////////////////////////////////////////////
	HINSTANCE hDll= NULL;//DLL��� 	
	typedef HRESULT (*lpFun)(std::string*&,int&); 
	hDll = LoadLibrary(_T("KTLicSetting.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("��ʾ��Ϣ" );
		LocalFree( lpMsgBuf );

		return E_FAIL;
	}


	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"KTVerifyLic");
		if (NULL==pMBDQuery)
		{
			//AfxMessageBox(_T("DLL�к���Ѱ��ʧ��"));
			ShowDlgNotify("������ʾ��Ϣ","KTLicSetting.dll�к���Ѱ��ʧ��");
			hr = E_FAIL;
			return hr;
		}

		//������Ҫ���������������жϣ�����ȷ�����ݵĿɿ���
		//std::string *decryptedText = new std::string("");
		std::string* decryptedText;
		int iSubStrs;


		hr = pMBDQuery(decryptedText,iSubStrs);

		if (SUCCEEDED(hr))
		{
			for (int i = 0; i < iSubStrs; i ++)
			{
				CATUnicodeString ustrLic = (decryptedText[i]).c_str();
				listustrLic.Append(ustrLic);
			}
		}
		else
		{
			CATUnicodeString ustrLic = (decryptedText[0]).c_str();
			listustrLic.Append(ustrLic);

			ShowDlgNotify("��ʾ��Ϣ","����������Ȩ����\n\n���û����Ȩ�ļ�������ϵ����������Ӧ�̹���������Ȩ��");
		}

		::FreeLibrary(hDll);
	}


	return hr;
}

HRESULT ktGetMacInfo(CATListValCATUnicodeString &alistMac)
{

	HRESULT hr = S_OK;

	//����DLL
	//////////////////////////////////////////////////////////////////////////
	HINSTANCE hDll= NULL;//DLL��� 	
	typedef HRESULT (*lpFun)(CString *&, int &); 
	hDll = LoadLibrary(_T("KTLicSetting.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("��ʾ��Ϣ" );
		LocalFree( lpMsgBuf );

		return E_FAIL;
	}


	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"KTGetMacInfo");
		if (NULL==pMBDQuery)
		{
			ShowDlgNotify("������ʾ��Ϣ","KTLicSetting.dll�к���Ѱ��ʧ��");
			hr = E_FAIL;
			return hr;
		}

		//������Ҫ���������������жϣ�����ȷ�����ݵĿɿ���
		CString *iocstrInfo;
		int ioMacCount;

		hr = pMBDQuery(iocstrInfo,ioMacCount);

		if (SUCCEEDED(hr))
		{
			int strCount = ioMacCount / 4;

			for (int i = 0; i < strCount; i++)
			{
				CATUnicodeString ustrTemp = CStringToUS(iocstrInfo[i*4]);
				alistMac.Append(ustrTemp);
			}

		}
		else{

			alistMac = NULL;

		}

		::FreeLibrary(hDll);
	}


	return hr;	
}

HRESULT ktGetCurrentTime(CATUnicodeString &strUserTime)
{
	HRESULT hr = S_OK;
	//����DLL
	//////////////////////////////////////////////////////////////////////////
	HINSTANCE hDll= NULL;//DLL��� 	
	typedef HRESULT (*lpFun)(CString &); 
	hDll = LoadLibrary(_T("KTLicSetting.dll"));
	if(NULL == hDll)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		//MessageBox("��ʾ��Ϣ" );
		LocalFree( lpMsgBuf );

		return E_FAIL;
	}


	if (NULL!=hDll)
	{
		lpFun pMBDQuery = (lpFun)GetProcAddress(hDll,"KTGetCurrentTime");
		if (NULL==pMBDQuery)
		{
			//AfxMessageBox(_T("DLL�к���Ѱ��ʧ��"));
			ShowDlgNotify("������ʾ��Ϣ","KTLicSetting.dll�к���Ѱ��ʧ��");
			hr = E_FAIL;
			return hr;
		}

		//����
		CString iostrTime;

		hr = pMBDQuery(iostrTime);

		if (SUCCEEDED(hr))
		{
			strUserTime = CStringToUS(iostrTime);
		}
		else{

			strUserTime = "";
		}

		::FreeLibrary(hDll);
	}


	return hr;
}

HRESULT ktVerifyUserLic(CATUnicodeString &ustrKTPRDNAME)
{

	HRESULT hr;
	hr = S_OK;

	CATListOfCATUnicodeString listustrLic;
	CATUnicodeString strUserTime;
	CATListValCATUnicodeString alistMac;

	CATUnicodeString strMac,strStartTime,strEndTime,strPRDNAME;

	hr = ktGetSoftwareLic(listustrLic);

	//У���Ƿ����lic��Ϣ
	if (FAILED(hr))
	{
		ShowDlgNotify("��Ȩ��Ϣ��ʾ","δ�ܻ�ȡ��ȷ����Ȩ��Ϣ������ϵ����������Ӧ��������Ȩ�����ȷ���ر���ʾ��");
		hr = E_FAIL;
		return hr;
	}

	//���û�иò�Ʒ��Ȩ �˴�ֵΪFALSE
	CATBoolean KTPRDFlag = FALSE;

	//У���ȡ����Ȩ��Ϣ
	for (int i = 1; i <= listustrLic.Size(); i ++)
	{
		//һ��������
		CATUnicodeString ustrLic = listustrLic[i];

		//�������Ȩ��Ϣ���������������ֱ������
		if (ustrLic == "LICENSE PARSE EXCEPTION")
		{
			continue;
		}

		//���lic��Ϣ
		strMac = ustrLic.SubString(0,12);
		strStartTime = ustrLic.SubString(12,8);
		strEndTime = ustrLic.SubString(20,8);

		int liclength = ustrLic.GetLengthInChar();

		//��ȡKT��Ʒ��ʶ��
		if (liclength > 28)
		{
			strPRDNAME = ustrLic.SubString(28,liclength-28);
		}

		//1 �����ҵ��ò�Ʒ��lic��Ϣ��
		//��֤KT��Ʒ���Ƿ����
		if (strPRDNAME != ustrKTPRDNAME)
		{
			continue;
		}
		//������
		else
		{
			//��ȡ�û����е�macֵ
			hr = ktGetMacInfo(alistMac);
			CATBoolean Macflag = FALSE;

			for (int i = 1; i <= alistMac.Size(); i++)
			{
				if (alistMac[i] == strMac)
				{
					Macflag = TRUE;
				}
			}

			//����mac
			if (Macflag == TRUE)
			{
				// ��ȡ�û�ʱ��
				hr = ktGetCurrentTime(strUserTime);
				// У����ʼʱ��	
				long starttime,endtime,usertime;
				strStartTime.ConvertToNum(&starttime);
				strEndTime.ConvertToNum(&endtime);
				strUserTime.ConvertToNum(&usertime);

				// ��֤licʱ���Ƿ��Ǻ�
				if (usertime >= starttime && usertime <= endtime)
				{
					KTPRDFlag = TRUE;
					hr = S_OK;

					// ����������ʾ
					if ((endtime - usertime) <= 5)
					{
						CATUnicodeString strlastTime;
						strlastTime.BuildFromNum(endtime - usertime + 1);
						ShowDlgNotify("��Ȩ��Ϣ��ʾ",ustrKTPRDNAME+"��Ʒ����Ȩ�ļ�"+ strlastTime +"�����ڣ�����ϵ����������Ӧ����������Ȩ�����ȷ���ر���ʾ��");
					}

					return hr;						
				}
				else
				{
					// �û���Ȩʱ����ڲ���ȷ���
					ShowDlgNotify("��Ȩ��Ϣ��ʾ",ustrKTPRDNAME+"��Ʒ����Ȩ�ļ��Ѿ����ڣ�����ϵ����������Ӧ����������Ȩ�����ȷ���ر���ʾ��");
					hr = E_FAIL;
					return hr;
				}

			} 
			else
			{
				// �û���ַ��Ϣ���ڲ���ȷ���
				ShowDlgNotify("��Ȩ��Ϣ��ʾ",ustrKTPRDNAME+"��Ʒ����Ȩ�ļ�����������Ϣ����������ϵ����������Ӧ��������Ȩ�����ȷ���ر���ʾ��");
				hr = E_FAIL;
				return hr;
			}
		}
	}

	if (KTPRDFlag == FALSE)
	{
		hr = E_FAIL;
	}
		
	return hr;
}

HRESULT CheckLicHeaderStatus(CATUnicodeString ustrKTPRDName,CATListOfCATString listCmdHeader)
{

	// ����
	HRESULT hr = ktVerifyUserLic(ustrKTPRDName);
	if (SUCCEEDED (hr))
	{
		CATCommandHeader*  poCommandHeader;

		for (int i = 1; i <= listCmdHeader.Size(); i ++)
		{
			::CATAfrGetCommandHeader(listCmdHeader[i],poCommandHeader);
			poCommandHeader->BecomeAvailable();
		}
	}
	else{

		CATCommandHeader*  poCommandHeader;

		for (int i = 1; i <= listCmdHeader.Size(); i ++)
		{
			::CATAfrGetCommandHeader(listCmdHeader[i],poCommandHeader);
			poCommandHeader->BecomeUnavailable();
		}
	}


	return hr;

}