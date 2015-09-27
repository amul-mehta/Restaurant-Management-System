#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"
#include "Main_Frame.h"

// CMLogin dialog

class CMLogin : public CDialog
{
	DECLARE_DYNAMIC(CMLogin)

public:
	CMLogin(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CMLogin();

// Dialog Data
	enum { IDD = IDD_MLOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit *Login;
	CEdit *Pwd;
	bool IL;
};
