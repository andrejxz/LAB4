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