#pragma once
#include "stdafx.h"
#include "Table.h"
#include "Book.h"
#include "Give.h"
#include "Reader.h"

// описывает БД
class DataBase
{
public:
	Table<Book> Books;			// таблица книг
	Table<Give> Gives;			// тиблица выданных книг
	Table<Reader> Readers;		// таблица читателей

	DataBase();
	~DataBase();
};

