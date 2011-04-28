// RightButtonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "RightButtonDlg.h"


// CRightButtonDlg �Ի���

IMPLEMENT_DYNAMIC(CRightButtonDlg, CDialog)

CRightButtonDlg::CRightButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRightButtonDlg::IDD, pParent)
{
}

CRightButtonDlg::~CRightButtonDlg()
{
}

void CRightButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRightButtonDlg, CDialog)
	ON_BN_CLICKED(IDC_RIGHT_RECYCLE, &CRightButtonDlg::OnBnClickedRightRecycle)
	ON_BN_CLICKED(IDC_RIGHT_RECYCLE2, &CRightButtonDlg::OnBnClickedRightRecycle2)
	ON_BN_CLICKED(IDC_RIGHT_MOVETO, &CRightButtonDlg::OnBnClickedRightMoveto)
	ON_BN_CLICKED(IDC_RIGHT_MOVETO2, &CRightButtonDlg::OnBnClickedRightMoveto2)
END_MESSAGE_MAP()


// CRightButtonDlg ��Ϣ�������

void CRightButtonDlg::OnBnClickedRightRecycle()
{
	RightButton.AddSystemRecycle();
	MessageBox(L"��ӳɹ�");
}

void CRightButtonDlg::OnBnClickedRightRecycle2()
{
	RightButton.DelSystemRecycle();
	MessageBox(L"�Ƴ��ɹ�");
}

void CRightButtonDlg::OnBnClickedRightMoveto()
{
	RightButton.AddSystemCutTo();
	MessageBox(L"��ӳɹ�");
}

void CRightButtonDlg::OnBnClickedRightMoveto2()
{
	RightButton.DelSystemCutTo();
	MessageBox(L"�Ƴ��ɹ�");
}
