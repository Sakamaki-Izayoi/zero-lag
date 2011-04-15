#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "RunManage.h"


// CRunManageDlg �Ի���

class CRunManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CRunManageDlg)

public:
	CRunManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRunManageDlg();

	friend void ScanRegRunThread(LPVOID param);
	friend void ScanDirRunThread(LPVOID param);

// �Ի�������
	enum { IDD = IDD_DIALOG_RUNMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	CString GetFilenameInPathname(CString pathname);

	HANDLE hThread1,hThread2;
	HTREEITEM ht0,ht1;
	int ThreadStatus;

	CRunManage *RunManage;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRunmbegin();
public:
	CButton m_bBegin;
public:
	virtual BOOL OnInitDialog();
public:
	CTreeCtrl m_tRunList;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnRunmGoto();
public:
	afx_msg void OnRunmBaidu();
public:
	afx_msg void OnNMRclickTreeRunmanage(NMHDR *pNMHDR, LRESULT *pResult);
};
