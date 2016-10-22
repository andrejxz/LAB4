
// LAB4Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CLAB4Dlg
class CLAB4Dlg : public CDialogEx
{
// Создание
public:
	CLAB4Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	CEdit Name;
	void ShowAll();
	void ShowBooks();
	CListBox _books;
	afx_msg void OnLbnSelchangeList3();
};
