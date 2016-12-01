// LAB4Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "LAB4.h"
#include "LAB4Dlg.h"
#include "afxdialogex.h"
#include "Give.h"
#include "Journal.h"

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
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
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
	DDX_Control(pDX, IDC_LIST2, _journals);
}

BEGIN_MESSAGE_MAP(CLAB4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLAB4Dlg::OnBnClickedButton1)
//	ON_LBN_SELCHANGE(IDC_LIST3, &CLAB4Dlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_BUTTON3, &CLAB4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CLAB4Dlg::OnBnClickedButton5)
//	ON_LBN_SELCHANGE(IDC_LIST4, &CLAB4Dlg::OnLbnSelchangeList4)
//ON_LBN_DBLCLK(IDC_LIST3, &CLAB4Dlg::OnLbnDblclkList3)
ON_LBN_DBLCLK(IDC_LIST3, &CLAB4Dlg::OnLbnDblclkList3)
ON_LBN_DBLCLK(IDC_LIST4, &CLAB4Dlg::OnLbnDblclkList4)
//ON_BN_CLICKED(IDOK, &CLAB4Dlg::OnBnClickedOk)
ON_LBN_DBLCLK(IDC_LIST5, &CLAB4Dlg::OnLbnDblclkList5)
ON_BN_CLICKED(IDC_BUTTON2, &CLAB4Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON7, &CLAB4Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CLAB4Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON6, &CLAB4Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON4, &CLAB4Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON9, &CLAB4Dlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CLAB4Dlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON11, &CLAB4Dlg::OnBnClickedButton11)
ON_BN_CLICKED(IDC_BUTTON12, &CLAB4Dlg::OnBnClickedButton12)
ON_LBN_DBLCLK(IDC_LIST2, &CLAB4Dlg::OnLbnDblclkList2)
ON_BN_CLICKED(IDC_BUTTON13, &CLAB4Dlg::OnBnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CLAB4Dlg::OnBnClickedButton14)
ON_EN_KILLFOCUS(IDC_EDIT14, &CLAB4Dlg::OnEnKillfocusEdit14)
ON_EN_KILLFOCUS(IDC_EDIT36, &CLAB4Dlg::OnEnKillfocusEdit36)
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

void CLAB4Dlg::OnBnClickedButton1()							// Добавление книги
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

void CLAB4Dlg::OnBnClickedButton3()							// Добавление читателя
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
	GetDlgItemText(IDC_EDIT36, str);
	newGive.SetJournalId(_wtoi(str));

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

void CLAB4Dlg::OnBnClickedButton5()							// Добавление выдачи
{
	lib.GetDB().Gives.AddNewRow(InputGive());
	ShowAll();
}

void CLAB4Dlg::ShowAll()
{
	ShowBooks();
	ShowReaders();
	ShowGives();
	ShowJournals();
	LibInf();
}

void CLAB4Dlg::ShowJournals()
{
	SetDlgItemText(IDC_EDIT31, L"");
	SetDlgItemText(IDC_EDIT32, L"");
	SetDlgItemText(IDC_EDIT33, L"");
	SetDlgItemText(IDC_EDIT34, L"");
	SetDlgItemText(IDC_EDIT35, L"");
	SetDlgItemText(IDC_EDIT37, L"");
	_journals.ResetContent();
	for each(auto i in lib.GetDB().Journals._data)
		_journals.AddString(i.second.ToString());
}

void CLAB4Dlg::ShowBooks()									// Вывод списка книг
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

void CLAB4Dlg::ShowReaders()								// Вывод списка читателей
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

void CLAB4Dlg::ShowGives()									// Вывод списка выдачи
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

void CLAB4Dlg::OnLbnDblclkList3()							// Получение id выбраного элемента двойным нажатием
{
	ShowBookByIndex(_books.GetCurSel());
}

void CLAB4Dlg::OnLbnDblclkList2()
{
	ShowJournalByIndex(_journals.GetCurSel());

}

void CLAB4Dlg::ShowJournalByIndex(int index)					// Показ читателя по индексу
{
	for (auto i = lib.GetDB().Journals._data.begin(); i != lib.GetDB().Journals._data.end(); ++i, --index) {
		if (index == 0) {
			ShowJournal(i->second);
			return;
		}
	}
}

