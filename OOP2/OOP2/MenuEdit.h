#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"
#include "CMenuRecord.h"

// CMenuEdit dialog

class CMenuEdit : public CDialog
{
	DECLARE_DYNAMIC(CMenuEdit)
private:
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;

	int rec_index1;
	int rec_index2;
	int rec_index3;

public:
	CMenuEdit(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CMenuEdit();

// Dialog Data
	enum { IDD = IDD_MENUEDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOk();
	BOOL OnInitDialog(void);
	CButton *Add_R;
	CButton *Delete_R;
	CButton *R_Starters;
	CButton *R_Main;
	CButton *R_Tandoor;
	int cur_sel;
	int w,k,rc1,rc2,rc3;
	CEdit *item;
	CEdit *price;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton6();
	int s;
	afx_msg void OnBnClickedCancel();
};
