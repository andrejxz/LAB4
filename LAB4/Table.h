#pragma once
#include "stdafx.h"
#include "TableRow.h"
#include <map>
#include <list>
#include <utility>

// ��������� ������� ����� ���������� ����
template<class RowType>
class Table
{
	class IObserver;
	RowType _prototype;					// ��������, ��� �������� ������ ��������
	unsigned _currentId = 0;			// ������� ID ����� ������
	void CheckId(unsigned id)	// ��������� ������� id � ������ ���������� ���� ��� ���
	{
		if (_data.find(id) == _data::end()) throw "�� ������� �������� ������ - ����� ������ ���";
	}
public:
	std::map<unsigned, RowType> _data;	// ��� ������ �������

	void SetPrototype(RowType prototype)
	{
		_prototype = prototype;
		((TableRow&)_prototype).SetId(0);
	}
	
	Table()
	{
	}
	Table(RowType prototype)
	{
		SetPrototype(prototype);
	}

	RowType operator[](unsigned id)	// ���������� ������ �� �� ID
	{
		// ������������
		CheckId(id);
		// ����� ����������
		return _data[id];
	}
	RowType AddNewRow()				// ������� ����� ������ � ������� �� ���������
	{
		return AddNewRow(_prototype);
	}
	RowType AddNewRow(RowType newRow)	// ������� ����� ������ � ������� �� ������ ������
	{
		((TableRow&)newRow).SetId(++_currentId);
		_data.insert(std::make_pair(((TableRow&)newRow).GetId(), newRow));
		// ����� ����������
		return newRow;
	}
	void Remove(unsigned id)
	{
		_data.erase(id);
		for (auto i = Observers.begin();i < Observers.end();++i) i->OnRemoveRow(id);
	}
	void Clear()
	{
		_data.clear();
		for (auto i = Observers.begin();i < Observers.end();++i) i->Onclear(id);
	}
};