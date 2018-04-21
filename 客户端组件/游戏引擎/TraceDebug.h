#pragma once
#include "GameEngineHead.h"

//����ȼ�
enum enGameTraceLevel
{
	TraceLevel_Game_Info				=0,									//��Ϣ��Ϣ
	TraceLevel_Game_Normal				=1,									//��ͨ��Ϣ
	TraceLevel_Game_Warning				=2,									//������Ϣ
	TraceLevel_Game_Exception			=3,									//�쳣��Ϣ
	TraceLevel_Game_Debug				=4,									//������Ϣ
};

//�¼����
interface IGameTraceService
{
	//�ִ����
	virtual bool TraceString(LPCTSTR pszString, enGameTraceLevel TraceLevel)=NULL;
	//�ִ����
	virtual bool TraceString(enGameTraceLevel TraceLevel,LPCTSTR pszString, ...)=NULL;
};


// CTraceRichEdit
//////////////////////////////////////////////////////////////////////////
//׷�ٷ���
class GAME_ENGINE_CLASS CGameTraceService
{
protected:
	IGameTraceService					* m_pTraceService;
	TCHAR								m_szLogFile[MAX_PATH];

public:
	CGameTraceService();

	static CGameTraceService*GetInstance();

public:
	//���ýӿ�
	void SetInterFace(IGameTraceService *pTraceService);
	//�����ļ�
	void SetLogFile(LPCTSTR lpszFileName);
	//�ִ����
	bool TraceString(LPCTSTR pszString, enGameTraceLevel TraceLevel);
	//�ִ����
	bool TraceString(enGameTraceLevel TraceLevel,LPCTSTR pszString, ...);
};

#define TraceService	CGameTraceService::GetInstance()
//////////////////////////////////////////////////////////////////////////


