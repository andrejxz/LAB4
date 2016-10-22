#include "stdafx.h"
#include "DataBase.h"


DataBase::DataBase()
{
	Book bookPrototype;
	bookPrototype.SetName(L"Новая книга");
	Books.SetPrototype(bookPrototype);
}


DataBase::~DataBase()
{
}
