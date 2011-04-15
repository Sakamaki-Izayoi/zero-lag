#include "StdAfx.h"
#include "ProcessManage.h"

CProcessManage::CProcessManage(void)
{
}

CProcessManage::~CProcessManage(void)
{
	ProcessList.clear();
}

void CProcessManage::Init()
{
	DWORD aProcesses[1024], cbNeeded;
	ProcessStruct ps;

	AdjustPurview();

	//ö��ϵͳ����ID�б�
	if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
	{
		return;
	}
	//�����������
	Count = cbNeeded / sizeof(DWORD);
	// �õ�ÿ�����̵����ƺ�ID
	for (int i=0; i<Count;i++)
	{
		ps.pid = aProcesses[i];
		PrintProcessNameAndID(aProcesses[i], ps.name);
		ProcessList.push_back(ps);
	}
}

void CProcessManage::Init2()
{
	HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (!hSnapshot)
	{
		MessageBox(0, L"create snapshot failed!", L"", 0);
		return;
	}

	PROCESSENTRY32 pe;
	ProcessStruct ps;
	Count = 0;

	pe.dwSize=sizeof(PROCESSENTRY32);
	BOOL retval=Process32First(hSnapshot,&pe);
	while(retval)
	{
		Count++;
		ps.pid = pe.th32ProcessID;
		StrCpy(ps.name, pe.szExeFile);
		ProcessList.push_back(ps);
		retval=Process32Next(hSnapshot,&pe);
	}

	CloseHandle(hSnapshot);
}

int CProcessManage::GetCount()
{
	return Count;
}

ProcessStruct CProcessManage::GetProcessInfo(int i)
{
	return ProcessList[i];
}

//��������Ȩ��
BOOL  CProcessManage::AdjustPurview()
{
	TOKEN_PRIVILEGES TokenPrivileges;
	BOOL bRet;
	HANDLE hToken;

	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &TokenPrivileges.Privileges[0].Luid);   
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);

	TokenPrivileges.PrivilegeCount = 1;   
	TokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	bRet = AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, 0, NULL, NULL);

	CloseHandle(hToken);
	return bRet;
}


void CProcessManage::PrintProcessNameAndID(DWORD processID,WCHAR* pPathName)
{
	//ȡ�ý��̵ľ��
	HANDLE hProcess = OpenProcess( 
		PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, 
		processID );
	memset(pPathName, 0, MAX_PATH);
	//ȡ�ý�������
	if ( hProcess )
	{
		//HMODULE hMod;
		//DWORD cbNeeded;
		//if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded) )
		{
			GetModuleFileNameEx(hProcess,NULL,pPathName,MAX_PATH);   
		}
	}
	CloseHandle( hProcess );
}

BOOL CProcessManage::TerminateProcessById(DWORD dwId)
{
	BOOL bRet=FALSE;
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwId);
	if(hProcess!=NULL)
	{
		bRet=TerminateProcess(hProcess,0);
	}
	CloseHandle(hProcess);
	return bRet;
}