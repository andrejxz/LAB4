#pragma once
#include "stdafx.h"
#include "Table.h"
#include "Book.h"
#include "Give.h"
#include "Reader.h"

// ��������� ��
class DataBase
{
public:
	Table<Book> Books;			// ������� ����
	Table<Give> Gives;			// ������� �������� ����
	Table<Reader> Readers;		// ������� ���������

	DataBase();
	~DataBase();
};

