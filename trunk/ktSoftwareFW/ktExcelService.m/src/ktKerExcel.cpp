#include "stdafx.h"
#include "ktKerExcel.h"
#include "CATDlgNotify.h"
#include "CATApplicationFrame.h"
#include "CATISpecAttrAccess.h"
#include "CATISpecAttribute.h"
#include "CATISpecAttrKey.h"
#include "CATIAlias.h"



CATImplementClass( CKerExcel,
				  Implementation, 
				  CATBaseUnknown,
				  CATNull );


CKerExcel::CKerExcel():CATBaseUnknown()
{
	strFilePath=_T("");
}
CString CKerExcel::GetAppPath()
{
	CString strFileName;
	GetModuleFileName(NULL,strFileName.GetBufferSetLength (MAX_PATH+1),MAX_PATH);

	int nIndex = strFileName.ReverseFind ('\\');
	CString strPath;
	if (nIndex > 0)
		strPath = strFileName.Left (nIndex);
	else
		strPath = "";
	return strPath;
}

CKerExcel::~CKerExcel()
{
	COleVariant covFalse((short)FALSE);
	COleVariant	covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR); 
	MyRange.ReleaseDispatch();
	MySheet.ReleaseDispatch();
	MySheets.ReleaseDispatch();
	MyBook.Close(covFalse,_variant_t(strFilePath),covOptional);
	MyBook.ReleaseDispatch();
	MyBooks.Close();
	MyBooks.ReleaseDispatch();
	MyApp.Quit();
	MyApp.ReleaseDispatch();
	CoUninitialize();
}
BOOL CKerExcel::Open()
{
	LPDISPATCH lpDisp=NULL;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);   
	CoInitialize(NULL);
	if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
	{
		AfxMessageBox(_T("EXCEL初始化时出错!"),MB_OK|MB_ICONERROR);
		return FALSE;
	}
	lpDisp=MyApp.GetWorkbooks();
	MyBooks.AttachDispatch(lpDisp,TRUE);
	lpDisp = MyBooks.Add(covOptional); 
	MyBook.AttachDispatch(lpDisp,TRUE);
	lpDisp=MyBook.GetWorksheets();
	MySheets.AttachDispatch(lpDisp,TRUE);
	return TRUE;
}

//打开自标准模板
BOOL CKerExcel::OpenFrom(CATUnicodeString UstrTemplatePath)
{
	CString strFilePath(UstrTemplatePath.ConvertToChar());

	if(IsFileExist(strFilePath,FALSE)==FALSE)
	{
		ktErrorMsgBox("对应路径下EXCEL模板文件不存在！");
		LPDISPATCH lpDisp=NULL;
		COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);   
		CoInitialize(NULL);
		if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
		{
			AfxMessageBox(_T("EXCEL初始化时出错!"),MB_OK|MB_ICONERROR);
			return FALSE;
		}
		lpDisp=MyApp.GetWorkbooks();
		MyBooks.AttachDispatch(lpDisp,TRUE);
		lpDisp = MyBooks.Add(covOptional); 
		MyBook.AttachDispatch(lpDisp,TRUE);
		lpDisp=MyBook.GetWorksheets();
		MySheets.AttachDispatch(lpDisp,TRUE);
		return TRUE;	
	}
	else
	{
		LPDISPATCH lpDisp=NULL;
		COleVariant covOptional(strFilePath);  
		CoInitialize(NULL);
		if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
		{
			AfxMessageBox(_T("EXCEL初始化时出错!"),MB_OK|MB_ICONERROR);
			return FALSE;
		}
		lpDisp=MyApp.GetWorkbooks();
		MyBooks.AttachDispatch(lpDisp,TRUE);
		lpDisp = MyBooks.Add(covOptional); 
		MyBook.AttachDispatch(lpDisp,TRUE);
		lpDisp=MyBook.GetWorksheets();
		MySheets.AttachDispatch(lpDisp,TRUE);	
		return TRUE;
	}	
}

