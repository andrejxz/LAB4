#pragma once

// ��������� ����
class Date
{
	// ���� ����� ���
	unsigned int day, month, year;
	// �������� ��� �������/��������� ������
	unsigned int Check(int);
public:
	// �����������
	Date(int day = 1, int month = 1, int year = 2015);
	// ������
	void Print();
	// ��������� ����
	void SetDate(int day, int month, int year);
	// ��������� ���
	unsigned int GetDay();
	// ��������� ������
	unsigned int GetMonth();
	// ��������� ����
	unsigned int GetYear();
};