#pragma once
#include <winsvc.h>

class CServerManage
{
public:
	CServerManage(void);
public:
	~CServerManage(void);

	void EnumServername(ENUM_SERVICE_STATUS** lpservice,
		DWORD serverType,
		DWORD serverState,
		DWORD* servicesReturned); //ö��ϵͳ�ķ�����״̬��
	BOOL ChangeServerStatusByname(wchar_t* servername,BOOL start = TRUE);

	BOOL GetServerStatusByname(wchar_t* servername,SERVICE_STATUS&  ssStatus);
};
