#pragma once
#include "Book.h"
#include "Date.h"
#include "Serializer.h"

// ��������� ������
class Journal : public Book
{
	unsigned _countList;		// ���������� ������
	unsigned _num;				// ����� �������
	Date _releaseDate;			// ���� �������

public:
	void SetCountList(unsigned countList) { _countList = countList; }
	void SetNum(unsigned num) { _num = num; }
	void SetReleaseDate(Date releaseDate) { _releaseDate = releaseDate; }


	unsigned GetCountList() { return _countList; }
	unsigned GetNum() { return  _num; }
	Date GetReleaseDate() { return _releaseDate; }

	virtual CString ToString()
	{
		CString ID;
		ID.Format(_T("%u"), this->GetId());
		return ID + L". " + GetName();
	}
};

template<>
void Serialize<Journal>(std::ostream &os, Journal& value);
template<>
Journal Deserialize<Journal>(std::istream &is);
