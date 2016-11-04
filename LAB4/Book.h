#pragma once
#include "stdafx.h"
#include <string>
#include "TableRow.h"

// ��������� ���� �����
class Book : public TableRow
{
	CString _name;				// �������� �����
	CString _author;			// �����
	int _year = 0;				// ��� �������
	double _cost = 0;			// ���� �����
	unsigned _count = 0;		// ����� �����������
	unsigned _giveCount = 0;	// ����� ������� �����������
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

