#include "StdAfx.h"
#include "TableFrameSink.h"
#include "FvMask.h"

bool CTableFrameSink::hasRule(BYTE cbRule)
{
	return FvMask::HasAny(m_dwGameRuleIdex,_MASK_(cbRule));
}
BYTE CTableFrameSink::AnalyseChiHuCardZZ(const BYTE cbCardIndex[MAX_INDEX], const tagWeaveItem WeaveItem[], BYTE cbWeaveCount, BYTE cbCurrentCard, CChiHuRight &ChiHuRight,bool bSelfSendCard)
{
		//��������
	BYTE cbChiHuKind=WIK_NULL;
	CAnalyseItemArray AnalyseItemArray;

	if (hasRule(GAME_TYPE_ZZ_ZIMOHU) && !bSelfSendCard)
	{
		return WIK_NULL;
	}

	//���ñ���
	AnalyseItemArray.RemoveAll();
	ChiHuRight.SetEmpty();
	ChiHuRight |= CHR_SHU_FAN;

	//���ܺ�
	if( m_wCurrentUser == INVALID_CHAIR && m_bGangStatus)
	{
		if (hasRule(GAME_TYPE_ZZ_QIANGGANGHU))
		{
			ChiHuRight |= CHR_QIANG_GANG_HU;
		}
		else
		{
			ChiHuRight.SetEmpty();
			return WIK_NULL;
		}
		
	}
	//�����˿�
	BYTE cbCardIndexTemp[MAX_INDEX];
	CopyMemory(cbCardIndexTemp,cbCardIndex,sizeof(cbCardIndexTemp));

	//cbCurrentCardһ����Ϊ0			!!!!!!!!!
	ASSERT( cbCurrentCard != 0 );
	if( cbCurrentCard == 0 ) return WIK_NULL;

	//�����˿�
	if (cbCurrentCard!=0)
		cbCardIndexTemp[m_GameLogic.SwitchToCardIndex(cbCurrentCard)]++;

	//�����˿�
	bool bValue = m_GameLogic.AnalyseCard(cbCardIndexTemp,WeaveItem,cbWeaveCount,AnalyseItemArray);
	if (!bValue)
	{

		ChiHuRight.SetEmpty();
		return WIK_NULL;
	}

	//���Ʒ���
	//���ͷ���
	for (INT_PTR i=0;i<AnalyseItemArray.GetCount();i++)
	{
		//��������
		tagAnalyseItem * pAnalyseItem=&AnalyseItemArray[i];
		if (hasRule(GAME_TYPE_ZZ_258))
		{
			BYTE cbCardValue = pAnalyseItem->cbCardEye&MASK_VALUE;
			if( cbCardValue != 2 && cbCardValue != 5 && cbCardValue != 8 )
			{
				continue;
			}
		}
		cbChiHuKind = WIK_CHI_HU;
		break;
	}

	if (bSelfSendCard)
	{
		cbChiHuKind = WIK_CHI_HU;
		ChiHuRight = CHR_SHU_FAN;
		ChiHuRight |= CHR_ZI_MO;
	}

	return cbChiHuKind;
}
BYTE CTableFrameSink::AnalyseChiHuCardCS(const BYTE cbCardIndex[MAX_INDEX], const tagWeaveItem WeaveItem[], BYTE cbWeaveCount, BYTE cbCurrentCard, CChiHuRight &ChiHuRight)
{
	//��������
	BYTE cbChiHuKind=WIK_NULL;
	CAnalyseItemArray AnalyseItemArray;

	//���ñ���
	AnalyseItemArray.RemoveAll();
//	ChiHuRight.SetEmpty();

	//�����˿�
	BYTE cbCardIndexTemp[MAX_INDEX];
	CopyMemory(cbCardIndexTemp,cbCardIndex,sizeof(cbCardIndexTemp));

	//cbCurrentCardһ����Ϊ0			!!!!!!!!!
	ASSERT( cbCurrentCard != 0 );
	if( cbCurrentCard == 0 ) return WIK_NULL;

	/*
	//	���ⷬ��
	*/
	//��С����
	int nGenCount = 0;
	if( m_GameLogic.IsQiXiaoDui(cbCardIndex,WeaveItem,cbWeaveCount,cbCurrentCard,nGenCount) )
	{
		if (nGenCount >0)
		{
			ChiHuRight |= CHR_HAOHUA_QI_XIAO_DUI;
		}
		else
		{
			ChiHuRight |= CHR_QI_XIAO_DUI;
		}
	}
	if( m_GameLogic.IsJiangJiangHu(cbCardIndex,WeaveItem,cbWeaveCount,cbCurrentCard) ) 
	{
		ChiHuRight |= CHR_JIANGJIANG_HU;
	}
	if(cbWeaveCount == 4 &&  m_GameLogic.IsDanDiao(cbCardIndex,cbCurrentCard))
	{
		ChiHuRight |= CHR_QUAN_QIU_REN;
	}
	
	if( !ChiHuRight.IsEmpty() )
		cbChiHuKind = WIK_CHI_HU;

	//�����˿�
	if (cbCurrentCard!=0)
		cbCardIndexTemp[m_GameLogic.SwitchToCardIndex(cbCurrentCard)]++;

	//�����˿�
	bool bValue = m_GameLogic.AnalyseCard(cbCardIndexTemp,WeaveItem,cbWeaveCount,AnalyseItemArray);

	//���Ʒ���
	if (!bValue)
	{
		ChiHuRight.SetEmpty();
		return WIK_NULL;
	}
	else
	{
		cbChiHuKind = WIK_CHI_HU;
	}

	//���ͷ���
	for (INT_PTR i=0;i<AnalyseItemArray.GetCount();i++)
	{
		//��������
		tagAnalyseItem * pAnalyseItem=&AnalyseItemArray[i];

		/*
		//	�жϷ���
		*/
		//������
		if( m_GameLogic.IsPengPeng(pAnalyseItem) ) 
			ChiHuRight |= CHR_PENGPENG_HU;
	}

	//�ط�
	if( cbChiHuKind == WIK_CHI_HU && ChiHuRight.IsEmpty() )
		ChiHuRight |= CHR_SHU_FAN;

	if( cbChiHuKind == WIK_CHI_HU )
	{
		//��һɫ��
		if( m_GameLogic.IsQingYiSe(cbCardIndex,WeaveItem,cbWeaveCount,cbCurrentCard) )
			ChiHuRight |= CHR_QING_YI_SE;
	}

	return cbChiHuKind;
}
BYTE CTableFrameSink::AnalyseChiHuCardCS_XIAOHU(const BYTE cbCardIndex[MAX_INDEX], CChiHuRight &ChiHuRight)
{
	BYTE cbReplaceCount = 0;
	BYTE cbChiHuKind=WIK_NULL;

	//��ʱ����
	BYTE cbCardIndexTemp[MAX_INDEX];
	CopyMemory(cbCardIndexTemp,cbCardIndex,sizeof(cbCardIndexTemp));

	bool bDaSiXi = false;//����ϲ
	bool bBanBanHu = true;//����
	BYTE cbQueYiMenColor[3] = { 1,1,1 };//ȱһɫ
	BYTE cbLiuLiuShun = 0;//����˳

	//���㵥��
	for (BYTE i=0;i<MAX_INDEX;i++)
	{
		BYTE cbCardCount=cbCardIndexTemp[i];

		if (cbCardCount == 0)
		{
			continue;
		}

		if( cbCardCount == 4)
		{
			bDaSiXi = true;
		}

		if(cbCardCount == 3 )
		{
			cbLiuLiuShun ++;
		}

		BYTE cbValue = m_GameLogic.SwitchToCardData(i) & MASK_VALUE;
		if (cbValue == 2 || cbValue == 5 || cbValue == 8)
		{
			bBanBanHu = false;
		}

		BYTE cbCardColor = m_GameLogic.SwitchToCardData(i)&MASK_COLOR;
		cbQueYiMenColor[cbCardColor>>4] = 0;
	}
	if (bDaSiXi)
	{
		ChiHuRight |= CHR_XIAO_DA_SI_XI;
		cbChiHuKind = WIK_XIAO_HU;
	}
	if (bBanBanHu)
	{
		ChiHuRight |= CHR_XIAO_BAN_BAN_HU;
		cbChiHuKind = WIK_XIAO_HU;
	}
	if (cbQueYiMenColor[0] || cbQueYiMenColor[1] || cbQueYiMenColor[2])
	{
		ChiHuRight |= CHR_XIAO_QUE_YI_SE;
		cbChiHuKind = WIK_XIAO_HU;
	}
	if (cbLiuLiuShun >= 2)
	{
		ChiHuRight |= CHR_XIAO_LIU_LIU_SHUN;
		cbChiHuKind = WIK_XIAO_HU;
	}
	return cbChiHuKind;
}
BYTE CTableFrameSink::AnalyseChiHuCard(const BYTE cbCardIndex[MAX_INDEX], const tagWeaveItem WeaveItem[], BYTE cbWeaveCount, BYTE cbCurrentCard, CChiHuRight &ChiHuRight)
{
	if (GAME_TYPE_ZZ == m_cbGameTypeIdex)
	{
		return AnalyseChiHuCardZZ(cbCardIndex,WeaveItem,cbWeaveCount,cbCurrentCard,ChiHuRight,m_wProvideUser == m_wCurrentUser);
	}
	if (GAME_TYPE_CS == m_cbGameTypeIdex)
	{
		return AnalyseChiHuCardCS(cbCardIndex,WeaveItem,cbWeaveCount,cbCurrentCard,ChiHuRight);
	}
	ASSERT(false);
	return 0;
}
//
void CTableFrameSink::FiltrateRight( WORD wChairId,CChiHuRight &chr )
{
	//Ȩλ����
	//���ܣ����˳��ƣ������иܣ����к���
	if( m_wCurrentUser == INVALID_CHAIR && m_bGangStatus )
	{
		chr |= CHR_QIANG_GANG_HU;
	}
	if (m_cbLeftCardCount==0)
	{
		chr |= CHR_HAI_DI_LAO;
	}
	//����Ȩλ
	//���ϻ�������֮�����ƺ���
	if( m_wCurrentUser==wChairId && m_bGangStatus )
	{
		chr |= CHR_GANG_KAI;
	}
	//�����ڣ�����֮�󣬱��˺���
	if( m_bGangOutStatus && !m_bGangStatus )
	{
		chr |= CHR_GANG_SHANG_PAO;
	}
}
