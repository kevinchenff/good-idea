// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// MBDTechnicInfoNewAddinDlg.h
// The dialog : MBDTechnicInfoNewAddinDlg
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
#ifndef MBDTechnicInfoNewAddinDlg_H
#define MBDTechnicInfoNewAddinDlg_H

//ktsoftware PubHeader
#include "ktPubHeaders.h"

#include "CATDlgDialog.h"
#include "CATDlgInclude.h"
#include "CATLISTPIUnknown.h"
#include "CATListOfInt.h"
#include "CATListOfCATUnicodeString.h"



//----------------------------------------------------------------------

/**
 * Describe the purpose of your panel here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 * <p>
 * refer to programming resources of Dialog framework.
 * (consult base class description).
 */
class MBDTechnicInfoNewAddinDlg: public CATDlgDialog
{
  // Allows customization/internationalization of command's messages
  // ---------------------------------------------------------------
  DeclareResource( MBDTechnicInfoNewAddinDlg, CATDlgDialog )

  public:

  MBDTechnicInfoNewAddinDlg();
  virtual ~MBDTechnicInfoNewAddinDlg();

  void Build ();

  void ChangeDatabaseComboListCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  CATBoolean ComboItemSearchCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  HRESULT SetSearchItemComboList(CATListValCATUnicodeString astrKeyWords,CATDlgCombo * piDlgCombo);
  void GetAllWBSItemInfo(CATLISTV(CATUnicodeString) &listStrSearchItems);
  void ApplyNoteToEditorPBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);
  HRESULT GetSerialNumberList();
  void ApplyNoteToDatabasePBCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

//CAA2 WIZARD WIDGET DECLARATION SECTION
 CATDlgFrame*      _Frame001;
 CATDlgLabel*      _Label005;
 CATDlgCombo*      _DatabaseListCombo;
 CATDlgFrame*      _Frame002;
 CATDlgEditor*      _TechnicalNoteCttEditor;
 CATDlgFrame*      _SearchItemsFrame;
 CATDlgFrame*      _Frame004;
 CATDlgPushButton*      _ApplyNoteToEditorPB;
 CATDlgPushButton*      _ApplyNoteToDatabasePB;
//END CAA2 WIZARD WIDGET DECLARATION SECTION

 //��ʼ�����б�
 CATLISTP(IUnknown)  m_ItemEditorList;
 CATLISTP(IUnknown)  m_ItemComboList;

 //��ʾ�Ŀؼ��б�
 CATLISTP(IUnknown)  m_ShowItemComboList;
 CATLISTP(IUnknown)  m_ShowItemEditorList;

 CATLISTV(CATUnicodeString) ListDbName;
 CATLISTV(CATUnicodeString) ListDbWBSItem;
 CATListOfInt countNode;
 CATLISTV(CATUnicodeString) ListComboName;
 CATLISTV(CATUnicodeString) ListWBSItem;
 CATLISTV(CATUnicodeString) ListGSMToolName;
 CATLISTV(CATUnicodeString) ListGSMToolSwitch;

 //��ǰ״̬label and combo XML����
 CATLISTV(CATUnicodeString) ListCurrentComboName;
 CATLISTV(CATUnicodeString) ListCurrentWBSItem;

 //�����CMDֱ�Ӳ�ѯ��
 CATLISTV(CATUnicodeString) m_ListWBSItemValue;

 //��ǰ���к�����
 CATListValCATUnicodeString m_astrSerialNumValue;
 CATUnicodeString m_CurrSerialNum;


 int m_NodeLocate;
 CATUnicodeString m_xmlPath;

};

//----------------------------------------------------------------------

#endif