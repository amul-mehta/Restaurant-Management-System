// CMRecord.h : Implementation of the CMRecord class



// CMRecord implementation

// code generated on 28 October 2014, 02:12

#include "stdafx.h"
#include "CMRecord.h"
IMPLEMENT_DYNAMIC(CMRecord, CRecordset)

CMRecord::CMRecord(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_StartersS_ID = 0;
	m_StartersS_Item = L"";
	m_StartersPrice = 0;
	m_TandoorT_ID = 0;
	m_TandoorT_Item = L"";
	m_TandoorPrice = 0;
	m_VeggieV_ID = 0;
	m_VeggieV_Item = L"";
	m_VeggiePrice = 0;
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CMRecord::GetDefaultConnect()
{
	return _T("DSN=Menu;DBQ=D:\\Menu4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMRecord::GetDefaultSQL()
{
	return _T("[Starters],[Tandoor],[Veggie]");
}

void CMRecord::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Starters].[S_ID]"), m_StartersS_ID);
	RFX_Text(pFX, _T("[Starters].[S_Item]"), m_StartersS_Item);
	RFX_Long(pFX, _T("[Starters].[Price]"), m_StartersPrice);
	RFX_Long(pFX, _T("[Tandoor].[T_ID]"), m_TandoorT_ID);
	RFX_Text(pFX, _T("[Tandoor].[T_Item]"), m_TandoorT_Item);
	RFX_Long(pFX, _T("[Tandoor].[Price]"), m_TandoorPrice);
	RFX_Long(pFX, _T("[Veggie].[V_ID]"), m_VeggieV_ID);
	RFX_Text(pFX, _T("[Veggie].[V_Item]"), m_VeggieV_Item);
	RFX_Long(pFX, _T("[Veggie].[Price]"), m_VeggiePrice);

}
/////////////////////////////////////////////////////////////////////////////
// CMRecord diagnostics

#ifdef _DEBUG
void CMRecord::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMRecord::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


