// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstKnowledgeNutDlg.h
// The dialog : PrtFstKnowledgeNutDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   DIALOG
//End CAA2 Wizard Generation Report
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstKnowledgeNutDlg_H
#define PrtFstKnowledgeNutDlg_H

#include "CATDlgDialog.h"
#include "CATDlgInclude.h"

//----------------------------------------------------------------------

/**
 * Describe the purpose of your panel here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog framework.
 * (consult base class description).
 */
class PrtFstKnowledgeNutDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstKnowledgeNutDlg, CATDlgDialog )

  public:

  PrtFstKnowledgeNutDlg();
  virtual ~PrtFstKnowledgeNutDlg();

  void Build ();

//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame002;
 CATDlgMultiList*      _SearchResultsML;
 CATDlgFrame*      _Frame003;
 CATDlgPushButton*      _NextStepPB;
 CATDlgPushButton*      _LastStepPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
