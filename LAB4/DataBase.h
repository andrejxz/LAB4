#pragma once
#include "stdafx.h"
#include "Table.h"
#include "Book.h"
#include "Give.h"
#include "Reader.h"
#include "Journal.h"
#include <iostream>
#include "Serializer.h"

// описывает БД
class DataBase
{
public:
	Table<Book> Books;			// таблица книг
	Table<Give> Gives;			// тиблица выданных книг
	Table<Reader> Readers;		// таблица читателей
	Table<Journal> Journals;	// таблица журналов

	DataBase();
	~DataBase();
};

template<>
void Serialize<DataBase>(std::ostream &os, DataBase& value);
template<>
DataBase Deserialize<DataBase>(std::istream &is);