//-------------------------------------------------------------------------
//打开excel文档
//-------------------------------------------------------------------------
BOOL CKerExcel::Open(CATUnicodeString UstrFile )
{
	CString strFile(UstrFile.ConvertToChar());

	LPDISPATCH   lpDisp=NULL;
	CoInitialize(NULL);
	if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
	{
		AfxMessageBox(_T("EXCEL初始化时出错!"),MB_OK|MB_ICONERROR);
		return FALSE;
	}
	lpDisp=MyApp.GetWorkbooks();
	MyBooks.AttachDispatch(lpDisp,TRUE);
	lpDisp = MyBooks.Open(strFile, vtMissing, vtMissing, vtMissing, 
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,vtMissing);
	MyBook.AttachDispatch(lpDisp,TRUE);
	lpDisp=MyBook.GetWorksheets(); 
	MySheets.AttachDispatch(lpDisp,TRUE);
	strFilePath=strFile;
	return TRUE;
}

//-------------------------------------------------------------------------
//打开Sheet,按照名称
//-------------------------------------------------------------------------
BOOL CKerExcel::OpenSheet(CATUnicodeString UstrSheet)
{
	CString strSheet(UstrSheet.ConvertToChar());

	LPDISPATCH  lpDisp=NULL;
	long len;
	len=MySheets.GetCount();
	bool existFlag = FALSE;
	for(long i=1;i<=len;i++)
	{
		lpDisp=MySheets.GetItem((_variant_t)(long)i);
		MySheet.AttachDispatch(lpDisp,TRUE);
		CString str=MySheet.GetName();
		if(MySheet.GetName()==strSheet)
		{
			lpDisp=MySheet.GetCells();
			MyRange.AttachDispatch(lpDisp,TRUE);
			existFlag = TRUE;
			break;
		}
	}

	//如果没能找到则创建
	if (existFlag == FALSE)
	{
		lpDisp = MySheets.Add(vtMissing, vtMissing, COleVariant(1L), vtMissing);
		//获取sheet
		MySheet.AttachDispatch(lpDisp,TRUE);
		MySheet.SetName((LPCTSTR)strSheet); //(const WCHAR *)(strSheet.AllocSysString())
		//获得range
		lpDisp=MySheet.GetCells();
		MyRange.AttachDispatch(lpDisp,TRUE);
	}

	return TRUE;
}

//-------------------------------------------------------------------------
//打开Sheet,按照序号
//-------------------------------------------------------------------------
BOOL CKerExcel::OpenSheet(int indexSheet)
{
	LPDISPATCH  lpDisp=NULL;
	long len;
	len=MySheets.GetCount();
	if (indexSheet <= len)
	{
		lpDisp=MySheets.GetItem((_variant_t)(long)indexSheet);
		MySheet.AttachDispatch(lpDisp,TRUE);
		lpDisp=MySheet.GetCells();
		MyRange.AttachDispatch(lpDisp,TRUE);
		return TRUE;		
	}
	else
	{
		return FALSE;
	}	
}


//-------------------------------------------------------------------------
//设置cell值
//-------------------------------------------------------------------------
BOOL CKerExcel::SetItemText(int iRow,int iCol, CATUnicodeString UStrText)
{
	long Row = iRow;
	long Col = iCol;

	CString strText(UStrText.ConvertToChar());
	long lRow=0,lCol=0;
	lRow=GetRowS();
	lCol=GetColS();
	if(Row>lRow ||Col>lCol)
	{
		CString strText;
		strText.Format(L"由于(%d,%d)已经超过了(%d,%d)的范围,所以在(%d,%d)设置失败!",Row,Col,lRow,lCol,Row,Col);
		CATUnicodeString  UStrText = CStringToUS(strText);
		ktErrorMsgBox(UStrText);
		return FALSE;
	}
	MyRange.SetItem(_variant_t(Row), _variant_t(Col), _variant_t(strText));
	return TRUE;
}

