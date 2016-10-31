// LAB4Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "LAB4.h"
#include "LAB4Dlg.h"
#include "afxdialogex.h"
#include "Give.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
	DDX_Control(pDX, IDC_LIST1, _debtors);
}

BEGIN_MESSAGE_MAP(CLAB4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLAB4Dlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST3, &CLAB4Dlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_BUTTON3, &CLAB4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CLAB4Dlg::OnBnClickedButton5)
//	ON_LBN_SELCHANGE(IDC_LIST4, &CLAB4Dlg::OnLbnSelchangeList4)
//ON_LBN_DBLCLK(IDC_LIST3, &CLAB4Dlg::OnLbnDblclkList3)
ON_LBN_DBLCLK(IDC_LIST3, &CLAB4Dlg::OnLbnDblclkList3)
ON_LBN_DBLCLK(IDC_LIST4, &CLAB4Dlg::OnLbnDblclkList4)
ON_BN_CLICKED(IDOK, &CLAB4Dlg::OnBnClickedOk)
ON_LBN_DBLCLK(IDC_LIST5, &CLAB4Dlg::OnLbnDblclkList5)
ON_BN_CLICKED(IDC_BUTTON2, &CLAB4Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON7, &CLAB4Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CLAB4Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON6, &CLAB4Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON4, &CLAB4Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON9, &CLAB4Dlg::OnBnClickedButton9)
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

/*****************************************************************************************************/

// Добавление книги
void CLAB4Dlg::OnBnClickedButton1()
{
	Book newBook;
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	newBook.SetName(str);
	GetDlgItemText(IDC_EDIT2, str);
	newBook.SetAuthor(str);
	GetDlgItemText(IDC_EDIT3, str);
	newBook.SetYear(_wtoi(str));
	GetDlgItemText(IDC_EDIT4, str);
	newBook.SetCost(_ttof(str));
	GetDlgItemText(IDC_EDIT5, str);
	newBook.SetCount(_tcstoul(str, 0, 0));
	GetDlgItemText(IDC_EDIT6, str);
	newBook.SetGiveCount(_tcstoul(str, 0, 0));

	lib.GetDB().Books.AddNewRow(newBook);
	ShowAll();
}

// Добавление читателя
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

	lib.GetDB().Readers.AddNewRow(newReader);
	ShowAll();
}

Give CLAB4Dlg::InputGive()
{
	Give newGive;
	CString str;
	GetDlgItemText(IDC_EDIT22, str);
	newGive.SetId(_wtoi(str));
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
	return newGive;
}
// Добавление выдачи
void CLAB4Dlg::OnBnClickedButton5()
{
	lib.GetDB().Gives.AddNewRow(InputGive());
	ShowAll();
}

void CLAB4Dlg::ShowAll()
{
	ShowBooks();
	ShowReaders();
	ShowGives();
	LibInf();
}

// Вывод списка книг
void CLAB4Dlg::ShowBooks()
{
	// Очистка полей
	SetDlgItemText(IDC_EDIT21, L"");
	SetDlgItemText(IDC_EDIT1, L"");
	SetDlgItemText(IDC_EDIT2, L"");
	SetDlgItemText(IDC_EDIT3, L"");
	SetDlgItemText(IDC_EDIT4, L"");
	SetDlgItemText(IDC_EDIT5, L"");
	SetDlgItemText(IDC_EDIT6, L"");
	_books.ResetContent();
	// Вывод списка
	for (auto i = lib.GetDB().Books._data.begin();i != lib.GetDB().Books._data.end();++i)
		_books.AddString(i->second.ToString());
}

// Вывод списка читателей
void CLAB4Dlg::ShowReaders()
{
	// Очистка полей
	SetDlgItemText(IDC_EDIT9, L"");
	SetDlgItemText(IDC_EDIT10, L"");
	SetDlgItemText(IDC_EDIT11, L"");
	SetDlgItemText(IDC_EDIT12, L"");
	_reader.ResetContent();
	// Вывод списка
	for (auto i = lib.GetDB().Readers._data.begin();i != lib.GetDB().Readers._data.end();++i) 
		_reader.AddString(i->second.ToString());
}

// Вывод списка выдачи
void CLAB4Dlg::ShowGives()
{
	// Очистка полей
	SetDlgItemText(IDC_EDIT13, L"");
	SetDlgItemText(IDC_EDIT14, L"");
	SetDlgItemText(IDC_EDIT15, L"");
	SetDlgItemText(IDC_EDIT16, L"");
	SetDlgItemText(IDC_EDIT7, L"");
	SetDlgItemText(IDC_EDIT8, L"");
	SetDlgItemText(IDC_EDIT19, L"");
	SetDlgItemText(IDC_EDIT18, L"");
	SetDlgItemText(IDC_EDIT20, L"");
	SetDlgItemText(IDC_EDIT22, L"");
	_gives.ResetContent();
	// Вывод списка
	for (auto i = lib.GetDB().Gives._data.begin();i != lib.GetDB().Gives._data.end();++i)
		_gives.AddString(i->second.ToString());
}

void CLAB4Dlg::OnLbnSelchangeList3()
{
	UpdateWindow();	
}

// Получение id выбраного элемента двойным нажатием
void CLAB4Dlg::OnLbnDblclkList3()
{
	ShowBookByIndex(_books.GetCurSel());
}

