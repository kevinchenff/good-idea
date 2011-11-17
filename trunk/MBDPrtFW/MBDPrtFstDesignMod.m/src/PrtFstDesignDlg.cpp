// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PrtFstDesignDlg.cpp
// The dialog : PrtFstDesignDlg
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: Code generated by the CAA wizard  xyuser
//===================================================================
#include "PrtFstDesignDlg.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef PrtFstDesignDlg_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif




//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
PrtFstDesignDlg::PrtFstDesignDlg() :
  CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),
//CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
"PrtFstDesignDlg",CATDlgGridLayout
//END CAA2 WIZARD CONSTRUCTOR DECLARATION SECTION
                               )
{
//CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
 _Frame001 = NULL;
 _PointsSL = NULL;
 _Frame002 = NULL;
 _Label008 = NULL;
 _Label009 = NULL;
 _FirstSurfSL = NULL;
 _SecondSurfSL = NULL;
 _DirectionPB = NULL;
 _Label014 = NULL;
 _Frame003 = NULL;
 _ChooseFstPB = NULL;
 _Frame004 = NULL;
 _SpecInfoEditor = NULL;
 _Frame015 = NULL;
 _ShowDetailInfoPB = NULL;
//END CAA2 WIZARD CONSTRUCTOR INITIALIZATION SECTION
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
PrtFstDesignDlg::~PrtFstDesignDlg()
{
//  Do not delete the control elements of your dialog: 
//     this is done automatically
//  --------------------------------------------------
//CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
 _Frame001 = NULL;
 _PointsSL = NULL;
 _Frame002 = NULL;
 _Label008 = NULL;
 _Label009 = NULL;
 _FirstSurfSL = NULL;
 _SecondSurfSL = NULL;
 _DirectionPB = NULL;
 _Label014 = NULL;
 _Frame003 = NULL;
 _ChooseFstPB = NULL;
 _Frame004 = NULL;
 _SpecInfoEditor = NULL;
 _Frame015 = NULL;
 _ShowDetailInfoPB = NULL;
//END CAA2 WIZARD DESTRUCTOR DECLARATION SECTION
}



void PrtFstDesignDlg::Build()
{
//  TODO: This call builds your dialog from the layout declaration file
//  -------------------------------------------------------------------

//CAA2 WIZARD WIDGET CONSTRUCTION SECTION
 SetGridRowResizable(0,1);
 SetGridRowResizable(3,1);
 SetGridColumnResizable(0,1);
 _Frame001 = new CATDlgFrame(this, "Frame001", CATDlgGridLayout);
_Frame001 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame001 -> SetGridRowResizable(0,1);
 _Frame001 -> SetGridColumnResizable(0,1);
 _PointsSL = new CATDlgSelectorList(_Frame001, "PointsSL");
 _PointsSL -> SetVisibleTextHeight(10);
 _PointsSL -> SetVisibleTextWidth(40);
_PointsSL -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 = new CATDlgFrame(this, "Frame002", CATDlgGridLayout);
_Frame002 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _Frame002 -> SetGridColumnResizable(1,1);
 _Label008 = new CATDlgLabel(_Frame002, "Label008");
_Label008 -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Label009 = new CATDlgLabel(_Frame002, "Label009");
_Label009 -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);
 _FirstSurfSL = new CATDlgSelectorList(_Frame002, "FirstSurfSL");
 _FirstSurfSL -> SetVisibleTextHeight(1);
_FirstSurfSL -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 _SecondSurfSL = new CATDlgSelectorList(_Frame002, "SecondSurfSL");
 _SecondSurfSL -> SetVisibleTextHeight(1);
_SecondSurfSL -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 _DirectionPB = new CATDlgPushButton(_Frame002, "DirectionPB");
_DirectionPB -> SetGridConstraints(2, 1, 1, 1, CATGRID_LEFT|CATGRID_TOP|CATGRID_BOTTOM);
 _Label014 = new CATDlgLabel(_Frame002, "Label014");
_Label014 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 = new CATDlgFrame(this, "Frame003", CATDlgGridLayout);
_Frame003 -> SetGridConstraints(2, 0, 1, 1, CATGRID_4SIDES);
 _Frame003 -> SetGridColumnResizable(0,1);
 _ChooseFstPB = new CATDlgPushButton(_Frame003, "ChooseFstPB");
_ChooseFstPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
 _Frame004 = new CATDlgFrame(this, "Frame004", CATDlgGridLayout);
_Frame004 -> SetGridConstraints(3, 0, 1, 1, CATGRID_4SIDES);
 _Frame004 -> SetGridRowResizable(0,1);
 _Frame004 -> SetGridColumnResizable(0,1);
 _SpecInfoEditor = new CATDlgEditor(_Frame004, "SpecInfoEditor", CATDlgEdtMultiline);
_SpecInfoEditor -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);
 _Frame015 = new CATDlgFrame(this, "Frame015", CATDlgFraNoTitle|CATDlgGridLayout);
_Frame015 -> SetGridConstraints(4, 0, 1, 1, CATGRID_4SIDES);
 _ShowDetailInfoPB = new CATDlgPushButton(_Frame015, "ShowDetailInfoPB");
_ShowDetailInfoPB -> SetGridConstraints(0, 0, 1, 1, CATGRID_LEFT|CATGRID_TOP|CATGRID_BOTTOM);
//END CAA2 WIZARD WIDGET CONSTRUCTION SECTION
_FirstSurfSL->SetLine("未选择面");
_SecondSurfSL->SetLine("未选择面");
_PointsSL->SetLine("未选择点");


//CAA2 WIZARD CALLBACK DECLARATION SECTION
//END CAA2 WIZARD CALLBACK DECLARATION SECTION

}

