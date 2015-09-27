// EmpTable.h : Implementation of the CEmpTable class



// CEmpTable implementation

// code generated on 27 October 2014, 05:00

#include "stdafx.h"
#include "EmpTable.h"
IMPLEMENT_DYNAMIC(CEmpTable, CRecordset)

CEmpTable::CEmpTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_EmployeeID = L"";
	m_EmployeeName = L"";
	m_Deprtment = L"";
	m_Shift = L"";
	m_Salary = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CEmpTable::GetDefaultConnect()
{
	return _T("DSN=Employee;DBQ=D:\\Employee.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CEmpTable::GetDefaultSQL()
{
	return _T("[EmpTable]");
}

void CEmpTable::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Employee ID]"), m_EmployeeID);
	RFX_Text(pFX, _T("[Employee Name]"), m_EmployeeName);
	RFX_Text(pFX, _T("[Deprtment]"), m_Deprtment);
	RFX_Text(pFX, _T("[Shift]"), m_Shift);
	RFX_Long(pFX, _T("[Salary]"), m_Salary);

}
/////////////////////////////////////////////////////////////////////////////
// CEmpTable diagnostics

#ifdef _DEBUG
void CEmpTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEmpTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


