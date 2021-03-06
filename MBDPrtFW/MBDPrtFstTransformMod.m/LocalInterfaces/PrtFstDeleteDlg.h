// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstDeleteDlg.h
// The dialog : PrtFstDeleteDlg
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
//  May 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#ifndef PrtFstDeleteDlg_H
#define PrtFstDeleteDlg_H

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
class PrtFstDeleteDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstDeleteDlg, CATDlgDialog )

  public:

  PrtFstDeleteDlg();
  virtual ~PrtFstDeleteDlg();

  void Build ();



//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgFrame*      _Frame008;
 CATDlgSelectorList*      _FSTLineSL;
 CATDlgFrame*      _Frame010;
 CATDlgPushButton*      _RemoveSelPB;
 CATDlgPushButton*      _RemoveAllPB;
 CATDlgFrame*      _Frame002;
 CATDlgFrame*      _Frame003;
 CATDlgMultiList*      _InstanceInfoML;
 CATDlgFrame*      _Frame004;
 CATDlgMultiList*      _ExternalInfoML;
//END CAA2 WIZARD WIDGET DECLARATION SECTION

};

//----------------------------------------------------------------------

#endif
