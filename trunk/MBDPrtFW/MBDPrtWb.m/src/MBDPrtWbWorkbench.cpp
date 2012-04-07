#include <MBDPrtWbWorkbench.h>
#include <TIE_CATIPrtWksConfiguration.h>
#include <IMBDPrtWbAddin.h>
#include <HeaderDeclarations.h>
#include <CATCreateWorkshop.h>

#include "ktSoftwareLic.h"
// Globle function

CATImplementClass(MBDPrtWb, Implementation, CATBaseUnknown, CATNull);
TIE_CATIPrtWksConfiguration(MBDPrtWb);

#include "TIE_CATIPrtCfgAddin.h"
TIE_CATIPrtCfgAddin(MBDPrtWb);

#include "TIE_CATIShapeDesignWorkshopAddin.h"
TIE_CATIShapeDesignWorkshopAddin(MBDPrtWb);

MBDPrtWb::MBDPrtWb()
{}
MBDPrtWb::~MBDPrtWb()
{}

void MBDPrtWb::CreateCommands()
{
	#include <Headers.h>

	//ÊÚÈ¨¿ØÖÆ
	/*CATUnicodeString ustrKTPRDName("MBDPRTDESIGNER");
	CATListOfCATString listCmdHeader;
	listCmdHeader.Append("MBDPrtWbCmdHdr01");
	listCmdHeader.Append("MBDPrtWbCmdHdr02");
	listCmdHeader.Append("MBDPrtWbCmdHdr03");
	listCmdHeader.Append("MBDPrtWbCmdHdr04");
	listCmdHeader.Append("MBDPrtWbCmdHdr05");

	listCmdHeader.Append("MBDPrtWbCmdHdr06");
	listCmdHeader.Append("MBDPrtWbCmdHdr07");
	listCmdHeader.Append("MBDPrtWbCmdHdr08");
	listCmdHeader.Append("MBDPrtWbCmdHdr09");
	listCmdHeader.Append("MBDPrtWbCmdHdr10");

	CheckLicHeaderStatus(ustrKTPRDName,listCmdHeader);*/
}

CATCmdWorkbench * MBDPrtWb::CreateWorkbench()
{
#include <Workshop.h>
}

CATClassId MBDPrtWb::GetAddinInterface()
{
  return IMBDPrtWbAddin::ClassName();
}

void MBDPrtWb::GetCustomInterfaces(CATListPV* defaultIIDList,
                                       CATListPV* customIIDList)
{}

CATCmdContainer* MBDPrtWb::CreateToolbars()
{
#include <AddinWorkshop.h>
}
