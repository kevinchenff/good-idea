// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDTechnicInfoDlg.h
// The dialog : MBDTechnicInfoDlg
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
//  Apr 2011  Creation: Code generated by the CAA wizard  ev5adm
//===================================================================
#ifndef MBDTechnicInfoDlg_H
#define MBDTechnicInfoDlg_H

//ktsoftware PubHeader
#include "ktPubHeaders.h"


#include "CATDlgDialog.h"
#include "CATDlgInclude.h"
#include "CAATreeCtrl.h"

#include "CATLISTPIUnknown.h"
#include "CATListOfInt.h"
#include "CATListOfCATUnicodeString.h"
#include "CATDocument.h"
#include "CATLISTV_CATISpecObject.h"



//----------------------------------------------------------------------

/**
 * Describe the purpose of your panel here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog framework.
 * (consult base class description).
 */
class MBDTechnicInfoDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDTechnicInfoDlg, CATDlgDialog )

  public:

  MBDTechnicInfoDlg();
  virtual ~MBDTechnicInfoDlg();

  void Build ();
  void GetGSMToolSpecs(CATDocument * ipDoc,CATListValCATISpecObject_var &listTreeNodeSpec);

  //protected:

  //private:


//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame002;
 CATDlgFrame*      _Frame004;
 CATDlgPushButton*      _TechnicNoteSearchPB;
 CATDlgPushButton*      _NewNoteAddinPB;
 CATDlgFrame*      _Frame005;
 CATDlgEditor*      _SpecialFeatureEditor;
 CATDlgCombo*      _FlagNoteCombo;
 CATDlgLabel*      _Label006;
 CATDlgLabel*      _Label008;
 CATDlgFrame*      _Frame003;
 CATDlgFrame*      _SearchResultFrame;
 CATDlgMultiList*      _SearchResultML;
 CATDlgPushButton*      _InsertToGSMToolPB;
 CATDlgFrame*      _TechnicalNoteDetailFrame;
 CATDlgEditor*      _TechnicalNoteDetailEditor;
 CATDlgFrame*      _Frame001;
 CATDlgFrame*      _TreeFrame;
 CATDlgFrame*      _TechnicNoteFrame;
 CATDlgMultiList*      _TreeGSMToolNotesML;
//END CAA2 WIZARD WIDGET DECLARATION SECTION

 CAATreeCtrl * m_piTreeCtrl;

 CATLISTV(CATUnicodeString) m_ListTreeNodeName;

 //
 CATUnicodeString m_xmlPath;

};

//----------------------------------------------------------------------

#endif
