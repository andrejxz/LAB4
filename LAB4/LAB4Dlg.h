
// LAB4Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "Book.h"


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
	void ShowReaders();
	void ShowGive();
	void ShowBook(Book book);
	CListBox _books;
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedButton3();
	CListBox _reader;
	CListBox _gives;
	afx_msg void OnBnClickedButton5();
//	afx_msg void OnLbnSelchangeList4();
//	afx_msg void OnLbnDblclkList3();
	afx_msg void OnLbnDblclkList3();
};
