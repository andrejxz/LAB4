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
	RowType _prototype;					// прототип, для создания нового элемента
	unsigned _currentId = 0;			// текущий ID новой записи
	void CheckId(unsigned id)			// проверяет наличие id и выдает исключение если его нет
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


	RowType operator[](unsigned id)					// возвращает строку по ее ID
	{
		// ограничитель
		CheckId(id);
		// вывод результата
		return _data[id];
	}
	RowType AddNewRow()								// создает новую строку с данными из прототипа
	{
		return AddNewRow(_prototype);
	}
	RowType AddNewRow(RowType newRow)				// создает новую строку с данными из другой строки
	{
		((TableRow&)newRow).SetId(++_currentId);
		_data.insert(std::make_pair(((TableRow&)newRow).GetId(), newRow));
		// вывод результата
		return newRow;
	}
	bool EditRow(RowType row)						// меняет информацию о выдачи
	{
		// ограничитель если запись не верная
		if (row.GetId() == 0) return false;
		// ограничитель. если в контейнере нет строки с указанным ID то выход
		if (_data.find(row.GetId()) == _data.end()) return false;
		// смена значения
		_data[row.GetId()] = row;
		return true;
	}
	void Remove(unsigned id)						// удаление из map
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
	int Size()										// количество элементов в map
	{
		return _data.size();
	}

	// сериализует таблицу
	void Serialize(std::ostream &os)
	{
		// сериализуем текущий индекс нового элемента
		::Serialize(os, _currentId);
		// сериализуем размер
		size_t size = _data.size();
		::Serialize(os, size);
		// сериализуем все пары ключей и значений
		unsigned key;
		RowType val;
		for each(auto value in _data) {
			key = value.first;
			val = value.second;
			::Serialize(os, key);
			::Serialize(os, val);
		}
	}

	// десериализует таблицу
	void Dederialize(std::istream &is)
	{
		// очистка данных
		_data.clear();
		// десериализуем текущий индекс нового элемента
		_currentId = Deserialize<unsigned>(is);
		// десериализуем размер
		auto size = Deserialize<size_t>(is);
		// десериализуем все пары
		while (size-->0) {
			// десериализуем ключ
			auto key = Deserialize<unsigned>(is);
			// десериализуем значение
			auto val = Deserialize<RowType>(is);
			// вставляем пару
			_data.insert(std::make_pair(key, val));
		}
	}
};