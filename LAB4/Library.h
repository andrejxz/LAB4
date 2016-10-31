#pragma once
#include "DataBase.h"
#include <list>
#include "GiveSummary.h"

// ��������� ��� ����������
class Library
{
	DataBase *_db;	// ��������� �� ��
public:
	CString _adres;
	CString _phone;
	double _penya = 2;

	Library();
	~Library();

	DataBase& GetDB() { return *_db; }
	int FindBookListIndex(CString bookName);	// ���������� ������ ����� � ������
	std::list<GiveSummary> GetOverdue();		// ���������� ���������� ��� ���� ���������
	std::list<GiveSummary> GetDeptors();		// ���������� ������ ���� ���������
};