void CLAB4Dlg::ShowJournal(Journal journal) 
{
	wchar_t str[80];
	CString coast;
	SetDlgItemText(IDC_EDIT31, _itow(journal.GetId(), str, 10));
	SetDlgItemText(IDC_EDIT32, journal.GetName());
	SetDlgItemText(IDC_EDIT33, journal.GetAuthor());
	SetDlgItemText(IDC_EDIT34, _itow(journal.GetNum(), str, 10));
	
	SetDlgItemText(IDC_EDIT35, _itow(journal.GetReleaseDate().GetDay(), str, 10));
	SetDlgItemText(IDC_EDIT38, _itow(journal.GetReleaseDate().GetMonth(), str, 10));
	SetDlgItemText(IDC_EDIT40, _itow(journal.GetReleaseDate().GetYear(), str, 10));

	coast.Format(_T("%.2f"), journal.GetCost());
	SetDlgItemText(IDC_EDIT37, coast);
}

void CLAB4Dlg::ShowReaderByIndex(int index)					// Показ читателя по индексу
{
	for (auto i = lib.GetDB().Readers._data.begin(); i != lib.GetDB().Readers._data.end(); ++i, --index) {
		if (index == 0) {
			ShowReader(i->second);
			return;
		}
	}
}

void CLAB4Dlg::ShowBookByIndex(int index)					// Показ книги по индексу
{
	for (auto i = lib.GetDB().Books._data.begin(); i != lib.GetDB().Books._data.end(); ++i, --index) {
		if (index == 0) {
			ShowBook(i->second);
			return;
		}
	}
}

void CLAB4Dlg::ShowBook(Book book)							// Показ информации о книге
{
	wchar_t str[80];
	CString coast;
	SetDlgItemText(IDC_EDIT21, _itow(book.GetId(),str,10));
	SetDlgItemText(IDC_EDIT1, book.GetName());
	SetDlgItemText(IDC_EDIT2, book.GetAuthor());
	SetDlgItemText(IDC_EDIT3, _itow(book.GetYear(), str,10));
	coast.Format(_T("%.2f"), book.GetCost());
	SetDlgItemText(IDC_EDIT4, coast);
	SetDlgItemText(IDC_EDIT5, _itow(book.GetCount(), str,10));
	SetDlgItemText(IDC_EDIT6, _itow(book.GetGiveCount(), str,10));
}

void CLAB4Dlg::OnLbnDblclkList4()							// Получение id выбраного элемента двойным нажатием
{
	ShowReaderByIndex(_reader.GetCurSel());
}

void CLAB4Dlg::ShowReader(Reader reader)					// Показ информации Читателя
{
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT9, _itow(reader.GetId(),str,10));
	SetDlgItemText(IDC_EDIT10, reader.GetFio());
	SetDlgItemText(IDC_EDIT11, reader.GetAddress());
	SetDlgItemText(IDC_EDIT12, reader.GetPhone());
}

void CLAB4Dlg::OnLbnDblclkList5()							// Получение id выбраного элемента двойным нажатием
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

void CLAB4Dlg::ShowGive(Give give)							// Показ информации Выдачи
{
	wchar_t str[80];
	
	_books.SetCurSel(give.GetBookId()-1);
	ShowBookByIndex(give.GetBookId()-1);
	_reader.SetCurSel(give.GetReaderId()-1);
	ShowReaderByIndex(give.GetReaderId() - 1);
	_journals.SetCurSel(give.GetJournalId() - 1);
	ShowJournalByIndex(give.GetJournalId() - 1);
	

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
	SetDlgItemText(IDC_EDIT36, _itow(give.GetJournalId(), str, 10));
}

//void CLAB4Dlg::OnBnClickedOk()
//{
//	// TODO: добавьте свой код обработчика уведомлений
//	CDialogEx::OnOK();
//}

void CLAB4Dlg::OnBnClickedButton2()							// Удаление Книги
{
	if (lib.GetDB().Books.RemoveAt(_books.GetCurSel())) ShowAll();
}

void CLAB4Dlg::OnBnClickedButton4()							// Удаление Читателя
{
	if (lib.GetDB().Readers.RemoveAt(_reader.GetCurSel())) ShowAll();
}

void CLAB4Dlg::OnBnClickedButton6()							// Удаление Выдачи
{
	if (lib.GetDB().Gives.RemoveAt(_gives.GetCurSel())) ShowAll();
}

void CLAB4Dlg::OnBnClickedButton7()							// Изменение выдачи
{
	if(lib.GetDB().Gives.EditRow(InputGive())) ShowGives();
	else MessageBox(L"Выдачу изменить не удалось - не верный id выдачи", L"Изменение выдачи");
}

