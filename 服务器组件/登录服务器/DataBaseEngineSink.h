#ifndef DATABASE_ENGINE_SINK_HEAD_FILE
#define DATABASE_ENGINE_SINK_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "InitParameter.h"
#include "DataBasePacket.h"

//////////////////////////////////////////////////////////////////////////////////

//���ݿ���
class CDataBaseEngineSink : public IDataBaseEngineSink
{
	//��Ԫ����
	friend class CServiceUnits;

	//�û����ݿ�
protected:
	CDataBaseAide					m_AccountsDBAide;					//�û����ݿ�
	CDataBaseHelper					m_AccountsDBModule;					//�û����ݿ�

	//��Ϸ�����ݿ�
protected:
	CDataBaseAide					m_TreasureDBAide;					//��Ϸ�����ݿ�
	CDataBaseHelper					m_TreasureDBModule;					//��Ϸ�����ݿ�

	//ƽ̨���ݿ�
protected:
	CDataBaseAide					m_PlatformDBAide;					//ƽ̨���ݿ�
	CDataBaseHelper					m_PlatformDBModule;					//ƽ̨���ݿ�

	//�������
protected:
	CInitParameter *				m_pInitParameter;					//���ò���
	IDataBaseEngineEvent *			m_pIDataBaseEngineEvent;			//�����¼�

	//��������
public:
	//���캯��
	CDataBaseEngineSink();
	//��������
	virtual ~CDataBaseEngineSink();

	//�����ӿ�
public:
	//�ͷŶ���
	virtual VOID Release() { return; }
	//�ӿڲ�ѯ
	virtual VOID * QueryInterface(REFGUID Guid, DWORD dwQueryVer);

	//ϵͳ�¼�
public:
	//�����¼�
	virtual bool OnDataBaseEngineStart(IUnknownEx * pIUnknownEx);
	//ֹͣ�¼�
	virtual bool OnDataBaseEngineConclude(IUnknownEx * pIUnknownEx);

	//�ں��¼�
public:
	//ʱ���¼�
	virtual bool OnDataBaseEngineTimer(DWORD dwTimerID, WPARAM dwBindParameter);
	//�����¼�
	virtual bool OnDataBaseEngineControl(WORD wControlID, VOID * pData, WORD wDataSize);
	//�����¼�
	virtual bool OnDataBaseEngineRequest(WORD wRequestID, DWORD dwContextID, VOID * pData, WORD wDataSize);

	//��¼����
protected:
	//I D ��¼
	bool OnRequestLogonGameID(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�ʺŵ�¼
	bool OnRequestLogonAccounts(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�ʺ�ע��
	bool OnRequestRegisterAccounts(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�ο͵�¼
	bool OnRequestLogonVisitor(DWORD dwContextID, VOID * pData, WORD wDataSize);
	
	//�ֻ���¼
protected:
	//I D ��¼
	bool OnMobileLogonGameID(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�ʺŵ�¼
	bool OnMobileLogonAccounts(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�ʺ�ע��
	bool OnMobileRegisterAccounts(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//�˺ŷ���
protected:
	//�޸Ļ���
	bool OnRequestModifyMachine(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�����
	bool OnRequestModifyLogonPass(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�����
	bool OnRequestModifyInsurePass(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸��ʺ�
	bool OnRequestModifyAccounts(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸��Ƽ���
	bool OnRequestModifySpreader(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�ǩ��
	bool OnRequestModifyUnderWrite(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�ͷ��
	bool OnRequestModifySystemFace(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�ͷ��
	bool OnRequestModifyCustomFace(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�����
	bool OnRequestModifyIndividual(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�����Ϸ״̬
	bool OnRequestUserInGameServerID(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//�޸�����
	bool OnRequestPublicNotic(DWORD dwContextID, VOID * pData, WORD wDataSize);
	
	//���з���
protected:
	//������Ϸ��
	bool OnRequestUserSaveScore(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ȡ��Ϸ��
	bool OnRequestUserTakeScore(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//ת����Ϸ��
	bool OnRequestUserTransferScore(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//��Ϣ��ѯ
protected:
	//��ѯ������Ϣ
	bool OnRequestQueryAccountInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ѯ����
	bool OnRequestQueryIndividual(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ѯ����
	bool OnRequestQueryInsureInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ѯ�û�
	bool OnRequestQueryTransferUserInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//ϵͳ����
protected:
	//�����б�
	bool OnRequestLoadGameList(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//������Ϣ
	bool OnRequestOnLineCountInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//ǩ��
protected:
	//���ؽ���
	bool OnRequestCheckInReward(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ѯǩ��
	bool OnRequestCheckInQueryInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//ִ��ǩ��
	bool OnRequestCheckInDone(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ȡǩ������
	bool OnRequestCheckAward(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//���ֻ
protected:
	//�������ֻ
	bool OnRequestBeginnerConfig(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//
	bool OnRequestBeginnerQueryInfo(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//
	bool OnRequestBeginnerDone(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//׬���
protected:
	//
	bool OnRequestAddBankAwardConfig(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//
	bool OnRequestAddBackUpAward(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//
	bool OnRequestGetAddBank(DWORD dwContextID, VOID * pData, WORD wDataSize);


	//�ͱ�����
protected:
	//���صͱ�
	bool OnRequestLoadBaseEnsure(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��ȡ�ͱ�
	bool OnRequestTakeBaseEnsure(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//��������
protected:
	//��������
	bool OnRequestMatchSignup(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//ȡ������
	bool OnRequestMatchUnSignup(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//���ؽ���
	bool OnRequestLoadMatchReward(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//��Ϸ��¼
protected:
	//��Ϸ��¼
	bool OnRequestGameRecordList(DWORD dwContextID, VOID * pData, WORD wDataSize);
	//��Ϸ�ط�
	bool OnRequestGameTotalRecord(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//�Ƽ������
protected:
	bool OnRequestQuerySpreaterNickName(DWORD dwContextID, VOID * pData, WORD wDataSize);
	bool OnRequestAddSpreater(DWORD dwContextID, VOID * pData, WORD wDataSize);


	//�һ�����
protected:
	//�һ������б�
	bool OnRequestGetExchangeHuaFeiList(DWORD dwContextID, VOID * pData, WORD wDataSize);

	//�̳�
protected:
	//�̳��б�
	bool OnRequestGetShopInfoList(DWORD dwContextID, VOID * pData, WORD wDataSize);
	
	//�������
protected:
	//��¼���
	VOID OnLogonDisposeResult(DWORD dwContextID, DWORD dwErrorCode, LPCTSTR pszErrorString, bool bMobileClient);
	//���н��
	VOID OnInsureDisposeResult(DWORD dwContextID, DWORD dwErrorCode, LPCTSTR pszErrorString, bool bMobileClient);
	//�������
	VOID OnOperateDisposeResult(DWORD dwContextID, DWORD dwErrorCode, LPCTSTR pszErrorString, bool bMobileClient);
};

//////////////////////////////////////////////////////////////////////////////////

#endif