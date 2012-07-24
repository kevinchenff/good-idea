// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDPrtAnnotateToXMLCmd.h
// The state chart based command: MBDPrtAnnotateToXMLCmd
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
//  Jan 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDPrtAnnotateToXMLCmd_H
#define MBDPrtAnnotateToXMLCmd_H

// ktsoftware module
#include "ktKerExcel.h"

//ktsoftware PubHeader
#include "ktPubHeaders.h"


//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class MBDPrtAnnotateToXMLCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDPrtAnnotateToXMLCmd, CATStateCommand )

  public:

  MBDPrtAnnotateToXMLCmd();
  virtual ~MBDPrtAnnotateToXMLCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();


 /**
   * �洢XML�ĵ��Ի�����Ӧ
   */
  void OnSaveFileCancelAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void OnSaveFileOKAction(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  
  private:

	  // CATPart�ĵ�ָ��
	  CATDocument * m_piDoc;

	  // ���� �洢������·��
	  CATDlgFile * m_pSaveFileDlg;
	  CATUnicodeString  m_strSaveFilePath;
};

//----------------------------------------------------------------------

#endif