// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CLog.h
// Header definition of CLog
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2009  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef CLog_H
#define CLog_H

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "ktStrLogService.h"


//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href CLog constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new CLog;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktStrLogService CLog: public CATBaseUnknown
{
	CATDeclareClass;

	public:

		// Standard constructors and destructors
		// -------------------------------------
		CLog ();
		virtual ~CLog ();

		// Copy constructor and equal operator
		// -----------------------------------
		CLog (CLog &);
		CLog& operator=(CLog&);

		//使用四种日志级别DEBUG, INFO, ERROR, FATAL记录日志，四种级别由低到高
		//当系统配置为记录某种级别时，低于此级别的日志将不被记录
		
		static HRESULT InitLog(char* path);

		static HRESULT Debug(const CATUnicodeString msg);	
		static HRESULT Debug(const char* msg);

		static HRESULT Info(const CATUnicodeString msg);	
		static HRESULT Info(const char* msg);

		static HRESULT Warn(const CATUnicodeString msg);	
		static HRESULT Warn(const char* msg);

		static HRESULT Error(const CATUnicodeString msg);	
		static HRESULT Error(const char* msg);

		static HRESULT Fatal(const CATUnicodeString msg);	
		static HRESULT Fatal(const char* msg);
		

	private:
		static FILE   *logFile ;
		static unsigned int logLevel;
		static CATUnicodeString logFilePath;
		static CATUnicodeString initialLogFilePath;

		static long fileCounter;
		static long lineCounter;

		static HRESULT WriteLog(const char* msg);
		static HRESULT WriteLog(const char* msg, unsigned int outLevel);
		static HRESULT WriteLog(const CATUnicodeString msg, unsigned int outLevel);
};

//-----------------------------------------------------------------------

#endif
