#include <MBDPPRWbWorkbench.h>
#include <TIE_CATIWSPROCConfiguration.h>
#include <IMBDPPRWbAddin.h>
#include <HeaderDeclarations.h>
#include <CATCreateWorkshop.h>

CATImplementClass(MBDPPRWb, Implementation, CATBaseUnknown, CATNull);
TIE_CATIWSPROCConfiguration(MBDPPRWb);

MBDPPRWb::MBDPPRWb()
{}
MBDPPRWb::~MBDPPRWb()
{}

void MBDPPRWb::CreateCommands()
{
#include <Headers.h>
}

CATCmdWorkbench * MBDPPRWb::CreateWorkbench()
{
#include <Workshop.h>
}


CATClassId MBDPPRWb::GetAddinInterface()
{
  return IMBDPPRWbAddin::ClassName();
}

void MBDPPRWb::GetCustomInterfaces(CATListPV* defaultIIDList,
                                       CATListPV* customIIDList)
{}
