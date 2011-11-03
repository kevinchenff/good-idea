//使用说明:
//此类的设计方便了VS对EXCEL的操作。主要功能如下:
//	A.打开EXCEL文档进行修改和保存
//	B.新建EXCEL文档进行操作存储
//	B.读取和填写EXCEL中的数据
//	C.设置EXCEL中边框的参数
//	D.设置EXCEL中背景颜色的参数
//	E.打印和预览
//	F.自动回收内存
//	G.在显示之后,此类将自动关闭不能进行其它相关的操作
//---------------------------------------------------------

#include "stdafx.h"
#include "excel9.h"
#include <comdef.h>
#include "ktExcelService.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATISpecObject.h"
#include "CATListOfDouble.h"
#include "CATPathElement.h"

#include "atlstr.h"
#include "iostream"
using namespace std;


//下滑线的种类
#define xlUnderlineStyleDouble -4119
#define xlUnderlineStyleDoubleAccounting 5
#define xlUnderlineStyleNone -4142
#define xlUnderlineStyleSingle 2
#define xlUnderlineStyleSingleAccounting 4
//边框方位
#define xlDiagonalDown 5
#define xlDiagonalUp 6
#define xlEdgeBottom 9
#define xlEdgeLeft 7
#define xlEdgeRight 10
#define xlEdgeTop 8
#define xlInsideHorizontal 12
#define xlInsideVertical 11
//边框划线类型
#define xlContinuous 1
#define xlDash -4115
#define xlDashDot 4
#define xlDashDotDot 5
#define xlDot -4118
#define xlDouble -4119
#define xlLineStyleNone -4142
#define xlNone -4142
#define xlSlantDashDot 13
//字体水平对齐方式
#define xlGeneral 1
#define xlCenter -4108
#define xlLeft -4131
#define xlRight -4152
#define xlFill 5
#define xlJustify -4130
//字体垂直对齐方式
#define xlTop -4160
#define xlBottom -4107
//边框划线的粗细
#define xlHairline 1
#define xlMedium -4138
#define xlThick 4
#define xlThin 2
//背景图案的类型
#define xlSolid 1
#define xlGray8 18
#define xlGray75 -4126
#define xlGray50 -4125
#define xlGray25 -4124
#define xlGray16 17
#define xlHorizontal -4128
#define xlVertical -4166
#define xlDown -4121
#define xlUp -4162
#define xlChecker 9
#define xlSemiGray75 10
#define xlLightHorizontal 11
#define xlLightVertical 12
#define xlLightDown 13
#define xlLightUp 14
#define xlGrid 15
#define xlCrissCross 16
//边框设置参数类
class ExportedByktExcelService MyBorder
{
public:
	//线条形状
	short LineStyle;
	//粗线
    short Weight;
	//颜色
    long Color;
	//构造函数
	MyBorder();
};
//背景设置参数类
class ExportedByktExcelService MyBackStyle
{
public:
	//背景颜色
	long Color;
	//背景图案
    short Pattern;
	//背景图案颜色
    long PatternColor;
	//透明不透明
	BOOL transparent;
	//构造函数
	MyBackStyle();
};
//字体设置参数类
class ExportedByktExcelService MyFont
{
public:
	//名字
    CString Name;
	//大小
	long size;
	//前景
	long ForeColor;
	//粗体
	BOOL Bold;
	//斜体
	BOOL Italic;
	//中间线
	BOOL Strikethrough;
	//阴影
	BOOL Shadow;
	//下标
	BOOL Subscript;
	//上标
	BOOL Superscricp;
	//下划线
	short Underline;
	//构造函数
	MyFont();
};
//文字对齐方式设置参数类
class ExportedByktExcelService MyAlignment
{
public:
	//水平对齐
	short HorizontalAlignment;
	//垂直对齐
	short VerticalAlignment;
	//构造函数
	MyAlignment();
};
//列数据类型的设置参数类
class ExportedByktExcelService MyNumberFormat
{
public:
	MyNumberFormat();
	//设置参数
	CString strValue;
	//返回文本类型的设置
	CString GetText();
	//返回数字格式的设置
	//blnBox: 使用分隔符 RightSum: 小数位数 
	CString GetNumber(BOOL blnBox,int RightSum);
	//返回货币格式的设置
	//blnChinese: TURE:"￥",FALSE:"$"
	//RightSum: 小数位数 
	CString GetMoney(BOOL blnChinese,int RightSum);
	//返回日期格式的设置
	//blnChinese: TURE:"年月日",FALSE:"-"
	CString GetDate(BOOL blnChinese);
	//返回时间格式的设置
	//blnChinese: TURE:"时分秒",FALSE:":"
	CString GetTime(BOOL blnChinese);
	//返回常规设置
	CString GetGeneral();
	//返回特殊数字的设置
	//blnChinese: TURE:大写,FALSE:小写
	CString GetDBNumber(BOOL blnChinese);
	//返回百分数的设置
	//RightSum: 小数位数 
	CString GetPercentNumBer(int RightSum);
	//返回分数的设置
	//DownSum:分母位数 DownNum(0): 固定分母数(0)
	CString GetFractionNumBer(int DownSum,int DownNum);
	//返回科学计数的设置
	//RightSum: 小数位数 
	CString GetTechNumBer(int RightSum);
	//返回6位邮政编码格式
	//Sum: 固定邮政编码的位数
	CString GetPost(int Sum);
	//返回日期加时间的设置
	//blnChinese: TURE:"年月日时分秒",FALSE:"-:"
	CString GetDateTime(BOOL blnChinese);
};
class ExportedByktExcelService CKerExcel: public CATBaseUnknown
{