void CLAB4Dlg::ShowBookByIndex(int index)
{
	for (auto i = lib.GetDB().Books._data.begin(); i != lib.GetDB().Books._data.end(); ++i, --index) {
		if (index == 0) {
			ShowBook(i->second);
			return;
		}
	}
}

// Показ информации о книге
void CLAB4Dlg::ShowBook(Book book)
{
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT21, _itow(book.GetId(),str,10));
	SetDlgItemText(IDC_EDIT1, book.GetName());
	SetDlgItemText(IDC_EDIT2, book.GetAuthor());
	SetDlgItemText(IDC_EDIT3, _itow(book.GetYear(), str,10));
	SetDlgItemText(IDC_EDIT4, _itow(book.GetCost(), str,10));
	SetDlgItemText(IDC_EDIT5, _itow(book.GetCount(), str,10));
	SetDlgItemText(IDC_EDIT6, _itow(book.GetGiveCount(), str,10));
}

// Получение id выбраного элемента двойным нажатием
void CLAB4Dlg::OnLbnDblclkList4()
{
	int curindex = _reader.GetCurSel();
	int index = 0;
	for (auto i = lib.GetDB().Readers._data.begin(); i != lib.GetDB().Readers._data.end(); ++i) {
		if (index == curindex) {
			ShowReader(i->second);
			return;
		}
		++index;
	}
}

// Показ информации Читателя
void CLAB4Dlg::ShowReader(Reader reader)
{
	// ???
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT9, _itow(reader.GetId(),str,10));
	SetDlgItemText(IDC_EDIT10, reader.GetFio());
	SetDlgItemText(IDC_EDIT11, reader.GetAddress());
	SetDlgItemText(IDC_EDIT12, reader.GetPhone());
}

// Получение id выбраного элемента двойным нажатием
void CLAB4Dlg::OnLbnDblclkList5()
{
	int curindex = _gives.GetCurSel();
	int index = 0;
	for (auto i = lib.GetDB().Gives._data.begin(); i != lib.GetDB().Gives._data.end(); ++i) {
		if (index == curindex) {
			ShowGive(i->second);
			return;
		}
		++index;
	}
}

// Показ информации Выдачи
void CLAB4Dlg::ShowGive(Give give)
{
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT22, _itow(give.GetId(), str, 10));
	SetDlgItemText(IDC_EDIT13, _itow(give.GetReaderId(), str, 10));
	SetDlgItemText(IDC_EDIT14, _itow(give.GetBookId(),str,10));
	SetDlgItemText(IDC_EDIT15, _itow(give.GetCopyNumber(),str,10));
	SetDlgItemText(IDC_EDIT16, _itow(give.GetGiveDate().GetDay(),str,10));
	SetDlgItemText(IDC_EDIT7, _itow(give.GetGiveDate().GetMonth(), str, 10));
	SetDlgItemText(IDC_EDIT8, _itow(give.GetGiveDate().GetYear(), str, 10));
	SetDlgItemText(IDC_EDIT19, _itow(give.GetReturnDate().GetDay(), str, 10));
	SetDlgItemText(IDC_EDIT18, _itow(give.GetReturnDate().GetMonth(), str, 10));
	SetDlgItemText(IDC_EDIT20, _itow(give.GetReturnDate().GetYear(), str, 10));
}


void CLAB4Dlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

// Удаление Книги
void CLAB4Dlg::OnBnClickedButton2()
{
	if (lib.GetDB().Books.RemoveAt(_books.GetCurSel())) ShowAll();
}

// Удаление Читателя
void CLAB4Dlg::OnBnClickedButton4()
{
	// ??? Надо ли ID билета уменьшать?
	if (lib.GetDB().Readers.RemoveAt(_reader.GetCurSel())) ShowAll();
}

// Удаление Выдачи
void CLAB4Dlg::OnBnClickedButton6()
{
	// ??? Надо ли ID билета уменьшать?
	if (lib.GetDB().Gives.RemoveAt(_gives.GetCurSel())) ShowAll();
}

// Изменение выдачи
void CLAB4Dlg::OnBnClickedButton7()
{
	if(lib.GetDB().Gives.EditRow(InputGive())) ShowGives();
	else MessageBox(L"Выдачу изменить не удалось - не верный id выдачи", L"Изменение выдачи");
}

// Поиск книги
void CLAB4Dlg::OnBnClickedButton8()
{
	// читаем имя книги
	CString bookName;
	GetDlgItemText(IDC_EDIT23, bookName);
	// производим поиск индекса книги
	int index = lib.FindBookListIndex(bookName);
	// вывод результата поиска
	_books.SetCurSel(index);
	if (index >= 0) ShowBookByIndex(index);	
	else MessageBox(L"Книга не найдена", L"Поиск книги");
}

// Информация о библиотеке
void CLAB4Dlg::LibInf()
{
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT28, _itow(lib.GetDB().Books.Size(),str,10));
	SetDlgItemText(IDC_EDIT27, _itow(lib.GetDB().Readers.Size(), str, 10));
	SetDlgItemText(IDC_EDIT26, _itow(lib.GetDB().Gives.Size(), str, 10));
}

void CLAB4Dlg::OnBnClickedButton9()
{
	// очистка всех должников
	_debtors.ResetContent();
	// вывод должников
	_deptors = lib.GetDeptors();
	for each(auto i in _deptors)
		_debtors.AddString(i.ToString());
}
