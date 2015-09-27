// MLogin.cpp : implementation file
//

#include "stdafx.h"
#include "MLogin.h"
#include "afxdialogex.h"


// CMLogin dialog

IMPLEMENT_DYNAMIC(CMLogin, CDialog)

CMLogin::CMLogin(LPCTSTR lpszTemplateName, CWnd *pParentWnd)
	: CDialog(lpszTemplateName,pParentWnd)
{

}

CMLogin::~CMLogin()
{
}

void CMLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_EDIT1, Login);
//	DDX_Control(pDX, IDC_EDIT2, Pwd);
}


BEGIN_MESSAGE_MAP(CMLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CMLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CMLogin message handlers


void CMLogin::OnBnClickedOk()
{
	CString L("admin");
	CString P("admin");
	CString LID,PWD;
	// TODO: Add your control notification handler code here
	Login=(CEdit *)GetDlgItem(IDC_EDIT1);
	Pwd=(CEdit *)GetDlgItem(IDC_EDIT2);
	Login->GetWindowTextA(LID);
	Pwd->GetWindowText(PWD);
	if (LID == L && PWD == P){
		MessageBox(_T("Login Successful !!"),_T("Login"));
		 IL = true;}
	else
	{
		MessageBox(_T("Login UnSuccessful !! Try Again"),_T("Login"));
		IL= false;
	}
	CDialog::OnOK();
}
