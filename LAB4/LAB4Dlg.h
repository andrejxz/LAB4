
// LAB4Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "Book.h"
#include "Reader.h"
#include "Give.h"
#include "DataBase.h"
#include "Library.h"


// ���������� ���� CLAB4Dlg
class CLAB4Dlg : public CDialogEx
{
// ��������
public:
	CLAB4Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;
	Library lib;
	// ��������� ������� ����� ���������
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
	void ShowBook(Book book);
	void ShowReader(Reader reader);
	void ShowGive(Give give);
	Give InputGive();
	void ShowBookByIndex(int index);
	CListBox _books;
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedButton3();
	CListBox _reader;
	CListBox _gives;
	afx_msg void OnBnClickedButton5();
//	afx_msg void OnLbnSelchangeList4();
//	afx_msg void OnLbnDblclkList3();
	afx_msg void OnLbnDblclkList3();
	afx_msg void OnLbnDblclkList4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnDblclkList5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	void LibInf();
};
