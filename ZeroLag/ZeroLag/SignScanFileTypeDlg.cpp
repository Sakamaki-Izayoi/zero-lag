// SignScanFileTypeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "SignScanFileTypeDlg.h"


// CSignScanFileTypeDlg �Ի���

IMPLEMENT_DYNAMIC(CSignScanFileTypeDlg, CDialog)

CSignScanFileTypeDlg::CSignScanFileTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignScanFileTypeDlg::IDD, pParent)
{

}

CSignScanFileTypeDlg::~CSignScanFileTypeDlg()
{
}

void CSignScanFileTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_FileType);
	DDX_Radio(pDX, IDC_RADIO3, m_HideHave);
}


BEGIN_MESSAGE_MAP(CSignScanFileTypeDlg, CDialog)
END_MESSAGE_MAP()


// CSignScanFileTypeDlg ��Ϣ�������
