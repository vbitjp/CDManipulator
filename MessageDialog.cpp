// MessageDialog.cpp : 実装ファイル
//

#include "stdafx.h"
#include "cdm.h"
#include "MessageDialog.h"
#include ".\messagedialog.h"


// CMessageDialog ダイアログ

IMPLEMENT_DYNAMIC(CMessageDialog, CDialog)
CMessageDialog::CMessageDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageDialog::IDD, pParent)
	, m_Message(_T(""))
	, m_Title(_T(""))
{
}

CMessageDialog::~CMessageDialog()
{
}

void CMessageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE, m_Message);
}


BEGIN_MESSAGE_MAP(CMessageDialog, CDialog)
END_MESSAGE_MAP()


// CMessageDialog メッセージ ハンドラ

void CMessageDialog::MessageBox(LPCTSTR Title, LPCTSTR Message)
{
	m_Title = Title;
	m_Message = Message;
	DoModal();
}

BOOL CMessageDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO :  ここに初期化を追加してください
	SetWindowText(m_Title);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}
