// MenuEdit.cpp : implementation file
//

#include "stdafx.h"
#include "MenuEdit.h"
#include "afxdialogex.h"


// CMenuEdit dialog

IMPLEMENT_DYNAMIC(CMenuEdit, CDialog)

CMenuEdit::CMenuEdit(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
{

}

CMenuEdit::~CMenuEdit()
{
}

void CMenuEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMenuEdit, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &CMenuEdit::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMenuEdit::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMenuEdit::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMenuEdit::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMenuEdit::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMenuEdit::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMenuEdit::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMenuEdit::OnBnClickedButton5)
	ON_BN_CLICKED(IDOK, &CMenuEdit::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CMenuEdit::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON6, &CMenuEdit::OnBnClickedButton6)
	ON_BN_CLICKED(IDCANCEL, &CMenuEdit::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMenuEdit message handlers


void CMenuEdit::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	cur_sel=1;
	
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Starters";
	 rc1 = 0;
	short col_index = 0;
	int ind = 0;
	rec_index1=1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rc1++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index1);
	
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);

}


void CMenuEdit::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	cur_sel=2;
		
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Veggie";
	 rc2 = 0;
	short col_index = 0;
	int ind = 0;
	rec_index2=1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rc2++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index2);
	
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);

}



void CMenuEdit::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	cur_sel=3;
	
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Tandoor";
	 rc3 = 0;
	short col_index = 0;
	int ind = 0;
	rec_index3=1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rc3++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index3);
	
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);

}


void CMenuEdit::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	price->SetSel(0,-1);
	price->Clear();
	item->SetSel(0,-1);
	item->Clear();
}


void CMenuEdit::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	if(cur_sel == 1){ 
		SqlString =  "SELECT * FROM Starters";
		rec_index1--;
		if(rec_index1 == 0){
			rec_index1 =rc1;
	
	}
	}
	else if(cur_sel == 2){ 
		SqlString =  "SELECT * FROM Veggie";
		rec_index2--;
		if(rec_index2 == 0)
			rec_index2 =rc2;
	
	}
	else if(cur_sel == 3){ 
		SqlString =  "SELECT * FROM Tandoor";
		rec_index3--;
		if(rec_index3 == 0)
			rec_index3 =rc3;
	
	}
	
	//rowcount = 0;
	short col_index = 0;
	//int ind = 0;
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	if(cur_sel == 1)
	{
		recset.SetAbsolutePosition(rec_index1);
	}
	else if(cur_sel == 2)
	{
		recset.SetAbsolutePosition(rec_index2);
	}
	else if(cur_sel == 3)
	{
		recset.SetAbsolutePosition(rec_index3);
	}
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);
	
}


void CMenuEdit::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	if(cur_sel == 1){ 
		SqlString =  "SELECT * FROM Starters";
		rec_index1++;
		if(rec_index1 == (rc1+1))
			rec_index1 =1;
	}
	else if(cur_sel == 2){ 
		SqlString =  "SELECT * FROM Veggie";
		rec_index2++;
		if(rec_index2 == (rc2+1))
			rec_index2 =1;
	}
	else if(cur_sel == 3){ 
		SqlString =  "SELECT * FROM Tandoor";
		rec_index3++;
		if(rec_index3 == (rc3+1))
			rec_index3 =1;
	}
	
	//rowcount = 0;
	short col_index = 0;
	//int ind = 0;
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	if(cur_sel == 1)
	{
		recset.SetAbsolutePosition(rec_index1);
	}
	else if(cur_sel == 2)
	{
		recset.SetAbsolutePosition(rec_index2);
	}
	else if(cur_sel == 3)
	{
		recset.SetAbsolutePosition(rec_index3);
	}
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);
	
}


void CMenuEdit::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CString SqlString,s1;
	CString var_name,var_price;
//	int s;
	if(cur_sel == 1){ 
		s1.Format("INSERT INTO Starters (S_Item ,Price) VALUES (");
	
	}
	else if(cur_sel == 2){ 
		s1.Format("INSERT INTO Veggie (V_Item ,Price) VALUES (");
	
	}
	else if(cur_sel == 3){ 
		s1.Format("INSERT INTO Tandoor (T_Item ,Price) VALUES (");
		
	}
	
	int flg=0;
	item->GetWindowText(var_name);
	price->GetWindowText(var_price);
	//int p=_ttoi(var_price);
	CString coma(", ");
	CString CB(");");
	CString Quo("'");
	SqlString=s1+Quo+var_name+Quo+coma+var_price+CB;

	try
{
   database.ExecuteSQL(SqlString);
}
catch(CDBException* pe)
{
	flg=1;
   // The error code is in pe->m_nRetCode
   pe->ReportError();
   pe->Delete();
}
if (flg == 0)
{
MessageBox(_T("Record Successfully Added To The Database"),_T("Successfull")); 
}

	
}