//-------------------------------------------------------------------------
//获得cell值
//-------------------------------------------------------------------------
CATUnicodeString CKerExcel::GetItemText(int iRow,int iCol)
{
	long Row = iRow;
	long Col = iCol;

	CString strValue=_T("");
	long lRow=0,lCol=0;
	lRow=GetRowS();
	lCol=GetColS();
	if(Row>lRow ||Col>lCol)
	{
		CString strText;
		strText.Format(L"由于(%d,%d)已经超过了(%d,%d)的范围,所以返回空值",Row,Col,lRow,lCol,Row,Col);
		CATUnicodeString  UStrText = CStringToUS(strText);
		ktErrorMsgBox(UStrText);

		CATUnicodeString  UStrValue = CStringToUS(strValue);
		return UStrValue;
	}
	VARIANT lpDisp=MyRange.GetItem(_variant_t(Row), _variant_t(Col));
	Range rgRgeValue;
	rgRgeValue.AttachDispatch(lpDisp.pdispVal, TRUE);
	_variant_t vtVal = rgRgeValue.GetValue();
	if (vtVal.vt == VT_EMPTY)
	{
		rgRgeValue.ReleaseDispatch();
		strValue = _T("");
		rgRgeValue.ReleaseDispatch();
		CATUnicodeString  UStrValue = CStringToUS(strValue);
		return UStrValue;
	}
	vtVal.ChangeType(VT_BSTR);
	strValue= vtVal.bstrVal;
	rgRgeValue.ReleaseDispatch();

	CATUnicodeString  UStrValue = CStringToUS(strValue);
	return UStrValue;
}

//-------------------------------------------------------------------------
//获得表数目
//-------------------------------------------------------------------------
int CKerExcel::GetSheetNumber()
{
	LPDISPATCH  lpDisp=NULL;
	long len;
	len=MySheets.GetCount();
	int iLength = len;
	return iLength;
}

//-------------------------------------------------------------------------
//获得SheetName
//-------------------------------------------------------------------------
CATUnicodeString CKerExcel::GetSheetName(int iIndex)
{
	long i = iIndex;
	CString str = "";
	LPDISPATCH  lpDisp=NULL;
	long len;
	len=MySheets.GetCount();
	if(i<=len)
	{	lpDisp=MySheets.GetItem((_variant_t)(long)i);
		MySheet.AttachDispatch(lpDisp,TRUE);
		str=MySheet.GetName();
		MySheet.ReleaseDispatch();
	}		

	CATUnicodeString  UStrSheetName = CStringToUS(str);
	return UStrSheetName;
}

//-------------------------------------------------------------------------
//判断单元格是否合并
//-------------------------------------------------------------------------
BOOL CKerExcel::IsMergedCells(int iCellRow,int iCellCol, int &iRowNum, int &iColumnNum, int &iStartRow, int &iStartColumn)
{
	long Row = iCellRow;
	long Col = iCellCol;

	iRowNum = 0;
	iColumnNum = 0;
	iStartRow = 0;
	iStartColumn = 0;

	VARIANT lpDisp=MyRange.GetItem(_variant_t(Row), _variant_t(Col));
	Range unionRange;
	unionRange.AttachDispatch(lpDisp.pdispVal, TRUE);

	VARIANT vResult=unionRange.GetMergeCells();   

	if(vResult.boolVal==-1)             //是合并的单元格    
	{
		Range rangeMerge;
		rangeMerge.AttachDispatch( unionRange.GetMergeArea(), TRUE );
		// 合并行数
		Range TempRange;
		TempRange.AttachDispatch( rangeMerge.GetRows(), TRUE );
		iRowNum = TempRange.GetCount();
		TempRange.ReleaseDispatch();

		// 合并列数
		TempRange.AttachDispatch( rangeMerge.GetColumns(), TRUE );
		iColumnNum = TempRange.GetCount();
		TempRange.ReleaseDispatch();

		// 起始行
		iStartRow = rangeMerge.GetRow();

		//起始列
		iStartColumn = rangeMerge.GetColumn();

		rangeMerge.ReleaseDispatch();
		unionRange.ReleaseDispatch();

		return TRUE;
	}
	else
	{
		unionRange.ReleaseDispatch();
		return FALSE;
	}		
}

