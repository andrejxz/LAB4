#pragma once
#include "stdafx.h"
#include "TableRow.h"
#include <string>
#include "Serializer.h"

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

template<>
void Serialize<Reader>(std::ostream &os, Reader& value);
template<>
Reader Deserialize<Reader>(std::istream &is);