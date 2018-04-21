#ifndef DATA_BASE_PACKETOUT_HEAD_FILE
#define DATA_BASE_PACKETOUT_HEAD_FILE

#include "..\..\ȫ�ֶ���\datastream.h"

#pragma pack(1)
//////////////////////////////////////////////////////////////////////////////////
//�����Ϣ

//��¼���
#define DBO_GP_LOGON_SUCCESS		100									//��¼�ɹ�
#define DBO_GP_LOGON_FAILURE		101									//��¼ʧ��
#define DBR_GP_VALIDATE_MBCARD		102									//��¼ʧ��

//�������
#define DBO_GP_USER_FACE_INFO		110									//�û�ͷ��
#define DBO_GP_USER_INDIVIDUAL		111									//�û�����
#define DBO_GP_USER_ACCOUNTINFO		112									//�û���Ϣ

//��������
#define DBO_GP_USER_INSURE_INFO		120									//��������
#define DBO_GP_USER_INSURE_SUCCESS	121									//���гɹ�
#define DBO_GP_USER_INSURE_FAILURE	122									//����ʧ��
#define DBO_GP_USER_INSURE_USER_INFO   123								//�û�����
#define DBO_GP_USER_INGAME_SERVER_ID   124								//�û���Ϸ״̬

//�б���
#define DBO_GP_GAME_TYPE_ITEM		130									//������Ϣ
#define DBO_GP_GAME_KIND_ITEM		131									//������Ϣ
#define DBO_GP_GAME_NODE_ITEM		132									//�ڵ���Ϣ
#define DBO_GP_GAME_PAGE_ITEM		133									//������Ϣ
#define DBO_GP_GAME_LIST_RESULT		134									//���ؽ��

//ǩ������
#define DBO_GP_CHECKIN_REWARD		160									//ǩ������
#define DBO_GP_CHECKIN_INFO			161									//ǩ����Ϣ
#define DBO_GP_CHECKIN_RESULT		162									//ǩ�����


#define DBO_GP_BASEENSURE_PARAMETER	180									//�ͱ�����
#define DBO_GP_BASEENSURE_RESULT	181									//��ȡ���
//�������
#define DBO_GP_MATCH_SIGNUP_RESULT	190									//�������	
#define DBO_GP_MATCH_AWARD			191									//��������

//������
#define DBO_GP_PUBLIC_NOTICE		200									//�����ɹ�

//���ֻ����
#define DBO_GP_BEGINNER_CONFIG		210									//���ֻ����
#define DBO_GP_BEGINNER_INFO		211									//���ֻ��Ϣ
#define DBO_GP_BEGINNER_RESULT		212									//���ֻ���

//�����Ƽ��˽��
#define DBO_GP_SPREADER_RESOULT		220									//�����Ƽ��˽��

//׬���
#define DBO_GP_ADDRANK_AWARD_CONFIG	240									//����							
#define DBO_GP_ADDRANK_RANK_BACK	241									//���н��						

//��Ϸ��¼
#define DBO_GP_GAME_RECORD_LIST		250									//��¼�б�							
#define DBO_GP_GAME_RECORD_TOTAL	251									//���н��	

//�һ�����
#define DBO_GP_EXCHAGE_HUAFEI_BACK	260									//�һ������б�

//�̳���Ϣ
#define DBO_GP_SHOPINFO_BACK	270									//�̳��б�		

//������
#define DBO_GP_OPERATE_SUCCESS		500									//�����ɹ�
#define DBO_GP_OPERATE_FAILURE		501									//����ʧ��



//��¼�ɹ�
struct DBO_GP_LogonSuccess
{
	//��������
	WORD							wFaceID;							//ͷ���ʶ
	DWORD							dwUserID;							//�û���ʶ
	DWORD							dwGameID;							//��Ϸ��ʶ
	DWORD							dwGroupID;							//���ű�ʶ
	DWORD							dwCustomID;							//�Զ�����
	DWORD							dwUserMedal;						//�û�����
	DWORD							dwExperience;						//������ֵ
	DWORD							dwLoveLiness;						//�û�����
	DWORD							dwSpreaderID;						//�ƹ�ID
	BYTE							cbInsureEnabled;					//����ʹ��
	TCHAR							szPassword[LEN_MD5];				//��¼����
	TCHAR							szAccounts[LEN_ACCOUNTS];			//��¼�ʺ�
	TCHAR							szNickName[LEN_NICKNAME];			//�û��ǳ�
	TCHAR							szGroupName[LEN_GROUP_NAME];		//��������

