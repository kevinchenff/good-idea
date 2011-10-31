// DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
// END WIZARD EDITION ZONE
//Add additional command headers included in your workbench


// For example:
// new MBDPrdWbCmdHeader("MBDPrdWbCmdHdr1",			//命令的头指针标识  
// 						  "MBDPrdXXXMod",			//添加的Module的模块名字//实现header与实现函数命令的连接
//						  "MBDPrdXXXXXCmd",		    //MBDPrdXXXMod module下，对应的Command类名称
//						  (void *)NULL);

// ADE Command Header
new MBDPrdWbCmdHeader("MBDPrdWbADEHdr01", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbADEHdr02", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbADEHdr03", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbADEHdr04", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbADEHdr05", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);

// AME Command Header
new MBDPrdWbCmdHeader("MBDPrdWbAMEHdr01", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbAMEHdr02", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbAMEHdr03", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbAMEHdr04", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbAMEHdr05", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);

// 技术条件功能 Command Header
new MBDPrdWbCmdHeader("MBDPrdWbAddTechHdr", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdWbCheckTechHdr", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);


// 模型规范性检验 Command Header
new MBDPrdWbCmdHeader("MBDPrdWbDataVerifyHdr", "MBDPrdXXXMod","MBDPrdXXXXXCmd",(void *)NULL);


// MBD模型差异性对比 Command Header
new MBDPrdWbCmdHeader("MBDPrdLoadPrtVPMHdr", "MBDPrdLoadPrtVPMMod","MBDPrdLoadPrtVPMCmd",(void *)NULL);
new MBDPrdWbCmdHeader("MBDPrdPartsCompareHdr", "MBDPrdPartsCompareMod","MBDPrdPartsCompareCmd",(void *)NULL);

