/************************************************************************/
/* ͳһ����˵��*/
//��������ʵ����ȫ����p��ͷ;����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdWorkbench,pMBDPrtWbWkb,MBDPrtWbWkb);
//
//Menu���˵���������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Mnu";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdContainer,pMBDPrtMnu,MBDPrtMnu); //Menu Title
//Menu�Ӳ˵���������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Snu";����Ϊ��ʵ����ȥ����ĸp
//ʾ��: NewAccess(CATCmdContainer,pMBDPrtSnu01,MBDPrtSnu01);
//Menu�Ӳ˵���ť��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"SnuStr";����Ϊ��ʵ����ȥ����ĸp
//ʾ��: NewAccess(CATCmdContainer,pMBDPrtSnuStr01,MBDPrtSnuStr01);
//
//Toolbar��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"Tlb";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdContainer,pMBDPrtTlb01,MBDPrtTlb01);
//Toolbar��ť��������������ʵ����ȫ����p��ͷ�����ƺ�׺Ϊ"TlbStr";����Ϊ��ʵ����ȥ����ĸp
//ʾ����NewAccess(CATCmdStarter,pMBDPrtTlb01Str01,MBDPrtTlb01Str01);
//
/************************************************************************/

//����workbench��container
NewAccess(CATCmdWorkbench,pMBDPrtWbWkb,MBDPrtWbWkb);
SetWorkbenchPriority (pMBDPrtWbWkb, 25);

//*************************************************************************************
//  [12/17/2010 ev5adm]
//************************************************************************************
//���������� ���̼���Ϣ����
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktTlb,MBDPrtWbFastenerTktTlb);
SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbFastenerTktTlb);

//�������̼���Ϣ�����Ӧ��toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr01,MBDPrtWbFastenerTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFastenerTktTlbStr01, "MBDPrtWbCmdHdr01");
SetAccessChild(pMBDPrtWbFastenerTktTlb,pMBDPrtWbFastenerTktTlbStr01);

//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr02,MBDPrtWbFastenerTktTlbStr02); // toolbar command �Ӱ�ť2: XXXX����
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr02, "MBDPrtWbCmdHdr02");
//SetAccessNext(pMBDPrtWbFastenerTktTlbStr01,pMBDPrtWbFastenerTktTlbStr02);
//  [12/17/2010 ev5adm]
//*************************************************************************************

//************************************************************************************
//���������� CATIA MBD��ע��Ϣ
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktTlb,MBDPrtWbMBDAnnotateTktTlb);
SetAccessNext(pMBDPrtWbFastenerTktTlb,pMBDPrtWbMBDAnnotateTktTlb);

//���� ����MBD��ע��Ϣ toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktTlbStr01,MBDPrtWbMBDAnnotateTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbMBDAnnotateTktTlbStr01, "MBDPrtWbCmdHdr03");
SetAccessChild(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDAnnotateTktTlbStr01);



//************************************************************************************
//���������� ��Ӳ�����Ϣ
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktTlb,MBDPrtWbMBDMaterialTktTlb);
SetAccessNext(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDMaterialTktTlb);

//���� ��Ӳ�����Ϣ toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktTlbStr01,MBDPrtWbMBDMaterialTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbMBDMaterialTktTlbStr01, "MBDPrtWbCmdHdr04");
SetAccessChild(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbMBDMaterialTktTlbStr01);


//���ù�����λ��
AddToolbarView(pMBDPrtWbFastenerTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDAnnotateTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDMaterialTktTlb,1,Right);


//************************************************************************************
//����menus
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbTktMbr,MBDPrtWbTktMbr); // ����menu ,No Source files
//===============================================================
//��ȡCATIA Insert�Դ����ܰ�ť�˵�
//===============================================================
NewAccess(CATCmdContainer,pCATAfrInsertMnu,CATAfrInsertMnu);
SetAccessChild(pMBDPrtWbTktMbr,pCATAfrInsertMnu);


//=======================================================================
//���˵�������1
//=======================================================================
NewAccess(CATCmdContainer,pMBDPrtWbTktMnu,MBDPrtWbTktMnu); //Menu Title
SetAccessNext(pCATAfrInsertMnu,pMBDPrtWbTktMnu);  // ���˵�������1

	//���������Ӳ˵�: ���̼���Ϣ����
	NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktMbr,MBDPrtWbFastenerTktMbr); 
	SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbFastenerTktMbr); // �����˵�1:���̼���Ϣ����

	//������Ӧ��MenuBar command starter���� ���̼���Ϣ����
	NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr01,MBDPrtWbFastenerTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFastenerTktMbrStr01, "MBDPrtWbCmdHdr01");
	SetAccessChild(pMBDPrtWbFastenerTktMbr,pMBDPrtWbFastenerTktMbrStr01);

	//������Ӧ��MenuBar command starter���� ���̼���Ϣ����
	//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr02,MBDPrtWbFastenerTktMbrStr02); // MenuBar command �Ӱ�ť1: XXXX����
	//SetAccessCommand(pMBDPrtWbFastenerTktMbrStr02, "MBDPrtWbCmdHdr02");
	//SetAccessNext(pMBDPrtWbFastenerTktMbrStr01,pMBDPrtWbFastenerTktMbrStr02);


	//���������Ӳ˵�: CATIA MBD ��ע��Ϣ
	NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktMbr,MBDPrtWbMBDAnnotateTktMbr); 
	SetAccessNext(pMBDPrtWbFastenerTktMbr,pMBDPrtWbMBDAnnotateTktMbr); // �����˵�2:CATIA MBD ��ע��Ϣ

	//������Ӧ��MenuBar command starter���� ����MBD��ע��Ϣ
	NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktMbrStr01,MBDPrtWbMBDAnnotateTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbMBDAnnotateTktMbrStr01, "MBDPrtWbCmdHdr03");
	SetAccessChild(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDAnnotateTktMbrStr01);

	//���������Ӳ˵�: ��Ӳ�����Ϣ
	NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktMbr,MBDPrtWbMBDMaterialTktMbr); 
	SetAccessNext(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDMaterialTktMbr); // �����˵�3: ��Ӳ�����Ϣ

	//������Ӧ��MenuBar command starter���� ��Ӳ�����Ϣ
	NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktMbrStr01,MBDPrtWbMBDMaterialTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbMBDMaterialTktMbrStr01, "MBDPrtWbCmdHdr04");
	SetAccessChild(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbMBDMaterialTktMbrStr01);



// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrtWbWkb,pMBDPrtWbTktMbr);


return pMBDPrtWbWkb;