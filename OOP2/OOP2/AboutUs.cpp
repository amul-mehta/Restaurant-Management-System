// AboutUs.cpp : implementation file
//

#include "stdafx.h"
#include "AboutUs.h"
#include "afxdialogex.h"


// CAboutUs dialog

IMPLEMENT_DYNAMIC(CAboutUs, CDialog)

CAboutUs::CAboutUs(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
{

}

CAboutUs::~CAboutUs()
{
}

void CAboutUs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutUs, CDialog)
END_MESSAGE_MAP()


// CAboutUs message handlers
