// ServerManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "ServerManageDlg.h"


// CServerManageDlg �Ի���

IMPLEMENT_DYNAMIC(CServerManageDlg, CDialog)

CServerManageDlg::CServerManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerManageDlg::IDD, pParent)
	, m_ServerHide(FALSE)
{

}

CServerManageDlg::~CServerManageDlg()
{
}

void CServerManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SERVER, m_ServerList);
	DDX_Check(pDX, IDC_CHECK_SERVERHIDE, m_ServerHide);
}


BEGIN_MESSAGE_MAP(CServerManageDlg, CDialog)
	ON_BN_CLICKED(IDC_SERVER_FLUSH, &CServerManageDlg::OnBnClickedServerFlush)
	ON_COMMAND(ID_SERVER_STATUS, &CServerManageDlg::OnServerStatus)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_SERVER, &CServerManageDlg::OnNMRclickListServer)
	ON_BN_CLICKED(IDC_CHECK_SERVERHIDE, &CServerManageDlg::OnBnClickedCheckServerhide)
END_MESSAGE_MAP()


// CServerManageDlg ��Ϣ�������

void CServerManageDlg::OnBnClickedServerFlush()
{
	//�@���[��δ�\���}�x��Ġ�B
	UpdateData(TRUE);

	m_ServerList.DeleteAllItems();

	ENUM_SERVICE_STATUS* lpservice = NULL;
	DWORD servicesReturned = 0;
	ServerManage.EnumServername(&lpservice,SERVICE_WIN32|SERVICE_DRIVER,SERVICE_STATE_ALL,&servicesReturned);

	unsigned j=0;
	for(unsigned i=0;i < servicesReturned;i++)
	{
		if (lpservice[i].ServiceStatus.dwCurrentState == SERVICE_RUNNING)
		{
			m_ServerList.InsertItem(j,L"");
			m_ServerList.SetItemText(j,0,lpservice[i].lpServiceName);
			m_ServerList.SetItemText(j,1,lpservice[i].lpDisplayName);
			m_ServerList.SetItemText(j,2,L"���\��");
			j++;
		}
		else if (m_ServerHide == FALSE)
		{
			m_ServerList.InsertItem(j,L"");
			m_ServerList.SetItemText(j,0,lpservice[i].lpServiceName);
			m_ServerList.SetItemText(j,1,lpservice[i].lpDisplayName);
			m_ServerList.SetItemText(j,2,L"��ֹͣ");
			j++;
		}
	}
}

BOOL CServerManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ServerList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_ServerList.InsertColumn(0,L"�������Q",LVCFMT_LEFT,200);
	m_ServerList.InsertColumn(1,L"��������",LVCFMT_LEFT,300);
	m_ServerList.InsertColumn(2,L"���ՠ�B",LVCFMT_LEFT,100);

	OnBnClickedServerFlush();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CServerManageDlg::OnServerStatus()
{
	POSITION pos = m_ServerList.GetFirstSelectedItemPosition();
	int nItem = m_ServerList.GetNextSelectedItem(pos);
	CString SName = m_ServerList.GetItemText(nItem, 0);
	if (m_ServerList.GetItemText(nItem, 2) == "��ֹͣ")
	{
		ServerManage.ChangeServerStatusByname((wchar_t *)SName.GetString(), TRUE);
	} 
	else
	{
		ServerManage.ChangeServerStatusByname((wchar_t *)SName.GetString(), FALSE);
	}
	OnBnClickedServerFlush();
}

void CServerManageDlg::OnNMRclickListServer(NMHDR *pNMHDR, LRESULT *pResult)
{
	//������
	LPPOINT lpoint=new tagPOINT;   
	::GetCursorPos(lpoint);   
	CMenu menu,*pSubMenu; 
	//���ز˵� 
	menu.LoadMenu(IDR_MENU_RIGHT);
	//�����Ӳ˵�,���ò˵�������Ŀ��ʼλ�� 
	pSubMenu=menu.GetSubMenu(3);
	//��ʾ�˵�
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this); 
	pSubMenu->DestroyMenu();

	*pResult = 0;
}

void CServerManageDlg::OnBnClickedCheckServerhide()
{
	OnBnClickedServerFlush();
}
