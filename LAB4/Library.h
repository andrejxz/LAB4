#pragma once
#include "DataBase.h"
#include <list>
#include "GiveSummary.h"

// ��������� ��� ����������
class Library
{
	DataBase *_db;	// ��������� �� ��
	CString _name;
	CString _addres;
	CString _phone;
public:
	double _penya = 2;

	Library();
	~Library();

	DataBase& GetDB() { return *_db; }
	CString GetName() { return _name; }
	CString GetAddres() { return _addres;}
	CString GetPhone() { return _phone; }

	void SetName(CString name) { _name = name; }
	void SetAddres(CString addres) { _addres = addres; }
	void SetPhone(CString phone) { _phone = phone; }

	int FindBookListIndex(CString bookName);	// ���������� ������ ����� � ������
	std::list<GiveSummary> GetOverdue();		// ���������� ���������� ��� ���� ���������
	std::list<GiveSummary> GetDeptors();		// ���������� ������ ���� ���������
};

