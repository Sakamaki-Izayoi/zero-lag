// ZeroLag.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CZeroLagApp:
// �йش����ʵ�֣������ ZeroLag.cpp
//

class CZeroLagApp : public CWinApp
{
public:
	CZeroLagApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CZeroLagApp theApp;