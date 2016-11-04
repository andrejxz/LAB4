#pragma once
#include "stdafx.h"
#include <string>
#include "TableRow.h"

// описывает одну книгу
class Book : public TableRow
{
	CString _name;				// название книги
	CString _author;			// автор
	int _year = 0;				// год издания
	double _cost = 0;			// цена книги
	unsigned _count = 0;		// число экземпляров
	unsigned _giveCount = 0;	// число выданых экземпляров
public:

	CString GetName() const { return _name; }
	CString GetAuthor() const { return _author; }
	int GetYear() const { return _year; }
	double GetCost() const { return _cost; }
	unsigned GetCount() const { return _count; }
	unsigned GetGiveCount() const { return _giveCount; }

	void SetAll(CString name, CString author, int year, float cost, unsigned count, unsigned giveCount);
	void SetName(CString name) { _name = name; }
	void SetAuthor(CString author) { _author = author; }
	void SetYear(int year) { _year = year; }
	void SetCost(double cost) { _cost = cost; }
	void SetCount(unsigned count) { _count = count; }
	void SetGiveCount(unsigned giveCount) { _giveCount = giveCount; }

	virtual CString ToString()
	{
		CString ID;
		ID.Format(_T("%u"), this->GetId());
		return ID + L". " + GetName();
	}
};