//-------------------------------------------------------------------------
// 获得使用的行数
//-------------------------------------------------------------------------
int CKerExcel::GetUsedRowNum()
{
	Range MyRange2;
	MyRange2.AttachDispatch( MySheet.GetUsedRange(), TRUE );

	Range MyRange3;
	long lgUsedRowNum = 0;
	MyRange3.AttachDispatch( MyRange2.GetRows(), TRUE );
	lgUsedRowNum = MyRange3.GetCount();

	MyRange2.ReleaseDispatch();
	MyRange3.ReleaseDispatch();
	int ilgUsedRowNum = lgUsedRowNum;
	return ilgUsedRowNum;
}

//-------------------------------------------------------------------------
// 获得使用的列数
//-------------------------------------------------------------------------
int CKerExcel::GetUsedColumnNum()
{
	MyRange.AttachDispatch( MySheet.GetUsedRange(), TRUE );

	long lgUsedColumnNum = 0;
	MyRange.AttachDispatch( MyRange.GetColumns(), TRUE );
	lgUsedColumnNum = MyRange.GetCount();

	int ilgUsedColumnNum = lgUsedColumnNum;
	return ilgUsedColumnNum;
}

int CKerExcel::GetBackGroundColor()
{
/*	
LPDISPATCH  lpDisp=NULL;
	Interior Itor;
	lpDisp=MyRange.GetInterior();
	Itor.AttachDispatch(lpDisp,TRUE);
	if(BackStyle.transparent==TRUE)
		Itor.SetColorIndex((_variant_t)(short)xlNone);
	else
	{
		Itor.SetColor((_variant_t)(long)BackStyle.Color);
	}
	Itor.ReleaseDispatch();


	VARIANT lpDisp=MyRange.GetItem(_variant_t(Row), _variant_t(Col));
	Range unionRange;
	unionRange.AttachDispatch(lpDisp.pdispVal, TRUE);

	VARIANT vResult=unionRange.GetMergeCells();   

	if(vResult.boolVal==-1)             //是合并的单元格    
	{
		Range rangeMerge;
		rangeMerge.AttachDispatch( unionRange.GetMergeArea(), TRUE );

		// 合并行数
		rangeMerge.AttachDispatch( rangeMerge.GetRows(), TRUE );
		iRowNum = rangeMerge.GetCount();

		// 合并列数
		rangeMerge.AttachDispatch( rangeMerge.GetColumns(), TRUE );
		iColumnNum = rangeMerge.GetCount();

		// 起始行
		iStartRow = rangeMerge.GetRow();

		//起始列
		iStartColumn = rangeMerge.GetColumn();
		return TRUE;
	}
*/
	return 0;

}





//-------------------------------------------------------------------------
//保存
//-------------------------------------------------------------------------
void CKerExcel::SaveAs(CATUnicodeString UstrPath)
{
	CString strPath(UstrPath.ConvertToChar());

	if(IsFileExist(strPath,FALSE)==TRUE)
		DeleteFile(strPath);
	MyBook.SaveAs(_variant_t(strPath),vtMissing,vtMissing,vtMissing,vtMissing,vtMissing
		,0,vtMissing,vtMissing,vtMissing,vtMissing);
	strFilePath=strPath;
}


// Converts (row,col) indices to an Excel-style A1:C1 string in Excel
void CKerExcel::IndexToString( int row, int col, char* strResult )
{
	{
		if( col > 26 )
		{
			sprintf( strResult,"%c%c%d",'A' + (col-1)/26-1,'A' + (col-1)%26,row );
		}
		else
		{
			sprintf( strResult,"%c%d", 'A' + (col-1)%26,row );
		}
	}
}





