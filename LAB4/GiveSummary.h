#pragma once
#include "Give.h"
#include "Book.h"
#include "Reader.h"
#include "DataBase.h"

// возвращает сводные данные о выдаче
class GiveSummary
{
	Give _give;
	Book _book;
	Reader _reader;

	GiveSummary(Give &give, Book book, Reader reader, double penya)
	{
		_give = give;
		_book = book;
		_reader = reader;
		_penya = penya;
	}
public:
	double _penya;		// начисленная пеня
	static Book FindBook(Give &give, DataBase &db)
	{
		for each(auto i in db.Books._data) {
			if (i.second.GetId() == give.GetBookId())
				return i.second;
		}
		throw std::exception("Book not found");
	}
	static Reader FindReader(Give &give, DataBase &db)
	{
		for each(auto i in db.Readers._data) {
			if (i.second.GetId() == give.GetReaderId())
				return i.second;
		}
		throw std::exception("Reader not found");
	}
	static double CalcPenya(Give &give, double dayPenya)
	{
		double res = 0;
		time_t rawtime;
		time(&rawtime);
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);

		int delta;
		delta = give.GetReturnDate().GetYear() - timeinfo->tm_year + 1900;
		res += (delta > 0) ? (delta * 365) : 0;

		delta = give.GetReturnDate().GetMonth() - timeinfo->tm_mon + 1;
		res += (delta > 0) ? (delta * 31) : 0;

		delta = give.GetReturnDate().GetDay() - timeinfo->tm_mday;
		res += (delta > 0) ? delta : 0;

		return res;
	}
	static GiveSummary Make(Give &give, DataBase &db, double dayPenya)
	{
		auto book = FindBook(give, db);
		auto reader = FindReader(give, db);
		double penya = CalcPenya(give, dayPenya);
		return GiveSummary(give, book, reader, penya);
	}

	Give GetGive() { return _give; }
	Book GetBook() { return _book; }
	Reader GetReader() { return _reader; }

	CString ToString()
	{
		//CString str = _itoa(_penya, str,10);
		//return _reader.ToString()+str;
		return _reader.ToString();
	}
};

