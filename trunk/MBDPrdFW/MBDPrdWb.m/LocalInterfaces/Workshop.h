/************************************************************************/
/* ͳһ����˵��*/
//��������ʵ����ȫ����p��ͷ;����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdWorkbench,pMBDPrdWbWkb,MBDPrdWbWkb);
//
//Menu���˵���������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Mnu";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdContainer,pMBDPrdMnu,MBDPrdMnu); //Menu Title
//Menu�Ӳ˵���������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Snu";����Ϊ��ʵ����ȥ����ĸp
//ʾ��: NewAccess(CATCmdContainer,pMBDPrdSnu01,MBDPrdSnu01);
//Menu�Ӳ˵���ť��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"SnuStr";����Ϊ��ʵ����ȥ����ĸp
//ʾ��: NewAccess(CATCmdContainer,pMBDPrdSnuStr01,MBDPrdSnuStr01);
//
//Toolbar��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Tlb";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdContainer,pMBDPrdTlb01,MBDPrdTlb01);
//Toolbar��ť��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"TlbStr";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdStarter,pMBDPrdTlb01Str01,MBDPrdTlb01Str01);
//
/************************************************************************/

//����workbench��container
NewAccess(CATCmdWorkbench,pMBDPrdWbWkb,MBDPrdWbWkb);
SetWorkbenchPriority (pMBDPrdWbWkb, 25);


