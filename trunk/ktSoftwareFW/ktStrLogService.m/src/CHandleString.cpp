// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CHandleString.cpp
// Header definition of CHandleString
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2009  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#include "CHandleString.h"
#include "CATString.h"



CATImplementClass( CHandleString,
                   Implementation, 
                   CATBaseUnknown,
                   CATNull );
 
//-----------------------------------------------------------------------------
// CHandleString : constructor
//-----------------------------------------------------------------------------
CHandleString::CHandleString():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// CHandleString : destructor
//-----------------------------------------------------------------------------
CHandleString::~CHandleString()
{
}
 
//-----------------------------------------------------------------------------
// CHandleString : copy constructor
//-----------------------------------------------------------------------------
CHandleString::CHandleString(CHandleString& original):
   CATBaseUnknown(original)
{
}
 
//-----------------------------------------------------------------------------
// CHandleString : equal operator
//-----------------------------------------------------------------------------
CHandleString& CHandleString::operator=(CHandleString& original)
{
   CATBaseUnknown::operator=(original);
   return *this;
}
 

void CHandleString::VerString(char *str)
{
	int   i      ;
	char  tmp[8] ;

	rmStrSpace( str ) ;
	StrToUpper( str ) ;

	strcpy( tmp , "") ;

	if( strlen(str) < 3)
		for(i=0;i<3-strlen(str);i++) strcat( tmp , "-") ;

	strcat( tmp, str);

	tmp[3] = '\0' ;

	strcpy(str , tmp) ;

	for (i=0; i<3 ; i++) if(str[i] == ' ') str[i] = '-' ;
}

int CHandleString::rmStrSpace(char *str)
{
	//PrtHead("rmStrSpace");

	int   i     ;
	char  *tmp ;

	for (i=0; i < strlen(str); i++) if(str[i] != ' ')  break ;

	tmp = str + i ;

	for (i=strlen(tmp)-1; i >= 0; i--) if(tmp[i] != ' ')  break ;

	tmp[i+1] = '\0' ;

	strcpy(str ,  tmp )  ;

	return  0 ;
}


char* CHandleString::StrToUpper(char *strx)
{
	for(int i=0;i<strlen(strx);i++) strx[i] = toupper(strx[i])  ;
	return strx ;
}

HRESULT CHandleString::GetValuesFromString(const CATUnicodeString &StrLine,
										   CATLISTV(CATUnicodeString) &oFieldList)
{
	HRESULT rc = S_OK;

	if (oFieldList != NULL)
		oFieldList.RemoveAll(CATCollec::ReleaseAllocation);

	int n = StrLine.GetLengthInChar();
	int point = 0;
	for (int i=0;i<=n;i++)
	{
		if (StrLine.SubString(i,1) == "	")
		{
			CATUnicodeString temp1 = StrLine.SubString(point,i-point);
			oFieldList.Append(temp1);
			//cout<<temp1.ConvertToChar()<<endl;
			point = i + 1;
		}
	}

	return rc;
}

void  CHandleString::myGetTime(char* str) 
{
	struct tm *loc ;
	time_t    t      ;

	t   = time(NULL) ;
	loc = localtime(&t) ;


	sprintf(str, "%4d-%02d-%02d %02d:%02d:%02d" , \
		loc->tm_year + 1900       ,        \
		loc->tm_mon  + 1          ,        \
		loc->tm_mday              ,        \
		loc->tm_hour              ,        \
		loc->tm_min               ,        \
		loc->tm_sec                         ) ;

}

void  CHandleString::myGetTime2(char* str) 
{
	struct tm *loc ;
	time_t    t      ;

	t   = time(NULL) ;
	loc = localtime(&t) ;


	sprintf(str, "%4d%02d%02d%02d%02d%02d" , \
		loc->tm_year + 1900       ,        \
		loc->tm_mon  + 1          ,        \
		loc->tm_mday              ,        \
		loc->tm_hour              ,        \
		loc->tm_min               ,        \
		loc->tm_sec                         ) ;

}

void  CHandleString::GetTime(char* str) 
{
	struct tm *loc ;
	time_t    t      ;

	t   = time(NULL) ;
	loc = localtime(&t) ;

	sprintf(str, "%04d%02d%02d-%02d%02d" , \
		loc->tm_year - 100        ,    \
		loc->tm_mon  + 1          ,    \
		loc->tm_mday              ,    \
		loc->tm_hour              ,    \
		loc->tm_min                    ) ;

}

