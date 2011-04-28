#pragma once
#include ".\public\browsedir.h"

class CSignScan :
	public CBrowseDir
{
public:
	CSignScan(void);
public:
	~CSignScan(void);

	//������Ŀ¼���� 
	int GetSubdirCount() 
	{ 
		return m_nSubdirCount; 
	}
	//�����ļ����� 
	int GetFileCount() 
	{ 
		return m_nFileCount; 
	}

	void SetSubdirCount(int n) 
	{ 
		m_nSubdirCount = n; 
	}
	void SetFileCount(int n) 
	{ 
		m_nFileCount = n; 
		m_DisplayCount = n;
	}

	CListCtrl *pList;
	BOOL HideHave;

protected:
	int m_nFileCount; //�����ļ�����
	int m_nSubdirCount; //������Ŀ¼����
	int m_DisplayCount; //�@ʾ�ļ�����

	virtual bool ProcessFile(const char *filename);

	virtual void ProcessDir(const char *currentdir,const char *parentdir);

	BOOL InitFunc();
	BOOL CheckFileTrust( LPCWSTR lpFileName );
};
