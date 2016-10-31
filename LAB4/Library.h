#pragma once
#include "DataBase.h"
#include <list>
#include "GiveSummary.h"

// описывает всю библиотеку
class Library
{
	DataBase *_db;	// указатель на БД
public:
	CString _adres;
	CString _phone;
	double _penya = 2;

	Library();
	~Library();

	DataBase& GetDB() { return *_db; }
	int FindBookListIndex(CString bookName);	// возвращает индекс книги в списке
	std::list<GiveSummary> GetOverdue();		// возвращает информацию обо всех просроках
	std::list<GiveSummary> GetDeptors();		// возвращает список всех должников
};