//************************************************************************************
//����������
//************************************************************************************
	//ADE: Aircraft Design Environment Toolkit toolbar
	NewAccess(CATCmdContainer,pMBDPrdWbADETktTlb,MBDPrdWbADETktTlb);
	SetAccessChild(pMBDPrdWbWkb,pMBDPrdWbADETktTlb);
		//����ADE��Ӧ��toolbar command starter����
		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr01,MBDPrdWbADETktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbADETktTlbStr01, "MBDPrdWbADEHdr01");
		SetAccessChild(pMBDPrdWbADETktTlb,pMBDPrdWbADETktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr02,MBDPrdWbADETktTlbStr02); // toolbar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbADETktTlbStr02, "MBDPrdWbADEHdr02");
		SetAccessNext(pMBDPrdWbADETktTlbStr01,pMBDPrdWbADETktTlbStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr03,MBDPrdWbADETktTlbStr03); // toolbar command �Ӱ�ť3: XXXX����
		SetAccessCommand(pMBDPrdWbADETktTlbStr03, "MBDPrdWbADEHdr03");
		SetAccessNext(pMBDPrdWbADETktTlbStr02,pMBDPrdWbADETktTlbStr03);


		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr04,MBDPrdWbADETktTlbStr04); // toolbar command �Ӱ�ť4: XXXX����
		SetAccessCommand(pMBDPrdWbADETktTlbStr04, "MBDPrdWbADEHdr04");
		SetAccessNext(pMBDPrdWbADETktTlbStr03,pMBDPrdWbADETktTlbStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktTlbStr05,MBDPrdWbADETktTlbStr05); // toolbar command �Ӱ�ť5: XXXX����
		SetAccessCommand(pMBDPrdWbADETktTlbStr05, "MBDPrdWbADEHdr05");
		SetAccessNext(pMBDPrdWbADETktTlbStr04,pMBDPrdWbADETktTlbStr05);


	//AME: Aircraft Manufacture Environment Toolkit	toolbar
	NewAccess(CATCmdContainer,pMBDPrdWbAMETktTlb,MBDPrdWbAMETktTlb);
	SetAccessNext(pMBDPrdWbADETktTlb,pMBDPrdWbAMETktTlb);
		//����AME��Ӧ��toolbar command starter����
		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr01,MBDPrdWbAMETktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktTlbStr01, "MBDPrdWbAMEHdr01");
		SetAccessChild(pMBDPrdWbAMETktTlb,pMBDPrdWbAMETktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr02,MBDPrdWbAMETktTlbStr02); // toolbar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktTlbStr02, "MBDPrdWbAMEHdr02");
		SetAccessNext(pMBDPrdWbAMETktTlbStr01,pMBDPrdWbAMETktTlbStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr03,MBDPrdWbAMETktTlbStr03); // toolbar command �Ӱ�ť3: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktTlbStr03, "MBDPrdWbAMEHdr03");
		SetAccessNext(pMBDPrdWbAMETktTlbStr02,pMBDPrdWbAMETktTlbStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr04,MBDPrdWbAMETktTlbStr04); // toolbar command �Ӱ�ť4: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktTlbStr04, "MBDPrdWbAMEHdr04");
		SetAccessNext(pMBDPrdWbAMETktTlbStr03,pMBDPrdWbAMETktTlbStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktTlbStr05,MBDPrdWbAMETktTlbStr05); // toolbar command �Ӱ�ť5: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktTlbStr05, "MBDPrdWbAMEHdr05");
		SetAccessNext(pMBDPrdWbAMETktTlbStr04,pMBDPrdWbAMETktTlbStr05);

	//������������:��Ӽ���������Ϣ��У�˼���������Ϣ
	NewAccess(CATCmdContainer,pMBDPrdWbTechTktTlb,MBDPrdWbTechTktTlb);
	SetAccessNext(pMBDPrdWbAMETktTlb,pMBDPrdWbTechTktTlb);
		//����technic ����toolbar����
		NewAccess(CATCmdStarter,pMBDPrdWbTechTktTlbStr01,MBDPrdWbTechTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbTechTktTlbStr01, "MBDPrdWbAddTechHdr");
		SetAccessChild(pMBDPrdWbTechTktTlb,pMBDPrdWbTechTktTlbStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbTechTktTlbStr02,MBDPrdWbTechTktTlbStr02); // toolbar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbTechTktTlbStr02, "MBDPrdWbCheckTechHdr");
		SetAccessNext(pMBDPrdWbTechTktTlbStr01,pMBDPrdWbTechTktTlbStr02);

	// ģ�͹淶�Լ��� MBDPrdWbDataVerifyHdr
	NewAccess(CATCmdContainer,pMBDPrdWbDataVerifyTktTlb,MBDPrdWbDataVerifyTktTlb);
	SetAccessNext(pMBDPrdWbTechTktTlb,pMBDPrdWbDataVerifyTktTlb);
		//����technic ����toolbar����
		NewAccess(CATCmdStarter,pMBDPrdWbDataVerifyTlbStr,MBDPrdWbDataVerifyTlbStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbDataVerifyTlbStr, "MBDPrdWbDataVerifyHdr");
		SetAccessChild(pMBDPrdWbDataVerifyTktTlb,pMBDPrdWbDataVerifyTlbStr);


	//////////////////////////////////////////////////////////////////////////
	// ���������� MBDģ�Ͳ���Ա�
	NewAccess(CATCmdContainer,pMBDPrdWbPartsCompareTktTlb,MBDPrdWbPartsCompareTktTlb);
	SetAccessNext(pMBDPrdWbTechTktTlb,pMBDPrdWbPartsCompareTktTlb);
		//����LOAD PARTS FROM VPM
		NewAccess(CATCmdStarter,pMBDPrdWbLoadPrtVPMTlbStr,MBDPrdWbLoadPrtVPMTlbStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbLoadPrtVPMTlbStr, "MBDPrdLoadPrtVPMHdr");
		SetAccessChild(pMBDPrdWbPartsCompareTktTlb,pMBDPrdWbLoadPrtVPMTlbStr);

		//����PARTS COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbPartsCompareTlbStr,MBDPrdWbPartsCompareTlbStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbPartsCompareTlbStr, "MBDPrdPartsCompareHdr");
		SetAccessNext(pMBDPrdWbLoadPrtVPMTlbStr,pMBDPrdWbPartsCompareTlbStr);

		//����PARTS Geometry COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbGeomCompareTlbStr,MBDPrdWbGeomCompareTlbStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbGeomCompareTlbStr, "CATPartCompNHdr");
		SetAccessNext(pMBDPrdWbPartsCompareTlbStr,pMBDPrdWbGeomCompareTlbStr);


//���ù�����λ��
AddToolbarView(pMBDPrdWbADETktTlb,1,Right);
AddToolbarView(pMBDPrdWbAMETktTlb,1,Right);
AddToolbarView(pMBDPrdWbTechTktTlb,1,Right);
AddToolbarView(pMBDPrdWbDataVerifyTktTlb,1,Right);
AddToolbarView(pMBDPrdWbPartsCompareTktTlb,1,Right);


