// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PrtFstKnowledgeMainBoltDlg.cpp
// The dialog : PrtFstKnowledgeMainBoltDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2012  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstKnowledgeMainBoltDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstKnowledgeMainBoltDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstKnowledgeMainBoltDlg::PrtFstKnowledgeMainBoltDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstKnowledgeMainBoltDlg",CATDlgWndModal|CATDlgWndBtnClose|CATDlgGridLayout
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
 _MinSpinner = NULL;
 _DiameterLabel = NULL;
 _MaxSpinner = NULL;
 _GoToSearchPB = NULL;
 _Frame003 = NULL;
 _SearchResultsML = NULL;
 _Frame004 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION


 //
 //初始化属性显示名称
 m_lstStrPropertyName[0]=CATUnicodeString("紧固件标准号");
 m_lstStrPropertyName[1]=CATUnicodeString("紧固件名称");
 m_lstStrPropertyName[2]=CATUnicodeString("头部类型");
 m_lstStrPropertyName[3]=CATUnicodeString("材料");
 m_lstStrPropertyName[4]=CATUnicodeString("表面处理"); 
 m_lstStrPropertyName[5]=CATUnicodeString("紧固件标识");
 m_lstStrPropertyName[6]=CATUnicodeString("公称直径");
 m_lstStrPropertyName[7]=CATUnicodeString("总长度");
 m_lstStrPropertyName[8]=CATUnicodeString("夹持厚度"); 
 m_lstStrPropertyName[9]=CATUnicodeString("重量（kg）");
 m_lstStrPropertyName[10]=CATUnicodeString("头部直径");
 m_lstStrPropertyName[11]=CATUnicodeString("头部厚度");
 m_lstStrPropertyName[12]=CATUnicodeString("**余量**");
 //

//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstKnowledgeMainBoltDlg::~PrtFstKnowledgeMainBoltDlg()
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
 _MinSpinner = NULL;
 _DiameterLabel = NULL;
 _MaxSpinner = NULL;
 _GoToSearchPB = NULL;
 _Frame003 = NULL;
 _SearchResultsML = NULL;
 _Frame004 = NULL;
 _NextStepPB = NULL;
 _LastStepPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstKnowledgeMainBoltDlg::Build()
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
 _MinSpinner = new CATDlgSpinner(_Frame002, "MinSpinner", CATDlgSpnEntry|CATDlgSpnDouble);
 //_MinSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
_MinSpinner -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _DiameterLabel = new CATDlgLabel(_Frame002, "DiameterLabel");
_DiameterLabel -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _MaxSpinner = new CATDlgSpinner(_Frame002, "MaxSpinner", CATDlgSpnEntry|CATDlgSpnDouble);
 //_MaxSpinner -> SetRange(0.000000, 10.000000, (float)10.000000);
_MaxSpinner -> SetGridConstraints(0, 2, 1, 1, CATGRID_4SIDES);
 _GoToSearchPB = new CATDlgPushButton(_Frame002, "GoToSearchPB");
_GoToSearchPB -> SetGridConstraints(1, 2, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridRowResizable(0,1);
 _Frame003 -> SetGridColumnResizable(0,1);
 _SearchResultsML = new CATDlgMultiList(_Frame003, "SearchResultsML");
 //CATUnicodeString SearchResultsMLTitles [ 6 ];
 //SearchResultsMLTitles[0] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle1");
 //SearchResultsMLTitles[1] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle2");
 //SearchResultsMLTitles[2] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle3");
 //SearchResultsMLTitles[3] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle4");
 //SearchResultsMLTitles[4] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle5");
 //SearchResultsMLTitles[5] = CATMsgCatalog::BuildMessage("PrtFstKnowledgeMainBoltDlg", "Frame003.SearchResultsML.ColumnTitle6");
 _SearchResultsML -> SetColumnTitles(13, m_lstStrPropertyName);
 _SearchResultsML -> SetVisibleColumnCount( 13 );
_SearchResultsML -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame004 = new CATDlgFrame(this, "Frame004", CATDlgFraNoFrame|CATDlgGridLayout);
_Frame004 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Frame004 -> SetGridColumnResizable(0,1);
 _NextStepPB = new CATDlgPushButton(_Frame004, "NextStepPB");
_NextStepPB -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _LastStepPB = new CATDlgPushButton(_Frame004, "LastStepPB");
_LastStepPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION

//设置参数
double Start, End, StepMM;
Start = 0.0;
End = 1e+6;
StepMM = 0.001;
//
_MinSpinner->SetMinMaxStep(Start, End, StepMM);
_MaxSpinner->SetMinMaxStep(Start, End, StepMM);
//
_MinSpinner->SetUnit(CATDlgControl::Millimeter);
_MaxSpinner->SetUnit(CATDlgControl::Millimeter);

//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

