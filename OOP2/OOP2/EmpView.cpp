// EmpView.cpp : implementation file
//

#include "stdafx.h"
#include "EmpView.h"
#include "afxdialogex.h"


// CEmpView dialog

IMPLEMENT_DYNAMIC(CEmpView, CDialog)

CEmpView::CEmpView(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
{

}

CEmpView::~CEmpView()
{
}

void CEmpView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEmpView, CDialog)
//	ON_EN_CHANGE(IDC_EDITID2, &CEmpView::OnEnChangeEditid2)
	ON_BN_CLICKED(IDC_BUTNEXT, &CEmpView::OnBnClickedButnext)
	ON_BN_CLICKED(IDC_BUTPREV, &CEmpView::OnBnClickedButprev)
	ON_BN_CLICKED(IDCANCEL, &CEmpView::OnBnClickedCancel)
END_MESSAGE_MAP()


// CEmpView message handlers


BOOL CEmpView::OnInitDialog(void)
{
	CDialog::OnInitDialog();

	sDriver = "MICROSOFT ACCESS DRIVER (*.mdb)";
	sFile = "D:\\Employee.mdb";
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
	
	id=(CEdit *)GetDlgItem(IDC_EDITID);
	name=(CEdit *)GetDlgItem(IDC_EDITNAME);
	dept=(CEdit *)GetDlgItem(IDC_EDITDEPT);
	shift=(CEdit *)GetDlgItem(IDC_EDITSHIFT);
	sal=(CEdit *)GetDlgItem(IDC_EDITSAL);
	M_Next=(CButton*)GetDlgItem(IDC_BUTNEXT) ;
	M_Prev=(CButton *)GetDlgItem(IDC_BUTPREV);
	
	
	// Creating Recordset
	CString var_id,var_name,var_dept,var_shift,var_sal;
	CString SqlString;
//	CString var_name,var_price;

	CEmpTable recset(&database);
	
	SqlString =  "SELECT * FROM EmpTable";
	short col_index = 0;
	int ind = 0;
	rec_index=1;
	rc=0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		while(!recset.IsEOF())
	{
		rc++;
		recset.MoveNext();
	}
	recset.SetAbsolutePosition(rec_index);
	
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dept);
	recset.GetFieldValue(col_index+4,var_shift);
	recset.GetFieldValue(col_index+5,var_sal);
	id->SetWindowText(var_id);
	name->SetWindowText(var_name);
	dept->SetWindowText(var_dept);
	shift->SetWindowText(var_shift);
	sal->SetWindowText(var_sal);

	return TRUE;
}

/*void CEmpView::OnEnChangeEditid2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}*/


void CEmpView::OnBnClickedButnext()
{
	// TODO: Add your control notification handler code here
	CString SqlString;
	CString var_id,var_name,var_dept,var_shift,var_sal;
	rec_index++;
	CEmpTable recset(&database);
	SqlString =  "SELECT * FROM EmpTable";
	short col_index = 0;
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.SetAbsolutePosition(rec_index);
	if(recset.IsEOF())
	{
		rec_index=1;
		recset.SetAbsolutePosition(rec_index);
	}
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dept);
	recset.GetFieldValue(col_index+4,var_shift);
	recset.GetFieldValue(col_index+5,var_sal);
	
	id->SetWindowText(var_id);
	name->SetWindowText(var_name);
	dept->SetWindowText(var_dept);
	shift->SetWindowText(var_shift);
	sal->SetWindowText(var_sal);

	
}


void CEmpView::OnBnClickedButprev()
{
	// TODO: Add your control notification handler code here
	CString SqlString;
	CString var_id,var_name,var_dept,var_shift,var_sal;
	rec_index--;
	CEmpTable recset(&database);
	SqlString =  "SELECT * FROM EmpTable";
	short col_index = 0;
	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.SetAbsolutePosition(rec_index);
	if(rec_index==0)
	{
		rec_index=rc;
		recset.SetAbsolutePosition(rec_index);

		//recset.MoveLast();
	}
	recset.GetFieldValue(col_index+1,var_id);
	recset.GetFieldValue(col_index+2,var_name);
	recset.GetFieldValue(col_index+3,var_dept);
	recset.GetFieldValue(col_index+4,var_shift);
	recset.GetFieldValue(col_index+5,var_sal);
	
	id->SetWindowText(var_id);
	name->SetWindowText(var_name);
	dept->SetWindowText(var_dept);
	shift->SetWindowText(var_shift);
	sal->SetWindowText(var_sal);

	
}


void CEmpView::OnBnClickedCancel()
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
