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
//NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktTlb,MBDPrtWbFastenerTktTlb);
//SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbFastenerTktTlb);
//
//�������̼���Ϣ�����Ӧ��toolbar command starter����
//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr01,MBDPrtWbFastenerTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr01, "MBDPrtWbCmdHdr01");
//SetAccessChild(pMBDPrtWbFastenerTktTlb,pMBDPrtWbFastenerTktTlbStr01);

//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktTlbStr02,MBDPrtWbFastenerTktTlbStr02); // toolbar command �Ӱ�ť2: XXXX����
//SetAccessCommand(pMBDPrtWbFastenerTktTlbStr02, "MBDPrtWbCmdHdr02");
//SetAccessNext(pMBDPrtWbFastenerTktTlbStr01,pMBDPrtWbFastenerTktTlbStr02);
//  [12/17/2010 ev5adm]
//*************************************************************************************

//************************************************************************************
//���������� CATIA MBD��ע��Ϣ
//************************************************************************************
//NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktTlb,MBDPrtWbMBDAnnotateTktTlb);
//SetAccessNext(pMBDPrtWbFastenerTktTlb,pMBDPrtWbMBDAnnotateTktTlb);
//
////���� ����MBD��ע��Ϣ toolbar command starter����
//NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktTlbStr01,MBDPrtWbMBDAnnotateTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
//SetAccessCommand(pMBDPrtWbMBDAnnotateTktTlbStr01, "MBDPrtWbCmdHdr03");
//SetAccessChild(pMBDPrtWbMBDAnnotateTktTlb,pMBDPrtWbMBDAnnotateTktTlbStr01);



//************************************************************************************
//���������� ��Ӳ�����Ϣ
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktTlb,MBDPrtWbMBDMaterialTktTlb);
SetAccessChild(pMBDPrtWbWkb,pMBDPrtWbMBDMaterialTktTlb);

//���� ��Ӳ�����Ϣ toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktTlbStr01,MBDPrtWbMBDMaterialTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbMBDMaterialTktTlbStr01, "MBDPrtWbCmdHdr04");
SetAccessChild(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbMBDMaterialTktTlbStr01);


// [11/6/2011 xyuser]
//************************************************************************************
//���������� ���̼�ѡ��ģ��
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbFDADesignTktTlb,MBDPrtWbFDADesignTktTlb);
SetAccessNext(pMBDPrtWbMBDMaterialTktTlb,pMBDPrtWbFDADesignTktTlb);

//���� ��ӽ��̼�ѡ�� toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktTlbStr01,MBDPrtWbFDADesignTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDADesignTktTlbStr01, "MBDPrtWbCmdHdr05");
SetAccessChild(pMBDPrtWbFDADesignTktTlb,pMBDPrtWbFDADesignTktTlbStr01);

NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktTlbStr02,MBDPrtWbFDADesignTktTlbStr02); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDADesignTktTlbStr02, "MBDPrtWbCmdHdr06");
SetAccessNext(pMBDPrtWbFDADesignTktTlbStr01,pMBDPrtWbFDADesignTktTlbStr02);


// [11/6/2011 xyuser]
//************************************************************************************
//���������� ���̼��任ģ��
//************************************************************************************
NewAccess(CATCmdContainer,pMBDPrtWbFDATransformTktTlb,MBDPrtWbFDATransformTktTlb);
SetAccessNext(pMBDPrtWbFDADesignTktTlb,pMBDPrtWbFDATransformTktTlb);

//���� ���̼��任ģ�� toolbar command starter����
NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr01,MBDPrtWbFDATransformTktTlbStr01); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr01, "MBDPrtWbCmdHdr07");
SetAccessChild(pMBDPrtWbFDATransformTktTlb,pMBDPrtWbFDATransformTktTlbStr01);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr02,MBDPrtWbFDATransformTktTlbStr02); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr02, "MBDPrtWbCmdHdr08");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr01,pMBDPrtWbFDATransformTktTlbStr02);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr03,MBDPrtWbFDATransformTktTlbStr03); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr03, "MBDPrtWbCmdHdr09");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr02,pMBDPrtWbFDATransformTktTlbStr03);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr04,MBDPrtWbFDATransformTktTlbStr04); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr04, "MBDPrtWbCmdHdr10");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr03,pMBDPrtWbFDATransformTktTlbStr04);

NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktTlbStr05,MBDPrtWbFDATransformTktTlbStr05); // toolbar command �Ӱ�ť1: XXXX����
SetAccessCommand(pMBDPrtWbFDATransformTktTlbStr05, "MBDPrtWbCmdHdr11");
SetAccessNext(pMBDPrtWbFDATransformTktTlbStr04,pMBDPrtWbFDATransformTktTlbStr05);



//���ù�����λ��
//AddToolbarView(pMBDPrtWbFastenerTktTlb,1,Right);
//AddToolbarView(pMBDPrtWbMBDAnnotateTktTlb,1,Right);
AddToolbarView(pMBDPrtWbMBDMaterialTktTlb,1,Right);