void CLAB4Dlg::OnBnClickedButton8()							// Поиск книги
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

void CLAB4Dlg::LibInf()										// Информация о библиотеке
{
	wchar_t str[80];
	SetDlgItemText(IDC_EDIT24, lib.GetName());
	SetDlgItemText(IDC_EDIT25, lib.GetAddres());
	SetDlgItemText(IDC_EDIT29, lib.GetPhone());
	SetDlgItemText(IDC_EDIT28, _itow(lib.GetDB().Books.Size(),str,10));
	SetDlgItemText(IDC_EDIT27, _itow(lib.GetDB().Readers.Size(), str, 10));
	SetDlgItemText(IDC_EDIT26, _itow(lib.GetDB().Gives.Size(), str, 10));
	SetDlgItemText(IDC_EDIT30, _itow(lib._penya, str, 10));
}

void CLAB4Dlg::OnBnClickedButton9()							// Должники
{
	CString penya;
	GetDlgItemText(IDC_EDIT30, penya);
	lib._penya = _ttof(penya);
	// Очистка всех должников
	_debtors.ResetContent();
	// Вывод должников
	_deptors = lib.GetDeptors();
	for each(auto i in _deptors)
		_debtors.AddString(i.ToString());
}

void CLAB4Dlg::OnBnClickedButton10()						// Ок
{
	CString str;
	GetDlgItemText(IDC_EDIT24, str);
	lib.SetName(str);
	GetDlgItemText(IDC_EDIT25, str);
	lib.SetAddres(str);
	GetDlgItemText(IDC_EDIT29, str);
	lib.SetPhone(str);
}