void CKerExcel::Save()
{
	MyBook.Save();
//	AfxMessageBox(_T("Excel保存成功"),MB_OK|MB_ICONINFORMATION);
}
void CKerExcel::AddSheet(CString strSheet)
{
	LPDISPATCH  lpDisp=NULL;
	lpDisp=MySheets.Add(vtMissing,vtMissing,vtMissing,vtMissing);
	MySheet.AttachDispatch(lpDisp,TRUE);
	MySheet.SetName(strSheet);
	lpDisp=MySheet.GetCells();
	MyRange.AttachDispatch(lpDisp,TRUE);
}
void CKerExcel::GetRange(CString strBegin,CString strEnd)
{
	MyRange=MySheet.GetRange(_variant_t(strBegin),_variant_t(strEnd));
}
void CKerExcel::AutoColFit()
{
	Range rg=MyRange.GetEntireColumn();
	rg.AutoFit();
	rg.ReleaseDispatch();
}
void CKerExcel::AutoRowFit()
{
	Range rg=MyRange.GetEntireRow();
	rg.AutoFit();	
	rg.ReleaseDispatch();
}
void CKerExcel::SetWrapText(BOOL blnTrue)
{
	MyRange.SetWrapText((_variant_t)(short)blnTrue);
}
void CKerExcel::SetVisible(BOOL blnVisible)
{
	if(blnVisible==TRUE)
		if(strFilePath!="")
		{
			if(IsFileExist(strFilePath,FALSE))
			{
				Exit();
				ShellExecute(NULL,L"open",strFilePath,NULL,NULL,SW_SHOW);
			}
			else
			{
				CString strName;
				strName="路径"+strFilePath+"错误,不能打开显示!";
				AfxMessageBox(strFilePath,MB_OK|MB_ICONINFORMATION);
			}
		}
		else
		{
			AfxMessageBox(L"请先存文件后,方可打开!",MB_OK|MB_ICONINFORMATION);
		}
}
void CKerExcel::SetFont(MyFont font)
{
	Font f=MyRange.GetFont();
	f.SetName(_variant_t(font.Name));
	f.SetShadow((_variant_t)(short)font.Shadow);
	f.SetSize((_variant_t)(short)font.size);
	f.SetUnderline((_variant_t)(short)font.Underline);
	f.SetBold((_variant_t)(short)font.Bold);
	f.SetColor((_variant_t)(long)font.ForeColor);
	f.SetItalic((_variant_t)(short)font.Italic);
	f.SetStrikethrough((_variant_t)(short)font.Strikethrough);
	f.SetSubscript((_variant_t)(short)font.Subscript);
	f.SetSuperscript((_variant_t)(short)font.Subscript);
	f.ReleaseDispatch();
}
void CKerExcel::SetAlignment(MyAlignment XMyAlignment)
{
	MyRange.SetHorizontalAlignment((_variant_t)(short)XMyAlignment.HorizontalAlignment);
	MyRange.SetVerticalAlignment((_variant_t)(short)XMyAlignment.VerticalAlignment);
}
void CKerExcel::AutoRange()
{
	LPDISPATCH  lpDisp=NULL;
	lpDisp=MySheet.GetCells();
	MyRange.AttachDispatch(lpDisp,TRUE);
}
void CKerExcel::SetMergeCells(BOOL blnTrue)
{
	if(blnTrue==TRUE)
	{
		int i,j;
		long Row=GetRowS();
		long Col=GetColS();
		for(j=2;j<=Col;j++) SetItemText(1,j,"");
		for(i=2;i<=Row;i++)
			for(j=1;j<=Col;j++)
				SetItemText(i,j,"");
	}
	MyRange.SetMergeCells((_variant_t)(short)blnTrue);
}

