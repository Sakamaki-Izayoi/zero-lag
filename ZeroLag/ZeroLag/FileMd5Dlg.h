#pragma once


// CFileMd5Dlg �Ի���

class CFileMd5Dlg : public CDialog
{
	DECLARE_DYNAMIC(CFileMd5Dlg)

public:
	CFileMd5Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileMd5Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_FILEMD5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_PathName;
public:
	CString m_md5_16;
public:
	CString m_md5_32;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedFilemd516();
public:
	afx_msg void OnBnClickedFilemd532();
};
