#pragma once


// CMemoryModifyDlg �Ի���

class CMemoryModifyDlg : public CDialog
{
	DECLARE_DYNAMIC(CMemoryModifyDlg)

public:
	CMemoryModifyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMemoryModifyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MEMORYMODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DWORD HexToDword(CString hex);

	DECLARE_MESSAGE_MAP()
public:
	CString m_tName;
public:
	CString m_tAddr;
public:
	CString m_tNewHex;
public:
	afx_msg void OnBnClickedOk();
};
