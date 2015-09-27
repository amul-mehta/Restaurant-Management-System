#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"
#include "EmpTable.h"


// CEmpEdit dialog

class CEmpEdit : public CDialog
{
	DECLARE_DYNAMIC(CEmpEdit)
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;
	int rec_index;
	

public:
	CEmpEdit(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CEmpEdit();

// Dialog Data
	enum { IDD = IDD_EMPEDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	BOOL OnInitDialog(void);
	CEdit* EID;
	CEdit *ENA;
	CEdit* EDE;
	CEdit *EWO;
	CEdit* ESA;
	int rc;
	afx_msg void OnBnClickedCancel();
};
