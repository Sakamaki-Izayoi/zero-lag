// ProcessModuleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "ProcessModuleDlg.h"
#include "ProcessModule.h"


// CProcessModuleDlg �Ի���

IMPLEMENT_DYNAMIC(CProcessModuleDlg, CDialog)

CProcessModuleDlg::CProcessModuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessModuleDlg::IDD, pParent)
{

}

CProcessModuleDlg::~CProcessModuleDlg()
{
}

void CProcessModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PROCESS_MODULE, m_ProcessModuleList);
}


BEGIN_MESSAGE_MAP(CProcessModuleDlg, CDialog)
END_MESSAGE_MAP()


// CProcessModuleDlg ��Ϣ�������

BOOL CProcessModuleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ProcessModuleList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_ProcessModuleList.InsertColumn(0,L"ģ�K�R��·��",LVCFMT_LEFT,360);
	m_ProcessModuleList.InsertColumn(1,L"ģ�K�R�����ַ",LVCFMT_LEFT,120);

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

int CProcessModuleDlg::Init()
{
	CProcessModule::GetModule(Pid,&m_ProcessModuleList);
	return 0;
}