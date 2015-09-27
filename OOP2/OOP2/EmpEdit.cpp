// EmpEdit.cpp : implementation file
//

#include "stdafx.h"
#include "EmpEdit.h"
#include "afxdialogex.h"


// CEmpEdit dialog

IMPLEMENT_DYNAMIC(CEmpEdit, CDialog)

CEmpEdit::CEmpEdit(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
{

}

CEmpEdit::~CEmpEdit()
{
}

void CEmpEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
/*	DDX_Control(pDX, IDC_EDIT1, EID);
	DDX_Control(pDX, IDC_EDIT2, ENA);
	DDX_Control(pDX, IDC_EDIT3, EDE);
	DDX_Control(pDX, IDC_EDIT4, EWO);
	DDX_Control(pDX, IDC_EDIT5, ESA);*/
}


BEGIN_MESSAGE_MAP(CEmpEdit, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CEmpEdit::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEmpEdit::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CEmpEdit::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CEmpEdit::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CEmpEdit::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CEmpEdit::OnBnClickedButton7)
	ON_BN_CLICKED(IDCANCEL, &CEmpEdit::OnBnClickedCancel)
END_MESSAGE_MAP()


// CEmpEdit message handlers


void CEmpEdit::OnBnClickedButton1()
{
	// TODO: New
	CString var_id;
	//EID->SetSel(0,-1);
	ENA->SetSel(0,-1);
	EWO->SetSel(0,-1);
	ESA->SetSel(0,-1);
	EDE->SetSel(0,-1);
	//EID->Clear();
	ENA->Clear();
	EWO->Clear();
	ESA->Clear();
	EDE->Clear();
	CEmpTable recset(&database);
	CString SqlString("SELECT * FROM EmpTable");
	short col_index = 0;
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	//AfxMessageBox(_T("5"));
	recset.MoveLast();
	recset.GetFieldValue(col_index+1,var_id);
	var_id.Remove('E');
	//AfxMessageBox(var_id);
	int k=_ttoi(var_id);
	k++;
	CString id;
	id.Format("E%d",k);
	EID->SetWindowText(id);
}


void CEmpEdit::OnBnClickedButton2()
{

	// TODO: Next Record
	CString var_name,var_id,var_sh,var_sa,var_dep;
	CEmpTable recset(&database);
	CString SqlString("SELECT * FROM EmpTable");
	short col_index = 0;
	rec_index++;
		if(rec_index == (rc+1))
			rec_index =1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.SetAbsolutePosition(rec_index);
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dep);
	recset.GetFieldValue(col_index+4,var_sh);
	recset.GetFieldValue(col_index+5,var_sa);
	EID->SetWindowText(var_id);
	ENA->SetWindowText(var_name);
	EWO->SetWindowText(var_sh);
	ESA->SetWindowText(var_sa);
	EDE->SetWindowText(var_dep);
	
	
}


void CEmpEdit::OnBnClickedButton3()
{
	// TODO: Previous Record
	CString var_name,var_id,var_sh,var_sa,var_dep;
	CEmpTable recset(&database);
	CString SqlString("SELECT * FROM EmpTable");
	short col_index = 0;
	rec_index--;
		if(rec_index == 0)
			rec_index =rc;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.SetAbsolutePosition(rec_index);
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dep);
	recset.GetFieldValue(col_index+4,var_sh);
	recset.GetFieldValue(col_index+5,var_sa);
	EID->SetWindowText(var_id);
	ENA->SetWindowText(var_name);
	EWO->SetWindowText(var_sh);
	ESA->SetWindowText(var_sa);
	EDE->SetWindowText(var_dep);
	
}


