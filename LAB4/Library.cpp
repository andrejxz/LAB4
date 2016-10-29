#include "stdafx.h"
#include "Library.h"


Library::Library()
{
	_db = new DataBase();
}


Library::~Library()
{
	delete _db;
}
int Library::FindBookListIndex(CString bookName)	// ���������� ������ ����� � ������
{
	int index = 0;
	for (auto i = GetDB().Books._data.begin(); i != GetDB().Books._data.end();++i,++index) {
		if (i->second.GetName() == bookName) return index;
	}
	return -1;
}
