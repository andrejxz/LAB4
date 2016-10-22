
// LAB4.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLAB4App:
// О реализации данного класса см. LAB4.cpp
//

class CLAB4App : public CWinApp
{
public:
	CLAB4App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLAB4App theApp;