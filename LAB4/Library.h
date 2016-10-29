#pragma once
#include "DataBase.h"

// описывает всю библиотеку
class Library
{
	DataBase *_db;	// указатель на Ѕƒ
public:
	CString _adres;
	CString _phone;
	double _penya = 2;

	DataBase& GetDB() { return *_db; }
	int FindBookListIndex(CString bookName);	// возвращает индекс книги в списке
	Library();
	~Library();
};