void CKerExcel::SetBackStyle(MyBackStyle BackStyle)
{
	LPDISPATCH  lpDisp=NULL;
	Interior Itor;
	lpDisp=MyRange.GetInterior();
	Itor.AttachDispatch(lpDisp,TRUE);
	if(BackStyle.transparent==TRUE)
		Itor.SetColorIndex((_variant_t)(short)xlNone);
	else
	{
		Itor.SetColor((_variant_t)(long)BackStyle.Color);
		Itor.SetPattern((_variant_t)(short)BackStyle.Pattern);
		Itor.SetPatternColor((_variant_t)(long)BackStyle.PatternColor);
	}
	Itor.ReleaseDispatch();

}
void CKerExcel::SetBorderLine(short Xposition,MyBorder XBorder)
{
	long Row,Col;
	Row=GetRowS();
	Col=GetColS();
	if(Row==1)
		if(Xposition==xlInsideHorizontal) return;
	if(Col==1)
		if(Xposition==xlInsideVertical) return;
	LPDISPATCH  lpDisp=NULL;
	lpDisp=MyRange.GetBorders();   
	Borders   bds;   
	bds.AttachDispatch(lpDisp);   
	Border   bd;   
	lpDisp=bds.GetItem((long)Xposition);   
	bd.AttachDispatch(lpDisp);   
	bd.SetLineStyle((_variant_t)(short)XBorder.LineStyle);
	bd.SetColor((_variant_t)(long)XBorder.Color);
	bd.SetWeight((_variant_t)(short)XBorder.Weight);
	bd.ReleaseDispatch();
	bds.ReleaseDispatch();
}
long CKerExcel::GetRowS()
{
	long len=0;
	Range rg=MyRange.GetEntireRow();	
	len=rg.GetCount();
	rg.ReleaseDispatch();
	return len;
}
long CKerExcel::GetColS()
{
	long len=0;
	Range rg=MyRange.GetEntireColumn();
	len=rg.GetCount();
	rg.ReleaseDispatch();
	return len;
}
void CKerExcel::SetNumberFormat(MyNumberFormat XNumberFormat)
{
	CString strText=XNumberFormat.strValue;
	MyRange.SetNumberFormat(_variant_t(strText));
}
void CKerExcel::SetColumnWidth(int intWidth)
{
	double f=intWidth/8.08;
	MyRange.SetColumnWidth((_variant_t)(double)f);
}
void CKerExcel::SetRowHeight(int intHeight)
{
	double f=intHeight/8.08;
	MyRange.SetRowHeight((_variant_t)(double)f);
}
void CKerExcel::InsertPicture(CString strFilePath)
{
	LPDISPATCH  lpDisp=NULL;
	if(IsFileExist(strFilePath,FALSE))
	{
	//	lpDisp=MySheet.get
	}
}
void CKerExcel::SetBackPicture(CString strFilePath)
{
	if(IsFileExist(strFilePath,FALSE)==TRUE)
		MySheet.SetBackgroundPicture(strFilePath);
}
void CKerExcel::PrintOut(short CopySum)
{
	if(CopySum<=0) CopySum=1;
	COleVariant covTrue((short)TRUE); 
	COleVariant covFalse((short)FALSE); 
	COleVariant	covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR); 
	MySheet.PrintOut(vtMissing,vtMissing,(_variant_t)(short)CopySum,vtMissing
		,vtMissing,vtMissing,covTrue,vtMissing);
}
void CKerExcel::PrePrintOut(BOOL blnEnable)
{
	COleVariant covOptional((short)blnEnable);
	MySheet.PrintPreview(covOptional);
}
BOOL CKerExcel::IsFileExist(CString strFn, BOOL bDir)
{
    HANDLE h;
	LPWIN32_FIND_DATA pFD=new WIN32_FIND_DATA;
	BOOL bFound=FALSE;
	if(pFD)
	{
		h=FindFirstFile(strFn,pFD);
		bFound=(h!=INVALID_HANDLE_VALUE);
		if(bFound)
		{
			if(bDir)
				bFound= (pFD->dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)!=NULL;
			FindClose(h);
		}
		delete pFD;
	}
	return bFound;
}
void CKerExcel::Exit()
{
	COleVariant covFalse((short)FALSE);
	COleVariant	covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR); 
	MyRange.ReleaseDispatch();
	MySheet.ReleaseDispatch();
	MySheets.ReleaseDispatch();
	MyBook.Close(covFalse,_variant_t(strFilePath),covOptional);
	MyBook.ReleaseDispatch();
	MyBooks.Close();
	MyBooks.ReleaseDispatch();
	MyApp.Quit();
	MyApp.ReleaseDispatch();
}




