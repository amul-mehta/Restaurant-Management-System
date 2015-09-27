// MenuView.cpp : implementation file
//

#include "stdafx.h"
#include "MenuView.h"
#include "afxdialogex.h"
#include "resource.h"
#include "CMenuRecord.h"



// CMenuView dialog

IMPLEMENT_DYNAMIC(CMenuView, CDialog)

CMenuView::CMenuView(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
	, R_Starters(0)
	, R_Main(0)
	, R_Tandoor(0)
{

}

CMenuView::~CMenuView()
{
}

void CMenuView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_LIST1, menu_view);
//	DDX_Control(pDX, IDC_LIST2, price_view);
}


BEGIN_MESSAGE_MAP(CMenuView, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &CMenuView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMenuView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMenuView::OnBnClickedRadio3)
	ON_BN_CLICKED(IDOK, &CMenuView::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMenuView::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMenuView message handlers


void CMenuView::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("Starters"));

	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Starters";
	int rowcount = 0;
	short col_index = 0;
	int ind = 0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rowcount++;
		recset.MoveNext();
	}

	recset.MoveFirst();
	menu_view->ResetContent();
	price_view->ResetContent();
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_view->InsertString(ind,var_name);
		price_view->InsertString(ind,var_price);
		//p1[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


void CMenuView::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("Main Course"));
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Veggie";
	int rowcount = 0;
	short col_index = 0;
	int ind = 0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rowcount++;
		recset.MoveNext();
	}

	recset.MoveFirst();
	menu_view->ResetContent();
	price_view->ResetContent();
		
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_view->InsertString(ind,var_name);
		price_view->InsertString(ind,var_price);
		//p2[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


void CMenuView::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("Tandoor"));
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Tandoor";
	int rowcount = 0;
	short col_index = 0;
	int ind = 0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
	menu_view->ResetContent();
	price_view->ResetContent();
		
	while(!recset.IsEOF())
	{
		rowcount++;
		recset.MoveNext();
	}

	recset.MoveFirst();
		
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_view->InsertString(ind,var_name);
		price_view->InsertString(ind,var_price);
		//p3[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


BOOL CMenuView::OnInitDialog(void)
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
	
	menu_view=(CListBox *)GetDlgItem(IDC_LIST1);
	price_view=(CListBox *)GetDlgItem(IDC_LIST2);
	R_Starters=(CButton*)GetDlgItem(IDC_RADIO1) ;
	R_Main=(CButton *)GetDlgItem(IDC_RADIO2);
	R_Tandoor=(CButton *)GetDlgItem(IDC_RADIO3);
	R_Starters->SetCheck(1);
	//cur_sel=1;
	w=0;
	//k=w;
	
	// Creating Recordset
	
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Starters";
	int rowcount = 0;
	short col_index = 0;
	int ind = 0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
		
	while(!recset.IsEOF())
	{
		rowcount++;
		recset.MoveNext();
	}
	recset.MoveFirst();
		
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_view->InsertString(ind,var_name);
		price_view->InsertString(ind,var_price);
		//p1[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
	/*cust_id = (CEdit *)GetDlgItem(IDC_CUSTID);
	cust_fname = (CEdit *)GetDlgItem(IDC_FNAME);
	cust_lname = (CEdit *)GetDlgItem(IDC_LNAME);
	cust_cno = (CEdit *)GetDlgItem(IDC_CNO);
	cust_eid = (CEdit *)GetDlgItem(IDC_EID);
	cust_nation = (CEdit *)GetDlgItem(IDC_NATION);
	cust_pno = (CEdit *)GetDlgItem(IDC_PNO);
	cust_dlno = (CEdit *)GetDlgItem(IDC_DLNO);
	rec_no = (CEdit *)GetDlgItem(IDC_RECNO);*/

	//ind = 1;
	
	return TRUE;
}


void CMenuView::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void CMenuView::OnBnClickedCancel()
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
