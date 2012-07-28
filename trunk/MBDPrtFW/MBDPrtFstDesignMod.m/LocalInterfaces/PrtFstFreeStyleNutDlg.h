// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleNutDlg.h
// The dialog : PrtFstFreeStyleNutDlg
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
#ifndef PrtFstFreeStyleNutDlg_H
#define PrtFstFreeStyleNutDlg_H

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
class PrtFstFreeStyleNutDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstFreeStyleNutDlg, CATDlgDialog )

  public:

  PrtFstFreeStyleNutDlg();
  virtual ~PrtFstFreeStyleNutDlg();

  void Build ();

//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgLabel*      _Label01;
 CATDlgLabel*      _Label02;
 CATDlgLabel*      _Label03;
 CATDlgLabel*      _Label04;
 CATDlgCombo*      _Combo01;
 CATDlgCombo*      _Combo02;
 CATDlgCombo*      _Combo03;
 CATDlgCombo*      _Combo04;
 CATDlgPushButton*      _GoToSearchPB;
 CATDlgLabel*      _Label05;
 CATDlgCombo*      _Combo05;
 CATDlgFrame*      _Frame002;
 CATDlgMultiList*      _SearchResultML;
 CATDlgFrame*      _Frame003;
 CATDlgPushButton*      _NextStepPB;
 CATDlgPushButton*      _LastStepPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
