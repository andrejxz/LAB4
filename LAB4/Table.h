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
	RowType _prototype;					// ��������, ��� �������� ������ ��������
	unsigned _currentId = 0;			// ������� ID ����� ������
	void CheckId(unsigned id)			// ��������� ������� id � ������ ���������� ���� ��� ���
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


	RowType operator[](unsigned id)					// ���������� ������ �� �� ID
	{
		// ������������
		CheckId(id);
		// ����� ����������
		return _data[id];
	}
	RowType AddNewRow()								// ������� ����� ������ � ������� �� ���������
	{
		return AddNewRow(_prototype);
	}
	RowType AddNewRow(RowType newRow)				// ������� ����� ������ � ������� �� ������ ������
	{
		((TableRow&)newRow).SetId(++_currentId);
		_data.insert(std::make_pair(((TableRow&)newRow).GetId(), newRow));
		// ����� ����������
		return newRow;
	}
	bool EditRow(RowType row)						// ������ ���������� � ������
	{
		// ������������ ���� ������ �� ������
		if (row.GetId() == 0) return false;
		// ������������. ���� � ���������� ��� ������ � ��������� ID �� �����
		if (_data.find(row.GetId()) == _data.end()) return false;
		// ����� ��������
		_data[row.GetId()] = row;
		return true;
	}
	void Remove(unsigned id)						// �������� �� map
	{
		_data.erase(id);
	}
	void Clear()
	{
		_data.clear();
	}
	bool RemoveAt(int index)
	{
		for (auto i = _data.begin(); i != _data.end() && index >= 0; ++i, --index)
			if (index == 0) {
				Remove(i->second.GetId());
				return true;
			}
		return false;
	}
	int Size()										// ���������� ��������� � map
	{
		return _data.size();
	}

	// ����������� �������
	void Serialize(std::ostream &os)
	{
		// ����������� ������� ������ ������ ��������
		::Serialize(os, _currentId);
		// ����������� ������
		size_t size = _data.size();
		::Serialize(os, size);
		// ����������� ��� ���� ������ � ��������
		unsigned key;
		RowType val;
		for each(auto value in _data) {
			key = value.first;
			val = value.second;
			::Serialize(os, key);
			::Serialize(os, val);
		}
	}

	// ������������� �������
	void Dederialize(std::istream &is)
	{
		// ������� ������
		_data.clear();
		// ������������� ������� ������ ������ ��������
		_currentId = Deserialize<unsigned>(is);
		// ������������� ������
		auto size = Deserialize<size_t>(is);
		// ������������� ��� ����
		while (size-->0) {
			// ������������� ����
			auto key = Deserialize<unsigned>(is);
			// ������������� ��������
			auto val = Deserialize<RowType>(is);
			// ��������� ����
			_data.insert(std::make_pair(key, val));
		}
	}
};