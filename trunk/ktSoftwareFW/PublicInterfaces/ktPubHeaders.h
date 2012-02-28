//公共函数头文件，方便以后加入，直接写在这里，减少不必要的工作量

#include "CATBaseUnknown.h"
#include "CATIPrtPart.h"
#include "CATDocument.h"
#include "CATISpecObject.h"
#include "CATIProduct.h"
#include "CATVisPropertiesValues.h"
#include "CATVisPropertyType.h"
#include "CATVisGeomType.h"
#include "CATICkeParm.h"
#include "CATIContainer.h"
#include "CATICkeParmFactory.h"
#include "CATIGSMFactory.h"

// ObjectModelerBase framework
#include "CATSessionServices.h"  // Create, delete a session
#include "CATDocumentServices.h" // Open,close a document
#include "CATIDocRoots.h"
#include "CATIContainer.h"
#include "CATInit.h"
#include "CATILinkableObject.h"
#include "CATGetEnvValue.h"

// ObjectModelerBase Framework
#include "CATIIniInteractiveSession.h"
#include "CATSessionServices.h"
#include "CATIEditor.h"
#include "CATIAlias.h"
#include "CATSession.h"

// System framework
#include "CATUnicodeString.h"

// ProductStructure framework
#include "CATIProduct.h"
#include "CATIPrdProperties.h"

// MecModInterfaces framework
#include "CATIContainerOfDocument.h"
#include "CATIPrtContainer.h"
#include "CATIPrtPart.h"

// ObjectSpecsModeler framework
#include "CATISpecObject.h"
#include "CATDocument.h"   
#include "CATIStorageProperty.h"


// Visualization
#include "CATHSO.h"

// VisualizationBase 
#include "CAT3DViewpoint.h"
#include "CATViewer.h"


// KnowledgeInterfaces framework
#include "CATICkeParm.h"
#include "CATICkeParmFactory.h"
#include "CATICkeParameterSet.h"
#include "CATICkeRelationFactory.h"

//#include "CATICkeParameterSet.h"
#include "CATIDescendants.h"
#include "CATIAlias.h"
#include "CATIGSMTool.h"
#include "CATIMechanicalTool.h"

//MecModInterfaces Framework
#include "CATMfErrUpdate.h"


//碰撞检查函数
#include "CATIClashFactory.h"
#include "CATIClash.h"
#include "CATIClashResult.h"
#include "CATIClash.h"
#include "CATIConflict.h"

// ApplicationFrame 
#include "CATFrmEditor.h"
#include "CATApplicationFrame.h"
#include "CATCafCenterGraph.h"
#include "CATFrmNavigGraphicWindow.h"

// Dialog
#include "CATDlgWindow.h"
#include "CATDlgNotify.h"

// VisualizationBase 
#include "CATPathElement.h"

//VB headers
#include "CATIAParameters.h"
#include "CATIABase.h"
#include "CATIAPart.h"
#include "CATIAStrParam.h"
// VBA
#include "CATScriptUtilities.h"
#include "CATVariant.h"
#include "CATAutoConversions.h"

#include "CATListOfDouble.h"
#include "CATIAProduct.h"
#include "CATIAArrangementRuns.h"
#include "CATIAArrangementRun.h"
#include "CATAutoConversions.h"
#include "CATIArrSegmentsString.h"
#include "CATIRouSection.h"
#include "CATRouSectionTypes.h"
#include "CATIAArrangementProduct.h"

//Global Function
#include "CATLib.h"

#include "CATCollec.h"
#include "CATListOfInt.h"


#include "CATIBuildPath.h"
#include "CATIVisProperties.h"
#include "CATIModelEvents.h"
#include "CATModify.h"
#include "CATIRedrawEvent.h"
#include "CATFrmEditor.h"

#include "CATMmrLinearBodyServices.h"
#include "CATIMechanicalRootFactory.h" // To create Open Body
#include "CATIMechanicalTool.h"          
#include "CATIMmiOrderedGeometricalSet.h"          
#include "CATIMmiNonOrderedGeometricalSet.h"          
#include "CATIGSMTool.h"               // To handle GSMTool (Open Body)  
#include "CATMfErrUpdate.h"            // To handle Update Exceptions
#include "CATIGSMProceduralView.h"
#include "CATModifyVisProperties.h"
#include "CATIDocId.h"
#include "CATIEnumere.h"
#include "CATIParmManipulator.h"
#include "CATICkeRelation.h"
#include "CATCkeGlobalFunctions.h"
#include "CATIGSMExtractSolide.h"
#include "CATICutAndPastable.h"
#include "CATIGSMFactory.h"
#include "SpecBindNativeFormat.h"
#include "CATIDatumFactory.h"
#include "CATIGeometricalElement.h"
#include "CATBody.h"
#include "CATCell.h"
#include "CATGeoFactory.h"
#include "CATIMf3DBehavior.h"
#include "CATDelete.h"
#include "CATFace.h"
#include "LifeCycleObject.h"
#include "CATSoftwareConfiguration.h"
#include "CATCGMJournalList.h"
#include "CATHybIntersect.h"

// XMLParser
#include "CATIDOMElement.h"
#include "CATIDOMImplementation.h"
#include "CATIXMLDOMDocumentBuilder.h"
#include "CATIDOMDocument.h"
#include "CATIDOMText.h"
#include "CATListOfCATUnicodeString.h"
#include "CATIDOMDocumentType.h"
#include "CATIXMLSAXFactory.h"
#include "CATIXMLInputStream.h"
#include "CATISAXInputSource.h"
#include "CATIDOMNodeList.h"

// MecModInterfaces Framework
#include "CATIPartRequest.h"

// GSM POINT AND LINE
#include "CATIGSMLinePtPt.h"
#include "CATIGSMLinePtDir.h"
#include "CATIGSMAssemble.h"

//
#include "CATIMfZeroDimResult.h"
#include "CATIMfBiDimResult.h"
#include "CATISO.h"
#include "CAT3DAnnotationTextGP.h"
#include "CATIMeasurablePoint.h"
#include "CATModelForRep3D.h"
#include "CAT3DCustomRep.h"
#include "CATGraphicAttributeSet.h"
#include "CATIStructureAnalyse.h"
#include "CATIMmiMechanicalImportApplicative.h"
#include "CATIGSMIntersect.h"
#include "CATIGSMLineNormal.h"
#include "CAT3DMarkerGP.h"
#include "CAT3DFixedArrowGP.h"
#include "CATIMfBRep.h"
#include "CAT4x4Matrix.h"
//#include "CATIMmiInternalCopyWithLink.h"

// 拓扑层操作接口
#include "CATCreateTopAssemble.h"
#include "CATSoftwareConfiguration.h"
#include "CATTopData.h"
#include "CATCreateTopProject.h"
#include "CATHybProject.h"
#include "CATVertex.h"
#include "CATPoint.h"


// MechanicalModeler
#include "CATMmrInterPartCopy.h"

// XMLParser framework
#include "CATSAXParseException.h" // To represent SAX parse errors.
#include "CATError.h"             // V5 error handling functions

//
#include "CATStateCommand.h"
#include "CATISpecAttrAccess.h"
#include "CATISpecAttribute.h"
#include "CATISpecAttrKey.h"

//
#include "CHandleString.h"
#include "CLog.h"
#include "DirFileService.h"
#include "ktSoftwareLic.h"
#include "MBDWebservice.h"
#include "PrdService.h"
#include "PrtService.h"
#include "XMLService.h"

// Standard C++ library
#include "atlstr.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "stdio.h"
#include <sstream>
#include "iostream"
using namespace std;