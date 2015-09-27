#include "App.h"
#include "Main_Frame.h"



CApp::CApp(void)
{
}


CApp::~CApp(void)
{
}


BOOL CApp::InitInstance(void)
{
	m_pMainWnd= new Main_Frame; //
	m_pMainWnd->ShowWindow(m_nCmdShow);//
	m_pMainWnd->UpdateWindow();
//AfxMessageBox("Hi", MB_YESNOCANCEL);
return TRUE;
}


CApp app;
