// PeInfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "PeInfoDlg.h"


// CPeInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CPeInfoDlg, CDialog)

CPeInfoDlg::CPeInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPeInfoDlg::IDD, pParent)
	, m_eFileSize(_T(""))
	, m_eFileName(_T(""))
{

}

CPeInfoDlg::~CPeInfoDlg()
{
}

void CPeInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PEINFOLIST, m_SecList);
	DDX_Text(pDX, IDC_EDIT_PEINFOFILESIZE, m_eFileSize);
	DDX_Text(pDX, IDC_EDIT_PEINFOFILENAME, m_eFileName);
}


BEGIN_MESSAGE_MAP(CPeInfoDlg, CDialog)
END_MESSAGE_MAP()


// CPeInfoDlg ��Ϣ�������

BOOL CPeInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	PeInfo.zInit(PathName);

	m_SecList.InsertColumn(0, L"�^����", LVCFMT_LEFT, 80);
	m_SecList.InsertColumn(1, L"�^�δ�С", LVCFMT_LEFT,120);

	m_eFileName = FileName;
	m_eFileSize.Format(L"%d�ֹ�", PeInfo.zGetFileSize());

	UpdateData(FALSE);

	for (int n=0;n<PeInfo.zGetSecNum();n++)
	{
		CString temp;
		PIMAGE_SECTION_HEADER p = PeInfo.zGetSecHeader(n);
		temp.Format(L"%c%c%c%c%c%c%c%c",p->Name[0],p->Name[1],p->Name[2],p->Name[3],p->Name[4],p->Name[5],p->Name[6],p->Name[7]);
		m_SecList.InsertItem(n,L"");
		m_SecList.SetItemText(n,0,temp);
		temp.Format(L"0x%08X",p->SizeOfRawData);
		m_SecList.SetItemText(n,1,temp);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
