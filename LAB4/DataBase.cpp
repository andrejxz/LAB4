#include "stdafx.h"
#include "DataBase.h"

DataBase::DataBase()
{
}


DataBase::~DataBase()
{
}

template<>
void Serialize<DataBase>(std::ostream &os, DataBase& value)
{
	value.Books.Serialize(os);
	value.Gives.Serialize(os);
	value.Readers.Serialize(os);
}

template<>
DataBase Deserialize<DataBase>(std::istream &is)	// TODO: сделать десериализацию таблицы - см ее сериализацию
{
	DataBase db;
	db.Books = Deserialize<Table<Book>>(is);
	db.Gives = Deserialize<Table<Give>>(is);
	db.Readers = Deserialize<Table<Reader>>(is);
	return db;
}


/*void DataBase::Serialize(std::ostream &os)
{
 	::Serialize(os, Books);
 	::Serialize(os, Gives);
 	::Serialize(os, Readers);
}
void Deserialize(std::istream &is)
{

}*/