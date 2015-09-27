#include "Main_Frame.h"


Main_Frame::Main_Frame(void)
{
	Create(NULL, "Restaurant Management System", WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
	IsLogin=false;
}


Main_Frame::~Main_Frame(void)
{
}
BEGIN_MESSAGE_MAP(Main_Frame,CFrameWnd)
	ON_COMMAND(ID_MENU_VIEW,OnMenuView)
	ON_COMMAND(ID_MENU_EDIT,OnMenuEdit)
	ON_COMMAND(ID_STAFF_VIEW,OnStaffView)
	ON_COMMAND(ID_STAFF_EDIT,OnStaffEdit)
	ON_COMMAND(ID_CUSTOMER_PLACEORDER,OnOrder)
	ON_COMMAND(ID_LOGIN_MANAGER,OnLogin)
	ON_COMMAND(ID_ABOUTUS,OnAboutUs)

END_MESSAGE_MAP()

afx_msg void Main_Frame::OnMenuView(void)
{
	if(IsLogin == true){
		CMenuView cdlg(MAKEINTRESOURCE(IDD_MENUVIEW),this);
		cdlg.DoModal();
	
	}
	else{
		MessageBox(_T("Please Login First !!"),_T("Error"));}
	
	//return afx_msg void();
}


afx_msg  void Main_Frame::OnMenuEdit(void)
{
	if(IsLogin == true){
		CMenuEdit cdlg(MAKEINTRESOURCE(IDD_MENUEDIT),this);
		cdlg.DoModal();
	}
	else{
		MessageBox(_T("Please Login First !!"),_T("Error"));}
	//return afx_msg  void();
}


afx_msg void Main_Frame::OnStaffView(void)
{
	if(IsLogin == true){
		CEmpView cdlg(MAKEINTRESOURCE(IDD_EMPVIEW),this);
		cdlg.DoModal();
	}
	else{
		MessageBox(_T("Please Login First !!"),_T("Error"));}
	
	//return afx_msg void();
}


afx_msg void Main_Frame::OnStaffEdit(void)
{
	if(IsLogin == true){
		CEmpEdit cdlg(MAKEINTRESOURCE(IDD_EMPEDIT),this);
		cdlg.DoModal();
	
	}
	else{
		MessageBox(_T("Please Login First !!"),_T("Error"));}
	
	//return afx_msg void();
}


afx_msg void Main_Frame::OnOrder(void)
{
	COrder cdlg(MAKEINTRESOURCE(IDD_ORDER),this);
    cdlg.DoModal();
	//return afx_msg void();
}


afx_msg void Main_Frame::OnLogin(void)
{
	CMLogin cdlg(MAKEINTRESOURCE(IDD_MLOGIN),this);
    cdlg.DoModal();
	IsLogin=cdlg.IL;
	//return afx_msg void();
}


afx_msg void Main_Frame::OnAboutUs(void)
{
	CAboutUs cdlg(MAKEINTRESOURCE(IDD_ABOUTUS),this);
    cdlg.DoModal();

}
