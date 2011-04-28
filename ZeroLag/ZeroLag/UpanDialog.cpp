// UpanDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "UpanDialog.h"


// CUpanDialog �Ի���

IMPLEMENT_DYNAMIC(CUpanDialog, CDialog)

CUpanDialog::CUpanDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CUpanDialog::IDD, pParent)
{

}

CUpanDialog::~CUpanDialog()
{
}

void CUpanDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_UPAN_DRIVELIST, m_DriveList);
	DDX_Control(pDX, IDC_COMBO_UPAN_DRIVELIST2, m_UpanList);
}


BEGIN_MESSAGE_MAP(CUpanDialog, CDialog)
	ON_BN_CLICKED(IDC_UPAN_CREATEAUTORUN, &CUpanDialog::OnBnClickedUpanCreateautorun)
	ON_CBN_DROPDOWN(IDC_COMBO_UPAN_DRIVELIST, &CUpanDialog::OnCbnDropdownComboUpanDrivelist)
	ON_BN_CLICKED(IDC_UPAN_KILLHIDE, &CUpanDialog::OnBnClickedUpanKillhide)
	ON_CBN_DROPDOWN(IDC_COMBO_UPAN_DRIVELIST2, &CUpanDialog::OnCbnDropdownComboUpanDrivelist2)
END_MESSAGE_MAP()


// CUpanDialog ��Ϣ�������

void CUpanDialog::OnBnClickedUpanCreateautorun()
{
	int index = m_DriveList.GetCurSel();
	if (index == CB_ERR)
	{
		//�Д��Ƿ����x��űP
		MessageBox(L"Ո���x��űP���c�����߰��o��");
	}
	else
	{
		CString name;
		m_DriveList.GetLBText(index, name);
		WCHAR ch = name.GetAt(0);
		char n = *(char *)&ch;
		Upan.StopAutorun(n);
		MessageBox(L"������ɣ�");
	}
}

void CUpanDialog::OnCbnDropdownComboUpanDrivelist()
{
	m_DriveList.ResetContent();
	CString temp;
	for (char ch='C';ch<='Z';ch++)
	{
		if (Upan.IsEnableDrive(ch) == TRUE)
		{
			temp.Format(L"%c:",ch);
			m_DriveList.AddString(temp);
		}
	}
}

BOOL CUpanDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CUpanDialog::OnBnClickedUpanKillhide()
{
	int index = m_UpanList.GetCurSel();
	if (index == CB_ERR)
	{
		//�Д��Ƿ����x��űP
		MessageBox(L"Ո���x��űP���c���O�ð��o��");
	}
	else
	{
		CString name;
		m_UpanList.GetLBText(index, name);
		WCHAR ch = name.GetAt(0);
		char n = *(char *)&ch;
		MessageBox(L"Ո���ĵȺ������д����Ԅ��P�]��");
		Upan.KillHide(n);
		MessageBox(L"�O����ɣ�");
	}
}

void CUpanDialog::OnCbnDropdownComboUpanDrivelist2()
{
	m_UpanList.ResetContent();
	CString temp;
	for (char ch='D';ch<='Z';ch++)
	{
		if (Upan.IsRemoveDrive(ch) == TRUE)
		{
			temp.Format(L"%c:",ch);
			m_UpanList.AddString(temp);
		}
	}
}