//*********************************************************************************************************************************
//*********************************************************************************************************************************
//����menus
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrdWbTktMbr,MBDPrdWbTktMbr); // ����menu ,No Source files
//===============================================================
//��ȡCATIA Insert�Դ����ܰ�ť�˵�
//===============================================================
NewAccess(CATCmdContainer,pCATAfrInsertMnu,CATAfrInsertMnu);
SetAccessChild(pMBDPrdWbTktMbr,pCATAfrInsertMnu);
//===============================================================
//���˵�����
//===============================================================
NewAccess(CATCmdContainer,pMBDPrdWbTktMnu,MBDPrdWbTktMnu); //Menu Title
SetAccessNext(pCATAfrInsertMnu,pMBDPrdWbTktMnu);  // ���˵�����
	
	//���������Ӳ˵�ADE
	NewAccess(CATCmdContainer,pMBDPrdWbADETktMbr,MBDPrdWbADETktMbr); 
	SetAccessChild(pMBDPrdWbTktMnu,pMBDPrdWbADETktMbr); // �����˵�1:ADE

		//����ADE��Ӧ��MenuBar command starter����
		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr01,MBDPrdWbADETktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbADETktMbrStr01, "MBDPrdWbADEHdr01");
		SetAccessChild(pMBDPrdWbADETktMbr,pMBDPrdWbADETktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr02,MBDPrdWbADETktMbrStr02); // MenuBar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbADETktMbrStr02, "MBDPrdWbADEHdr02");
		SetAccessNext(pMBDPrdWbADETktMbrStr01,pMBDPrdWbADETktMbrStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr03,MBDPrdWbADETktMbrStr03); // MenuBar command �Ӱ�ť3: XXXX����
		SetAccessCommand(pMBDPrdWbADETktMbrStr03, "MBDPrdWbADEHdr03");
		SetAccessNext(pMBDPrdWbADETktMbrStr02,pMBDPrdWbADETktMbrStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr04,MBDPrdWbADETktMbrStr04); // MenuBar command �Ӱ�ť4: XXXX����
		SetAccessCommand(pMBDPrdWbADETktMbrStr04, "MBDPrdWbADEHdr04");
		SetAccessNext(pMBDPrdWbADETktMbrStr03,pMBDPrdWbADETktMbrStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbADETktMbrStr05,MBDPrdWbADETktMbrStr05); // MenuBar command �Ӱ�ť5: XXXX����
		SetAccessCommand(pMBDPrdWbADETktMbrStr05, "MBDPrdWbADEHdr05");
		SetAccessNext(pMBDPrdWbADETktMbrStr04,pMBDPrdWbADETktMbrStr05);	

	
	
	//�����Ӳ˵�AME
	NewAccess(CATCmdContainer,pMBDPrdWbAMETktMbr,MBDPrdWbAMETktMbr); 
	SetAccessNext(pMBDPrdWbADETktMbr,pMBDPrdWbAMETktMbr); // �����˵�2:AME

		//����ADE��Ӧ��MenuBar command starter����
		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr01,MBDPrdWbAMETktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktMbrStr01, "MBDPrdWbAMEHdr01");
		SetAccessChild(pMBDPrdWbAMETktMbr,pMBDPrdWbAMETktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr02,MBDPrdWbAMETktMbrStr02); // MenuBar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktMbrStr02, "MBDPrdWbAMEHdr02");
		SetAccessNext(pMBDPrdWbAMETktMbrStr01,pMBDPrdWbAMETktMbrStr02);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr03,MBDPrdWbAMETktMbrStr03); // MenuBar command �Ӱ�ť3: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktMbrStr03, "MBDPrdWbAMEHdr03");
		SetAccessNext(pMBDPrdWbAMETktMbrStr02,pMBDPrdWbAMETktMbrStr03);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr04,MBDPrdWbAMETktMbrStr04); // MenuBar command �Ӱ�ť4: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktMbrStr04, "MBDPrdWbAMEHdr04");
		SetAccessNext(pMBDPrdWbAMETktMbrStr03,pMBDPrdWbAMETktMbrStr04);

		NewAccess(CATCmdStarter,pMBDPrdWbAMETktMbrStr05,MBDPrdWbAMETktMbrStr05); // MenuBar command �Ӱ�ť5: XXXX����
		SetAccessCommand(pMBDPrdWbAMETktMbrStr05, "MBDPrdWbAMEHdr05");
		SetAccessNext(pMBDPrdWbAMETktMbrStr04,pMBDPrdWbAMETktMbrStr05);	


	//�����Ӳ˵�TECHNIC TOOLKIT
	NewAccess(CATCmdContainer,pMBDPrdWbTechTktMbr,MBDPrdWbTechTktMbr); 
	SetAccessNext(pMBDPrdWbAMETktMbr,pMBDPrdWbTechTktMbr); // �����˵�3:TECHNIC TOOLKIT

		//����TECHNIC TOOLKIT��Ӧ��MenuBar command starter����
		NewAccess(CATCmdStarter,pMBDPrdWbTechTktMbrStr01,MBDPrdWbTechTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbTechTktMbrStr01, "MBDPrdWbAddTechHdr");
		SetAccessChild(pMBDPrdWbTechTktMbr,pMBDPrdWbTechTktMbrStr01);

		NewAccess(CATCmdStarter,pMBDPrdWbTechTktMbrStr02,MBDPrdWbTechTktMbrStr02); // MenuBar command �Ӱ�ť2: XXXX����
		SetAccessCommand(pMBDPrdWbTechTktMbrStr02, "MBDPrdWbCheckTechHdr");
		SetAccessNext(pMBDPrdWbTechTktMbrStr01,pMBDPrdWbTechTktMbrStr02);


	// �����Ӳ˵� ģ�͹淶�Լ���
	NewAccess(CATCmdContainer,pMBDPrdWbDataVerifyTktMbr,MBDPrdWbDataVerifyTktMbr);
	SetAccessNext(pMBDPrdWbTechTktMbr,pMBDPrdWbDataVerifyTktMbr);
		//����ģ�͹淶�Լ���
		NewAccess(CATCmdStarter,pMBDPrdWbDataVerifyMbrStr,MBDPrdWbDataVerifyMbrStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbDataVerifyMbrStr, "MBDPrdWbDataVerifyHdr");
		SetAccessChild(pMBDPrdWbDataVerifyTktMbr,pMBDPrdWbDataVerifyMbrStr);

