#include "StdAfx.h"
#include "Resource.h"
#include "ImageItemControl.h"

//////////////////////////////////////////////////////////////////////////////////
//��̬����

CImageItemControl *	CImageItemControl::m_pImageItemControl=NULL;			//ͷ��ӿ�

//////////////////////////////////////////////////////////////////////////////////

//���캯��
CImageItemControl::CImageItemControl()
{
	//���ö���
	ASSERT(m_pImageItemControl==NULL);
	if (m_pImageItemControl==NULL) m_pImageItemControl=this;

	//������Դ
	HINSTANCE hResInstance=GetModuleHandle(AVATAR_CONTROL_DLL_NAME);
	m_ImageUserImage.LoadImage(hResInstance,TEXT("USER_TABLE_IMAGE"));

	//���ñ���
	m_wLineCount=m_ImageUserImage.GetWidth()/IMAGE_CX/8;
	m_wFullCount=m_wLineCount*m_ImageUserImage.GetHeight()/IMAGE_CY;
	
	return;
}

//��������
CImageItemControl::~CImageItemControl()
{
	//���ö���
	ASSERT(m_pImageItemControl==this);
	if (m_pImageItemControl==this) m_pImageItemControl=NULL;

	return;
}

//�ӿڲ�ѯ
VOID * CImageItemControl::QueryInterface(REFGUID Guid, DWORD dwQueryVer)
{
	QUERYINTERFACE(IImageItemControl,Guid,dwQueryVer);
	QUERYINTERFACE_IUNKNOWNEX(IImageItemControl,Guid,dwQueryVer);
	return NULL;
}

//ͷ����Ŀ
WORD CImageItemControl::GetImageCount()
{
	return m_wFullCount;
}

//��ȡ�ߴ�
VOID CImageItemControl::GetImageItemSize(CSize & SizeFace)
{
	//���ñ���
	SizeFace.SetSize(IMAGE_CX,IMAGE_CY);
	return;
}

//��ȡ��Դ
VOID CImageItemControl::GetAvatarResource(tagAvatarResource & AvatarResource)
{
	//���ñ���
	AvatarResource.pszResource=TEXT("USER_TABLE_IMAGE");
	AvatarResource.hResInstance=GetModuleHandle(AVATAR_CONTROL_DLL_NAME);

	return;
}

//�滭ͷ��
VOID CImageItemControl::DrawImage(CDC * pDC, INT nXPos, INT nYPos, INT nSrcWidth, INT nSrcHeight)
{
	m_ImageUserImage.DrawImage(pDC,nXPos,nYPos,IMAGE_CX,IMAGE_CY,nSrcWidth,nSrcHeight);

	return;
}

//////////////////////////////////////////////////////////////////////////////////

//�����������
DECLARE_CREATE_MODULE(ImageItemControl);

//////////////////////////////////////////////////////////////////////////////////
