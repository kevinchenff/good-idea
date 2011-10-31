/************************************************************************/
/* 统一命名说明*/
//创建的类实例，全部以p开头;名称为类实例名去掉字母p
//示例：NewAccess(CATCmdWorkbench,pMBDPrdWbWkb,MBDPrdWbWkb);
//
//Menu主菜单命名：创建的类实例，全部以p开头，名称后缀为"Mnu";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdContainer,pMBDPrdMnu,MBDPrdMnu); //Menu Title
//Menu子菜单命名：创建的类实例，全部以p开头，名称后缀为"Snu";名称为类实例名去掉字母p
//示例: NewAccess(CATCmdContainer,pMBDPrdSnu01,MBDPrdSnu01);
//Menu子菜单按钮命名：创建的类实例，全部以p开头，名称后缀为"SnuStr";名称为类实例名去掉字母p
//示例: NewAccess(CATCmdContainer,pMBDPrdSnuStr01,MBDPrdSnuStr01);
//
//Toolbar命名：创建的类实例，全部以p开头，名称后缀为"Tlb";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdContainer,pMBDPrdTlb01,MBDPrdTlb01);
//Toolbar按钮命名：创建的类实例，全部以p开头，名称后缀为"TlbStr";名称为类实例名去掉字母p
//示例：NewAccess(CATCmdStarter,pMBDPrdTlb01Str01,MBDPrdTlb01Str01);
//
/************************************************************************/

//创建workbench子container
NewAccess(CATCmdWorkbench,pMBDPrdWbWkb,MBDPrdWbWkb);
SetWorkbenchPriority (pMBDPrdWbWkb, 25);


