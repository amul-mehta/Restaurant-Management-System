#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"

// CMenuView dialog

class CMenuView : public CDialog
{
	DECLARE_DYNAMIC(CMenuView)
private:
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;


public:
	CMenuView(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CMenuView();

// Dialog Data
	enum { IDD = IDD_MENUVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	BOOL OnInitDialog(void);
	CListBox *menu_view;
	CListBox *price_view;
	CButton *R_Starters;
	CButton *R_Main;
	CButton *R_Tandoor;
	int w;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

