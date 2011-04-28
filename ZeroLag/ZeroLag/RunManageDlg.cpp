// RunManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "RunManageDlg.h"


// CRunManageDlg �Ի���

IMPLEMENT_DYNAMIC(CRunManageDlg, CDialog)

CRunManageDlg::CRunManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRunManageDlg::IDD, pParent)
{

}

CRunManageDlg::~CRunManageDlg()
{
}

void CRunManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_RUNMBEGIN, m_bBegin);
	DDX_Control(pDX, IDC_TREE_RUNMANAGE, m_tRunList);
}


BEGIN_MESSAGE_MAP(CRunManageDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_RUNMBEGIN, &CRunManageDlg::OnBnClickedButtonRunmbegin)
	ON_WM_TIMER()
	ON_COMMAND(ID_RUNM_GOTO, &CRunManageDlg::OnRunmGoto)
	ON_COMMAND(ID_RUNM_BAIDU, &CRunManageDlg::OnRunmBaidu)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_RUNMANAGE, &CRunManageDlg::OnNMRclickTreeRunmanage)
END_MESSAGE_MAP()


// CRunManageDlg ��Ϣ�������

void CRunManageDlg::OnBnClickedButtonRunmbegin()
{
	//��՘��ؼ�
	m_tRunList.DeleteAllItems();

	m_bBegin.EnableWindow(FALSE);
	ThreadStatus = 2;
	//ȫ�������ꮅ�r��ThreadStatus==0,���o�֏Ϳ���

	//0���]�Ա톢��헒���
	//1���ļ��A����헒���
	ht0 = m_tRunList.InsertItem(L"RegRun");
	ht1 = m_tRunList.InsertItem(L"DirRun");

	//100ms��ˢ�£�չ�_���ؼ�
	CRunManageDlg::SetTimer(0, 100, 0);

	RunManage = new CRunManage();
	RunManage->init();
	hThread1 = CreateThread(0,0,(LPTHREAD_START_ROUTINE)ScanRegRunThread,this,0,0);
	hThread2 = CreateThread(0,0,(LPTHREAD_START_ROUTINE)ScanDirRunThread,this,0,0);
}

void ScanRegRunThread(LPVOID param)
{
	CRunManageDlg *p = (CRunManageDlg *)param;
	
	CString temp;

	int count = p->RunManage->RegEnumer->GetCount();
	if (count == 0)
	{
		p->m_tRunList.InsertItem(L"�o�_�C�����", p->ht0);
	}
	else
	{
		for (int i=0;i<count;i++)
		{
			temp.Format(L"%s", p->RunManage->RegEnumer->GetItem(i).strPath);
			p->m_tRunList.InsertItem(temp, p->ht0);
		}
	}
	
	if (--(p->ThreadStatus) == 0)
	{
		p->m_bBegin.EnableWindow(TRUE);
		delete p->RunManage;
	}
	CloseHandle(p->hThread1);
}

void ScanDirRunThread(LPVOID param)
{
	CRunManageDlg *p = (CRunManageDlg *)param;

	CString temp;

	int count = p->RunManage->DirEnumer->GetCount();
	if (count == 0)
	{
		p->m_tRunList.InsertItem(L"�o�_�C�����", p->ht1);
	}
	else
	{
		for (int i=0;i<count;i++)
		{
			temp.Format(L"%s", p->RunManage->DirEnumer->GetItem(i).strParam);
			p->m_tRunList.InsertItem(temp, p->ht0);
		}
	}

	if (--(p->ThreadStatus) == 0)
	{
		p->m_bBegin.EnableWindow(TRUE);
		delete p->RunManage;
	}
	CloseHandle(p->hThread2);
}
BOOL CRunManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//�Ԅ��M��һ�Β���
	OnBnClickedButtonRunmbegin();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CRunManageDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 0)
	{
		//չ�_���ؼ�
		m_tRunList.Expand(ht0, TVE_EXPAND);
		m_tRunList.Expand(ht1, TVE_EXPAND);
		CRunManageDlg::KillTimer(0);
	}

	CDialog::OnTimer(nIDEvent);
}

void CRunManageDlg::OnRunmGoto()
{
	HTREEITEM  h = m_tRunList.GetSelectedItem();
	CString pathname = m_tRunList.GetItemText(h);
	CString sparam;
	sparam.Format(L"/select,%s",pathname);
	ShellExecute(0, L"open", L"explorer.exe", sparam , NULL,SW_SHOWNORMAL);
}

void CRunManageDlg::OnRunmBaidu()
{
	HTREEITEM  h = m_tRunList.GetSelectedItem();
	CString pathname = m_tRunList.GetItemText(h);
	CString url;
	url.Format(L"http://www.baidu.com/s?wd=%s", GetFilenameInPathname(pathname));
	ShellExecute(0, L"open", url, L"", L"", SW_SHOW );
}

void CRunManageDlg::OnNMRclickTreeRunmanage(NMHDR *pNMHDR, LRESULT *pResult)
{
	//������
	LPPOINT lpoint=new tagPOINT;   
	::GetCursorPos(lpoint);   
	CMenu menu,*pSubMenu; 
	//���ز˵� 
	menu.LoadMenu(IDR_MENU_RIGHT);
	//�����Ӳ˵�,���ò˵�������Ŀ��ʼλ�� 
	pSubMenu=menu.GetSubMenu(1);
	//��ʾ�˵�
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this); 
	pSubMenu->DestroyMenu();
	*pResult = 0;
}

CString CRunManageDlg::GetFilenameInPathname(CString pathname)
{
	int i,j=0;
	i = pathname.Find('\\');
	while (i != -1)
	{
		j = i;
		i = pathname.Find('\\',j+1);
	}
	return pathname.Mid(j+1);
}