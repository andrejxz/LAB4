#include "stdafx.h"
#include "Book.h"

void Book::SetAll(CString name, CString author, int year, float cost, unsigned count, unsigned giveCount)
{
	SetName(name);
	SetAuthor(author);
	SetYear(year);
	SetCost(cost);
	SetCount(count);
	SetGiveCount(giveCount);
}

template<>
void Serialize<Book>(std::ostream &os, Book& value)
{
	auto id = value.GetId();
	Serialize(os, id);
	auto name = value.GetName();
	Serialize(os, name);
	auto author = value.GetAuthor();
	Serialize(os, author);
	auto year = value.GetYear();
	Serialize(os, year);
	auto cost = value.GetCost();
	Serialize(os, cost);
	auto count = value.GetCount();
	Serialize(os, count);
	auto giveCount = value.GetGiveCount();
	Serialize(os, giveCount);
}
template<>
Book Deserialize<Book>(std::istream &is)
{
	Book book;
	book.SetId(Deserialize<unsigned>(is));
	book.SetName(Deserialize<CString>(is));
	book.SetAuthor(Deserialize<CString>(is));
	book.SetYear(Deserialize<int>(is));
	book.SetCost(Deserialize<double>(is));
	book.SetCount(Deserialize<unsigned>(is));
	book.SetGiveCount(Deserialize<unsigned>(is));
	return book;
}