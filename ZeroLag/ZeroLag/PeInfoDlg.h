#pragma once

#include "PeInfo.h"
#include "afxcmn.h"
#include "afxwin.h"

// CPeInfoDlg �Ի���

class CPeInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CPeInfoDlg)

public:
	CPeInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPeInfoDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CPeInfo PeInfo;
	CString FileName,PathName;
public:
	virtual BOOL OnInitDialog();
public:
	CListCtrl m_SecList;
public:
	CString m_eFileSize;
public:
	CString m_eFileName;
};
