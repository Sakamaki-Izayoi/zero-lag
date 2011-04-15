// ZeroLagDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "SignScanDlg.h"
#include "RunManageDlg.h"
#include "ProcessManageDlg.h"
#include "SystemInfoDlg.h"
#include "ServerManageDlg.h"
#include "UpanDialog.h"
#include "RightButtonDlg.h"

#include "WatchCpu.h"
#include "WatchMemory.h"

// CZeroLagDlg �Ի���
class CZeroLagDlg : public CDialog
{
// ����
public:
	CZeroLagDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ZEROLAG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CSignScanDlg *m_pdSignScan;
	CRunManageDlg *m_pdRunManage;
	CProcessManageDlg *m_pdProcessManage;
	CSystemInfoDlg *m_pdSystemInfo;
	CServerManageDlg *m_pdServerManage;
	CUpanDialog *m_pdUpanManage;
	CRightButtonDlg *m_pdRightButton;

	typedef CDialog* PDIALOG;
	CArray<PDIALOG, PDIALOG> m_pPages;

	void TabCtrlSetShow(int i);
	void Init();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tcMain;
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMabout();
	afx_msg void OnMclose();
	afx_msg void OnMenuViewpeinfo();
	afx_msg void OnMemuMemorymodify();
	afx_msg void OnMemuFilemd5();
	afx_msg void OnMeneAutoshut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CString m_CpuUsage;
	int CpuUsage;
	CWatchCpu WatchCpu;
	int MemoryUsage,MemoryTotal;
	CWatchMemory WatchMemory;
public:
	CString m_MemoryUsage;
};
