
// LAB4.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CLAB4App:
// � ���������� ������� ������ ��. LAB4.cpp
//

class CLAB4App : public CWinApp
{
public:
	CLAB4App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CLAB4App theApp;