	//�û��ɼ�
	SCORE							lUserScore;							//�û���Ϸ��
	SCORE							lUserInsure;						//�û�����

	//�û�����
	BYTE							cbGender;							//�û��Ա�
	BYTE							cbMoorMachine;						//��������
	TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//����ǩ��

	//��Ա����
	BYTE							cbMemberOrder;						//��Ա�ȼ�
	SYSTEMTIME						MemberOverDate;						//����ʱ��

	//������Ϣ
	WORD							wSignupCount;						//��������
	tagSignupMatchInfo				SignupMatchInfo[32];				//�����б�

	//������Ϣ
	TCHAR							szDescribeString[128];				//������Ϣ
};

//��¼ʧ��
struct DBO_GP_LogonFailure
{
	LONG							lResultCode;						//�������
	TCHAR							szDescribeString[128];				//������Ϣ
};

//��¼ʧ��
struct DBR_GP_ValidateMBCard
{
	UINT							uMBCardID;						//��������
};

//ͷ����Ϣ
struct DBO_GP_UserFaceInfo
{
	WORD							wFaceID;							//ͷ���ʶ
	DWORD							dwCustomID;							//�Զ�����
};

//��������
struct DBO_GP_UserIndividual
{
	//�û���Ϣ
	DWORD							dwUserID;							//�û� I D
	TCHAR							szUserNote[LEN_USER_NOTE];			//�û�˵��
	TCHAR							szCompellation[LEN_COMPELLATION];	//��ʵ����

	//�绰����
	TCHAR							szSeatPhone[LEN_SEAT_PHONE];		//�̶��绰
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//�ƶ��绰

	//��ϵ����
	TCHAR							szQQ[LEN_QQ];						//Q Q ����
	TCHAR							szEMail[LEN_EMAIL];					//�����ʼ�
	TCHAR							szDwellingPlace[LEN_DWELLING_PLACE];//��ϵ��ַ
	TCHAR							szHeadHttp[LEN_USER_NOTE];			//ͷ��
	TCHAR							szLogonIP[LEN_NICKNAME];			//IP
	TCHAR							szUserChannel[LEN_NICKNAME];		//������
};


//������Ϣ
struct DBO_GP_UserAccountInfo
{
	//��������
	WORD							wFaceID;							//ͷ���ʶ
	DWORD							dwUserID;							//�û���ʶ
	DWORD							dwGameID;							//��Ϸ��ʶ
	DWORD							dwGroupID;							//���ű�ʶ
	DWORD							dwCustomID;							//�Զ�����
	DWORD							dwUserMedal;						//�û�����
	DWORD							dwExperience;						//������ֵ
	DWORD							dwLoveLiness;						//�û�����
	DWORD							dwSpreaderID;						//�ƹ�ID
	TCHAR							szPassword[LEN_MD5];				//��¼����
	TCHAR							szAccounts[LEN_ACCOUNTS];			//��¼�ʺ�
	TCHAR							szNickName[LEN_NICKNAME];			//�û��ǳ�
	TCHAR							szGroupName[LEN_GROUP_NAME];		//��������
	TCHAR							szLogonIp[LEN_ACCOUNTS];			//��¼IP

	//�û��ɼ�
	SCORE							lUserScore;							//�û���Ϸ��
	SCORE							lUserInsure;						//�û�����

	//�û�����
	BYTE							cbGender;							//�û��Ա�
	BYTE							cbMoorMachine;						//��������
	TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//����ǩ��

	//��Ա����
	BYTE							cbMemberOrder;						//��Ա�ȼ�
	SYSTEMTIME						MemberOverDate;						//����ʱ��
};
//��������
struct DBO_GP_UserInsureInfo
{
	WORD							wRevenueTake;						//˰�ձ���
	WORD							wRevenueTransfer;					//˰�ձ���
	WORD							wServerID;							//�����ʶ
	SCORE							lUserScore;							//�û���Ϸ��
	SCORE							lUserInsure;						//������Ϸ��
	SCORE							lTransferPrerequisite;				//ת������
};

