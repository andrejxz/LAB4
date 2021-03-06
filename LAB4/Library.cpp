#include "stdafx.h"
#include "Library.h"
#include <time.h>


Library::Library()
{
	_db = new DataBase();
}

Library::~Library()
{
	delete _db;
}
int Library::FindBookListIndex(CString bookName)					// ���������� ������ ����� � ������
{
	int index = 0;
	for (auto i = GetDB().Books._data.begin(); i != GetDB().Books._data.end();++i,++index) {
		if (i->second.GetName() == bookName) return index;
	}
	return -1;
}
std::list<GiveSummary> Library::GetOverdue()						// ���������� ���������� ��� ���� ���������
{
	std::list<GiveSummary> res;
	time_t rawtime;
	time(&rawtime);
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	for each(auto i in _db->Gives._data) {
		if (i.second.GetBookId() == 0) continue;
		// ����� ���� ��������
		auto date = i.second.GetReturnDate();
		// ���� ���� �������� ���������� �� ����� � ���������
		if (date.GetYear() < timeinfo->tm_year + 1900 ||
			date.GetYear() == timeinfo->tm_year + 1900 && date.GetMonth() < timeinfo->tm_mon + 1 ||
			date.GetYear() == timeinfo->tm_year + 1900 && date.GetMonth() == timeinfo->tm_mon + 1 && date.GetDay() < timeinfo->tm_mday)
			///???
			res.push_back(GiveSummary::Make(i.second, *_db, _penya));
	}
	return res;
}
std::list<GiveSummary> Library::GetDeptors()						// ���������� ������ ���� ���������
{
	std::list<GiveSummary> res;
	auto owd = GetOverdue();
	bool found;
	for each(auto i in owd) {
		// �������� ���� �� ������� � ����������
		found = false;	// ���� �� ������� ��� � ����������
		for each(auto j in res)	// ����� �� ���� ����������� �� ���������
			if (j.GetReader().GetId() == i.GetReader().GetId()) { // ���� j ������� ��� ���� � ����������
				found = true;	// �������, ��� ��������� ��� �������� �� �����
				break;
			}
		if (found) continue;
		// ������ ����� ����� ��������
		GiveSummary summary(i);
		summary._penya = 0;
		for each(auto j in owd) {
			if (j.GetReader().GetId() == i.GetReader().GetId()) 
				summary._penya += j._penya;
		}
		// ������� ��������
		res.push_back(summary);
	}
		
	return res;
}
