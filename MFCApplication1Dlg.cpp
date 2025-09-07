
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, Editcontrol(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Editcontrol);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_0,&CMFCApplication1Dlg::OnBtn0)
	ON_BN_CLICKED(IDC_BTN_1, &CMFCApplication1Dlg::OnBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CMFCApplication1Dlg::OnBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CMFCApplication1Dlg::OnBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CMFCApplication1Dlg::OnBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CMFCApplication1Dlg::OnBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CMFCApplication1Dlg::OnBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CMFCApplication1Dlg::OnBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CMFCApplication1Dlg::OnBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CMFCApplication1Dlg::OnBtn9)

	ON_BN_CLICKED(IDC_BTN_DOT, &CMFCApplication1Dlg::OnDot)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCApplication1Dlg::OnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &CMFCApplication1Dlg::OnSub)
	ON_BN_CLICKED(IDC_BTN_MUL, &CMFCApplication1Dlg::OnMul)
	ON_BN_CLICKED(IDC_BTN_DIV, &CMFCApplication1Dlg::OnDiv)
	ON_BN_CLICKED(IDC_BTN_EQ, &CMFCApplication1Dlg::OnEq)
	ON_BN_CLICKED(IDC_BTN_CLR, &CMFCApplication1Dlg::OnClr)
	ON_BN_CLICKED(IDC_BTN_DEL, &CMFCApplication1Dlg::OnDel)
	ON_BN_CLICKED(IDC_BTN_SIGN, &CMFCApplication1Dlg::OnSign)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rc;
	GetWindowRect(&rc);
	int width = 400;
	int height = 600;
	SetWindowPos(nullptr, rc.left, rc.top, width, height, SWP_NOZORDER | SWP_NOMOVE);

	m_DisplayFont.CreatePointFont(200, _T("Segoe UI")); // 20pt
	CWnd* pDisplay = GetDlgItem(IDC_EDIT1);
	if (pDisplay && pDisplay->GetSafeHwnd())
	{
		pDisplay->SetFont(&m_DisplayFont);
	}

	// Force OnSize to run once with this initial size
	PostMessage(WM_SIZE, SIZE_RESTORED, MAKELPARAM(width, height));

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

double CMFCApplication1Dlg::StringToDouble(const CString& s)
{
	return _wtof(s);
}

CString CMFCApplication1Dlg::DoubleToString(double v)
{
	CString s;
	s.Format(L"%.15g", v);
	return s;
}

void CMFCApplication1Dlg::SetDisplay(const CString& s)
{
	Editcontrol = s;
	UpdateData(FALSE);
}

void CMFCApplication1Dlg::StartNewIfNeeded()
{
	if (m_newInput)
	{
		Editcontrol = _T("0");
		m_newInput = false;
		m_hasDot = false;
	}
}

void CMFCApplication1Dlg::AppendDigit(int d)
{
	UpdateData(TRUE);
	StartNewIfNeeded();

	if (Editcontrol == _T("0"))
	{
		CString digit;
		digit.Format(_T("%d"), d);
		Editcontrol = digit;
	}
	else
	{
		CString digit;
		digit.Format(_T("%d"), d);
		Editcontrol += digit;
	}

	SetDisplay(Editcontrol);
}

void CMFCApplication1Dlg::ApplyPendingOp(double right, bool showResult)
{
	if (m_op == '+') m_accum += right;
	else if (m_op == '-') m_accum -= right;
	else if (m_op == '*') m_accum *= right;
	else if (m_op == '/')
	{
		if (right == '0')
		{
			SetDisplay(_T("Error"));
			m_accum = 0.0; m_op = 0; m_newInput = true; m_hasDot = false;
			return;
		}
		m_accum /= right;
	}

	if (showResult) SetDisplay(DoubleToString(m_accum));

}

void CMFCApplication1Dlg::ClearAll()
{
	m_accum = 0;
	m_op = 0;
	m_newInput = true;
	m_hasDot = false;
	SetDisplay(_T("0"));
}

void CMFCApplication1Dlg::OnOpImpl(TCHAR op)
{
	UpdateData(TRUE);
	double current = (Editcontrol == _T("Error")) ? 0.0 : StringToDouble(Editcontrol);

	if (m_op == 0)
	{
		m_accum = current;

	}
	else if (!m_newInput)
	{
		ApplyPendingOp(current, true);
	}
	m_op = op;
	m_newInput = true;
	m_hasDot = false;
}

