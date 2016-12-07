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
	db.Books.Dederialize(is);
	db.Gives.Dederialize(is);
	db.Readers.Dederialize(is);
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