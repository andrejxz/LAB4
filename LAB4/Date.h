#pragma once

// описывает дату
class Date
{
	// день месяц год
	unsigned int day, month, year;
	// проверка дня четного/нечетного месяца
	unsigned int Check(int);
public:
	// конструктор
	Date(int day = 1, int month = 1, int year = 2015);
	// печать
	void Print();
	// установка даты
	void SetDate(int day, int month, int year);
	// получение дня
	unsigned int GetDay();
	// получение месяца
	unsigned int GetMonth();
	// получение года
	unsigned int GetYear();
};