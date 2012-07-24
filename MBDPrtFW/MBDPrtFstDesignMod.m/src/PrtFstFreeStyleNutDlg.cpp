// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleNutDlg.cpp
// The dialog : PrtFstFreeStyleNutDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstFreeStyleNutDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstFreeStyleNutDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstFreeStyleNutDlg::PrtFstFreeStyleNutDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstFreeStyleNutDlg",CATDlgWndBtnClose|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _Label04 = NULL;
 _Combo01 = NULL;
 _Combo02 = NULL;
 _Combo03 = NULL;
 _Combo04 = NULL;
 _Frame002 = NULL;
 _SearchResultML = NULL;
 _Frame003 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstFreeStyleNutDlg::~PrtFstFreeStyleNutDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _Label04 = NULL;
 _Combo01 = NULL;
 _Combo02 = NULL;
 _Combo03 = NULL;
 _Combo04 = NULL;
 _Frame002 = NULL;
 _SearchResultML = NULL;
 _Frame003 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstFreeStyleNutDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(1,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridColumnResizable(1,1);
 _Label01 = new CATDlgLabel(_Frame001, "Label01");
_Label01 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Label02 = new CATDlgLabel(_Frame001, "Label02");
_Label02 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Label03 = new CATDlgLabel(_Frame001, "Label03");
_Label03 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Label04 = new CATDlgLabel(_Frame001, "Label04");
_Label04 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Combo01 = new CATDlgCombo(_Frame001, "Combo01", CATDlgCmbDropDown);
_Combo01 -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Combo02 = new CATDlgCombo(_Frame001, "Combo02", CATDlgCmbDropDown);
_Combo02 -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _Combo03 = new CATDlgCombo(_Frame001, "Combo03", CATDlgCmbDropDown);
_Combo03 -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
 _Combo04 = new CATDlgCombo(_Frame001, "Combo04", CATDlgCmbDropDown);
_Combo04 -> SetGridConstraints(3, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridRowResizable(0,1);
 _Frame002 -> SetGridColumnResizable(0,1);
 _SearchResultML = new CATDlgMultiList(_Frame002, "SearchResultML");
 CATUnicodeString SearchResultMLTitles [ 8 ];
 SearchResultMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle1");
 SearchResultMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle2");
 SearchResultMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle3");
 SearchResultMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle4");
 SearchResultMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle5");
 SearchResultMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle6");
 SearchResultMLTitles[6] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle7");
 SearchResultMLTitles[7] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleNutDlg", "Frame002.SearchResultML.ColumnTitle8");
 _SearchResultML -> SetColumnTitles(8, SearchResultMLTitles);
 _SearchResultML -> SetVisibleColumnCount( 8 );
_SearchResultML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridColumnResizable(0,1);
 _NextStepPB = new CATDlgPushButton(_Frame003, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _LastStepPB = new CATDlgPushButton(_Frame003, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

