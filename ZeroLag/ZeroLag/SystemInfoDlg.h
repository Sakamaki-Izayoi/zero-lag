#pragma once
#include "SystemInfo.h"


// CSystemInfoDlg �Ի���

class CSystemInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CSystemInfoDlg)

public:
	CSystemInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSystemInfoDlg();

	CSystemInfo SystemInfo;

// �Ի�������
	enum { IDD = IDD_DIALOG_SYSTEMINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCpu();
};