//uTime must like 20070101123030
HRESULT CHandleString::ConvertStringTimeToCATTime(CATUnicodeString uTime, CATTime &tTime) 
{
	HRESULT rc = S_OK;

	if (uTime.GetLengthInChar() != 14) return E_FAIL;

	CATUnicodeString uYear, uMonth, uDay, uHour, uMinute, uSecond;
	int nYear, nMonth, nDay, nHour, nMinute, nSecond;
	uYear = uTime.SubString(0, 4);		uYear.ConvertToNum(&nYear);
	uMonth = uTime.SubString(4, 2);		uMonth.ConvertToNum(&nMonth);
	uDay = uTime.SubString(6, 2);		uDay.ConvertToNum(&nDay);
	uHour = uTime.SubString(8, 2);		uHour.ConvertToNum(&nHour);
	uMinute = uTime.SubString(10, 2);	uMinute.ConvertToNum(&nMinute);
	uSecond = uTime.SubString(12, 2);	uSecond.ConvertToNum(&nSecond);
	int nSetTime = tTime.SetDateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
	if (nSetTime == 0) return E_FAIL;

	return S_OK;
}


HRESULT CHandleString::Split(const CATUnicodeString uInput,const CATUnicodeString uSplitter, CATListOfCATUnicodeString &listOutput)
{
	int nSearch;
	CATUnicodeString uTemp = uInput;
	CATUnicodeString uEntry;
	//cout << "uTemp : " << uTemp.ConvertToChar() << endl;

	while(true)
	{
		nSearch = uTemp.SearchSubString(uSplitter);
		//cout << "nSearch : " << nSearch << endl;

		if(nSearch >= 0)
		{
			if(nSearch > 0) uEntry = uTemp.SubString(0,nSearch);
			else uEntry = "";
			//uTemp.Remove(1,nSearch+uSplitter.GetLengthInChar());
			uTemp = uTemp.SubString(nSearch+uSplitter.GetLengthInChar(),uTemp.GetLengthInChar()-nSearch-uSplitter.GetLengthInChar());
			//cout << "uTemp : " << uTemp.ConvertToChar() << endl;

			listOutput.Append(uEntry.Strip());
		}
		else
		{
			listOutput.Append(uTemp.Strip());
			break;
		}
	}

	return S_OK;
}

CATUnicodeString CHandleString::StringByReplaceChar(CATUnicodeString uString,int FileNameOrDirName)
{
	CATUnicodeString uTempString(uString);
	CATUnicodeString uSearchString = "[ \"(`');\\$/]";
	CATUnicodeString uReplaceChar = "_";

	//int nSize = uSearchString.GetLengthInByte()-1;
	if (1==FileNameOrDirName)
	{
		int nSize = uSearchString.GetLengthInByte()-1;
		for (int i=1;i<nSize;i++)
		{
			CATUnicodeString uSearchChar = uSearchString.SubString(i,1);
			//cout << " *** uSearchChar " << uSearchChar.ConvertToChar() << endl;
			int n = uTempString.SearchSubString(uSearchChar);
			if(n!=-1)
			{
				uTempString.ReplaceAll(uSearchChar,uReplaceChar);
			}
		}
	}
	else
	{
		int nSize = uSearchString.GetLengthInByte()-2;
		for (int i=1;i<nSize;i++)
		{
			CATUnicodeString uSearchChar = uSearchString.SubString(i,1);
			int n = uTempString.SearchSubString(uSearchChar);
			if(n!=-1)
			{
				uTempString.ReplaceAll(uSearchChar,uReplaceChar);
			}
		}
	}
	//exit (0);
	return uTempString;
}


bool CHandleString::EachCharIsNum(CATUnicodeString  Section) 
{
	if (Section=="")
		return false;
	int num;
	for (int i=0;i<Section.GetLengthInChar();i++)
	{
		num=Section.ConvertToChar()[i];
		if (num<48 || num>57)
			return false;
	}

	return true;
}

bool CHandleString::EachCharIsChar(CATUnicodeString  Section) 
{
	if (Section=="")
		return false;
	int num;
	Section.ToUpper();
	for (int i=0;i<Section.GetLengthInChar();i++)
	{
		num=Section.ConvertToChar()[i];
		if (num<48 || ( num>57 && num<65 ) || num>90 )
			return false;
	}

	return true;
}

//convert CString to CATUnicodeString
CATUnicodeString CHandleString::CStringToUS(CString iCString)
{
	if ("" == iCString) return FALSE;
	CATUnicodeString StrBSTR ;
	BSTR bstrText = iCString.AllocSysString();
	StrBSTR.BuildFromBSTR(bstrText);
	SysFreeString(bstrText); // 用完释放

	return StrBSTR;
}

//CATUnicodeString型转换为CString型
CString CHandleString::USToCString(CATUnicodeString iUString)
{
	CATString sTemp = iUString.ConvertToChar();
	char *cTemp = sTemp.CastToCharPtr();
	CString csTemp = cTemp;
	return csTemp;
}

