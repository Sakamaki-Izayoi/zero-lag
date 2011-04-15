#include "StdAfx.h"
#include "ServerManage.h"

CServerManage::CServerManage(void)
{
}

CServerManage::~CServerManage(void)
{
}

/* ���ܣ�ö�ٷ��ա�
/  ���÷�ʽ��

	ENUM_SERVICE_STATUS* lpservice;
	SERVICE_STATUS  servicestatus;
	DWORD servicesReturned = 0;
	lpservice = NULL;
	EnumServername(&lpservice,SERVICE_WIN32|SERVICE_DRIVER,
		SERVICE_STATE_ALL,&servicesReturned);
	����ֵ���ԣ�
	for(int i=0;i < servicesReturned;i++)
	{
		cout <<lpservice[i].lpServiceName;
		cout << lpservice[i].lpDisplayName;
		servicestatus = lpservice[i].ServiceStatus;
	}*/
void CServerManage::EnumServername(ENUM_SERVICE_STATUS** lpservice,DWORD serverType,DWORD serverState,DWORD* servicesReturned)
{
	SC_HANDLE       hService = NULL;
	DWORD bytesNeeded,resumeHandle = 0;
	ENUM_SERVICE_STATUS  service,*pservice;
	BOOL	rc;
	hService = OpenSCManager(NULL,NULL,SC_MANAGER_ENUMERATE_SERVICE);
	rc = ::EnumServicesStatus(hService,serverType,serverState,
		&service,sizeof(service),
		&bytesNeeded,servicesReturned,&resumeHandle);
	DWORD lperror = ::GetLastError();
	if ((rc == FALSE) && (lperror == ERROR_MORE_DATA))
	{
		resumeHandle = 0;
		DWORD bytes = bytesNeeded + sizeof(ENUM_SERVICE_STATUS);
		pservice = new ENUM_SERVICE_STATUS [bytes];
		*lpservice = pservice;
		::EnumServicesStatus(hService,serverType,serverState,
			pservice,bytes,
			&bytesNeeded,servicesReturned,&resumeHandle);
    }
	CloseServiceHandle(hService);
	//�ȴ曪©����δ��Q!!!
}

/*���ܣ�������ֹͣservername���񡣳ɹ�����TRUE��ʧ�ܷ���FALSE
//start== TRUE��������
/ start = falseֹͣ����*/
BOOL CServerManage::ChangeServerStatusByname(wchar_t* servername,BOOL start)
{
	if(servername[0] == '\0')
		return FALSE;
	BOOL         hr;
	SC_HANDLE       hSCM;
	SC_HANDLE       hService;
	SERVICE_STATUS  ssStatus;
	DWORD           dwStartTime;
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
	hService = OpenService(hSCM, servername, SERVICE_STOP|SERVICE_START|SERVICE_QUERY_STATUS);
	dwStartTime = GetTickCount();
	hr = QueryServiceStatus(hService, &ssStatus);
	if (!hr) 
	{
		CloseServiceHandle(hService);
		CloseServiceHandle(hSCM);
		return FALSE;
	}
	if(start) //��������
	{
		if (ssStatus.dwCurrentState != SERVICE_RUNNING)
		{
			hr = StartService(hService, 0, NULL);//����
			if (!hr) 
			{
				CloseServiceHandle(hService);
				CloseServiceHandle(hSCM);
				return FALSE;
			}
		}
	}
	else //ֹͣ����
	{
		if (ssStatus.dwCurrentState != SERVICE_STOPPED)
		{
			
			while (ssStatus.dwCurrentState == SERVICE_STOP_PENDING)
			{
				hr = QueryServiceStatus(hService, &ssStatus);
				if (!hr)
				{
					CloseServiceHandle(hService);
					CloseServiceHandle(hSCM);
					return FALSE;
				}
				if (ssStatus.dwCurrentState == SERVICE_STOPPED)
					break;
			}
			hr = ControlService(hService, SERVICE_CONTROL_STOP, &ssStatus);//ֹͣ
			if (!hr)
			{
				CloseServiceHandle(hService);
				CloseServiceHandle(hSCM);
				return FALSE;
			}
		}
	}
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCM);
	return TRUE;
}

/*�õ������״̬*/
BOOL CServerManage::GetServerStatusByname(wchar_t* servername,SERVICE_STATUS&  ssStatus)
{
	if(servername[0] == '\0')
		return FALSE;
	HRESULT         hr;
	SC_HANDLE       hSCM;
	SC_HANDLE       hService;
	DWORD           dwStartTime;
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
	hService = OpenService(hSCM, servername,SERVICE_QUERY_STATUS);
	dwStartTime = GetTickCount();
	hr = QueryServiceStatus(hService, &ssStatus);
	if (!hr) 
	{
		CloseServiceHandle(hService);
		CloseServiceHandle(hSCM);
		return FALSE;
	}
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCM);
	return TRUE;
}