// Order.cpp : implementation file
//

#include "stdafx.h"
#include "Order.h"
#include "afxdialogex.h"
#include "resource.h"
#include "CMenuRecord.h"


// COrder dialog

IMPLEMENT_DYNAMIC(COrder, CDialog)

COrder::COrder(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
	, R_Main(0)
	, R_Tandoor(0)
	, gt(0)
{

}

COrder::~COrder()
{
}

void COrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST1, menu_list);
	//	DDX_Control(pDX, IDC_LIST2, Order_List);
	//	DDX_Control(pDX, IDC_BUTTON1, Add_Order);
	//	DDX_Control(pDX, IDC_BUTTON2, Delete_Order);
	//	DDX_Control(pDX, IDC_BUTTON3, Calc);
	//	DDX_Control(pDX, IDC_RADIO1, R_Starters);
//	DDX_Control(pDX, IDC_LIST3, menu_price);
//	DDX_Control(pDX, IDC_LIST4, order_price);
}


BEGIN_MESSAGE_MAP(COrder, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &COrder::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &COrder::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &COrder::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &COrder::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COrder::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &COrder::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &COrder::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &COrder::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &COrder::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, &COrder::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// COrder message handlers


BOOL COrder::OnInitDialog(void)
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
	
	menu_list=(CListBox *)GetDlgItem(IDC_LIST1);
	menu_price=(CListBox *)GetDlgItem(IDC_LIST3);
	order_price=(CListBox *)GetDlgItem(IDC_LIST4);
	Order_List=(CListBox*)GetDlgItem(IDC_LIST2);
	Add_Order=(CButton*) GetDlgItem(IDC_BUTTON1);
	Delete_Order=(CButton*)GetDlgItem(IDC_BUTTON2) ;
	Calc=(CButton*)GetDlgItem(IDC_BUTTON1) ;
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
		menu_list->InsertString(ind,var_name);
		menu_price->InsertString(ind,var_price);
		p1[ind]=_ttoi(var_price);
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


void COrder::OnBnClickedRadio1()
{

	// Starters
	cur_sel=1;
	//AfxMessageBox(_T("Starters"));

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
	menu_list->ResetContent();
	menu_price->ResetContent();
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_list->InsertString(ind,var_name);
		menu_price->InsertString(ind,var_price);
		p1[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


void COrder::OnBnClickedRadio2()
{
	// MainCourse
	cur_sel=2;
	//AfxMessageBox(_T("Main Course"));
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
	menu_list->ResetContent();
	menu_price->ResetContent();
		
	for(int i=0;i<rowcount;i++)
	{
		recset.GetFieldValue(col_index+1,var_name);
		recset.GetFieldValue(col_index+2,var_price);
		menu_list->InsertString(ind,var_name);
		menu_price->InsertString(ind,var_price);
		p2[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


void COrder::OnBnClickedRadio3()
{
	// Tandoor
	cur_sel=3;
	//AfxMessageBox(_T("Tandoor"));
	CString SqlString;
	CString var_name,var_price;

	CMenuRecord recset(&database);
	
	SqlString =  "SELECT * FROM Tandoor";
	int rowcount = 0;
	short col_index = 0;
	int ind = 0;

	recset.Open(CRecordset::dynaset,SqlString,CRecordset::readOnly);
	recset.MoveFirst();
	menu_list->ResetContent();
	menu_price->ResetContent();
		
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
		menu_list->InsertString(ind,var_name);
		menu_price->InsertString(ind,var_price);
		p3[ind]=_ttoi(var_price);
		ind++;
		recset.MoveNext();
	}
}


void COrder::OnBnClickedButton1()
{
	// Add to Order
	int n;
	CString temp,tempm;
	n=menu_list->GetCurSel();
	if(n != LB_ERR){
	ord[w][0]=n;//What it is
	ord[w][1]=cur_sel;//Which Category It Belongs
	menu_list->GetText(n,temp);
	menu_price->GetText(n,tempm);
	Order_List->InsertString(k,temp);
	order_price->InsertString(k,tempm);
	w++;
	k++;}
	else{
		AfxMessageBox(_T("Please Select An Item First"));
	}
}


void COrder::OnBnClickedButton2()
{
	//Delete From Order
	int n;
	CString temp;
	n=Order_List->GetCurSel();
	if(n!= LB_ERR){
	ord[n][0]=-1;
	ord[n][1]=-1;
	Order_List->DeleteString(n);
	order_price->DeleteString(n);
	k--;}
	else{
		AfxMessageBox(_T("Please Select An Item First"));
	}
}	

void COrder::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	COrder::OnBnClickedButton3();
	MessageBox(_T("Thank You For Ordering With Us !! \n Have A Nice Day !! "),_T("Your Order Will Be Ready Soon !!"));
	database.Close();
	if(!(database.IsOpen()))
	{
		AfxMessageBox("Database Closed");
		//AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
	}
	else
		AfxMessageBox("Error Closing Database");
	CDialog::OnOK();
}


void COrder::OnBnClickedButton3()
{
	int total=0;
	
	// TODO: Calculate Bill
	/*CString SqlString1,SqlString2,SqlString3;
	//CString ;
	CMenuRecord recset1(&database);
	CMenuRecord recset2(&database);
	CMenuRecord recset3(&database);
	
	SqlString1 =  "SELECT * FROM Starters";
	SqlString2 =  "SELECT * FROM Veggie";
	SqlString3 =  "SELECT * FROM Tandoor";
	
	/*int rowcount = 0;
	short col_index = 0;
	int ind = 0;
	recset1.Open(CRecordset::dynaset,SqlString1,CRecordset::readOnly);
	recset2.Open(CRecordset::dynaset,SqlString2,CRecordset::readOnly);
	recset3.Open(CRecordset::dynaset,SqlString3,CRecordset::readOnly);
	
	recset1.MoveFirst();
	recset2.MoveFirst();
	recset3.MoveFirst();*/
	
	for(int i=0;i<w;i++)
	{
		if (ord[i][1]==1)
		{
			total+=p1[ord[i][0]];
		//recset1.SetAbsolutePosition(ord[w][0]);
		//recset.GetFieldValue(col_index+1,pr);

		}
		else if (ord[i][1]==2)
		{
		//recset2.SetAbsolutePosition(ord[w][0]);
			total+=p2[ord[i][0]];
		}
		else if (ord[i][1]==3)
		{
		//recset3.SetAbsolutePosition(ord[w][0]);
			total+=p3[ord[i][0]];
		}
	}
	CString t1("Your Total Bill is :\n");
	CString t2("\tBasic Total : ");
	CString t3;
	t3.Format(_T("%d\n"),total);
	CString t4("\tService Tax @ 12.5% : ");
	float st= float(total)*0.125;
	CString t5;
	t5.Format(_T("%4f \n"),st);
	CString t6("\n\tGrand Total : ");
	gt=st+total;
	CString t7;
	t7.Format(_T("%5f\n"),gt);
	CString fin;
	fin=t1+t2+t3+t4+t5+t6+t7;
	MessageBox(fin,_T("Total Bill Ammount"));
}


void COrder::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


void COrder::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	int k=menu_list->GetTopIndex();
	menu_price->SetTopIndex(k);
	int s=menu_list->GetCurSel();
	menu_price->SetCurSel(s);
	
}


void COrder::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
	int k=Order_List->GetTopIndex();
	order_price->SetTopIndex(k);
	int s=Order_List->GetCurSel();
	order_price->SetCurSel(s);
	
}
