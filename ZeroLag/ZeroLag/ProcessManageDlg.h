#pragma once
#include "afxcmn.h"
#include "ProcessManage.h"
#include "afxwin.h"


// CProcessManageDlg �Ի���

class CProcessManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CProcessManageDlg)

public:
	CProcessManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProcessManageDlg();

	friend void EnumProcesseThread(LPVOID param);
	CString GetFilenameInPathname(CString pathname);

// �Ի�������
	enum { IDD = IDD_DIALOG_PROCESSMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	CProcessManage *ProcessManage;
	HANDLE hThread;

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_tcProcessList;
public:
	afx_msg void OnBnClickedProcessmScan();
public:
	CButton m_bbegin;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnProcessmGoto();
public:
	afx_msg void OnProcessmBaidu();
public:
	afx_msg void OnProcessmPeinfo();
public:
	afx_msg void OnProcessmClose();
public:
	afx_msg void OnNMRclickListProcess(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnProcessModule();
};
