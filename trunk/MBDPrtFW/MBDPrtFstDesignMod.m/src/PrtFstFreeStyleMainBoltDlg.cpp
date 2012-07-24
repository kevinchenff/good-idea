// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstFreeStyleMainBoltDlg.cpp
// The dialog : PrtFstFreeStyleMainBoltDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstFreeStyleMainBoltDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstFreeStyleMainBoltDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstFreeStyleMainBoltDlg::PrtFstFreeStyleMainBoltDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstFreeStyleMainBoltDlg",CATDlgWndBtnClose|CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _MaxLayerThicknessEditor = NULL;
 _MinLayerThicknessEditor = NULL;
 _FirstLayerThicknessEditor = NULL;
 _Frame002 = NULL;
 _Label04 = NULL;
 _Spinner012 = NULL;
 _Spinner013 = NULL;
 _GoToSearchPB = NULL;
 _Frame003 = NULL;
 _SearchResultML = NULL;
 _Frame04 = NULL;
 _LastStepPB = NULL;
 _NextStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstFreeStyleMainBoltDlg::~PrtFstFreeStyleMainBoltDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _Label01 = NULL;
 _Label02 = NULL;
 _Label03 = NULL;
 _MaxLayerThicknessEditor = NULL;
 _MinLayerThicknessEditor = NULL;
 _FirstLayerThicknessEditor = NULL;
 _Frame002 = NULL;
 _Label04 = NULL;
 _Spinner012 = NULL;
 _Spinner013 = NULL;
 _GoToSearchPB = NULL;
 _Frame003 = NULL;
 _SearchResultML = NULL;
 _Frame04 = NULL;
 _LastStepPB = NULL;
 _NextStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstFreeStyleMainBoltDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(2,1);
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
 _MaxLayerThicknessEditor = new CATDlgEditor(_Frame001, "MaxLayerThicknessEditor", CATDlgEdtReadOnly);
 _MaxLayerThicknessEditor -> SetVisibleTextWidth(15);
_MaxLayerThicknessEditor -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _MinLayerThicknessEditor = new CATDlgEditor(_Frame001, "MinLayerThicknessEditor", CATDlgEdtReadOnly);
_MinLayerThicknessEditor -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _FirstLayerThicknessEditor = new CATDlgEditor(_Frame001, "FirstLayerThicknessEditor", CATDlgEdtReadOnly);
_FirstLayerThicknessEditor -> SetGridConstraints(2, 1, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridColumnResizable(0,1);
 _Frame002 -> SetGridColumnResizable(2,1);
 _Label04 = new CATDlgLabel(_Frame002, "Label04");
_Label04 -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _Spinner012 = new CATDlgSpinner(_Frame002, "Spinner012");
 _Spinner012 -> SetRange(0.000000, 10.000000, (float)10.000000);
_Spinner012 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Spinner013 = new CATDlgSpinner(_Frame002, "Spinner013");
 _Spinner013 -> SetRange(0.000000, 10.000000, (float)10.000000);
_Spinner013 -> SetGridConstraints(0, 2, 1, 1, CATGRID_4SIDES);
 _GoToSearchPB = new CATDlgPushButton(_Frame002, "GoToSearchPB");
_GoToSearchPB -> SetGridConstraints(1, 2, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridRowResizable(0,1);
 _Frame003 -> SetGridColumnResizable(0,1);
 _SearchResultML = new CATDlgMultiList(_Frame003, "SearchResultML");
 CATUnicodeString SearchResultMLTitles [ 9 ];
 SearchResultMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle1");
 SearchResultMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle2");
 SearchResultMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle3");
 SearchResultMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle4");
 SearchResultMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle5");
 SearchResultMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle6");
 SearchResultMLTitles[6] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle7");
 SearchResultMLTitles[7] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle8");
 SearchResultMLTitles[8] = CATMsgCatalog::BuildMessage("PrtFstFreeStyleMainBoltDlg", "Frame003.SearchResultML.ColumnTitle9");
 _SearchResultML -> SetColumnTitles(9, SearchResultMLTitles);
 _SearchResultML -> SetVisibleColumnCount( 9 );
_SearchResultML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame04 = new CATDlgFrame(this, "Frame04", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame04 -> SetGridConstraints(3, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
 _Frame04 -> SetGridRowResizable(0,1);
 _Frame04 -> SetGridColumnResizable(0,1);
 _Frame04 -> SetGridColumnResizable(1,1);
 _LastStepPB = new CATDlgPushButton(_Frame04, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _NextStepPB = new CATDlgPushButton(_Frame04, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