//////////////////////////////////////////////////////////////////////////
// �����Ӳ˵� MBDģ�Ͳ���Ա�
	NewAccess(CATCmdContainer,pMBDPrdWbPartsCompareTktMbr,MBDPrdWbPartsCompareTktMbr);
	SetAccessNext(pMBDPrdWbTechTktMbr,pMBDPrdWbPartsCompareTktMbr);
		//����LOAD PARTS FROM VPM
		NewAccess(CATCmdStarter,pMBDPrdWbLoadPrtVPMMbrStr,MBDPrdWbLoadPrtVPMMbrStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbLoadPrtVPMMbrStr, "MBDPrdLoadPrtVPMHdr");
		SetAccessChild(pMBDPrdWbPartsCompareTktMbr,pMBDPrdWbLoadPrtVPMMbrStr);

        //����PARTS COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbPartsCompareMbrStr,MBDPrdWbPartsCompareMbrStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbPartsCompareMbrStr, "MBDPrdPartsCompareHdr");
		SetAccessNext(pMBDPrdWbLoadPrtVPMMbrStr,pMBDPrdWbPartsCompareMbrStr);

		//����PARTS Geometry COMPARE
		NewAccess(CATCmdStarter,pMBDPrdWbGeomCompareMbrStr,MBDPrdWbGeomCompareMbrStr); // toolbar command �Ӱ�ť1: XXXX����
		SetAccessCommand(pMBDPrdWbGeomCompareMbrStr, "CATPartCompNHdr");
		SetAccessNext(pMBDPrdWbPartsCompareMbrStr,pMBDPrdWbGeomCompareMbrStr);

// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrdWbWkb,pMBDPrdWbTktMbr);

return pMBDPrdWbWkb;