void CMFCApplication1Dlg::OnBtn0() { AppendDigit(0); }
void CMFCApplication1Dlg::OnBtn1() { AppendDigit(1); }
void CMFCApplication1Dlg::OnBtn2() { AppendDigit(2); }
void CMFCApplication1Dlg::OnBtn3() { AppendDigit(3); }
void CMFCApplication1Dlg::OnBtn4() { AppendDigit(4); }
void CMFCApplication1Dlg::OnBtn5() { AppendDigit(5); }
void CMFCApplication1Dlg::OnBtn6() { AppendDigit(6); }
void CMFCApplication1Dlg::OnBtn7() { AppendDigit(7); }
void CMFCApplication1Dlg::OnBtn8() { AppendDigit(8); }
void CMFCApplication1Dlg::OnBtn9() { AppendDigit(9); }

void CMFCApplication1Dlg::OnDot()
{
	UpdateData(true);
	if (m_newInput) { Editcontrol = _T("0"); m_newInput = false; }
	if (!m_newInput)
	{
		Editcontrol += _T(".");
		m_hasDot = true;
		SetDisplay(Editcontrol);
	}
}

void CMFCApplication1Dlg::OnAdd() { OnOpImpl('+'); }
void CMFCApplication1Dlg::OnSub() { OnOpImpl('-'); }
void CMFCApplication1Dlg::OnMul() { OnOpImpl('*'); }
void CMFCApplication1Dlg::OnDiv() { OnOpImpl('/'); }

void CMFCApplication1Dlg::OnEq()
{
	UpdateData(TRUE);
	if (m_op != 0 && Editcontrol != _T("Error"))
	{
		double right = StringToDouble(Editcontrol);
		ApplyPendingOp(right, true);
		m_op = 0;
		m_newInput = true;
		m_hasDot = (Editcontrol.Find('.') != -1);
	}
}

void CMFCApplication1Dlg::OnClr()
{
	ClearAll();
}

void CMFCApplication1Dlg::OnDel()
{
	UpdateData(TRUE);
	if (m_newInput || Editcontrol == _T("Error")) return;
	if (Editcontrol.GetLength() <= 1) {
		Editcontrol = _T("0");
		m_hasDot = false;
		m_newInput = true;
	}
	else {
		if (Editcontrol.Right(1) == _T(".")) m_hasDot = false;
		Editcontrol.Truncate(Editcontrol.GetLength() - 1);
	}
	SetDisplay(Editcontrol);
}

void CMFCApplication1Dlg::OnSign()
{
	UpdateData(TRUE);
	if (Editcontrol == _T("0") || Editcontrol == _T("Error")) return;
	if (Editcontrol.Left(1) == _T("-")) Editcontrol = Editcontrol.Mid(1);
	else Editcontrol = _T("-") + Editcontrol;
	SetDisplay(Editcontrol);
}

void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (cx <= 0 || cy <= 0) return;

	int margin = 10;

	// === Resize Display ===
	if (GetDlgItem(IDC_EDIT1))
	{
		CRect rcDisplay(margin, margin, cx - margin, 100); // height fixed
		GetDlgItem(IDC_EDIT1)->MoveWindow(&rcDisplay);
	}

	// === Resize Buttons (grid layout) ===
	// Example: 4 columns, 5 rows
	int rows = 5;
	int cols = 4;
	int btnW = (cx - (cols + 1) * margin) / cols;
	int btnH = (cy - 110 - (rows + 1) * margin) / rows; // 80px for display

	// Button IDs in order (row by row)
	int buttonIDs[5][4] = {
		{ IDC_BTN_CLR, IDC_BTN_DEL, IDC_BTN_SIGN, IDC_BTN_DIV },
		{ IDC_BTN_7, IDC_BTN_8, IDC_BTN_9, IDC_BTN_MUL },
		{ IDC_BTN_4, IDC_BTN_5, IDC_BTN_6, IDC_BTN_SUB },
		{ IDC_BTN_1, IDC_BTN_2, IDC_BTN_3, IDC_BTN_ADD },
		{ IDC_BTN_0, IDC_BTN_DOT, IDC_BTN_EQ,0}
	};

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			int id = buttonIDs[r][c];
			if (id != 0 && GetDlgItem(id))
			{
				int left = margin + c * (btnW + margin);
				int top = 100 + margin + r * (btnH + margin);
				GetDlgItem(id)->MoveWindow(left, top, btnW, btnH);
			}
		}
	}
}

HBRUSH CMFCApplication1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_EDIT1)
	{
		// Black background
		pDC->SetBkColor(RGB(0, 0, 0));

		// Green glowing text
		pDC->SetTextColor(RGB(0, 255, 0));

		// Return solid black brush
		static CBrush br(RGB(0, 0, 0));
		return br;
	}

	return hbr;
}