MyFont::MyFont()
{
	//名字
    Name="Microsoft Sans Serif";
	//大小
	size=12;
	//前景
	ForeColor=RGB(0,0,0);
	//粗体
	Bold=FALSE;
	//斜体
	Italic=FALSE;
	//中间线
	Strikethrough=FALSE;
	//阴影
	Shadow=FALSE;
	//下标
	Subscript=FALSE;
	//上标
	Superscricp=FALSE;
	//下划线
	Underline=xlUnderlineStyleNone;	
}
MyBorder::MyBorder()
{
	//线条形状
	LineStyle=xlContinuous;
	//粗线
    Weight=xlThin;
	//颜色
    Color=RGB(0,0,0);
}
MyBackStyle::MyBackStyle()
{
	//背景颜色
	Color=RGB(255,255,255);
	//背景图案
    Pattern=xlSolid;
	//背景图案颜色
    PatternColor=RGB(255,0,0);
	//默认为不透明
	transparent=FALSE;
}
MyAlignment::MyAlignment()
{
	//普通
	HorizontalAlignment=xlGeneral;
	//居中对齐
	VerticalAlignment=xlCenter;
}
MyNumberFormat::MyNumberFormat()
{
	strValue="G/通用格式";
}
CString MyNumberFormat::GetText()
{
	strValue="@";
	return strValue;
}
CString MyNumberFormat::GetGeneral()
{
	strValue="G/通用格式";
	return strValue;
}
CString MyNumberFormat::GetNumber(BOOL blnBox,int RightSum)
{
	CString str="0";
	int i;
	if(RightSum<0) RightSum=0;
	if(blnBox==TRUE)
	{
		if(RightSum==0)
		{
			str="#,##0_ ";
			strValue=str;
			return strValue;
		}
		else
		{
			str="#,##0.";
			for(i=0;i<RightSum;i++) str=str+"0";
			str=str+"_ ";
			strValue=str;
			return strValue;	
		}
	}
	else
	{
		if(RightSum==0)
		{
			str="0_ ";
			strValue=str;
			return strValue;
		}
		else
		{
			str="0.";
			for(i=0;i<RightSum;i++) str=str+"0";
			str=str+"_ ";
			strValue=str;
			return strValue;	
		}
	}
}
CString MyNumberFormat::GetDate(BOOL blnChinese)
{
	if(blnChinese==TRUE)
		strValue="yyyy\"年\"m\"月\"d\"日\";@";
	else
		strValue="yyyy-m-d;@";
	return strValue;
}
CString MyNumberFormat::GetDateTime(BOOL blnChinese)
{
	if(blnChinese==TRUE)
		strValue="yyyy\"年\"m\"月\"d\"日\" h\"时\"mm\"分\"ss\"秒\";@";
	else
		strValue="yyyy-m-d h:mm:ss;@";
	return strValue;
}
CString MyNumberFormat::GetDBNumber(BOOL blnChinese)
{
	if(blnChinese==TRUE)
		strValue="[DBNum1][$-804]G/通用格式";
	else
		strValue="[DBNum2][$-804]G/通用格式";
	return strValue;
}
CString MyNumberFormat::GetFractionNumBer(int DownSum,int DownNum)
{	
	CString str;
	int i;
	if(DownNum>0 && DownSum>0)
	{
		AfxMessageBox(L"分母位数和固定数只能设置一个,默认返回分母位数的设置!"
			,MB_ICONINFORMATION|MB_OK);
	}
	if(DownSum<=0)
	{
		if(DownNum<=0)
		{
			str="# ?/1";
			strValue=str;
			return strValue;
		}
		else
		{
			str.Format(L"# ?/%d",DownNum);
			strValue=str;
			return strValue;
		}
	}
	else
	{
		str="# ?/";
		for(i=0;i<DownSum;i++) str=str+"?";
		strValue=str;
		return strValue;
	}
}
CString MyNumberFormat::GetMoney(BOOL blnChinese,int RightSum)
{
	CString str;
	int i;
	if(RightSum<=0) RightSum=0;
	if(blnChinese==TRUE)
	{
		if(RightSum==0)
		{
			str="#,##0";
			strValue="￥"+str+";"+"￥-"+str;
			return strValue;
		}
		else
		{
			str="#,##0.";
			for(i=0;i<RightSum;i++) str=str+"0";
			strValue="￥"+str+";"+"￥-"+str;
			return strValue;
		}

	}
	else
	{
		if(RightSum==0)
		{
			str="#,##0";
			strValue="$"+str+";"+"$-"+str;
			return strValue;
		}
		else
		{
			str="#,##0.";
			for(i=0;i<RightSum;i++) str=str+"0";
			strValue="$"+str+";"+"$-"+str;
			return strValue;
		}
	}
}
CString MyNumberFormat::GetPercentNumBer(int RightSum)
{
	CString str;
	int i;
	if(RightSum<=0) RightSum=0;
	if(RightSum==0)
	{
		str="0%";
		strValue=str;
		return strValue;
	}
	else
	{
		str="0.";
		for(i=0;i<RightSum;i++) str=str+"0";
		strValue=str+"%";
		return strValue;
	}
}
CString MyNumberFormat::GetTechNumBer(int RightSum)
{
	CString str;
	int i;
	if(RightSum<=0) RightSum=0;
	str="0.";
	for(i=0;i<RightSum;i++) str=str+"0";
	strValue=str+"E+00";
	return strValue;
}
CString MyNumberFormat::GetTime(BOOL blnChinese)
{
	if(blnChinese==TRUE)
	{
		strValue="h\"时\"mm\"分\"ss\"秒\";@";
		return strValue;
	}
	else
	{
		strValue="h:mm:ss;@";
		return strValue;
	}
}
CString MyNumberFormat::GetPost(int Sum)
{
	int i;
	CString str="";
	if(Sum<=0) Sum=1;
	for(i=0;i<Sum;i++)
		str=str+"0";
	strValue=str;
	return strValue;
}

