// DO NOT EDIT :: THE CAA2 WIZARDS WILL ADD CODE HERE
// END WIZARD EDITION ZONE
//Add additional command headers included in your workbench


// For example:
// new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr1",			//命令的头指针标识  
// 						  "MBDPrtXXXMod",			//添加的Module的模块名字//实现header与实现函数命令的连接
//						  "MBDPrtXXXXXCmd",		    //MBDPrtXXXMod module下，对应的Command类名称
//						  (void *)NULL);

//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr01", "MBDPrtFastenerInfoXMLMod","MBDPrtFastenerInfoToXMLCmd",(void *)NULL);
//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr02", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL);
//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr03", "MBDPrtAnnotateXMLMod","MBDPrtAnnotateToXMLCmd",(void *)NULL);
new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr04", "MBDPrtAddMaterialMod","MBDPrtAddMaterialCmd",(void *)NULL);

//紧固件选用
new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr05", "MBDPrtFstDesignMod","PrtFstPointsCmd",(void *)NULL); //定义安装点
new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr06", "MBDPrtFstDesignMod","PrtFstDesignCmd",(void *)NULL); //紧固件选用

//紧固件变换
//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr07", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL); //阵列紧固件
//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr08", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL); //对称紧固件
//new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr09", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL); //编辑紧固件
new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr10", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL); //删除紧固件
new MBDPrtWbCmdHeader("MBDPrtWbCmdHdr11", "MBDPrtXXXMod","MBDPrtXXXXXCmd",(void *)NULL); //更新紧固件