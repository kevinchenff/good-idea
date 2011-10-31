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
NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktTlb,MBDPrtWbFastenerTktTlb);
SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbFastenerTktTlb);

//创建紧固件信息处理对应的toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr01,MBDPrtWbFastenerTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbFastenerTktTlbStr01, "MBDPrtWbCmdHdr01");
SetAccessChild(pMBDPrtWbFastenerTktTlb,pMBDPrtWbFastenerTktTlbStr01);

//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr02,MBDPrtWbFastenerTktTlbStr02); // toolbar command 子按钮2: XXXX功能
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr02, "MBDPrtWbCmdHdr02");
//SetAccessNext(pMBDPrtWbFastenerTktTlbStr01,pMBDPrtWbFastenerTktTlbStr02);
//  [12/17/2010 ev5adm]
//*************************************************************************************

//************************************************************************************
//创建工具条 CATIA MBD附注信息
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktTlb,MBDPrtWbMBDAnnotateTktTlb);
SetAccessNext(pMBDPrtWbFastenerTktTlb,pMBDPrtWbMBDAnnotateTktTlb);

//创建 导出MBD附注信息 toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktTlbStr01,MBDPrtWbMBDAnnotateTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbMBDAnnotateTktTlbStr01, "MBDPrtWbCmdHdr03");
SetAccessChild(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDAnnotateTktTlbStr01);



//************************************************************************************
//创建工具条 添加材料信息
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktTlb,MBDPrtWbMBDMaterialTktTlb);
SetAccessNext(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDMaterialTktTlb);

//创建 添加材料信息 toolbar command starter功能
NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktTlbStr01,MBDPrtWbMBDMaterialTktTlbStr01); // toolbar command 子按钮1: XXXX功能
SetAccessCommand(pMBDPrtWbMBDMaterialTktTlbStr01, "MBDPrtWbCmdHdr04");
SetAccessChild(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbMBDMaterialTktTlbStr01);


//放置工具条位置
AddToolbarView(pMBDPrtWbFastenerTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDAnnotateTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDMaterialTktTlb,1,Right);


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
	NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktMbr,MBDPrtWbFastenerTktMbr); 
	SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbFastenerTktMbr); // 二级菜单1:紧固件信息处理

	//创建对应的MenuBar command starter功能 紧固件信息导出
	NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr01,MBDPrtWbFastenerTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbFastenerTktMbrStr01, "MBDPrtWbCmdHdr01");
	SetAccessChild(pMBDPrtWbFastenerTktMbr,pMBDPrtWbFastenerTktMbrStr01);

	//创建对应的MenuBar command starter功能 紧固件信息导入
	//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr02,MBDPrtWbFastenerTktMbrStr02); // MenuBar command 子按钮1: XXXX功能
	//SetAccessCommand(pMBDPrtWbFastenerTktMbrStr02, "MBDPrtWbCmdHdr02");
	//SetAccessNext(pMBDPrtWbFastenerTktMbrStr01,pMBDPrtWbFastenerTktMbrStr02);


	//创建二级子菜单: CATIA MBD 附注信息
	NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktMbr,MBDPrtWbMBDAnnotateTktMbr); 
	SetAccessNext(pMBDPrtWbFastenerTktMbr,pMBDPrtWbMBDAnnotateTktMbr); // 二级菜单2:CATIA MBD 附注信息

	//创建对应的MenuBar command starter功能 导出MBD附注信息
	NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktMbrStr01,MBDPrtWbMBDAnnotateTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbMBDAnnotateTktMbrStr01, "MBDPrtWbCmdHdr03");
	SetAccessChild(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDAnnotateTktMbrStr01);

	//创建二级子菜单: 添加材料信息
	NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktMbr,MBDPrtWbMBDMaterialTktMbr); 
	SetAccessNext(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDMaterialTktMbr); // 二级菜单3: 添加材料信息

	//创建对应的MenuBar command starter功能 添加材料信息
	NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktMbrStr01,MBDPrtWbMBDMaterialTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
	SetAccessCommand(pMBDPrtWbMBDMaterialTktMbrStr01, "MBDPrtWbCmdHdr04");
	SetAccessChild(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbMBDMaterialTktMbrStr01);



// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrtWbWkb,pMBDPrtWbTktMbr);


return pMBDPrtWbWkb;