//-------------------------------------------------------------------
//错误提示
//-------------------------------------------------------------------
void CKerExcel::ktErrorMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"错误",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(pMsg,"错误");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}
void CKerExcel::ktErrorMsgBox(const int iNum)
{
	CATUnicodeString Str;
	Str.BuildFromNum(iNum);

	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"错误",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(Str,"错误");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;

}
void CKerExcel::ktErrorMsgBox(const double dValue)
{

	CATUnicodeString Str;
	Str.BuildFromNum(dValue);

	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"错误",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(Str,"错误");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}


//-------------------------------------------------------------------
//警告提示
//-------------------------------------------------------------------
void CKerExcel::ktWarningMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"警告",
		CATDlgNfyWarning);	
	pNotifyDlg->DisplayBlocked(pMsg,"警告");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}

//-------------------------------------------------------------------
//消息
//-------------------------------------------------------------------
void CKerExcel::ktInfoMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"提示",
		CATDlgNfyInformation);	
	pNotifyDlg->DisplayBlocked(pMsg,"提示");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}

CATUnicodeString CKerExcel::CStringToUS(CString iCString)
{
	if ("" == iCString) return FALSE;
	CATUnicodeString StrBSTR ;
	BSTR bstrText = iCString.AllocSysString();
	StrBSTR.BuildFromBSTR(bstrText);
	SysFreeString(bstrText); // 用完释放

	return StrBSTR;
}

CString CKerExcel::USToCString(CATUnicodeString iUString)
{
	CATString sTemp = iUString.ConvertToChar();
	char *cTemp = sTemp.CastToCharPtr();
	CString csTemp = cTemp;
	return csTemp;
}