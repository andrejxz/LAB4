#pragma once
#include "stdafx.h"
#include "Table.h"
#include "Book.h"
#include "Give.h"
#include "Reader.h"
#include "Journal.h"

// описывает БД
class DataBase
{
public:
	Table<Book> Books;			// таблица книг
	Table<Give> Gives;			// тиблица выданных книг
	Table<Reader> Readers;		// таблица читателей
	Table<Journal> Journals; 

	DataBase();
	~DataBase();
};

