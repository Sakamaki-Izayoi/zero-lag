#pragma once


// CSignScanFileTypeDlg �Ի���

class CSignScanFileTypeDlg : public CDialog
{
	DECLARE_DYNAMIC(CSignScanFileTypeDlg)

public:
	CSignScanFileTypeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignScanFileTypeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SIGNSCAN_FILETYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_FileType;
public:
	BOOL m_HideHave;
};