void CMenuEdit::OnBnClickedButton5()
{

	// TODO: Add your control notification handler code here
	CString SqlString,s1;
	CString var_name,var_price,var_id;
	int flg=0,col_index=0;
	
	CMenuRecord recset(&database);

	item->GetWindowText(var_name);
	price->GetWindowText(var_price);
	CString coma(", ");
	CString CB(");");
	CString sc(" ;");
	CString Quo("'");
	CString Pr(" Price = ");
	CString sp("  ");
	CString wh(" WHERE ");
	if(cur_sel == 1){ 
		recset.Open(CRecordset::dynaset,_T("SELECT * FROM Starters"),CRecordset::readOnly);

		recset.SetAbsolutePosition(rec_index1);
		recset.GetFieldValue(col_index,var_id);
		
		CString id(" S_ID = ");
		s1.Format("UPDATE Starters SET S_Item = ");
		
		SqlString=s1+Quo+var_name+Quo+coma+Pr+var_price+sp+wh+id+var_id+sc;
	
	}
	else if(cur_sel == 2){ 
	
		recset.Open(CRecordset::dynaset,_T("SELECT * FROM Veggie"),CRecordset::readOnly);

		recset.SetAbsolutePosition(rec_index2);
		recset.GetFieldValue(col_index,var_id);
		
		CString id(" V_ID = ");
		s1.Format("UPDATE Veggie SET V_Item = ");
		
		SqlString=s1+Quo+var_name+Quo+coma+Pr+var_price+sp+wh+id+var_id+sc;
	
	}
	else if(cur_sel == 3){
		
		recset.Open(CRecordset::dynaset,_T("SELECT * FROM Tandoor"),CRecordset::readOnly);

		recset.SetAbsolutePosition(rec_index3);
		recset.GetFieldValue(col_index,var_id);
		
		CString id(" T_ID = ");
		s1.Format("UPDATE Tandoor SET T_Item = ");
		
		SqlString=s1+Quo+var_name+Quo+coma+Pr+var_price+sp+wh+id+var_id+sc;
	
		
	}
	try
{
   database.ExecuteSQL(SqlString);
}
catch(CDBException* pe)
{
	flg=1;
   // The error code is in pe->m_nRetCode
   pe->ReportError();
   pe->Delete();
}
if (flg == 0)
{
MessageBox(_T("Record Successfully Updated To The Database"),_T("Successfull")); 
}

}


void CMenuEdit::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


BOOL CMenuEdit::OnInitDialog(void)
{
	CDialog::OnInitDialog();

	sDriver = "MICROSOFT ACCESS DRIVER (*.mdb)";
	sFile = "D:\\Menu4.mdb";
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s",sDriver,sFile);
	TRY
	{
		// Open the database
		database.Open(NULL,false,false,sDsn,false);
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;

	//Initialization
	
	item=(CEdit *)GetDlgItem(IDC_EDIT2);
	price=(CEdit *)GetDlgItem(IDC_EDIT3);
	R_Starters=(CButton*)GetDlgItem(IDC_RADIO1) ;
	R_Main=(CButton *)GetDlgItem(IDC_RADIO2);
	R_Tandoor=(CButton *)GetDlgItem(IDC_RADIO3);
	R_Starters->SetCheck(1);
	cur_sel=1;
	w=0;
	k=w;
	
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Starters";
	 rc1 = 0;
	short col_index = 0;
	int ind = 0;
	rec_index1=1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rc1++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index1);
	
	recset.GetFieldValue(col_index+1,var_name);
	recset.GetFieldValue(col_index+2,var_price);
	item->SetWindowText(var_name);
	price->SetWindowText(var_price);

	return TRUE;
}


void CMenuEdit::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMenuEdit::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
		CString SqlString;
	CMenuRecord recset(&database);
	if(cur_sel == 1){ 
		SqlString =  "SELECT * FROM Starters";
		
	}
	else if(cur_sel == 2){ 
		SqlString =  "SELECT * FROM Veggie";
		
	}
	else if(cur_sel == 3){ 
		SqlString =  "SELECT * FROM Tandoor";
	}
	//SqlString =  "SELECT * FROM Starters";
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::none);
	CString var_name,var_price;
		if(cur_sel == 1)
	{
		recset.SetAbsolutePosition(rec_index1);
	}
	else if(cur_sel == 2)
	{
		recset.SetAbsolutePosition(rec_index2);
	}
	else if(cur_sel == 3)
	{
		recset.SetAbsolutePosition(rec_index3);
	}

	int col_index=0;
	if(recset.CanUpdate())
	{
		recset.Delete();
		if(rec_index1 == rc1){
			recset.MoveFirst();
		}
		else
			recset.MoveNext();
	AfxMessageBox("Record Successfully deleted!");

		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);

		item->SetWindowText(var_name);
		price->SetWindowText(var_price);


	}
	else
	{
		AfxMessageBox( "Record cannot be deleted.");
	}

}


void CMenuEdit::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	database.Close();
	if(!(database.IsOpen()))
	{
		AfxMessageBox("Database Closed");

	}
	else
		AfxMessageBox("Error Closing Database");
	
	CDialog::OnCancel();
}
