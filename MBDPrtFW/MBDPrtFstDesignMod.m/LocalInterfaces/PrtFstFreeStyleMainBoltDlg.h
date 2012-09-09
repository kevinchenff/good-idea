// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleMainBoltDlg.h
// The dialog : PrtFstFreeStyleMainBoltDlg
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
#ifndef PrtFstFreeStyleMainBoltDlg_H
#define PrtFstFreeStyleMainBoltDlg_H

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
class PrtFstFreeStyleMainBoltDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( PrtFstFreeStyleMainBoltDlg, CATDlgDialog )

  public:

  PrtFstFreeStyleMainBoltDlg();
  virtual ~PrtFstFreeStyleMainBoltDlg();

  void Build ();

//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgLabel*      _Label01;
 CATDlgLabel*      _Label02;
 CATDlgLabel*      _Label03;
 CATDlgEditor*      _MaxLayerThicknessEditor;
 CATDlgEditor*      _MinLayerThicknessEditor;
 CATDlgEditor*      _FirstLayerThicknessEditor;
 CATDlgFrame*      _Frame002;
 CATDlgLabel*      _Label04;
 CATDlgSpinner*      _MinSpinner;
 CATDlgSpinner*      _MaxSpinner;
 CATDlgPushButton*      _GoToSearchPB;
 CATDlgFrame*      _Frame003;
 CATDlgMultiList*      _SearchResultML;
 CATDlgFrame*      _Frame04;
 CATDlgPushButton*      _LastStepPB;
 CATDlgPushButton*      _NextStepPB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION

 //
 //����ͷ����
 CATUnicodeString m_lstStrPropertyName[8];


};

//----------------------------------------------------------------------

#endif
