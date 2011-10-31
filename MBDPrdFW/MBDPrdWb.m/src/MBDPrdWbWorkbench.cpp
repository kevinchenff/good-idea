#include <MBDPrdWbWorkbench.h>
#include <TIE_CATIPRDWorkshopConfiguration.h>
#include <IMBDPrdWbAddin.h>
#include <HeaderDeclarations.h>
#include <CATCreateWorkshop.h>

#include "ktSoftwareLic.h"

CATImplementClass(MBDPrdWb, Implementation, CATBaseUnknown, CATNull);
TIE_CATIPRDWorkshopConfiguration(MBDPrdWb);

MBDPrdWb::MBDPrdWb()
{}
MBDPrdWb::~MBDPrdWb()
{}

void MBDPrdWb::CreateCommands()
{
#include <Headers.h>

	////如果有全产品的授权信息，则可用
	//CATUnicodeString ustrKTPRDName = "MBDPRDDESIGNER";
	//CATListOfCATString listCmdHeader;

	//listCmdHeader.Append("MBDPrdWbADEHdr01");
	//listCmdHeader.Append("MBDPrdWbADEHdr02");
	//listCmdHeader.Append("MBDPrdWbADEHdr03");
	//listCmdHeader.Append("MBDPrdWbADEHdr04");
	//listCmdHeader.Append("MBDPrdWbADEHdr05");
	//listCmdHeader.Append("MBDPrdWbAMEHdr01");
	//listCmdHeader.Append("MBDPrdWbAMEHdr02");
	//listCmdHeader.Append("MBDPrdWbAMEHdr03");
	//listCmdHeader.Append("MBDPrdWbAMEHdr04");
	//listCmdHeader.Append("MBDPrdWbAMEHdr05");
	//listCmdHeader.Append("MBDPrdWbAddTechHdr");
	//listCmdHeader.Append("MBDPrdWbCheckTechHdr");
	//listCmdHeader.Append("MBDPrdWbDataVerifyHdr");
	//HRESULT hr = CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);
	//listCmdHeader.RemoveAll();


	//if (FAILED(hr))
	//{

	//	//授权控制
	//	ustrKTPRDName = "MBDPRDADE";
	//	listCmdHeader.Append("MBDPrdWbADEHdr01");
	//	listCmdHeader.Append("MBDPrdWbADEHdr02");
	//	listCmdHeader.Append("MBDPrdWbADEHdr03");
	//	listCmdHeader.Append("MBDPrdWbADEHdr04");
	//	listCmdHeader.Append("MBDPrdWbADEHdr05");
	//	CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);
	//	listCmdHeader.RemoveAll();

	//	ustrKTPRDName = "MBDPRDAME";
	//	listCmdHeader.Append("MBDPrdWbAMEHdr01");
	//	listCmdHeader.Append("MBDPrdWbAMEHdr02");
	//	listCmdHeader.Append("MBDPrdWbAMEHdr03");
	//	listCmdHeader.Append("MBDPrdWbAMEHdr04");
	//	listCmdHeader.Append("MBDPrdWbAMEHdr05");
	//	CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);
	//	listCmdHeader.RemoveAll();

	//	ustrKTPRDName = "MBDPRDTECHNICAL";
	//	listCmdHeader.Append("MBDPrdWbAddTechHdr");
	//	listCmdHeader.Append("MBDPrdWbCheckTechHdr");
	//	CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);
	//	listCmdHeader.RemoveAll();

	//	ustrKTPRDName = "MBDPRDDATAVERIFY";
	//	listCmdHeader.Append("MBDPrdWbDataVerifyHdr");
	//	CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);
	//	listCmdHeader.RemoveAll();


	//}
	
}

CATCmdWorkbench * MBDPrdWb::CreateWorkbench()
{
#include <Workshop.h>
}


CATClassId MBDPrdWb::GetAddinInterface()
{
  return IMBDPrdWbAddin::ClassName();
}

void MBDPrdWb::GetCustomInterfaces(CATListPV* defaultIIDList,
                                       CATListPV* customIIDList)
{}
