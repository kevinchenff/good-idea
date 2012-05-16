// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// MBDAddGSMToolCmd.h
// The state chart based command: MBDAddGSMToolCmd
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
//  Mar 2010  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDAddGSMToolCmd_H
#define MBDAddGSMToolCmd_H

// ktsoftware module
#include "ktKerExcel.h"

//ktsoftware PubHeader
#include "ktPubHeaders.h"


class MBDAddGSMToolDlg;
class CATDocument;

//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class MBDAddGSMToolCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDAddGSMToolCmd, CATStateCommand )

  public:

  MBDAddGSMToolCmd();
  virtual ~MBDAddGSMToolCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();

  void OnMBDOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void OnMBDCancelAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  
  void AddMBDGSMTools(CATDocument * piDocument);
  void AddARMGSMTools(CATDocument * piDocument);

  private:

	  MBDAddGSMToolDlg *m_pDlg;
	  CATDocument * m_piDoc;

  
};

//----------------------------------------------------------------------

#endif