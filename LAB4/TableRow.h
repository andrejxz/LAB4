#pragma once

// описывает строку таблицы
class TableRow
{
	unsigned _id = 0;
public:
	TableRow();
	TableRow(unsigned id);

	unsigned GetId() { return _id; }
	void SetId(unsigned id) { _id = id; }

	virtual ~TableRow();
	virtual CString ToString() = 0;
};