//************************************************************************************
//创建工具条
//************************************************************************************
	//ADE: Aircraft Design Environment Toolkit toolbar
	NewAccess(CATCmdContainer,pMBDPrdWbADETktTlb,MBDPrdWbADETktTlb);
	SetAccessChild(pMBDPrdWbWkb,pMBDPrdWbADETktTlb);
		//创建ADE对应的toolbar command starter功能
		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr01,MBDPrdWbADETktTlbStr01); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktTlbStr01, "MBDPrdWbADEHdr01");
		SetAccessChild(pMBDPrdWbADETktTlb,pMBDPrdWbADETktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr02,MBDPrdWbADETktTlbStr02); // toolbar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktTlbStr02, "MBDPrdWbADEHdr02");
		SetAccessNext(pMBDPrdWbADETktTlbStr01,pMBDPrdWbADETktTlbStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr03,MBDPrdWbADETktTlbStr03); // toolbar command 子按钮3: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktTlbStr03, "MBDPrdWbADEHdr03");
		SetAccessNext(pMBDPrdWbADETktTlbStr02,pMBDPrdWbADETktTlbStr03);


		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr04,MBDPrdWbADETktTlbStr04); // toolbar command 子按钮4: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktTlbStr04, "MBDPrdWbADEHdr04");
		SetAccessNext(pMBDPrdWbADETktTlbStr03,pMBDPrdWbADETktTlbStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr05,MBDPrdWbADETktTlbStr05); // toolbar command 子按钮5: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktTlbStr05, "MBDPrdWbADEHdr05");
		SetAccessNext(pMBDPrdWbADETktTlbStr04,pMBDPrdWbADETktTlbStr05);


	//AME: Aircraft Manufacture Environment Toolkit	toolbar
	NewAccess(CATCmdContainer,pMBDPrdWbAMETktTlb,MBDPrdWbAMETktTlb);
	SetAccessNext(pMBDPrdWbADETktTlb,pMBDPrdWbAMETktTlb);
		//创建AME对应的toolbar command starter功能
		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr01,MBDPrdWbAMETktTlbStr01); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktTlbStr01, "MBDPrdWbAMEHdr01");
		SetAccessChild(pMBDPrdWbAMETktTlb,pMBDPrdWbAMETktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr02,MBDPrdWbAMETktTlbStr02); // toolbar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktTlbStr02, "MBDPrdWbAMEHdr02");
		SetAccessNext(pMBDPrdWbAMETktTlbStr01,pMBDPrdWbAMETktTlbStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr03,MBDPrdWbAMETktTlbStr03); // toolbar command 子按钮3: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktTlbStr03, "MBDPrdWbAMEHdr03");
		SetAccessNext(pMBDPrdWbAMETktTlbStr02,pMBDPrdWbAMETktTlbStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr04,MBDPrdWbAMETktTlbStr04); // toolbar command 子按钮4: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktTlbStr04, "MBDPrdWbAMEHdr04");
		SetAccessNext(pMBDPrdWbAMETktTlbStr03,pMBDPrdWbAMETktTlbStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr05,MBDPrdWbAMETktTlbStr05); // toolbar command 子按钮5: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktTlbStr05, "MBDPrdWbAMEHdr05");
		SetAccessNext(pMBDPrdWbAMETktTlbStr04,pMBDPrdWbAMETktTlbStr05);

	//技术条件功能:添加技术条件信息，校核技术条件信息
	NewAccess(CATCmdContainer,pMBDPrdWbTechTktTlb,MBDPrdWbTechTktTlb);
	SetAccessNext(pMBDPrdWbAMETktTlb,pMBDPrdWbTechTktTlb);
		//创建technic 功能toolbar内容
		NewAccess(CATCmdStarter,pMBDPrdWbTechTktTlbStr01,MBDPrdWbTechTktTlbStr01); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbTechTktTlbStr01, "MBDPrdWbAddTechHdr");
		SetAccessChild(pMBDPrdWbTechTktTlb,pMBDPrdWbTechTktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbTechTktTlbStr02,MBDPrdWbTechTktTlbStr02); // toolbar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbTechTktTlbStr02, "MBDPrdWbCheckTechHdr");
		SetAccessNext(pMBDPrdWbTechTktTlbStr01,pMBDPrdWbTechTktTlbStr02);

	// 模型规范性检验 MBDPrdWbDataVerifyHdr
	NewAccess(CATCmdContainer,pMBDPrdWbDataVerifyTktTlb,MBDPrdWbDataVerifyTktTlb);
	SetAccessNext(pMBDPrdWbTechTktTlb,pMBDPrdWbDataVerifyTktTlb);
		//创建technic 功能toolbar内容
		NewAccess(CATCmdStarter,pMBDPrdWbDataVerifyTlbStr,MBDPrdWbDataVerifyTlbStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbDataVerifyTlbStr, "MBDPrdWbDataVerifyHdr");
		SetAccessChild(pMBDPrdWbDataVerifyTktTlb,pMBDPrdWbDataVerifyTlbStr);


	//////////////////////////////////////////////////////////////////////////
	// 创建工具条 MBD模型差异对比
	NewAccess(CATCmdContainer,pMBDPrdWbPartsCompareTktTlb,MBDPrdWbPartsCompareTktTlb);
	SetAccessNext(pMBDPrdWbTechTktTlb,pMBDPrdWbPartsCompareTktTlb);
		//创建LOAD PARTS FROM VPM
		NewAccess(CATCmdStarter,pMBDPrdWbLoadPrtVPMTlbStr,MBDPrdWbLoadPrtVPMTlbStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbLoadPrtVPMTlbStr, "MBDPrdLoadPrtVPMHdr");
		SetAccessChild(pMBDPrdWbPartsCompareTktTlb,pMBDPrdWbLoadPrtVPMTlbStr);

		//创建PARTS COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbPartsCompareTlbStr,MBDPrdWbPartsCompareTlbStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbPartsCompareTlbStr, "MBDPrdPartsCompareHdr");
		SetAccessNext(pMBDPrdWbLoadPrtVPMTlbStr,pMBDPrdWbPartsCompareTlbStr);

		//引用PARTS Geometry COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbGeomCompareTlbStr,MBDPrdWbGeomCompareTlbStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbGeomCompareTlbStr, "CATPartCompNHdr");
		SetAccessNext(pMBDPrdWbPartsCompareTlbStr,pMBDPrdWbGeomCompareTlbStr);


