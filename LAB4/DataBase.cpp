#include "stdafx.h"
#include "DataBase.h"


DataBase::DataBase()
{
	Book bookPrototype;
	bookPrototype.SetName(L"����� �����");
	Books.SetPrototype(bookPrototype);
}


DataBase::~DataBase()
{
}
