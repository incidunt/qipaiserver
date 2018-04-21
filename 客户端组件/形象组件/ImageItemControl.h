#ifndef IMAGE_ITEM_CONTROL_HEAD_FILE
#define IMAGE_ITEM_CONTROL_HEAD_FILE

#pragma once

#include "AvatarControlHead.h"

//�û�3D����ؼ�
class AVATAR_CONTROL_CLASS  CImageItemControl : public IImageItemControl
{
	//��������
protected:
	WORD							m_wLineCount;						//ͷ����Ŀ
	WORD							m_wFullCount;						//ͷ����Ŀ
	CPngImage						m_ImageUserImage;					//�û�����


	//����ӿ�
protected:
	static CImageItemControl *		m_pImageItemControl;					//ͷ��ӿ�

	//��������
public:
	//���캯��
	CImageItemControl();
	//��������
	virtual ~CImageItemControl();

	//�����ӿ�
public:
	//�ͷŶ���
	virtual VOID Release() { delete this; }
	//�ӿڲ�ѯ
	virtual VOID * QueryInterface(REFGUID Guid, DWORD dwQueryVer);
	
	//��Ϣ�ӿ�
public:
	//ͷ����Ŀ
	virtual WORD GetImageCount();
	//��ȡ�ߴ�
	virtual VOID GetImageItemSize(CSize & SizeFace);

	//��Դ�ӿ�
public:
	//��ȡ��Դ
	virtual VOID GetAvatarResource(tagAvatarResource & AvatarResource);

	//�滭�ӿ�
public:
	//�滭ͷ��
	virtual VOID DrawImage(CDC * pDC, INT nXPos, INT nYPos,INT nSrcWidth, INT nSrcHeight);

	//�滭�ӿ�
//public:
	//�滭ͷ��
	//virtual VOID DrawImageFree(CDC * pDC, INT nXPos, INT nYPos, INT nWidth, INT nHeight, WORD wFaceID);
	//�滭ͷ��
	//virtual VOID DrawImagePlaying(CDC * pDC, INT nXPos, INT nYPos, INT nWidth, INT nHeight, WORD wFaceID);


	//��̬����
public:
	//��ȡ����
	static CImageItemControl * GetInstance() { return m_pImageItemControl; }
};

#endif