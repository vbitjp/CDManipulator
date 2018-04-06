#pragma once
#include "afxwin.h"
#include "cdcontroller.h"


// CEraseDialog ダイアログ

class CEraseDialog : public CDialog
{
	DECLARE_DYNAMIC(CEraseDialog)

public:
	CEraseDialog(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CEraseDialog();

// ダイアログ データ
	enum { IDD = IDD_ERASE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CButton m_OKButton;
protected:
	HANDLE m_hThread;
	DWORD m_ThreadID;
	bool m_FastErase;
	CCDController *m_CD;
public:
	void EraseFast(CCDController *cd);
	void EraseCompletely(CCDController *cd);
	bool Erase(void);
	void Complete(void);
	CString m_Message;
	void Incomplete(void);
	afx_msg void OnUpdateDialog();
};
