// ZeroLagDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZeroLag.h"
#include "ZeroLagDlg.h"
#include "AboutDlg.h"
#include "PeInfoDlg.h"
#include "MemoryModifyDlg.h"
#include "FileMd5Dlg.h"
#include "AutoShutDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZeroLagDlg �Ի���




CZeroLagDlg::CZeroLagDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZeroLagDlg::IDD, pParent)
	, m_CpuUsage(_T(""))
	, m_MemoryUsage(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZeroLagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tcMain);
	DDX_Text(pDX, IDC_STATIC_CPUUSAGE, m_CpuUsage);
	DDX_Text(pDX, IDC_STATIC_MEMORYUSAGE, m_MemoryUsage);
}

BEGIN_MESSAGE_MAP(CZeroLagDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CZeroLagDlg::OnTcnSelchangeTabMain)
	ON_COMMAND(ID_MABOUT, &CZeroLagDlg::OnMabout)
	ON_COMMAND(ID_MCLOSE, &CZeroLagDlg::OnMclose)
	ON_COMMAND(ID_MENU_VIEWPEINFO, &CZeroLagDlg::OnMenuViewpeinfo)
	ON_COMMAND(ID_MEMU_MEMORYMODIFY, &CZeroLagDlg::OnMemuMemorymodify)
	ON_COMMAND(ID_MEMU_FILEMD5, &CZeroLagDlg::OnMemuFilemd5)
	ON_COMMAND(ID_MENE_AUTOSHUT, &CZeroLagDlg::OnMeneAutoshut)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CZeroLagDlg ��Ϣ�������

BOOL CZeroLagDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	
	//�OҕCPUʹ���ʺ̓ȴ�ʹ����
	SetTimer(1,1000,NULL);

	Init();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CZeroLagDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CZeroLagDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CZeroLagDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
/*	switch (m_tcMain.GetCurSel())
	{
	case 0:
		m_pdSignScan->ShowWindow(SW_SHOW);
		m_pdRunManage->ShowWindow(SW_HIDE);
		m_pdProcessManage->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pdSignScan->ShowWindow(SW_HIDE);
		m_pdRunManage->ShowWindow(SW_SHOW);
		m_pdProcessManage->ShowWindow(SW_HIDE);
		break;
	case 2:
		m_pdSignScan->ShowWindow(SW_HIDE);
		m_pdRunManage->ShowWindow(SW_HIDE);
		m_pdProcessManage->ShowWindow(SW_SHOW);
		break;
		
	default:
		break;
	}
*/

	TabCtrlSetShow(m_tcMain.GetCurSel());

	*pResult = 0;
}

