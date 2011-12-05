// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstPointsCmd.h
// The state chart based command: PrtFstPointsCmd
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
//  Nov 2011  Creation: Code generated by the CAA wizard  Administrator
//===================================================================
#ifndef PrtFstPointsCmd_H
#define PrtFstPointsCmd_H

#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "PrtFstPointsDlg.h"
#include "CATFeatureImportAgent.h"


//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class PrtFstPointsCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstPointsCmd, CATStateCommand )

  public:

  PrtFstPointsCmd();
  virtual ~PrtFstPointsCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();

  //消息框响应函数
  void OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  CATBoolean ChooseCurve( void *UsefulData);
  CATBoolean ChooseSurf( void *UsefulData);
  //
  CATBoolean ActiveCurveSL( void *UsefulData);
  CATBoolean ActiveSurfSL( void *UsefulData);



  
  private:

	  PrtFstPointsDlg *m_pDlg;

	  //定义代理
	  CATFeatureImportAgent *m_pCurveAgt,*m_pSurfAgt;
	  CATDialogAgent *m_pCurveSLAgt,*m_pSurfSLAgt;


};

//----------------------------------------------------------------------

#endif
