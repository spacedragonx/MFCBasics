
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "afxwin.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()


// Implementation
private:
	HICON m_hIcon;
	CString Editcontrol;

	double m_accum = 0.0;
	TCHAR m_op = 0;
	bool m_newInput = false;
	bool m_hasDot = false;

	CFont m_DisplayFont;

	static double StringToDouble(const CString& s);
	static CString DoubleToString(double v);
	void SetDisplay(const CString& s);
	void AppendDigit(int d);
	void StartNewIfNeeded();
	void ApplyPendingOp(double right, bool showresult = true);
	void ClearAll();
	void OnOpImpl(TCHAR op);

	afx_msg void OnBtn0();
	afx_msg void OnBtn1();
	afx_msg void OnBtn2();
	afx_msg void OnBtn3();
	afx_msg void OnBtn4();
	afx_msg void OnBtn5();
	afx_msg void OnBtn6();
	afx_msg void OnBtn7();
	afx_msg void OnBtn8();
	afx_msg void OnBtn9();

	// Other controls
	afx_msg void OnDot();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	afx_msg void OnMul();
	afx_msg void OnDiv();
	afx_msg void OnEq();
	afx_msg void OnClr();
	afx_msg void OnDel();
	afx_msg void OnSign();

	// Generated message map functions
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
public:
	afx_msg void OnEnChangeEdit1();
	
	
	afx_msg void OnBnClickedCancel();
};