//���гɹ�
struct DBO_GP_UserInsureSuccess
{
	DWORD							dwUserID;							//�û� I D
	SCORE							lSourceScore;						//ԭ����Ϸ��
	SCORE							lSourceInsure;						//ԭ����Ϸ��
	SCORE							lInsureRevenue;						//����˰��
	SCORE							lDestScore;					//��Ϸ�ұ仯
	SCORE							lDestInsure;					//���б仯
	TCHAR							szDescribeString[128];				//������Ϣ
};

//����ʧ��
struct  DBO_GP_UserInsureFailure
{
	LONG							lResultCode;						//��������
	TCHAR							szDescribeString[128];				//������Ϣ
};

//�����Ƽ��˽��
struct DBO_GP_SpreaderResoult
{
	LONG							lResultCode;						//��������
	SCORE							lScore;							//��������
	TCHAR							szDescribeString[128];				//�ɹ���Ϣ
};

//����ʧ��
struct DBO_GP_OperateFailure
{
	LONG							lResultCode;						//��������
	TCHAR							szDescribeString[128];				//������Ϣ
};

//�����ɹ�
struct DBO_GP_OperateSuccess
{
	LONG							lResultCode;						//��������
	TCHAR							szDescribeString[128];				//�ɹ���Ϣ
};

//////////////////////////////////////////////////////////////////////////////////

//��Ϸ����
struct DBO_GP_GameType
{
	WORD							wJoinID;							//�ҽ�����
	WORD							wSortID;							//��������
	WORD							wTypeID;							//��������
	TCHAR							szTypeName[LEN_TYPE];				//��������
};

//��Ϸ����
struct DBO_GP_GameKind
{
	WORD							wTypeID;							//��������
	WORD							wJoinID;							//�ҽ�����
	WORD							wSortID;							//��������
	WORD							wKindID;							//��������
	WORD							wGameID;							//ģ������
	TCHAR							szKindName[LEN_KIND];				//��Ϸ����
	TCHAR							szProcessName[LEN_PROCESS];			//��������
};

//��Ϸ�ڵ�
struct DBO_GP_GameNode
{
	WORD							wKindID;							//��������
	WORD							wJoinID;							//�ҽ�����
	WORD							wSortID;							//��������
	WORD							wNodeID;							//�ڵ�����
	TCHAR							szNodeName[LEN_NODE];				//�ڵ�����
};

//��������
struct DBO_GP_GamePage
{
	WORD							wKindID;							//��������
	WORD							wNodeID;							//�ڵ�����
	WORD							wSortID;							//��������
	WORD							wPageID;							//��������
	WORD							wOperateType;						//��������
	TCHAR							szDisplayName[LEN_PAGE];			//��ʾ����
};

//���ؽ��
struct DBO_GP_GameListResult
{
	BYTE							cbSuccess;							//�ɹ���־
};

//ǩ������
struct DBO_GP_CheckInReward
{
	SCORE							lRewardGold[LEN_SIGIN];				//�������
	BYTE							lRewardType[LEN_SIGIN];				//�������� 1��� 2����
	BYTE							lRewardDay[LEN_SIGIN];				//�������� 
};

//ǩ����Ϣ
struct DBO_GP_CheckInInfo
{
	WORD							wSeriesDate;						//��������
	WORD							wAwardDate;							//��Ʒ����
	bool							bTodayChecked;						//ǩ����ʶ
};

//ǩ�����
struct DBO_GP_CheckInResult
{
	bool							bType;								//�Ƿ��Ǵﵽ������ȡ��Ʒ
	bool							bSuccessed;							//�ɹ���ʶ
	SCORE							lScore;								//��ǰ����
	TCHAR							szNotifyContent[128];				//��ʾ����
};

//����������Ϣ
struct DBO_GP_BeginnerInfo
{
	WORD							wSeriesDate;						//��������
	bool							bTodayChecked;						//ǩ����ʶ
	bool							bLastCheckIned;						//ǩ����ʶ
};

//��ѯ���
struct DBO_GP_UserInGameServerID
{
	DWORD							LockKindID;			
	DWORD							LockServerID;							
};

