// TraceRichEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TraceDebug.h"
#include "TextureManager.h"
// CTraceRichEdit


// CTraceRichEdit ��Ϣ�������



CGameTraceService::CGameTraceService()
{
	m_pTraceService = NULL;
	m_szLogFile[0]=0;
}

void CGameTraceService::SetInterFace( IGameTraceService *pTraceService )
{	
	ASSERT( pTraceService != NULL );
	if ( pTraceService == NULL ) return;

	m_pTraceService = pTraceService;
}

bool CGameTraceService::TraceString( LPCTSTR pszString, enGameTraceLevel TraceLevel )
{
	if ( m_pTraceService == NULL ) return false;

	return m_pTraceService->TraceString(pszString,TraceLevel);
}

bool CGameTraceService::TraceString( enGameTraceLevel TraceLevel,LPCTSTR pszString, ... )
{
	//��û�е��Դ���ʱ����Ĭ�ϲ����ı�����ʽ��¼����ǰ����Ҫ���������ļ�����
	if ( m_pTraceService == NULL ) 
	{
		FILE *hf = NULL;
		va_list argList;
		if(!m_szLogFile[0]) return false;
		fopen_s(&hf,(CT2CA)m_szLogFile, "a");
		if(!hf) return false;
		va_start(argList, pszString);
		vfprintf(hf, (CT2CA)pszString, argList);
		va_end(argList);
		fprintf(hf, "\n");
		fclose(hf);

		return true;
	}
	else
	{
		CString StrTraceString;

		va_list argList;
		va_start( argList, pszString );
		StrTraceString.FormatV( pszString, argList );
		va_end( argList );

		return m_pTraceService->TraceString(StrTraceString,TraceLevel);
	}
}

CGameTraceService* CGameTraceService::GetInstance()
{
	static CGameTraceService _Instance;

	return &_Instance;
}

void CGameTraceService::SetLogFile( LPCTSTR lpszFileName )
{
	TCHAR szWorkDirectory[MAX_PATH];
	TextureManager->GetWorkDirectory(szWorkDirectory,CountArray(szWorkDirectory));

	_sntprintf_s(m_szLogFile,CountArray(m_szLogFile),TEXT("%s\\%s"),szWorkDirectory,lpszFileName);

	FILE *hf=NULL;
	fopen_s(&hf,(CT2CA)m_szLogFile,"w");
	if(!hf) m_szLogFile[0]=0;
	else fclose(hf);
}