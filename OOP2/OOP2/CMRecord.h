// CMRecord.h : Declaration of the CMRecord

#pragma once
#include "afxdb.h"

// code generated on 28 October 2014, 02:12

class CMRecord : public CRecordset
{
public:
	CMRecord(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMRecord)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_StartersS_ID;
	CStringW	m_StartersS_Item;
	long	m_StartersPrice;
	long	m_TandoorT_ID;
	CStringW	m_TandoorT_Item;
	long	m_TandoorPrice;
	long	m_VeggieV_ID;
	CStringW	m_VeggieV_Item;
	long	m_VeggiePrice;

// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


