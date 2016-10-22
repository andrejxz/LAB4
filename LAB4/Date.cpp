#include "stdafx.h"
#include "Date.h"
#include<iostream>
using namespace std;


// конструктор
Date::Date(int d, int m, int y){
#ifdef _DEBUG
	cout << "Date::Date" << endl;
#endif
	SetDate(d, m, y);
}

// установка даты
void Date::SetDate(int d, int m, int y) {
#ifdef _DEBUG
	cout << "Date::SetDate" << endl;
#endif	
	year = y;
	// проверка месяца
	if (m>0 && m <= 12)
		month = m;
	else {
		cout << "Error in month: " << m << endl;
		month = 1;
	}
	// проверка дня
	day = Check(d);
}

// печать
void Date::Print() {
#ifdef _DEBUG
	cout << "Date::Print" << endl;
#endif
	cout << day << '-' << month << '-' << year << endl;
}

// проверка дня
unsigned int Date::Check(int x) {
#ifdef _DEBUG
	cout << "Date::Check" << endl;
#endif
	int days[13] = { 0, 31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31 };
	if (x>0 && x <= days[month]) return x;
	if (x == 29 && month == 2 &&
		(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return x;
	cout << "Error in day: " << x << endl;
	return 1;
}

// получение дня
unsigned int Date::GetDay()
{
	return day;
}

// получение месяца
unsigned int Date::GetMonth()
{
	return month;
}

// получение года
unsigned int Date::GetYear()
{
	return year;
}