//��ѯ���
struct DBO_GP_PublicNotice
{
	LONG							lResultCode;						//��������
	TCHAR							szDescribeString[512];				//�ɹ���Ϣ
};
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//���ֻ����
struct DBO_GP_BeginnerCofig
{
	SCORE							lRewardGold[LEN_BEGINNER];				//�������
	BYTE							lRewardType[LEN_BEGINNER];				//�������� 1��� 2����
};
//���ֻ���
struct DBO_GP_BeginnerResult
{
	bool							bSuccessed;							//�ɹ���ʶ
	SCORE							lAwardCout;							//��������
	SCORE							lAwardType;							//��������
	TCHAR							szNotifyContent[128];				//��ʾ����
};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//׬���
struct DBO_GP_AddRankAwardConfig
{
	INT								iIdex;
	INT								kRewardGold[LEN_ADDRANK];
	INT								kRewardType[LEN_ADDRANK];
};

struct DBO_GP_BackAddBank
{
	int iRankIdex;
	std::vector<std::string>		kNickName;
	std::vector<int>				kUserID;
	std::vector<int>				kFaceID;
	std::vector<int>				kCustomID;
	std::vector<int>				kUserPoint;

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(iRankIdex);
		Stream_VALUE(kNickName);
		Stream_VALUE(kUserID);
		Stream_VALUE(kFaceID);
		Stream_VALUE(kCustomID);
		Stream_VALUE(kUserPoint);
	}
};



//�һ�����
struct DBO_GP_BackExchangeHuaFei
{
	std::vector<int>				kExchangeID;            //�һ�id
	std::vector<int>				kUseType;			   //�һ���������
	std::vector<int>				kUseNum;				   //�һ����߸���
	std::vector<int>				kGetType;			   //�һ���Ʒ����
	std::vector<int>				kGetNum;				   //�һ���Ʒ����
	std::vector<std::string>		kGoodsName;			   //�һ���Ʒ����
	std::vector<std::string>		kExchangeDesc;		   //�һ�����
	std::vector<std::string>		kImgIcon;			   //ͼ������
	std::vector<int>				kFlag;				   //���

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(kExchangeID);
		Stream_VALUE(kUseType);
		Stream_VALUE(kUseNum);
		Stream_VALUE(kGetType);
		Stream_VALUE(kGetNum);
		Stream_VALUE(kGoodsName);
		Stream_VALUE(kExchangeDesc);
		Stream_VALUE(kImgIcon);
		Stream_VALUE(kFlag);
	}
};


//�̳��б�
struct DBO_GP_BackShopInfo
{
	std::vector<int>				kItemID;					 //��Ʒid
	std::vector<int>				kItemType;				 //��Ʒ����
	std::vector<int>				kOrderID_IOS;				 //��Ʒ������ ƻ��
	std::vector<int>				kOrderID_Android;			 //��Ʒ������ ��׿
	std::vector<int>				kPrice;					 //��Ʒ�۸�
	std::vector<int>				kGoodsNum;				 //��Ʒ����
	std::vector<std::string>		kItemTitle;				 //����
	std::vector<std::string>		kItemDesc;				 //����
	std::vector<std::string>		kItemIcon;				 //ͼ������
	std::vector<std::string>		kItemName;				 //��Ʒ����

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(kItemID);
		Stream_VALUE(kItemType);
		Stream_VALUE(kOrderID_IOS);
		Stream_VALUE(kOrderID_Android);
		Stream_VALUE(kPrice);
		Stream_VALUE(kGoodsNum);
		Stream_VALUE(kItemTitle);
		Stream_VALUE(kItemDesc);
		Stream_VALUE(kItemIcon);
		Stream_VALUE(kItemName);
	}
};

//������Ϣ
struct tagDBMatchAwardkInfo
{
	WORD							MatchRank;							//��������
	SCORE						RewardGold;					//�������
	DWORD							RewardMedal;						//����Ԫ��
	DWORD							RewardExperience;					//��������
	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(MatchRank);
		Stream_VALUE(RewardGold);
		Stream_VALUE(RewardMedal);
		Stream_VALUE(RewardExperience);
	}
};

//��������
struct DBO_GR_MatchAwardList
{
	DWORD							dwMatchID;							//������ʶ
	DWORD							dwMatchNO;							//��������
	std::vector<tagDBMatchAwardkInfo> kAwards;

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(dwMatchID);
		Stream_VALUE(dwMatchNO);
		StructVecotrMember(tagDBMatchAwardkInfo,kAwards);
	}
};
#pragma pack()
#endif