AddToolbarView(pMBDPrtWbFDADesignTktTlb,1,Right);
AddToolbarView(pMBDPrtWbFDATransformTktTlb,1,Right);

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
	//NewAccess(CATCmdContainer,pMBDPrtWbFastenerTktMbr,MBDPrtWbFastenerTktMbr); 
	//SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbFastenerTktMbr); // �����˵�1:���̼���Ϣ����

	////������Ӧ��MenuBar command starter���� ���̼���Ϣ����
	//NewAccess(CATCmdStarter,pMBDPrtWbFastenerTktMbrStr01,MBDPrtWbFastenerTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	//SetAccessCommand(pMBDPrtWbFastenerTktMbrStr01, "MBDPrtWbCmdHdr01");
	//SetAccessChild(pMBDPrtWbFastenerTktMbr,pMBDPrtWbFastenerTktMbrStr01);

	//���������Ӳ˵�: CATIA MBD ��ע��Ϣ
	//NewAccess(CATCmdContainer,pMBDPrtWbMBDAnnotateTktMbr,MBDPrtWbMBDAnnotateTktMbr); 
	//SetAccessNext(pMBDPrtWbFastenerTktMbr,pMBDPrtWbMBDAnnotateTktMbr); // �����˵�2:CATIA MBD ��ע��Ϣ

	////������Ӧ��MenuBar command starter���� ����MBD��ע��Ϣ
	//NewAccess(CATCmdStarter,pMBDPrtWbMBDAnnotateTktMbrStr01,MBDPrtWbMBDAnnotateTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	//SetAccessCommand(pMBDPrtWbMBDAnnotateTktMbrStr01, "MBDPrtWbCmdHdr03");
	//SetAccessChild(pMBDPrtWbMBDAnnotateTktMbr,pMBDPrtWbMBDAnnotateTktMbrStr01);

	//���������Ӳ˵�: ��Ӳ�����Ϣ
	NewAccess(CATCmdContainer,pMBDPrtWbMBDMaterialTktMbr,MBDPrtWbMBDMaterialTktMbr); 
	SetAccessChild(pMBDPrtWbTktMnu,pMBDPrtWbMBDMaterialTktMbr); // �����˵�3: ��Ӳ�����Ϣ

	//������Ӧ��MenuBar command starter���� ��Ӳ�����Ϣ
	NewAccess(CATCmdStarter,pMBDPrtWbMBDMaterialTktMbrStr01,MBDPrtWbMBDMaterialTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbMBDMaterialTktMbrStr01, "MBDPrtWbCmdHdr04");
	SetAccessChild(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbMBDMaterialTktMbrStr01);

	//���������Ӳ˵�: ���̼�ѡ��
	NewAccess(CATCmdContainer,pMBDPrtWbFDADesignTktMbr,MBDPrtWbFDADesignTktMbr); 
	SetAccessNext(pMBDPrtWbMBDMaterialTktMbr,pMBDPrtWbFDADesignTktMbr); // �����˵�4: ���̼�ѡ��

	//������Ӧ��MenuBar command starter���� ��Ӳ�����Ϣ
	NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktMbrStr01,MBDPrtWbFDADesignTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDADesignTktMbrStr01, "MBDPrtWbCmdHdr05");
	SetAccessChild(pMBDPrtWbFDADesignTktMbr,pMBDPrtWbFDADesignTktMbrStr01);

	NewAccess(CATCmdStarter,pMBDPrtWbFDADesignTktMbrStr02,MBDPrtWbFDADesignTktMbrStr02); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDADesignTktMbrStr02, "MBDPrtWbCmdHdr06");
	SetAccessNext(pMBDPrtWbFDADesignTktMbrStr01,pMBDPrtWbFDADesignTktMbrStr02);

	//���������Ӳ˵�: ���̼��任
	NewAccess(CATCmdContainer,pMBDPrtWbFDATransformTktMbr,MBDPrtWbFDATransformTktMbr); 
	SetAccessNext(pMBDPrtWbFDADesignTktMbr,pMBDPrtWbFDATransformTktMbr); // �����˵�5: ���̼��任

	//������Ӧ��MenuBar command starter���� ��Ӳ�����Ϣ
	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr01,MBDPrtWbFDATransformTktMbrStr01); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr01, "MBDPrtWbCmdHdr07");
	SetAccessChild(pMBDPrtWbFDATransformTktMbr,pMBDPrtWbFDATransformTktMbrStr01);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr02,MBDPrtWbFDATransformTktMbrStr02); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr02, "MBDPrtWbCmdHdr08");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr01,pMBDPrtWbFDATransformTktMbrStr02);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr03,MBDPrtWbFDATransformTktMbrStr03); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr03, "MBDPrtWbCmdHdr09");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr02,pMBDPrtWbFDATransformTktMbrStr03);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr04,MBDPrtWbFDATransformTktMbrStr04); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr04, "MBDPrtWbCmdHdr10");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr03,pMBDPrtWbFDATransformTktMbrStr04);

	NewAccess(CATCmdStarter,pMBDPrtWbFDATransformTktMbrStr05,MBDPrtWbFDATransformTktMbrStr05); // MenuBar command �Ӱ�ť1: XXXX����
	SetAccessCommand(pMBDPrtWbFDATransformTktMbrStr05, "MBDPrtWbCmdHdr11");
	SetAccessNext(pMBDPrtWbFDATransformTktMbrStr04,pMBDPrtWbFDATransformTktMbrStr05);


// Menu bar to be merged with the workshop menu bar
SetWorkbenchMenu(pMBDPrtWbWkb,pMBDPrtWbTktMbr);


return pMBDPrtWbWkb;