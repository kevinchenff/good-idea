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
		AfxMessageBox(_T("EXCEL��ʼ��ʱ����!"),MB_OK|MB_ICONERROR);
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

//���Ա�׼ģ��
BOOL CKerExcel::OpenFrom(CATUnicodeString UstrTemplatePath)
{
	CString strFilePath(UstrTemplatePath.ConvertToChar());

	if(IsFileExist(strFilePath,FALSE)==FALSE)
	{
		ktErrorMsgBox("��Ӧ·����EXCELģ���ļ������ڣ�");
		LPDISPATCH lpDisp=NULL;
		COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);   
		CoInitialize(NULL);
		if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
		{
			AfxMessageBox(_T("EXCEL��ʼ��ʱ����!"),MB_OK|MB_ICONERROR);
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
			AfxMessageBox(_T("EXCEL��ʼ��ʱ����!"),MB_OK|MB_ICONERROR);
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
//��excel�ĵ�
//-------------------------------------------------------------------------
BOOL CKerExcel::Open(CATUnicodeString UstrFile )
{
	CString strFile(UstrFile.ConvertToChar());

	LPDISPATCH   lpDisp=NULL;
	CoInitialize(NULL);
	if (!MyApp.CreateDispatch(L"Excel.Application",NULL))
	{
		AfxMessageBox(_T("EXCEL��ʼ��ʱ����!"),MB_OK|MB_ICONERROR);
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
//��Sheet,��������
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

	//���û���ҵ��򴴽�
	if (existFlag == FALSE)
	{
		lpDisp = MySheets.Add(vtMissing, vtMissing, COleVariant(1L), vtMissing);
		//��ȡsheet
		MySheet.AttachDispatch(lpDisp,TRUE);
		MySheet.SetName((LPCTSTR)strSheet); //(const WCHAR *)(strSheet.AllocSysString())
		//���range
		lpDisp=MySheet.GetCells();
		MyRange.AttachDispatch(lpDisp,TRUE);
	}

	return TRUE;
}

//-------------------------------------------------------------------------
//��Sheet,�������
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
//����cellֵ
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
		strText.Format(L"����(%d,%d)�Ѿ�������(%d,%d)�ķ�Χ,������(%d,%d)����ʧ��!",Row,Col,lRow,lCol,Row,Col);
		CATUnicodeString  UStrText = CStringToUS(strText);
		ktErrorMsgBox(UStrText);
		return FALSE;
	}
	MyRange.SetItem(_variant_t(Row), _variant_t(Col), _variant_t(strText));
	return TRUE;
}

//-------------------------------------------------------------------------
//���cellֵ
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
		strText.Format(L"����(%d,%d)�Ѿ�������(%d,%d)�ķ�Χ,���Է��ؿ�ֵ",Row,Col,lRow,lCol,Row,Col);
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
//��ñ���Ŀ
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
//���SheetName
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
//�жϵ�Ԫ���Ƿ�ϲ�
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

	if(vResult.boolVal==-1)             //�Ǻϲ��ĵ�Ԫ��    
	{
		Range rangeMerge;
		rangeMerge.AttachDispatch( unionRange.GetMergeArea(), TRUE );
		// �ϲ�����
		Range TempRange;
		TempRange.AttachDispatch( rangeMerge.GetRows(), TRUE );
		iRowNum = TempRange.GetCount();
		TempRange.ReleaseDispatch();

		// �ϲ�����
		TempRange.AttachDispatch( rangeMerge.GetColumns(), TRUE );
		iColumnNum = TempRange.GetCount();
		TempRange.ReleaseDispatch();

		// ��ʼ��
		iStartRow = rangeMerge.GetRow();

		//��ʼ��
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
// ���ʹ�õ�����
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
// ���ʹ�õ�����
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

	if(vResult.boolVal==-1)             //�Ǻϲ��ĵ�Ԫ��    
	{
		Range rangeMerge;
		rangeMerge.AttachDispatch( unionRange.GetMergeArea(), TRUE );

		// �ϲ�����
		rangeMerge.AttachDispatch( rangeMerge.GetRows(), TRUE );
		iRowNum = rangeMerge.GetCount();

		// �ϲ�����
		rangeMerge.AttachDispatch( rangeMerge.GetColumns(), TRUE );
		iColumnNum = rangeMerge.GetCount();

		// ��ʼ��
		iStartRow = rangeMerge.GetRow();

		//��ʼ��
		iStartColumn = rangeMerge.GetColumn();
		return TRUE;
	}
*/
	return 0;

}





//-------------------------------------------------------------------------
//����
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
//	AfxMessageBox(_T("Excel����ɹ�"),MB_OK|MB_ICONINFORMATION);
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
				strName="·��"+strFilePath+"����,���ܴ���ʾ!";
				AfxMessageBox(strFilePath,MB_OK|MB_ICONINFORMATION);
			}
		}
		else
		{
			AfxMessageBox(L"���ȴ��ļ���,���ɴ�!",MB_OK|MB_ICONINFORMATION);
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
	//����
    Name="Microsoft Sans Serif";
	//��С
	size=12;
	//ǰ��
	ForeColor=RGB(0,0,0);
	//����
	Bold=FALSE;
	//б��
	Italic=FALSE;
	//�м���
	Strikethrough=FALSE;
	//��Ӱ
	Shadow=FALSE;
	//�±�
	Subscript=FALSE;
	//�ϱ�
	Superscricp=FALSE;
	//�»���
	Underline=xlUnderlineStyleNone;	
}
MyBorder::MyBorder()
{
	//������״
	LineStyle=xlContinuous;
	//����
    Weight=xlThin;
	//��ɫ
    Color=RGB(0,0,0);
}
MyBackStyle::MyBackStyle()
{
	//������ɫ
	Color=RGB(255,255,255);
	//����ͼ��
    Pattern=xlSolid;
	//����ͼ����ɫ
    PatternColor=RGB(255,0,0);
	//Ĭ��Ϊ��͸��
	transparent=FALSE;
}
MyAlignment::MyAlignment()
{
	//��ͨ
	HorizontalAlignment=xlGeneral;
	//���ж���
	VerticalAlignment=xlCenter;
}
MyNumberFormat::MyNumberFormat()
{
	strValue="G/ͨ�ø�ʽ";
}
CString MyNumberFormat::GetText()
{
	strValue="@";
	return strValue;
}
CString MyNumberFormat::GetGeneral()
{
	strValue="G/ͨ�ø�ʽ";
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
		strValue="yyyy\"��\"m\"��\"d\"��\";@";
	else
		strValue="yyyy-m-d;@";
	return strValue;
}
CString MyNumberFormat::GetDateTime(BOOL blnChinese)
{
	if(blnChinese==TRUE)
		strValue="yyyy\"��\"m\"��\"d\"��\" h\"ʱ\"mm\"��\"ss\"��\";@";
	else
		strValue="yyyy-m-d h:mm:ss;@";
	return strValue;
}
CString MyNumberFormat::GetDBNumber(BOOL blnChinese)
{
	if(blnChinese==TRUE)
		strValue="[DBNum1][$-804]G/ͨ�ø�ʽ";
	else
		strValue="[DBNum2][$-804]G/ͨ�ø�ʽ";
	return strValue;
}
CString MyNumberFormat::GetFractionNumBer(int DownSum,int DownNum)
{	
	CString str;
	int i;
	if(DownNum>0 && DownSum>0)
	{
		AfxMessageBox(L"��ĸλ���͹̶���ֻ������һ��,Ĭ�Ϸ��ط�ĸλ��������!"
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
			strValue="��"+str+";"+"��-"+str;
			return strValue;
		}
		else
		{
			str="#,##0.";
			for(i=0;i<RightSum;i++) str=str+"0";
			strValue="��"+str+";"+"��-"+str;
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
		strValue="h\"ʱ\"mm\"��\"ss\"��\";@";
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
//������ʾ
//-------------------------------------------------------------------
void CKerExcel::ktErrorMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"����",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(pMsg,"����");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}
void CKerExcel::ktErrorMsgBox(const int iNum)
{
	CATUnicodeString Str;
	Str.BuildFromNum(iNum);

	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"����",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(Str,"����");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;

}
void CKerExcel::ktErrorMsgBox(const double dValue)
{

	CATUnicodeString Str;
	Str.BuildFromNum(dValue);

	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"����",
		CATDlgNfyError);	
	pNotifyDlg->DisplayBlocked(Str,"����");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}


//-------------------------------------------------------------------
//������ʾ
//-------------------------------------------------------------------
void CKerExcel::ktWarningMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"����",
		CATDlgNfyWarning);	
	pNotifyDlg->DisplayBlocked(pMsg,"����");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}

//-------------------------------------------------------------------
//��Ϣ
//-------------------------------------------------------------------
void CKerExcel::ktInfoMsgBox(const char* pMsg)
{
	CATDlgNotify  *pNotifyDlg = new CATDlgNotify( CATApplicationFrame::GetApplicationFrame()->GetMainWindow(),
		"��ʾ",
		CATDlgNfyInformation);	
	pNotifyDlg->DisplayBlocked(pMsg,"��ʾ");
	pNotifyDlg->RequestDelayedDestruction();
	pNotifyDlg=NULL;
}

CATUnicodeString CKerExcel::CStringToUS(CString iCString)
{
	if ("" == iCString) return FALSE;
	CATUnicodeString StrBSTR ;
	BSTR bstrText = iCString.AllocSysString();
	StrBSTR.BuildFromBSTR(bstrText);
	SysFreeString(bstrText); // �����ͷ�

	return StrBSTR;
}

CString CKerExcel::USToCString(CATUnicodeString iUString)
{
	CATString sTemp = iUString.ConvertToChar();
	char *cTemp = sTemp.CastToCharPtr();
	CString csTemp = cTemp;
	return csTemp;
}