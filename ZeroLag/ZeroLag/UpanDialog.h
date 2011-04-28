#pragma once

#include "Upan.h"
#include "afxwin.h"

// CUpanDialog �Ի���

class CUpanDialog : public CDialog
{
	DECLARE_DYNAMIC(CUpanDialog)

public:
	CUpanDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpanDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_UPAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUpanCreateautorun();
public:
	afx_msg void OnCbnDropdownComboUpanDrivelist();

	CUpan Upan;
public:
	CComboBox m_DriveList;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedUpanKillhide();
public:
	afx_msg void OnCbnDropdownComboUpanDrivelist2();
public:
	CComboBox m_UpanList;
};
