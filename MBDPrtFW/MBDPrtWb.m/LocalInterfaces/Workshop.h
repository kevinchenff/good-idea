/************************************************************************/
/* 统一命名说明*/
//创建的类实例，全部以p开头;名称为类实例名去掉字母p
//示例：NewAccess(CATCmdWorkbench,pMBDPrtWbWkb,MBDPrtWbWkb);
//
//Menu主菜单命名：创建的类实例，全部以p开头，名称后缀为"Mnu";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdContainer,pMBDPrtMnu,MBDPrtMnu); //Menu Title
//Menu子菜单命名：创建的类实例，全部以p开头，名称后缀为"Snu";名称为类实例名去掉字母p
//示例: NewAccess(CATCmdContainer,pMBDPrtSnu01,MBDPrtSnu01);
//Menu子菜单按钮命名：创建的类实例，全部以p开头，名称后缀为"SnuStr";名称为类实例名去掉字母p
//示例: NewAccess(CATCmdContainer,pMBDPrtSnuStr01,MBDPrtSnuStr01);
//
//Toolbar命名：创建的类实例，全部以p开头，名称后缀为"Tlb";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdContainer,pMBDPrtTlb01,MBDPrtTlb01);
//Toolbar按钮命名：创建的类实例，全部以p开头，名称后缀为"TlbStr";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdStarter,pMBDPrtTlb01Str01,MBDPrtTlb01Str01);
//
/************************************************************************/

//创建workbench子container
NewAccess(CATCmdWorkbench,pMBDPrtWbWkb,MBDPrtWbWkb);
SetWorkbenchPriority (pMBDPrtWbWkb, 25);

//*************************************************************************************
//  [12/17/2010 ev5adm]
//************************************************************************************
//创建工具条 紧固件信息处理
//************************************************************************************
//NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktTlb,MBDPrtWbFastenerTktTlb);
//SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbFastenerTktTlb);
//
//创建紧固件信息处理对应的toolbar command starter功能
//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr01,MBDPrtWbFastenerTktTlbStr01); // toolbar command 子按钮1: XXXX功能
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr01, "MBDPrtWbCmdHdr01");
//SetAccessChild(pMBDPrtWbFastenerTktTlb,pMBDPrtWbFastenerTktTlbStr01);

//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr02,MBDPrtWbFastenerTktTlbStr02); // toolbar command 子按钮2: XXXX功能
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr02, "MBDPrtWbCmdHdr02");
//SetAccessNext(pMBDPrtWbFastenerTktTlbStr01,pMBDPrtWbFastenerTktTlbStr02);
//  [12/17/2010 ev5adm]
//*************************************************************************************

//************************************************************************************
//创建工具条 CATIA MBD附注信息
//************************************************************************************
//NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktTlb,MBDPrtWbMBDAnnotateTktTlb);
//SetAccessNext(pMBDPrtWbFastenerTktTlb,pMBDPrtWbMBDAnnotateTktTlb);
//
////创建 导出MBD附注信息 toolbar command starter功能
//NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktTlbStr01,MBDPrtWbMBDAnnotateTktTlbStr01); // toolbar command 子按钮1: XXXX功能
//SetAccessCommand(pMBDPrtWbMBDAnnotateTktTlbStr01, "MBDPrtWbCmdHdr03");
//SetAccessChild(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDAnnotateTktTlbStr01);



//************************************************************************************
//创建工具条 添加材料信息
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktTlb,MBDPrtWbMBDMaterialTktTlb);
SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbMBDMaterialTktTlb);

//创建 添加材料信息 toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktTlbStr01,MBDPrtWbMBDMaterialTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbMBDMaterialTktTlbStr01, "MBDPrtWbCmdHdr04");
SetAccessChild(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbMBDMaterialTktTlbStr01);


// [11/6/2011 xyuser]
//************************************************************************************
//创建工具条 紧固件选用模块
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbFDADesignTktTlb,MBDPrtWbFDADesignTktTlb);
SetAccessNext(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbFDADesignTktTlb);

//创建 添加紧固件选用 toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktTlbStr01,MBDPrtWbFDADesignTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDADesignTktTlbStr01, "MBDPrtWbCmdHdr05");
SetAccessChild(pMBDPrtWbFDADesignTktTlb,pMBDPrtWbFDADesignTktTlbStr01);

NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktTlbStr02,MBDPrtWbFDADesignTktTlbStr02); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDADesignTktTlbStr02, "MBDPrtWbCmdHdr06");
SetAccessNext(pMBDPrtWbFDADesignTktTlbStr01,pMBDPrtWbFDADesignTktTlbStr02);


// [11/6/2011 xyuser]
//************************************************************************************
//创建工具条 紧固件变换模块
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbFDATransformTktTlb,MBDPrtWbFDATransformTktTlb);
SetAccessNext(pMBDPrtWbFDADesignTktTlb,pMBDPrtWbFDATransformTktTlb);

//创建 紧固件变换模块 toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr01,MBDPrtWbFDATransformTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr01, "MBDPrtWbCmdHdr07");
SetAccessChild(pMBDPrtWbFDATransformTktTlb,pMBDPrtWbFDATransformTktTlbStr01);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr02,MBDPrtWbFDATransformTktTlbStr02); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr02, "MBDPrtWbCmdHdr08");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr01,pMBDPrtWbFDATransformTktTlbStr02);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr03,MBDPrtWbFDATransformTktTlbStr03); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr03, "MBDPrtWbCmdHdr09");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr02,pMBDPrtWbFDATransformTktTlbStr03);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr04,MBDPrtWbFDATransformTktTlbStr04); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr04, "MBDPrtWbCmdHdr10");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr03,pMBDPrtWbFDATransformTktTlbStr04);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr05,MBDPrtWbFDATransformTktTlbStr05); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr05, "MBDPrtWbCmdHdr11");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr04,pMBDPrtWbFDATransformTktTlbStr05);