	CATDeclareClass;

public:
	//Excel的应用
	_Application   MyApp;  
	_Workbook   MyBook;
	_Worksheet   MySheet;   
	Workbooks   MyBooks;   
	Worksheets   MySheets;   
	Range   MyRange;  
	CString strFilePath;

//构造函数
	CKerExcel();
//析构函数
	~CKerExcel();
//打开新的Excel文件
	BOOL Open();

//-------------------------------
//打开strFile文件
	BOOL Open(CATUnicodeString UstrFile);

//打开自标准模板
	BOOL OpenFrom(CATUnicodeString UstrTemplatePath);

//打开Sheet,按照序号
	BOOL OpenSheet(int indexSheet);

//打开名为strSheet的表
	BOOL OpenSheet(CATUnicodeString UstrSheet);

//设置(ROW,COL)的字符CATUnicodeString
	BOOL SetItemText(int iRow,int iCol, CATUnicodeString UStrText);

//取得(ROW,COL)的字符
	CATUnicodeString  GetItemText(int iRow,int iCol);

//取得表数目
	int GetSheetNumber();

//取得表名称
	CATUnicodeString GetSheetName(int iIndex);

//判断单元格是否合并
	BOOL IsMergedCells(int iCellRow,int iCellCol, int &iRowNum, int &iColumnNum, int &iStartRow, int &iStartColumn);

//获得使用行数
	int GetUsedRowNum();

//获得使用列数
	int GetUsedColumnNum();
	int GetBackGroundColor();

//保存为strPath
	void SaveAs(CATUnicodeString UstrPath);

// Converts (row,col) indices to an Excel-style A1:C1 string in Excel
	void IndexToString( int row, int col, char* strResult );

//退出excel
	void Exit();

//-------------------------------
//显示excel
	void SetVisible(BOOL blnVisible);
	//查找此文件是否存在
	BOOL IsFileExist(CString strFn, BOOL bDir);
	//自动保存(针对打开已经存在的文件)
	void Save();
	//添加新的表
	void AddSheet(CString strSheet);
	//得到新的选择区域
	void GetRange(CString strBegin,CString strEnd);
	//列自动展开
	void AutoColFit();
	//行自动展开
	void AutoRowFit();
	//设置自动换行
	void SetWrapText(BOOL blnTrue);
	//设置字体
	void SetFont(MyFont font);
	//得到整个区域
	void AutoRange();
	//合并单元格
	void SetMergeCells(BOOL blnTrue);
	//设置背景
	void SetBackStyle(MyBackStyle BackStyle);
	//设置边框
	void SetBorderLine(short Xposition,MyBorder XBorder);
	//设置对齐方式
	void SetAlignment(MyAlignment XMyAlignment);
	//得到列数
	long GetRowS();
	//得到行数
	long GetColS();
	//设置数据的类型
	void SetNumberFormat(MyNumberFormat XNumberFormat);
	//设置列宽
	void SetColumnWidth(int intWidth);
	//设置行高
	void SetRowHeight(int intHeight);
	//打印
	//CopySum:打印的份数
	void PrintOut(short CopySum);
	//打印预览
	//blnEnable:TRUE-允许修改 FALSE-不允许
	void PrePrintOut(BOOL blnEnable);
	//插入图片
	//strFilePath:文件名路径
	void InsertPicture(CString strFilePath);
	//设置背景图片
	//strFilePath:文件名路径
	void SetBackPicture(CString strFilePath);
	//返回当前程序所在路径
	CString GetAppPath();

//
//---------------------------------------------------------------------
//错误消息框
 void ktErrorMsgBox(const char* pMsg);
 void ktErrorMsgBox(const int iNum);
 void ktErrorMsgBox(const double dValue);

//警告信息
 void ktWarningMsgBox(const char* pMsg);

//提示信息
 void ktInfoMsgBox(const char* pMsg);

// 字符串转换函数

CATUnicodeString CStringToUS(CString iCString);
//---------------------------------------------------------------------

};