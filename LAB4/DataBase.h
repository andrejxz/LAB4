#pragma once
#include "stdafx.h"
#include "Table.h"
#include "Book.h"
#include "Give.h"
#include "Reader.h"
#include "Journal.h"
#include <iostream>
#include "Serializer.h"

// ��������� ��
class DataBase
{
public:
	Table<Book> Books;			// ������� ����
	Table<Give> Gives;			// ������� �������� ����
	Table<Reader> Readers;		// ������� ���������
	Table<Journal> Journals;	// ������� ��������

	DataBase();
	~DataBase();
};

template<>
void Serialize<DataBase>(std::ostream &os, DataBase& value);
template<>
DataBase Deserialize<DataBase>(std::istream &is);