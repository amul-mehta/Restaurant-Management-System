#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "afxwin.h"
#include "Main_Frame.h"


// CAboutUs dialog

class CAboutUs : public CDialog
{
	DECLARE_DYNAMIC(CAboutUs)

public:
	CAboutUs(LPCTSTR lpszTemplateName, CWnd* pParentWnd =NULL);   // standard constructor
	virtual ~CAboutUs();

// Dialog Data
	enum { IDD = IDD_ABOUTUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
