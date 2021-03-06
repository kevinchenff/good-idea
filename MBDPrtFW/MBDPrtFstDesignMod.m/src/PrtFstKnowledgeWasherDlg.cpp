// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstKnowledgeWasherDlg.cpp
// The dialog : PrtFstKnowledgeWasherDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstKnowledgeWasherDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstKnowledgeWasherDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstKnowledgeWasherDlg::PrtFstKnowledgeWasherDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstKnowledgeWasherDlg",CATDlgWndModal|CATDlgWndBtnClose|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _SearchResultsML = NULL;
 _Frame006 = NULL;
 _PosSTARTRB = NULL;
 _PosENDRB = NULL;
 _Frame002 = NULL;
 _Label009 = NULL;
 _Label010 = NULL;
 _ThickLeftEditor = NULL;
 _EndLeftEditor = NULL;
 _Frame003 = NULL;
 _ChooseWashersML = NULL;
 _Frame014 = NULL;
 _RemovePB = NULL;
 _ClearAllPB = NULL;
 _Frame004 = NULL;
 _LastStepPB = NULL;
 _NextStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION


 //
 m_lstStrPropertyName[0]=CATUnicodeString("紧固件标准号");
 m_lstStrPropertyName[1]=CATUnicodeString("紧固件名称");
 m_lstStrPropertyName[2]=CATUnicodeString("材料");
 m_lstStrPropertyName[3]=CATUnicodeString("表面处理");
 m_lstStrPropertyName[4]=CATUnicodeString("紧固件标识");
 m_lstStrPropertyName[5]=CATUnicodeString("公称直径");
 m_lstStrPropertyName[6]=CATUnicodeString("内径");
 m_lstStrPropertyName[7]=CATUnicodeString("外径");
 m_lstStrPropertyName[8]=CATUnicodeString("沉槽直径"); 
 m_lstStrPropertyName[9]=CATUnicodeString("厚度");
 m_lstStrPropertyName[10]=CATUnicodeString("重量（kg）");
 //
 m_lstStrPropertyName02[0]=CATUnicodeString("安装部位");
 m_lstStrPropertyName02[1]=CATUnicodeString("紧固件标准号");
 m_lstStrPropertyName02[2]=CATUnicodeString("紧固件名称");
 m_lstStrPropertyName02[3]=CATUnicodeString("材料");
 m_lstStrPropertyName02[4]=CATUnicodeString("表面处理");
 m_lstStrPropertyName02[5]=CATUnicodeString("单位制"); 
 m_lstStrPropertyName02[6]=CATUnicodeString("备注");
 m_lstStrPropertyName02[7]=CATUnicodeString("紧固件标识");
 m_lstStrPropertyName02[8]=CATUnicodeString("公称直径");
 m_lstStrPropertyName02[9]=CATUnicodeString("内径");
 m_lstStrPropertyName02[10]=CATUnicodeString("外径");
 m_lstStrPropertyName02[11]=CATUnicodeString("沉槽直径"); 
 m_lstStrPropertyName02[12]=CATUnicodeString("厚度");
 m_lstStrPropertyName02[13]=CATUnicodeString("重量（kg）");


}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstKnowledgeWasherDlg::~PrtFstKnowledgeWasherDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _SearchResultsML = NULL;
 _Frame006 = NULL;
 _PosSTARTRB = NULL;
 _PosENDRB = NULL;
 _Frame002 = NULL;
 _Label009 = NULL;
 _Label010 = NULL;
 _ThickLeftEditor = NULL;
 _EndLeftEditor = NULL;
 _Frame003 = NULL;
 _ChooseWashersML = NULL;
 _Frame014 = NULL;
 _RemovePB = NULL;
 _ClearAllPB = NULL;
 _Frame004 = NULL;
 _LastStepPB = NULL;
 _NextStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION


//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstKnowledgeWasherDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(0,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridRowResizable(1,1);
 _Frame001 -> SetGridColumnResizable(0,1);
 _SearchResultsML = new CATDlgMultiList(_Frame001, "SearchResultsML");
 //CATUnicodeString SearchResultsMLTitles [ 1 ];
 //SearchResultsMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeWasherDlg", "Frame001.SearchResultsML.ColumnTitle1");
 _SearchResultsML -> SetColumnTitles(11, m_lstStrPropertyName);
 _SearchResultsML -> SetVisibleColumnCount( 11 );
_SearchResultsML -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame006 = new CATDlgFrame(_Frame001, "Frame006", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame006 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _PosSTARTRB = new CATDlgRadioButton(_Frame006, "PosSTARTRB");
_PosSTARTRB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _PosENDRB = new CATDlgRadioButton(_Frame006, "PosENDRB");
_PosENDRB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridColumnResizable(1,1);
 _Label009 = new CATDlgLabel(_Frame002, "Label009");
_Label009 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Label010 = new CATDlgLabel(_Frame002, "Label010");
_Label010 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _ThickLeftEditor = new CATDlgEditor(_Frame002, "ThickLeftEditor", CATDlgEdtReadOnly);
 _ThickLeftEditor -> SetVisibleTextWidth(25);
_ThickLeftEditor -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _EndLeftEditor = new CATDlgEditor(_Frame002, "EndLeftEditor", CATDlgEdtReadOnly);
_EndLeftEditor -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridColumnResizable(0,1);
 _ChooseWashersML = new CATDlgMultiList(_Frame003, "ChooseWashersML");
 //CATUnicodeString ChooseWashersMLTitles [ 1 ];
 //ChooseWashersMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeWasherDlg", "Frame003.ChooseWashersML.ColumnTitle1");
 _ChooseWashersML -> SetColumnTitles(14, m_lstStrPropertyName02);
 _ChooseWashersML -> SetVisibleColumnCount( 14 );
_ChooseWashersML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame014 = new CATDlgFrame(_Frame003, "Frame014", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame014 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _RemovePB = new CATDlgPushButton(_Frame014, "RemovePB");
_RemovePB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _ClearAllPB = new CATDlgPushButton(_Frame014, "ClearAllPB");
_ClearAllPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Frame004 = new CATDlgFrame(this, "Frame004", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame004 -> SetGridConstraints(3, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
 _Frame004 -> SetGridColumnResizable(1,1);
 _LastStepPB = new CATDlgPushButton(_Frame004, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _NextStepPB = new CATDlgPushButton(_Frame004, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION
//
_PosENDRB->SetState(CATDlgCheck);

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