void CLAB4Dlg::OnBnClickedButton11()						// Тест
{
	
	// вставка журналов
	wchar_t str[80];
	Journal journal;
	journal.SetName(L"Journal 1");
	journal.SetAuthor(L"Author 1");
	journal.SetNum(1);
	journal.SetCost(250.75);
	journal.SetReleaseDate(Date(2, 2, 2016));
	lib.GetDB().Journals.AddNewRow(journal);

	journal.SetName(L"Journal 2");
	journal.SetAuthor(L"Author 2");
	journal.SetNum(2);
	journal.SetCost(100.50);
	journal.SetReleaseDate(Date(2, 3, 2016));
	lib.GetDB().Journals.AddNewRow(journal);
	
	// вставка информации о библиотеке
	lib.SetName(L"Незнайка");
	lib.SetPhone(L"228-14-88");
	lib.SetAddres(L"Nagib 13-37");

	// вставка книг
	Book book;
	book.SetName(L"Book 1");
	book.SetAuthor(L"Author 1");
	book.SetYear(1997);
	book.SetCost(250.75);
	lib.GetDB().Books.AddNewRow(book);

	book.SetName(L"Book 2");
	book.SetAuthor(L"Author 2");
	book.SetYear(2000);
	book.SetCost(300.65);
	lib.GetDB().Books.AddNewRow(book);

	book.SetName(L"Book 3");
	book.SetAuthor(L"Author 3");
	book.SetYear(2005);
	book.SetCost(600);
	lib.GetDB().Books.AddNewRow(book);

	book.SetName(L"Book 4");
	book.SetAuthor(L"Author 4");
	book.SetYear(2010);
	book.SetCost(750.25);
	lib.GetDB().Books.AddNewRow(book);
	book.SetName(L"Book 5");
	book.SetAuthor(L"Author 5");
	book.SetYear(2016);
	book.SetCost(1200.50);
	lib.GetDB().Books.AddNewRow(book);

	// вставка читателей
	Reader reader;
	reader.SetFio(L"Reader 1");
	reader.SetAddress(L"Address 1");
	reader.SetPhone(L"Phone 1");
	lib.GetDB().Readers.AddNewRow(reader);

	reader.SetFio(L"Reader 2");
	reader.SetAddress(L"Address 2");
	reader.SetPhone(L"Phone 2");
	lib.GetDB().Readers.AddNewRow(reader);

	reader.SetFio(L"Reader 3");
	reader.SetAddress(L"Address 3");
	reader.SetPhone(L"Phone 3");
	lib.GetDB().Readers.AddNewRow(reader);

	reader.SetFio(L"Reader 4");
	reader.SetAddress(L"Address 4");
	reader.SetPhone(L"Phone 5");
	lib.GetDB().Readers.AddNewRow(reader);

	reader.SetFio(L"Reader 5");
	reader.SetAddress(L"Address 5");
	reader.SetPhone(L"Phone 5");
	lib.GetDB().Readers.AddNewRow(reader);



	reader.SetFio(L"Reader 228");
	reader.SetAddress(L"Address 228");
	reader.SetPhone(L"Phone 288");
	lib.GetDB().Readers.AddNewRow(reader);



	// вставка выдачи книг
	Give give;

	// 1 пользователь - 1 журнал
	give.SetReaderId(1);
	give.SetBookId(0);
	give.SetJournalId(1);
	give.SetReturnDate(Date(1, 11, 2016));
	lib.GetDB().Gives.AddNewRow(give);

	give.SetReaderId(1);
	give.SetJournalId(0);
	give.SetBookId(2);
	give.SetReturnDate(Date(2, 11, 2016));
	lib.GetDB().Gives.AddNewRow(give);

	give.SetReaderId(1);
	give.SetJournalId(0);
	give.SetBookId(3);
	give.SetReturnDate(Date(3, 11, 2016));
	lib.GetDB().Gives.AddNewRow(give);

	give.SetReaderId(1);
	give.SetJournalId(0);
	give.SetBookId(4);
	give.SetReturnDate(Date(1, 11, 2017));
	lib.GetDB().Gives.AddNewRow(give);

	// 2 пользователь - ничего не должен
	give.SetReaderId(2);
	give.SetJournalId(0);
	give.SetBookId(1);
	give.SetReturnDate(Date(1, 11, 2017));
	lib.GetDB().Gives.AddNewRow(give);

	give.SetReaderId(2);
	give.SetJournalId(0);
	give.SetBookId(3);
	give.SetReturnDate(Date(1, 11, 2017));
	lib.GetDB().Gives.AddNewRow(give);

	// 3 пользователь  должен 1 книгу
	give.SetReaderId(3);
	give.SetJournalId(0);
	give.SetBookId(1);
	give.SetReturnDate(Date(1, 11, 2015));
	lib.GetDB().Gives.AddNewRow(give);

	
	// 6 пользователь  должен 1 книгу
	give.SetReaderId(6);
	give.SetBookId(0);
	give.SetJournalId(1);
	give.SetReturnDate(Date(1, 11, 2015));
	lib.GetDB().Gives.AddNewRow(give);

	// 6 пользователь  должен 1 книгу
	give.SetReaderId(5);
	give.SetBookId(0);
	give.SetJournalId(2);
	give.SetReturnDate(Date(1, 11, 2015));
	lib.GetDB().Gives.AddNewRow(give);
	
	ShowAll();
}

void CLAB4Dlg::OnBnClickedButton12()
{
	CDialog::OnCancel();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CLAB4Dlg::OnBnClickedButton13()
{
	Journal newJournal;
	CString str, str2, str3;
	GetDlgItemText(IDC_EDIT32, str);
	newJournal.SetName(str);
	GetDlgItemText(IDC_EDIT33, str);
	newJournal.SetAuthor(str);
	GetDlgItemText(IDC_EDIT34, str);
	newJournal.SetNum(_wtoi(str));
	GetDlgItemText(IDC_EDIT35, str);
	GetDlgItemText(IDC_EDIT38, str2);
	GetDlgItemText(IDC_EDIT40, str3);
	newJournal.SetReleaseDate(Date (_wtoi(str), _wtoi(str2), _wtoi(str3)));
	GetDlgItemText(IDC_EDIT37, str);
	newJournal.SetCost(_ttof(str));

	lib.GetDB().Journals.AddNewRow(newJournal);
	ShowAll();
}


void CLAB4Dlg::OnBnClickedButton14()
{
	if (lib.GetDB().Journals.RemoveAt(_journals.GetCurSel())) ShowAll();
}


void CLAB4Dlg::OnEnKillfocusEdit14()
{
	CString str;
	GetDlgItemText(IDC_EDIT14, str);
	if (_wtoi(str) != 0)SetDlgItemText(IDC_EDIT36, L"0");
}


void CLAB4Dlg::OnEnKillfocusEdit36()
{
	CString str;
	GetDlgItemText(IDC_EDIT36, str);
	if (_wtoi(str) != 0)SetDlgItemText(IDC_EDIT14, L"0");
}
