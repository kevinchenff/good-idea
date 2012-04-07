// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDPrtAddMaterialCmd.h
// The state chart based command: MBDPrtAddMaterialCmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   STATECOMMAND
//End CAA2 Wizard Generation Report
//
//  Feb 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDPrtAddMaterialCmd_H
#define MBDPrtAddMaterialCmd_H

// ktsoftware module
#include "ktKerExcel.h"

//ktsoftware PubHeader
#include "ktPubHeaders.h"

//Material Framework
#include "CATMaterialServices.h"

// CATMatInterfaces Framework
#include "CATIMaterialDocument.h" 
#include "CATIMaterialSupport.h" 
#include "CATILibraryFeature.h" 
#include "CATIMaterialFeature.h" 
#include "CATIFamilyFeature.h"

//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class MBDPrtAddMaterialCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDPrtAddMaterialCmd, CATStateCommand )

  public:

  MBDPrtAddMaterialCmd();
  virtual ~MBDPrtAddMaterialCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();


  //查询材料信息FROM DATABASE
  void SearchMaterialInfo();
  //获取材料catalog文件
  HRESULT CreateMaterialCatalog();

  //赋材料
  HRESULT ApplyMaterial(CATIMaterialFeature *pIMaterialFeature);

  //更改材料属性
  HRESULT SetMaterialProperty(CATIMaterialFeature * &pIMaterialFeature);

  private:

};

//----------------------------------------------------------------------

#endif
