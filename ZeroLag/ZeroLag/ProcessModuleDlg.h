#pragma once
#include "afxcmn.h"


// CProcessModuleDlg �Ի���

class CProcessModuleDlg : public CDialog
{
	DECLARE_DYNAMIC(CProcessModuleDlg)

public:
	CProcessModuleDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProcessModuleDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PROCESS_MODULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ProcessModuleList;
public:
	virtual BOOL OnInitDialog();
	int Init();
	int Pid;
};