void CZeroLagDlg::Init()
{
	m_tcMain.InsertItem(0,L"���ֺ�������");
	m_tcMain.InsertItem(1,L"����헹���");
	m_tcMain.InsertItem(2,L"�M�̹���");
	m_tcMain.InsertItem(3,L"Ӌ��C��Ϣ");
	m_tcMain.InsertItem(4,L"���չ���");
	m_tcMain.InsertItem(5,L"U�P�S�o");
	m_tcMain.InsertItem(6,L"���I�ˆι���");
	m_pdSignScan = new CSignScanDlg();
	m_pdRunManage = new CRunManageDlg();
	m_pdProcessManage = new CProcessManageDlg();
	m_pdSystemInfo = new CSystemInfoDlg();
	m_pdServerManage = new CServerManageDlg();
	m_pdUpanManage = new CUpanDialog();
	m_pdRightButton = new CRightButtonDlg();
	m_pdSignScan->Create(IDD_DIALOG_SIGNSCAN,&m_tcMain);
	m_pdRunManage->Create(IDD_DIALOG_RUNMANAGE,&m_tcMain);
	m_pdProcessManage->Create(IDD_DIALOG_PROCESSMANAGE,&m_tcMain);
	m_pdSystemInfo->Create(IDD_DIALOG_SYSTEMINFO,&m_tcMain);
	m_pdServerManage->Create(IDD_DIALOG_SERVERMANAGE,&m_tcMain);
	m_pdUpanManage->Create(IDD_DIALOG_UPAN,&m_tcMain);
	m_pdRightButton->Create(IDD_DIALOG_RIGHTBUTTON,&m_tcMain);
// 	m_pdSignScan->CenterWindow();
// 	m_pdRunManage->CenterWindow();
// 	m_pdProcessManage->CenterWindow();
// 	m_pdSignScan->ShowWindow(SW_SHOW);
// 	m_pdRunManage->ShowWindow(SW_HIDE);
// 	m_pdProcessManage->ShowWindow(SW_HIDE);
	m_pPages.Add(m_pdSignScan);
	m_pPages.Add(m_pdRunManage);
	m_pPages.Add(m_pdProcessManage);
	m_pPages.Add(m_pdSystemInfo);
	m_pPages.Add(m_pdServerManage);
	m_pPages.Add(m_pdUpanManage);
	m_pPages.Add(m_pdRightButton);
	for (int i=0;i<m_pPages.GetCount();i++)
	{
		m_pPages[i]->CenterWindow();
	}
	TabCtrlSetShow(0);
}
void CZeroLagDlg::OnMabout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CZeroLagDlg::OnMclose()
{
	for (int i=0;i<m_pPages.GetCount();i++)
	{
		m_pPages[i]->DestroyWindow();
		delete m_pPages[i];
	}
// 	m_pdRunManage->DestroyWindow();
// 	m_pdSignScan->DestroyWindow();
// 	m_pdProcessManage->DestroyWindow();
// 	delete m_pdSignScan;
// 	delete m_pdRunManage;
// 	delete m_pdProcessManage;
	CZeroLagDlg::OnOK();
}

void CZeroLagDlg::OnMenuViewpeinfo()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		CPeInfoDlg PeDlg;
		PeDlg.FileName = dlg.GetFileName();
		PeDlg.PathName = dlg.GetPathName();
		PeDlg.DoModal();
	}
}

void CZeroLagDlg::OnMemuMemorymodify()
{
	CMemoryModifyDlg dlg;
	dlg.DoModal();
}

void CZeroLagDlg::OnMemuFilemd5()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		CFileMd5Dlg PeDlg;
		PeDlg.m_PathName = dlg.GetPathName();
		PeDlg.DoModal();
	}
}

void CZeroLagDlg::TabCtrlSetShow(int i)
{
	for (int n=0;n<m_pPages.GetCount();n++)
	{
		m_pPages[n]->ShowWindow(SW_HIDE);
	}
	m_pPages[i]->ShowWindow(SW_SHOW);
}
void CZeroLagDlg::OnMeneAutoshut()
{
	CAutoShutDlg *dlg = new CAutoShutDlg();
	dlg->Create(IDD_DIALOG_AUTOSHUT);
	dlg->ShowWindow(SW_SHOW);
}

void CZeroLagDlg::OnTimer(UINT_PTR nIDEvent)
{
	//�OҕCPU�̓ȴ�ʹ����
	if (nIDEvent == 1)
	{
		if (WatchCpu.GetCpuUsage(&CpuUsage) == 0)
		{
			m_CpuUsage.Format(L"CPUʹ���ʣ�%2d%c",CpuUsage,'%');
		}
		else
		{
			//�@ȡʧ���tֱ���@ʾ50%
			m_CpuUsage.Format(L"CPUʹ���ʣ�%2d%c",50,'%');
			
		}
		WatchMemory.GetMemoryUsage(&MemoryUsage,&MemoryTotal);
		m_MemoryUsage.Format(L"Memoryʹ���ʣ�%4dM/%4dM",MemoryUsage,MemoryTotal);
		UpdateData(FALSE);
	}

	CDialog::OnTimer(nIDEvent);
}
