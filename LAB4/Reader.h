#pragma once
#include "stdafx.h"
#include "TableRow.h"
#include <string>

// описывает читателя
class Reader : public TableRow
{
	CString _fio;
	CString _address;
	CString _phone;
public:

	CString GetFio() { return _fio; }
	CString GetAddress() { return _address; }
	CString GetPhone() { return _phone; }

	void SetFio(CString fio) { _fio = fio; }
	void SetAddress(CString address) { _address = address; }
	void SetPhone(CString phone) { _phone = phone; }
	virtual CString ToString()
	{
		CString ID;
		ID.Format(_T("%u"), this->GetId());
		return ID + L". " + GetFio();
	}
};