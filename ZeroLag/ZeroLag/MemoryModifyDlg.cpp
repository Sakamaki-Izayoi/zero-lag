// MemoryModifyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "MemoryModifyDlg.h"
#include "MemoryModify.h"


// CMemoryModifyDlg �Ի���

IMPLEMENT_DYNAMIC(CMemoryModifyDlg, CDialog)

CMemoryModifyDlg::CMemoryModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemoryModifyDlg::IDD, pParent)
	, m_tName(_T("QQ2011"))
	, m_tAddr(_T("0x00112233"))
	, m_tNewHex(_T("0x88888888"))
{

}

CMemoryModifyDlg::~CMemoryModifyDlg()
{
}

void CMemoryModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MEMORYM_PNAME, m_tName);
	DDX_Text(pDX, IDC_MEMORYM_ADDR, m_tAddr);
	DDX_Text(pDX, IDC_MEMORYM_NEWHEX, m_tNewHex);
}


BEGIN_MESSAGE_MAP(CMemoryModifyDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CMemoryModifyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMemoryModifyDlg ��Ϣ�������

void CMemoryModifyDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMemoryModify Modify;
	Modify.Name = m_tName;
	Modify.Init();
	BOOL b = Modify.zWriteMemory(HexToDword(m_tAddr), HexToDword(m_tNewHex));
	if (b == TRUE)
	{
		MessageBox(L"�޸ĳɹ���");
	} 
	else
	{
		MessageBox(L"�޸�ʧ����");
	}
	OnOK();
}

DWORD CMemoryModifyDlg::HexToDword(CString Hex)
{
	char* num = new char[9];
	CString temp = Hex.Mid(2);
	memset(num, 0, 9);
	WideCharToMultiByte(CP_ACP, NULL, temp.GetBuffer(), 8, num, 8, 0, 0);
	DWORD d = strtoul(num, NULL, 16);
	return d;
}