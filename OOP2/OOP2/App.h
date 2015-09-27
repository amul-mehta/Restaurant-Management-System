#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxwin.h"
#include "resource.h"
class CApp :
	public CWinApp
{
public:
	CApp(void);
	~CApp(void);
	BOOL InitInstance(void);
};

