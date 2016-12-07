
// LAB4Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "Book.h"
#include "Reader.h"
#include "Give.h"
#include "DataBase.h"
#include "Library.h"


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
	Library lib;
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
	void ShowGives();
	void ShowJournals();
	void ShowJournal(Journal journal);
	void ShowBook(Book book);
	void ShowReader(Reader reader);
	void ShowGive(Give give);
	Give InputGive();
	void ShowJournalByIndex(int index);
	void ShowBookByIndex(int index);
	void ShowReaderByIndex(int index);
	CListBox _books;
	std::list<GiveSummary> _deptors;
//	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedButton3();
	CListBox _reader;
	CListBox _gives;
	afx_msg void OnBnClickedButton5();
//	afx_msg void OnLbnSelchangeList4();
//	afx_msg void OnLbnDblclkList3();
	afx_msg void OnLbnDblclkList3();
	afx_msg void OnLbnDblclkList4();
//	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnDblclkList5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	void LibInf();
	afx_msg void OnBnClickedButton9();
	CListBox _debtors;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	CListBox _journals;
	afx_msg void OnLbnDblclkList2();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnEnKillfocusEdit14();
	afx_msg void OnEnKillfocusEdit36();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
};
