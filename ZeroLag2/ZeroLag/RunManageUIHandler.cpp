#include "RunManageUIHandler.h"				  
#include "stdafx.h"
#include "MainWnd.h"

void CRunManageUIHandler::init(CMainWnd *p)
{
	pMain = p;

	if( !RunTree.Create( pMain->GetViewHWND(), 3001 ) )
	{
		CKuiMsgBox::Show( _T("�޷���ʼ�����ؼ�") );
	}
	else
	{
		scan();
	}
}



CRunManageUIHandler::CRunManageUIHandler(void)
{
}


CRunManageUIHandler::~CRunManageUIHandler(void)
{
}

void CRunManageUIHandler::scan()
{
	RunTree.DeleteAllItems();
	pMain->SetItemVisible(3101,FALSE);

	//0Ϊȫ��ɨ�����
	ThreadStatus = 2;
	ht0 = RunTree.InsertItem( _T("ע���������"), NULL, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
	ht1 = RunTree.InsertItem( _T("�ļ���������"), NULL, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );

	RunManage = new CRunManage();
	RunManage->init();
	hThread1 = CreateThread(0,0,(LPTHREAD_START_ROUTINE)ScanRegRunThread,this,0,0);
	hThread2 = CreateThread(0,0,(LPTHREAD_START_ROUTINE)ScanDirRunThread,this,0,0);
}

void CRunManageUIHandler::OnRunScan()
{
	scan();

}
void ScanRegRunThread(LPVOID param)
{
	CRunManageUIHandler *p = (CRunManageUIHandler *)param;

	CString temp;

	int count = p->RunManage->RegEnumer->GetCount();
	if (count == 0)
	{
		p->RunTree.InsertItem( _T("�޿���������"),  p->ht0, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
	}
	else
	{
		for (int i=0;i<count;i++)
		{
			temp.Format("%s", p->RunManage->RegEnumer->GetItem(i).strPath);
			p->RunTree.InsertItem(temp,  p->ht0, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		}
	}

	if (--(p->ThreadStatus) == 0)
	{
		p->pMain->SetItemVisible(3101,TRUE);
		delete p->RunManage;
	}
	CloseHandle(p->hThread1);
}

void ScanDirRunThread(LPVOID param)
{
	CRunManageUIHandler *p = (CRunManageUIHandler *)param;

	CString temp;

	int count = p->RunManage->DirEnumer->GetCount();
	if (count == 0)
	{
		p->RunTree.InsertItem( _T("�޿���������"),  p->ht1, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
	}
	else
	{
		for (int i=0;i<count;i++)
		{
			temp.Format("%s", p->RunManage->DirEnumer->GetItem(i).strParam);
			p->RunTree.InsertItem(temp,  p->ht1, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		}
	}

	if (--(p->ThreadStatus) == 0)
	{
		p->pMain->SetItemVisible(3101,TRUE);
		delete p->RunManage;
	}
	CloseHandle(p->hThread2);
}
