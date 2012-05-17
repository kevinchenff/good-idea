// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstUpdateDlg.h
// The dialog : PrtFstUpdateDlg
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
#ifndef PrtFstUpdateDlg_H
#define PrtFstUpdateDlg_H

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
class PrtFstUpdateDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstUpdateDlg, CATDlgDialog )

  public:

  PrtFstUpdateDlg();
  virtual ~PrtFstUpdateDlg();

  void Build ();


  protected:

  private:


//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgSelectorList*      _SelectorList004;
 CATDlgFrame*      _Frame007;
 CATDlgPushButton*      _PushButton005;
 CATDlgPushButton*      _PushButton006;
 CATDlgFrame*      _Frame002;
 CATDlgMultiList*      _MultiList008;
 CATDlgFrame*      _Frame003;
 CATDlgMultiList*      _MultiList009;
//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION


//END CAA2 WIZARD WIDGET DECLARATION SECTION
};

//----------------------------------------------------------------------

#endif