//放置工具条位置
AddToolbarView(pMBDPrdWbADETktTlb,1,Right);
AddToolbarView(pMBDPrdWbAMETktTlb,1,Right);
AddToolbarView(pMBDPrdWbTechTktTlb,1,Right);
AddToolbarView(pMBDPrdWbDataVerifyTktTlb,1,Right);
AddToolbarView(pMBDPrdWbPartsCompareTktTlb,1,Right);


//*********************************************************************************************************************************
//*********************************************************************************************************************************
//创建menus
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrdWbTktMbr,MBDPrdWbTktMbr); // 主空menu ,No Source files
//===============================================================
//获取CATIA Insert自带功能按钮菜单
//===============================================================
NewAccess(CATCmdContainer,pCATAfrInsertMnu,CATAfrInsertMnu);
SetAccessChild(pMBDPrdWbTktMbr,pCATAfrInsertMnu);
//===============================================================
//主菜单名称
//===============================================================
NewAccess(CATCmdContainer,pMBDPrdWbTktMnu,MBDPrdWbTktMnu); //Menu Title
SetAccessNext(pCATAfrInsertMnu,pMBDPrdWbTktMnu);  // 主菜单名称
	
	//创建二级子菜单ADE
	NewAccess(CATCmdContainer,pMBDPrdWbADETktMbr,MBDPrdWbADETktMbr); 
	SetAccessChild(pMBDPrdWbTktMnu,pMBDPrdWbADETktMbr); // 二级菜单1:ADE

		//创建ADE对应的MenuBar command starter功能
		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr01,MBDPrdWbADETktMbrStr01); // MenuBar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktMbrStr01, "MBDPrdWbADEHdr01");
		SetAccessChild(pMBDPrdWbADETktMbr,pMBDPrdWbADETktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr02,MBDPrdWbADETktMbrStr02); // MenuBar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktMbrStr02, "MBDPrdWbADEHdr02");
		SetAccessNext(pMBDPrdWbADETktMbrStr01,pMBDPrdWbADETktMbrStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr03,MBDPrdWbADETktMbrStr03); // MenuBar command 子按钮3: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktMbrStr03, "MBDPrdWbADEHdr03");
		SetAccessNext(pMBDPrdWbADETktMbrStr02,pMBDPrdWbADETktMbrStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr04,MBDPrdWbADETktMbrStr04); // MenuBar command 子按钮4: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktMbrStr04, "MBDPrdWbADEHdr04");
		SetAccessNext(pMBDPrdWbADETktMbrStr03,pMBDPrdWbADETktMbrStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr05,MBDPrdWbADETktMbrStr05); // MenuBar command 子按钮5: XXXX功能
		SetAccessCommand(pMBDPrdWbADETktMbrStr05, "MBDPrdWbADEHdr05");
		SetAccessNext(pMBDPrdWbADETktMbrStr04,pMBDPrdWbADETktMbrStr05);	

	
	
	//创建子菜单AME
	NewAccess(CATCmdContainer,pMBDPrdWbAMETktMbr,MBDPrdWbAMETktMbr); 
	SetAccessNext(pMBDPrdWbADETktMbr,pMBDPrdWbAMETktMbr); // 二级菜单2:AME

		//创建ADE对应的MenuBar command starter功能
		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr01,MBDPrdWbAMETktMbrStr01); // MenuBar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktMbrStr01, "MBDPrdWbAMEHdr01");
		SetAccessChild(pMBDPrdWbAMETktMbr,pMBDPrdWbAMETktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr02,MBDPrdWbAMETktMbrStr02); // MenuBar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktMbrStr02, "MBDPrdWbAMEHdr02");
		SetAccessNext(pMBDPrdWbAMETktMbrStr01,pMBDPrdWbAMETktMbrStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr03,MBDPrdWbAMETktMbrStr03); // MenuBar command 子按钮3: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktMbrStr03, "MBDPrdWbAMEHdr03");
		SetAccessNext(pMBDPrdWbAMETktMbrStr02,pMBDPrdWbAMETktMbrStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr04,MBDPrdWbAMETktMbrStr04); // MenuBar command 子按钮4: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktMbrStr04, "MBDPrdWbAMEHdr04");
		SetAccessNext(pMBDPrdWbAMETktMbrStr03,pMBDPrdWbAMETktMbrStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr05,MBDPrdWbAMETktMbrStr05); // MenuBar command 子按钮5: XXXX功能
		SetAccessCommand(pMBDPrdWbAMETktMbrStr05, "MBDPrdWbAMEHdr05");
		SetAccessNext(pMBDPrdWbAMETktMbrStr04,pMBDPrdWbAMETktMbrStr05);	


	//创建子菜单TECHNIC TOOLKIT
	NewAccess(CATCmdContainer,pMBDPrdWbTechTktMbr,MBDPrdWbTechTktMbr); 
	SetAccessNext(pMBDPrdWbAMETktMbr,pMBDPrdWbTechTktMbr); // 二级菜单3:TECHNIC TOOLKIT

		//创建TECHNIC TOOLKIT对应的MenuBar command starter功能
		NewAccess(CATCmdStarter,pMBDPrdWbTechTktMbrStr01,MBDPrdWbTechTktMbrStr01); // MenuBar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbTechTktMbrStr01, "MBDPrdWbAddTechHdr");
		SetAccessChild(pMBDPrdWbTechTktMbr,pMBDPrdWbTechTktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbTechTktMbrStr02,MBDPrdWbTechTktMbrStr02); // MenuBar command 子按钮2: XXXX功能
		SetAccessCommand(pMBDPrdWbTechTktMbrStr02, "MBDPrdWbCheckTechHdr");
		SetAccessNext(pMBDPrdWbTechTktMbrStr01,pMBDPrdWbTechTktMbrStr02);


	// 创建子菜单 模型规范性检验
	NewAccess(CATCmdContainer,pMBDPrdWbDataVerifyTktMbr,MBDPrdWbDataVerifyTktMbr);
	SetAccessNext(pMBDPrdWbTechTktMbr,pMBDPrdWbDataVerifyTktMbr);
		//创建模型规范性检验
		NewAccess(CATCmdStarter,pMBDPrdWbDataVerifyMbrStr,MBDPrdWbDataVerifyMbrStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbDataVerifyMbrStr, "MBDPrdWbDataVerifyHdr");
		SetAccessChild(pMBDPrdWbDataVerifyTktMbr,pMBDPrdWbDataVerifyMbrStr);

