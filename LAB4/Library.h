#pragma once
#include "DataBase.h"

// ��������� ��� ����������
class Library
{
	DataBase *_db;	// ��������� �� ��
public:
	CString _adres;
	CString _phone;
	double _penya = 2;

	DataBase& GetDB() { return *_db; }
	int FindBookListIndex(CString bookName);	// ���������� ������ ����� � ������
	Library();
	~Library();
};

