#pragma once
#include "stdafx.h"
#include "TableRow.h"
#include "Date.h"

// описывает одну выдачу
class Give : public TableRow
{
	unsigned _reader_id = 0;
	unsigned _book_id = 0;
	unsigned _copyNumber = 0;
	Date _giveDate;
	Date _returnDate;
public:

	unsigned GetReaderId() { return _reader_id; }
	unsigned GetBookId() { return _book_id; }
	unsigned GetCopyNumber() { return _copyNumber; }
	Date GetGiveDate() { return _giveDate; }
	Date GetReturnDate() { return _returnDate; }

	void SetReaderId(unsigned resder_id) { _reader_id = resder_id; }
	void SetBookId(unsigned book_id) { _book_id = book_id; }
	void SetCopyNumber(unsigned copyNumber) { _copyNumber = copyNumber; }
	void SetGiveDate(Date giveDate) { _giveDate = giveDate; }
	void SetReturnDate(Date returnDate) { _returnDate = returnDate; }
	virtual CString ToString() 
	{
		wchar_t str[80];
		CString ID;
		ID.Format(_T("%u"), this->GetId());
		return ID + L". " + _itow(GetBookId(), str, 10);;
	}
};

