// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstAccessDlg.cpp
// The dialog : PrtFstAccessDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstAccessDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstAccessDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstAccessDlg::PrtFstAccessDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstAccessDlg",CATDlgWndBtnOKCancel|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _FreeStyleRadioB = NULL;
 _KnowledgeBasedChooseRadioB = NULL;
 _GoToChoosePB = NULL;
 _Frame002 = NULL;
 _ChoosedFastenersML = NULL;
 _SaveBackCheckB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION

 //初始化显示信息
 ChoosedFastenersMLTitles[0]=CATUnicodeString("序号");
 ChoosedFastenersMLTitles[1]=CATUnicodeString("规格号");
 ChoosedFastenersMLTitles[2]=CATUnicodeString("名称");
 ChoosedFastenersMLTitles[3]=CATUnicodeString("类型");
 ChoosedFastenersMLTitles[4]=CATUnicodeString("安装部位");

}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstAccessDlg::~PrtFstAccessDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _FreeStyleRadioB = NULL;
 _KnowledgeBasedChooseRadioB = NULL;
 _GoToChoosePB = NULL;
 _Frame002 = NULL;
 _ChoosedFastenersML = NULL;
 _SaveBackCheckB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstAccessDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(1,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridColumnResizable(1,1);
 _FreeStyleRadioB = new CATDlgRadioButton(_Frame001, "FreeStyleRadioB");
_FreeStyleRadioB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _KnowledgeBasedChooseRadioB = new CATDlgRadioButton(_Frame001, "KnowledgeBasedChooseRadioB");
_KnowledgeBasedChooseRadioB -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _GoToChoosePB = new CATDlgPushButton(_Frame001, "GoToChoosePB");
_GoToChoosePB -> SetGridConstraints(1, 1, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridRowResizable(0,1);
 _Frame002 -> SetGridColumnResizable(0,1);
 _ChoosedFastenersML = new CATDlgMultiList(_Frame002, "ChoosedFastenersML");
 /*CATUnicodeString ChoosedFastenersMLTitles [ 5 ];
 ChoosedFastenersMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstAccessDlg", "Frame002.ChoosedFastenersML.ColumnTitle1");
 ChoosedFastenersMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstAccessDlg", "Frame002.ChoosedFastenersML.ColumnTitle2");
 ChoosedFastenersMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstAccessDlg", "Frame002.ChoosedFastenersML.ColumnTitle3");
 ChoosedFastenersMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstAccessDlg", "Frame002.ChoosedFastenersML.ColumnTitle4");
 ChoosedFastenersMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstAccessDlg", "Frame002.ChoosedFastenersML.ColumnTitle5");*/
 _ChoosedFastenersML -> SetColumnTitles(5, ChoosedFastenersMLTitles);
 _ChoosedFastenersML -> SetVisibleColumnCount( 5 );
_ChoosedFastenersML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _SaveBackCheckB = new CATDlgCheckButton(_Frame002, "SaveBackCheckB");
_SaveBackCheckB -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//
_FreeStyleRadioB->SetState(CATDlgCheck,0);


//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

