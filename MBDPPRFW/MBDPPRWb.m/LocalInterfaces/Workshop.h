NewAccess(CATCmdWorkbench,CATCmdWorkbench1,MBDPPRWbWkb);
SetWorkbenchPriority (CATCmdWorkbench1, 25);

NewAccess(CATCmdContainer,CATCmdContainer1,NewToolBar001Tlb);


AddToolbarView(CATCmdContainer1,1,Right);

SetAccessChild(CATCmdWorkbench1,CATCmdContainer1);


return CATCmdWorkbench1;

