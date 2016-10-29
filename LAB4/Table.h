#pragma once
#include "stdafx.h"
#include "TableRow.h"
#include <map>
#include <list>
#include <utility>

// описывает таблицу строк указанного типа
template<class RowType>
class Table
{
	class IObserver;
	RowType _prototype;					// прототип, для создания нового элемента
	unsigned _currentId = 0;			// текущий ID новой записи
	void CheckId(unsigned id)	// проверяет наличие id и выдает исключение если его нет
	{
		if (_data.find(id) == _data::end()) throw "Не удалось получить строку - такой строки нет";
	}
public:
	std::map<unsigned, RowType> _data;	// все строки таблицы

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


	RowType operator[](unsigned id)	// возвращает строку по ее ID
	{
		// ограничитель
		CheckId(id);
		// вывод результата
		return _data[id];
	}
	RowType AddNewRow()				// создает новую строку с данными из прототипа
	{
		return AddNewRow(_prototype);
	}
	RowType AddNewRow(RowType newRow)	// создает новую строку с данными из другой строки
	{
		((TableRow&)newRow).SetId(++_currentId);
		_data.insert(std::make_pair(((TableRow&)newRow).GetId(), newRow));
		// вывод результата
		return newRow;
	}
	bool EditRow(RowType row)
	{
		// ограничитель если запись не верная
		if (row.GetId() == 0) return false;
		// ограничитель. если в контейнере нет строки с указанным ID то выход
		if (_data.find(row.GetId()) == _data.end()) return false;
		// смена значения
		_data[row.GetId()] = row;
	}
	void Remove(unsigned id)
	{
		_data.erase(id);
	}
	void Clear()
	{
		_data.clear();
		for (auto i = Observers.begin();i < Observers.end();++i) i->Onclear(id);
	}
	bool RemoveAt(int index)
	{
		for (auto i =_data.begin();i !=_data.end() && index>=0;++i, --index)
			if (index == 0) {
				Remove(i->second.GetId());
				return true;
			}
		return false;
	}
	int Size()
	{
		return _data.size();
	}
};