//放置工具条位置
//AddToolbarView(pMBDPrtWbFastenerTktTlb,1,Right);
//AddToolbarView(pMBDPrtWbMBDAnnotateTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDMaterialTktTlb,1,Right);

AddToolbarView(pMBDPrtWbFDADesignTktTlb,1,Right);
AddToolbarView(pMBDPrtWbFDATransformTktTlb,1,Right);

//************************************************************************************
//创建menus
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbTktMbr,MBDPrtWbTktMbr); // 主空menu ,No Source files
//===============================================================
//获取CATIA Insert自带功能按钮菜单
//===============================================================
NewAccess(CATCmdContainer,pCATAfrInsertMnu,CATAfrInsertMnu);
SetAccessChild(pMBDPrtWbTktMbr,pCATAfrInsertMnu);


//=======================================================================
//主菜单工具箱1
//=======================================================================
NewAccess(CATCmdContainer,pMBDPrtWbTktMnu,MBDPrtWbTktMnu); //Menu Title
SetAccessNext(pCATAfrInsertMnu,pMBDPrtWbTktMnu);  // 主菜单工具箱1

	//创建二级子菜单: 紧固件信息处理
	//NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktMbr,MBDPrtWbFastenerTktMbr); 
	//SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbFastenerTktMbr); // 二级菜单1:紧固件信息处理

	////创建对应的MenuBar command starter功能 紧固件信息导出
	//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr01,MBDPrtWbFastenerTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	//SetAccessCommand(pMBDPrtWbFastenerTktMbrStr01, "MBDPrtWbCmdHdr01");
	//SetAccessChild(pMBDPrtWbFastenerTktMbr,pMBDPrtWbFastenerTktMbrStr01);

	//创建二级子菜单: CATIA MBD 附注信息
	//NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktMbr,MBDPrtWbMBDAnnotateTktMbr); 
	//SetAccessNext(pMBDPrtWbFastenerTktMbr,pMBDPrtWbMBDAnnotateTktMbr); // 二级菜单2:CATIA MBD 附注信息

	////创建对应的MenuBar command starter功能 导出MBD附注信息
	//NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktMbrStr01,MBDPrtWbMBDAnnotateTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	//SetAccessCommand(pMBDPrtWbMBDAnnotateTktMbrStr01, "MBDPrtWbCmdHdr03");
	//SetAccessChild(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDAnnotateTktMbrStr01);

	//创建二级子菜单: 添加材料信息
	NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktMbr,MBDPrtWbMBDMaterialTktMbr); 
	SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbMBDMaterialTktMbr); // 二级菜单3: 添加材料信息

	//创建对应的MenuBar command starter功能 添加材料信息
	NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktMbrStr01,MBDPrtWbMBDMaterialTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbMBDMaterialTktMbrStr01, "MBDPrtWbCmdHdr04");
	SetAccessChild(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbMBDMaterialTktMbrStr01);

	//创建二级子菜单: 紧固件选用
	NewAccess(CATCmdContainer,pMBDPrtWbFDADesignTktMbr,MBDPrtWbFDADesignTktMbr); 
	SetAccessNext(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbFDADesignTktMbr); // 二级菜单4: 紧固件选用

	//创建对应的MenuBar command starter功能 添加材料信息
	NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktMbrStr01,MBDPrtWbFDADesignTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDADesignTktMbrStr01, "MBDPrtWbCmdHdr05");
	SetAccessChild(pMBDPrtWbFDADesignTktMbr,pMBDPrtWbFDADesignTktMbrStr01);

	NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktMbrStr02,MBDPrtWbFDADesignTktMbrStr02); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDADesignTktMbrStr02, "MBDPrtWbCmdHdr06");
	SetAccessNext(pMBDPrtWbFDADesignTktMbrStr01,pMBDPrtWbFDADesignTktMbrStr02);

	//创建二级子菜单: 紧固件变换
	NewAccess(CATCmdContainer,pMBDPrtWbFDATransformTktMbr,MBDPrtWbFDATransformTktMbr); 
	SetAccessNext(pMBDPrtWbFDADesignTktMbr,pMBDPrtWbFDATransformTktMbr); // 二级菜单5: 紧固件变换

	//创建对应的MenuBar command starter功能 添加材料信息
	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr01,MBDPrtWbFDATransformTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr01, "MBDPrtWbCmdHdr07");
	SetAccessChild(pMBDPrtWbFDATransformTktMbr,pMBDPrtWbFDATransformTktMbrStr01);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr02,MBDPrtWbFDATransformTktMbrStr02); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr02, "MBDPrtWbCmdHdr08");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr01,pMBDPrtWbFDATransformTktMbrStr02);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr03,MBDPrtWbFDATransformTktMbrStr03); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr03, "MBDPrtWbCmdHdr09");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr02,pMBDPrtWbFDATransformTktMbrStr03);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr04,MBDPrtWbFDATransformTktMbrStr04); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr04, "MBDPrtWbCmdHdr10");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr03,pMBDPrtWbFDATransformTktMbrStr04);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr05,MBDPrtWbFDATransformTktMbrStr05); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr05, "MBDPrtWbCmdHdr11");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr04,pMBDPrtWbFDATransformTktMbrStr05);


// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrtWbWkb,pMBDPrtWbTktMbr);


return pMBDPrtWbWkb;