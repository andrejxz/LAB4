
// LAB4Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "LAB4.h"
#include "LAB4Dlg.h"
#include "afxdialogex.h"
#include "DataBase.h"
#include "Give.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

DataBase db;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CLAB4Dlg



CLAB4Dlg::CLAB4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LAB4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLAB4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Name);
	DDX_Control(pDX, IDC_LIST3, _books);
	DDX_Control(pDX, IDC_LIST4, _reader);
	DDX_Control(pDX, IDC_LIST5, _gives);
}

BEGIN_MESSAGE_MAP(CLAB4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLAB4Dlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST3, &CLAB4Dlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_BUTTON3, &CLAB4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CLAB4Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// обработчики сообщений CLAB4Dlg

BOOL CLAB4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLAB4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLAB4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLAB4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLAB4Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CLAB4Dlg::OnBnClickedButton1()
{
	Book newBook;
	CString name;
	CString author;
	CString year;
	CString cost;
	CString count;
	CString giveCount;
	GetDlgItemText(IDC_EDIT1, name);
	GetDlgItemText(IDC_EDIT2, author);
	GetDlgItemText(IDC_EDIT3, year);
	GetDlgItemText(IDC_EDIT4, cost);
	GetDlgItemText(IDC_EDIT5, count);
	GetDlgItemText(IDC_EDIT6, giveCount);
	newBook.SetAll(name, author, _wtoi(year), _ttof(cost), _tcstoul(count, 0, 0), _tcstoul(giveCount, 0, 0));
	db.Books.AddNewRow(newBook);
	// очистка поля ввода
	Name.SetSel(0, -1);
	Name.Clear();
	ShowAll();
}
void CLAB4Dlg::ShowAll()
{
	ShowBooks();
	ShowReaders();
	ShowGive();
}
void CLAB4Dlg::ShowBooks()
{
	SetDlgItemText(IDC_EDIT1, L"");
	SetDlgItemText(IDC_EDIT2, L"");
	SetDlgItemText(IDC_EDIT3, L"");
	SetDlgItemText(IDC_EDIT4, L"");
	SetDlgItemText(IDC_EDIT5, L"");
	SetDlgItemText(IDC_EDIT6, L"");
	_books.ResetContent();
	for (auto i = db.Books._data.begin();i != db.Books._data.end();++i) 
		_books.AddString(i->second.ToString());
}
void CLAB4Dlg::ShowReaders()
{
	_reader.ResetContent();
	for (auto i = db.Readers._data.begin();i != db.Readers._data.end();++i) 
		_reader.AddString(i->second.ToString());
}
void CLAB4Dlg::ShowGive()
{
	_gives.ResetContent();
	for (auto i = db.Gives._data.begin();i != db.Gives._data.end();++i)
		_gives.AddString(i->second.ToString());
}


void CLAB4Dlg::OnLbnSelchangeList3()
{
	UpdateWindow();	
}


void CLAB4Dlg::OnBnClickedButton3()
{
	Reader newReader;
	CString str;
	GetDlgItemText(IDC_EDIT10, str);
	newReader.SetFio(str);
	GetDlgItemText(IDC_EDIT11, str);
	newReader.SetAddress(str);
	GetDlgItemText(IDC_EDIT12, str);
	newReader.SetPhone(str);
	db.Readers.AddNewRow(newReader);
	ShowAll();
}


void CLAB4Dlg::OnBnClickedButton5()
{
	Give newGive;
	CString str;
	GetDlgItemText(IDC_EDIT13, str);
	newGive.SetReaderId(_wtoi(str));

	GetDlgItemText(IDC_EDIT14, str);
	newGive.SetBookId(_wtoi(str));

	GetDlgItemText(IDC_EDIT15, str);
	newGive.SetCopyNumber(_wtoi(str));

	// задаем дату выдачи
	Date date;
	int day, month, year;
	GetDlgItemText(IDC_EDIT16, str);
	day = _wtoi(str);
	GetDlgItemText(IDC_EDIT7, str);
	month = _wtoi(str);
	GetDlgItemText(IDC_EDIT8, str);
	year = _wtoi(str);
	date.SetDate(day, month, year);
	newGive.SetGiveDate(date);

	// задаем дату получения
	GetDlgItemText(IDC_EDIT19, str);
	day = _wtoi(str);
	GetDlgItemText(IDC_EDIT18, str);
	month = _wtoi(str);
	GetDlgItemText(IDC_EDIT20, str);
	year = _wtoi(str);
	date.SetDate(day, month, year);
	newGive.SetReturnDate(date);

	db.Gives.AddNewRow(newGive);

	ShowAll();
}
