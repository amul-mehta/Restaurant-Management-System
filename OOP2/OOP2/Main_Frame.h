#pragma once
#include "afxwin.h"
#include "App.h"
#include "Order.h"
#include "resource.h"
#include "MenuView.h"
#include "MLogin.h"
#include "stdafx.h"
#include "MenuEdit.h"
#include "EmpView.h"
#include "EmpEdit.h"
#include "AboutUs.h"
class Main_Frame :
	public CFrameWnd
{
public:
	Main_Frame(void);
	~Main_Frame(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuView(void);
	afx_msg  void OnMenuEdit(void);
	afx_msg void OnStaffView(void);
	afx_msg void OnStaffEdit(void);
	afx_msg void OnOrder(void);
	afx_msg void OnLogin(void);
public:
	bool IsLogin;
	afx_msg void OnAboutUs(void);
};

//bool Main_Frame:: IsLogin;