//  以特定字符拆分字符串
HRESULT CHandleString::StringToVector(const CATUnicodeString &iStr,const CATUnicodeString &iToken,CATLISTV(CATUnicodeString) &oStrVector) 
{
	HRESULT rc = E_FAIL;

	if (iStr != "" && iToken != "" && iStr.SearchSubString("//",0,CATUnicodeString::CATSearchModeForward) != 1) {
		CATUnicodeString aStr(iStr);
		int nStringLen = aStr.GetLengthInChar();
		int nTokenLen  = iToken.GetLengthInChar();

		CATUnicodeString subStr("");
		int nIndex = aStr.SearchSubString(iToken,0,CATUnicodeString::CATSearchModeForward);
		while (nIndex >=0 ) { // one occurence found
			subStr = aStr.SubString(0, nIndex);
			oStrVector.Append(subStr);

			// reset input
			aStr = aStr.SubString(nIndex + nTokenLen, nStringLen - nIndex - nTokenLen);
			nStringLen = aStr.GetLengthInChar();
			nIndex = aStr.SearchSubString(iToken,0,CATUnicodeString::CATSearchModeForward);
		}

		// put the left part
		oStrVector.Append(aStr);

		rc = S_OK;
	}
	else
	{
		rc = E_FAIL;
	}

	return rc;
}

// 以特定字符拆分字符串，前后模式，例如“< >”
HRESULT CHandleString::ParseStringByFBToken(const CATUnicodeString &iStr,
											 const CATUnicodeString &iFrontToken,
											 const CATUnicodeString &iBackToken,
											 CATLISTV(CATUnicodeString) &oStrVector)
{

	HRESULT rc = S_OK;

	if (iStr != "" && iFrontToken != "" && iBackToken != "" && (iStr.SearchSubString("//",0,CATUnicodeString::CATSearchModeForward) != 1  ||  iStr.SearchSubString("#",0,CATUnicodeString::CATSearchModeForward) != 1))
	{
		CATUnicodeString aStr(iStr);
		int nStringLen = aStr.GetLengthInChar();
		int nFrontToken  = iFrontToken.GetLengthInChar();
		int nBackToken  = iBackToken.GetLengthInChar();

		//获取每个分割符前半部分的位置
		int nFrontIndex = 0;
		CATListOfInt nFrontList; 
		nFrontIndex = aStr.SearchSubString(iFrontToken,nFrontIndex,CATUnicodeString::CATSearchModeForward);
		if (nFrontIndex != -1)
		{
			nFrontList.Append(nFrontIndex);
			//cout<<"nFrontIndex is :"<<nFrontIndex<<endl;
		}

		while(nFrontIndex != -1)
		{
			nFrontIndex = aStr.SearchSubString(iFrontToken,nFrontIndex+nFrontToken,CATUnicodeString::CATSearchModeForward);
			if (nFrontIndex != -1)
			{
				nFrontList.Append(nFrontIndex);
			}
		}

		//获取每个分割符后半部分的位置
		int nBackIndex = 0;
		CATRawCollint nBackList; 
		while(nBackIndex != -1)
		{
			nBackIndex = aStr.SearchSubString(iBackToken,nBackIndex+nBackToken,CATUnicodeString::CATSearchModeForward);
			if (nBackIndex != -1)
			{
				nBackList.Append(nBackIndex);
			}
		}


		//仅在完全匹配的情况下处理字符串
		if (nFrontList.Size() == nBackList.Size())
		{
			CATUnicodeString subStr("");
			for (int i = 1; i <= nFrontList.Size(); i++)
			{
				CATUnicodeString strValue("");
				// reset input
				strValue = aStr.SubString(nFrontList[i]+nFrontToken, nBackList[i] - nFrontList[i] - nFrontToken);

				// put the left part
				oStrVector.Append(strValue);
			}

		}			

	}

	else
	{
		oStrVector = NULL;
	}

	return rc;
}

BOOL CHandleString::CreateGUID(CATUnicodeString &strGUID)
{
	strGUID="";
	GUID   guid;   
	if (S_OK == ::CoCreateGuid(&guid))   
	{   
		CString strTemp;
		strTemp.Format(L"%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X"   
			,guid.Data1,guid.Data2,guid.Data3,
			guid.Data4[0],guid.Data4[1],guid.Data4[2],
			guid.Data4[3],guid.Data4[4],guid.Data4[5],
			guid.Data4[6],guid.Data4[7]);   
		//
		strGUID=CStringToUS(strTemp);
		return TRUE;
	}
	return FALSE;
}

