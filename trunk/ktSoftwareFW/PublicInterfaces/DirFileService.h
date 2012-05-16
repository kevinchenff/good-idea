// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// DirFileService.h
// Header definition of DirFileService
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef DirFileService_H
#define DirFileService_H

#include "ktDirFileService.h"
#include "CATBaseUnknown.h"
#include "ktPubHeaders.h"


//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href DirFileService constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new DirFileService;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktDirFileService DirFileService: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     DirFileService ();
     virtual ~DirFileService ();

  // Copy constructor and equal operator
  // -----------------------------------
  DirFileService (DirFileService &);
  DirFileService& operator=(DirFileService&);

  //**********************************************************************************************************************************************************************************************************************************************************
  //·������
  //**********************************************************************************************************************************************************************************************************************************************************
  //��õõ���ǰ�����intel_a�ļ���·��������intel_a��һ��
  static 
  HRESULT GetCurrentDataPath(CATUnicodeString &StrODataPath);

  //**********************************************************************************************************************************************************************************************************************************************************
  //�ļ��в���
  //**********************************************************************************************************************************************************************************************************************************************************
  //�����ļ���
  BOOL CreateDirectory(CATUnicodeString StrDir);

  //��ȡ�ض��ļ��������ض������ĵ���ȫ·��
  BOOL GetCertainFilesFromFolder(CATLISTV(CATUnicodeString) &ioLstFilePath,CATUnicodeString istrSuffix,CATUnicodeString iStrFolderPath);


  //**********************************************************************************************************************************************************************************************************************************************************
  //�ĵ���д����
  //**********************************************************************************************************************************************************************************************************************************************************
  //���ж�ȡ�ļ�������ÿ�����ݵ�����
  static HRESULT ReadFileByLines(CATUnicodeString ifilePathName,CATListValCATUnicodeString& ioastrFileContent);  

};

//-----------------------------------------------------------------------

#endif