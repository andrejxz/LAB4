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
	float _cost = 0;			// цена книги
	unsigned _count = 0;		// число экземпляров
	unsigned _giveCount = 0;	// число выданых экземпляров
public:

	CString GetName() { return _name; }
	CString GetAuthor() { return _author; }
	int GetYear() { return _year; }
	float GetCost() { return _cost; }
	unsigned GetCount() { return _count; }
	unsigned GetGiveCount() { return _giveCount; }

	void SetAll(CString name, CString author, int year, float cost, unsigned count, unsigned giveCount);
	void SetName(CString name) { _name = name; }
	void SetAuthor(CString author) { _author = author; }
	void SetYear(int year) { _year = year; }
	void SetCost(float cost) { _cost = cost; }
	void SetCount(unsigned count) { _count = count; }
	void SetGiveCount(unsigned giveCount) { _giveCount = giveCount; }

	virtual CString ToString() { return GetName(); }
};

