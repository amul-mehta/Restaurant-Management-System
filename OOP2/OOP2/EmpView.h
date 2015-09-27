#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"
#include "EmpTable.h"

// CEmpView dialog

class CEmpView : public CDialog
{
	DECLARE_DYNAMIC(CEmpView)

	private:
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;

	int rec_index;

public:
	CEmpView(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CEmpView();

// Dialog Data
	enum { IDD = IDD_EMPVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditid2();
	afx_msg void OnBnClickedButnext();

	BOOL OnInitDialog(void);
	CButton *M_Next;
	CButton *M_Prev;
	CEdit *id;
	CEdit *name;
	CEdit *dept;
	CEdit *shift;
	CEdit *sal;
	afx_msg void OnBnClickedButprev();
	int rc;
	afx_msg void OnBnClickedCancel();
};