void CEmpEdit::OnBnClickedButton5()
{
	// TODO: Add
	CString SqlString,s1;
	CString var_name,var_id,var_sh,var_sa,var_dep;
	// ( [Employee ID], [Employee Name], [Deprtment], [Shift], [Salary]) 
//	int s;
	s1.Format("INSERT INTO EmpTable ( [Employee ID], [Employee Name], [Deprtment], [Shift], [Salary] )  VALUES ( ");
	int flg=0;
	EID->GetWindowText(var_id);
	ENA->GetWindowText(var_name);
	EWO->GetWindowText(var_sh);
	ESA->GetWindowText(var_sa);
	EDE->GetWindowText(var_dep);
	
	//int p=_ttoi(var_price);
	CString coma(", ");
	CString CB(" );");
	CString Quo("'");
	CString Nu(" NULL ,");
	SqlString=s1+Quo+var_id+Quo+coma+Quo+var_name+Quo+coma+Quo+var_dep+Quo+coma+Quo+var_sh+Quo+coma+var_sa+CB;
	
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
	



void CEmpEdit::OnBnClickedButton6()
{
	// TODO: Update
	CString SqlString,s1;
	CString var_name,var_id,var_sh,var_sa,var_dep,var_Eid;
	int flg=0,col_index=1;
	
	CEmpTable recset(&database);
	
	EID->GetWindowText(var_id);
	ENA->GetWindowText(var_name);
	EWO->GetWindowText(var_sh);
	ESA->GetWindowText(var_sa);
	EDE->GetWindowText(var_dep);
	

	CString coma(", ");
	//CString CB(");");
	CString sc(" ;");
	CString Quo("'");
	CString Ei("  [Employee ID] = ");
	CString De(" , [Deprtment] = ");
	CString Sh(" , [Shift] = ");
	CString Sa(" , [Salary] = ");
	CString Id(" [ID] = ");
	CString sp(" AND ");
	CString wh(" WHERE "); 
	CString Bo(" ( ");
	CString Bc(" ) ");	
		recset.Open(CRecordset::dynaset,_T("SELECT * FROM EmpTable"),CRecordset::readOnly);

		recset.SetAbsolutePosition(rec_index);
		//recset.GetFieldValue(col_index,var_id);
		recset.GetFieldValue(col_index-1,var_Eid);

		
		s1.Format("UPDATE EmpTable SET [Employee Name] = ");

		
		SqlString=s1+Quo+var_name+Quo+De+Quo+var_dep+Quo+Sh+Quo+var_sh+Quo+Sa+var_sa+wh+Id+var_Eid+sc;
		AfxMessageBox(SqlString);
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
	


void CEmpEdit::OnBnClickedButton7()
{
	// TODO: Remove
			CString SqlString;
			CString var_name,var_id,var_sh,var_sa,var_dep,var_Eid;
	
	CEmpTable recset(&database);
	SqlString =  "SELECT * FROM EmpTable";
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::none);
	recset.SetAbsolutePosition(rec_index);
	int col_index=0;
	if(recset.CanUpdate())
	{
		recset.Delete();
		if(rec_index == rc){
			recset.MoveFirst();
		}
		else
			recset.MoveNext();
		AfxMessageBox("Record Successfully deleted!");
		recset.GetFieldValue(col_index+1,var_id);
		recset.GetFieldValue(col_index+2,var_name);
		recset.GetFieldValue(col_index+3,var_dep);
		recset.GetFieldValue(col_index+4,var_sh);
		recset.GetFieldValue(col_index+5,var_sa);
		EID->SetWindowText(var_id);	
		ENA->SetWindowText(var_name);
		EWO->SetWindowText(var_sh);
		ESA->SetWindowText(var_sa);
		EDE->SetWindowText(var_dep);
		rc--;
	
	}
}


BOOL CEmpEdit::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	//AfxMessageBox(_T("1"));
	sDriver = "MICROSOFT ACCESS DRIVER (*.mdb)";
	sFile = "D:\\Employee.mdb";
	sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s",sDriver,sFile);
	TRY
	{
		// Open the database
		database.Open(NULL,false,false,sDsn,false);
		//AfxMessageBox(_T("2"));
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;

	//Initialization
	
	EID=(CEdit *)GetDlgItem(IDC_EDIT1);
	ENA=(CEdit *)GetDlgItem(IDC_EDIT2);
	EDE=(CEdit *)GetDlgItem(IDC_EDIT3);
	EWO=(CEdit *)GetDlgItem(IDC_EDIT4);
	ESA=(CEdit *)GetDlgItem(IDC_EDIT5);
	/*w=0;
	k=w;*/
	//AfxMessageBox(_T("3"));
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_id,var_sh,var_sa,var_dep;

	CEmpTable recset(&database);
	//AfxMessageBox(_T("4"));
	SqlString =  "SELECT * FROM EmpTable";
	 rc = 0;
	short col_index = 0;
	int ind = 0;
	rec_index=1;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	//AfxMessageBox(_T("5"));
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rc++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index);
	//AfxMessageBox(_T("6"));
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dep);
	recset.GetFieldValue(col_index+4,var_sh);
	recset.GetFieldValue(col_index+5,var_sa);
	EID->SetWindowText(var_id);
	ENA->SetWindowText(var_name);
	EWO->SetWindowText(var_sh);
	ESA->SetWindowText(var_sa);
	EDE->SetWindowText(var_dep);
	//AfxMessageBox(_T("7"));
	return TRUE;
}


void CEmpEdit::OnBnClickedCancel()
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
