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
		HTREEITEM hItem = RunTree.InsertItem( _T("ע���������"), NULL, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ1"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ2"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ3"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ4"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ5"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );

		hItem = RunTree.InsertItem( _T("Ŀ¼������"), NULL, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ1"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ2"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ3"), hItem, NULL, KUIMulStatusTree::EM_TVIS_CHECK );
		RunTree.InsertItem( _T("������Ŀ4"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ5"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );

		hItem = RunTree.InsertItem( _T("����������"), NULL, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ1"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ2"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ3"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ4"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
		RunTree.InsertItem( _T("������Ŀ5"), hItem, NULL, KUIMulStatusTree::EM_TVIS_UNCHECK );
	}
}



CRunManageUIHandler::CRunManageUIHandler(void)
{
}


CRunManageUIHandler::~CRunManageUIHandler(void)
{
}
