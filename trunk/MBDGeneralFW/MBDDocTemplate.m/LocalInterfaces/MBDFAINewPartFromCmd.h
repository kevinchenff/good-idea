// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// MBDFAINewPartFromCmd.h
// The state chart based command: MBDFAINewPartFromCmd
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
//  Jan 2010  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDFAINewPartFromCmd_H
#define MBDFAINewPartFromCmd_H

// ktsoftware module
#include "ktKerExcel.h"

//ktsoftware PubHeader
#include "ktPubHeaders.h"

#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "MBDFAINewPartFromDlg.h"
#include "CATISpecObject.h"


//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class MBDFAINewPartFromCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDFAINewPartFromCmd, CATStateCommand )

  public:

  MBDFAINewPartFromCmd();
  virtual ~MBDFAINewPartFromCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();


  void OnOpenFileOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void OnMBDOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void OnMBDCancelAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  void ModifyCopyedGSMTool(CATLISTV(CATISpecObject_var) &ListSpecDesc);

  private:
	  MBDFAINewPartFromDlg * m_pDlg;
	  CATFrmEditor * m_pFrmEditor;

	  CATDlgFile * m_pOpenFileDlg;
	  CATUnicodeString  m_oSelectedFile;


};

//----------------------------------------------------------------------

#endif