//////////////////////////////////////////////////////////////////////////
// 创建子菜单 MBD模型差异对比
	NewAccess(CATCmdContainer,pMBDPrdWbPartsCompareTktMbr,MBDPrdWbPartsCompareTktMbr);
	SetAccessNext(pMBDPrdWbTechTktMbr,pMBDPrdWbPartsCompareTktMbr);
		//创建LOAD PARTS FROM VPM
		NewAccess(CATCmdStarter,pMBDPrdWbLoadPrtVPMMbrStr,MBDPrdWbLoadPrtVPMMbrStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbLoadPrtVPMMbrStr, "MBDPrdLoadPrtVPMHdr");
		SetAccessChild(pMBDPrdWbPartsCompareTktMbr,pMBDPrdWbLoadPrtVPMMbrStr);

        //创建PARTS COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbPartsCompareMbrStr,MBDPrdWbPartsCompareMbrStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbPartsCompareMbrStr, "MBDPrdPartsCompareHdr");
		SetAccessNext(pMBDPrdWbLoadPrtVPMMbrStr,pMBDPrdWbPartsCompareMbrStr);

		//引用PARTS Geometry COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbGeomCompareMbrStr,MBDPrdWbGeomCompareMbrStr); // toolbar command 子按钮1: XXXX功能
		SetAccessCommand(pMBDPrdWbGeomCompareMbrStr, "CATPartCompNHdr");
		SetAccessNext(pMBDPrdWbPartsCompareMbrStr,pMBDPrdWbGeomCompareMbrStr);

// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrdWbWkb,pMBDPrdWbTktMbr);

return pMBDPrdWbWkb;