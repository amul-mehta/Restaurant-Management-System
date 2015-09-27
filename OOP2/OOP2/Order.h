#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"


// COrder dialog

class COrder : public CDialog
{
	DECLARE_DYNAMIC(COrder)
private:
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;

	int rec_index;
	
public:
	COrder(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~COrder();

// Dialog Data
	enum { IDD = IDD_ORDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	
public:
	
	BOOL OnInitDialog(void);
	DECLARE_MESSAGE_MAP()
	CListBox *menu_list;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCancel();
	CListBox *Order_List;
	CButton *Add_Order;
	CButton *Delete_Order;
	CButton *Calc;
	CButton *R_Starters;
	CButton *R_Main;
	CButton *R_Tandoor;
	int cur_sel;
	int ord[50][2];
	int w,k;
	int p1[50],p2[50],p3[50];
	afx_msg void OnLbnSelchangeList1();
	CListBox *menu_price;
	CListBox *order_price;
	float gt;
	afx_msg void OnLbnSelchangeList2();
};
