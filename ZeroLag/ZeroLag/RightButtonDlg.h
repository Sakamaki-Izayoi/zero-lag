#pragma once

#include "RightButton.h"

// CRightButtonDlg �Ի���

class CRightButtonDlg : public CDialog
{
	DECLARE_DYNAMIC(CRightButtonDlg)

public:
	CRightButtonDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightButtonDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_RIGHTBUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	CRightButton RightButton;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRightRecycle();
public:
	afx_msg void OnBnClickedRightRecycle2();
public:
	afx_msg void OnBnClickedRightMoveto();
public:
	afx_msg void OnBnClickedRightMoveto2();
};
