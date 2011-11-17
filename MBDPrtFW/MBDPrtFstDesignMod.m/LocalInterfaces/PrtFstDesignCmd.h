// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignCmd.h
// The state chart based command: PrtFstDesignCmd
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
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstDesignCmd_H
#define PrtFstDesignCmd_H

#include "ktPubHeaders.h"
#include "CATStateCommand.h"
#include "CATBoolean.h"
#include "PrtFstDesignDlg.h"
#include "CATFeatureImportAgent.h"
#include "CATPathElementAgent.h"
#include "CATHSO.h"





//----------------------------------------------------------------------

/**
 * Describe your command here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog engine framework.
 * (consult base class description).
 */
class PrtFstDesignCmd: public CATStateCommand
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstDesignCmd, CATStateCommand )

  public:

  PrtFstDesignCmd();
  virtual ~PrtFstDesignCmd();

    /**
     * Defines the command automata.
     * <br>
     * <i>(states, transitions and agents)</i>
     */
  virtual void     BuildGraph();

  //��Ϣ����Ӧ����
  void OkDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  void CloseDlgCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  //�ж��Ƿ�ΪZPģ��
  BOOL IsThisZPPrt();

  //����ת����Ϣ��Ӧ����
  CATBoolean ChoosePoints( void *UsefulData);
  CATBoolean ChooseFirstSurfs( void *UsefulData);
  CATBoolean ChooseSecSurfs( void *UsefulData);
  //
  CATBoolean ActivePointsSL( void *UsefulData);
  CATBoolean ActiveFirstSurfSL( void *UsefulData);
  CATBoolean ActiveSecSurfSL( void *UsefulData);
  //
private:
	PrtFstDesignDlg *m_piDlg;

	//�ĵ�ָ��
	CATDocument *m_piDoc;
	CATUnicodeString m_strDocName;
	CATFrmEditor *m_piEditor;
	CATHSO *m_piHSO;

	//�������
	CATFeatureImportAgent *m_piFirstSurfAgt,*m_piSecSurfAgt,*m_piPointsAgt;

	CATDialogAgent *m_piPointSLAgt,*m_piFirstSurfSLAgt,*m_piSecSurfSLAgt;

	//�洢�м����ݱ���
	CATListValCATISpecObject_var m_lstSpecPoints;
	CATListValCATISpecObject_var m_lstSpecFirstSurfs,m_lstSpecSecSurfs;
};

//----------------------------------------------------------------------

#endif