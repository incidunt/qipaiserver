#include "Stdafx.h"
#include "D3DSound.h"
#include "TraceDebug.h"

CD3DSound::CD3DSound()
{
}

CD3DSound::~CD3DSound()
{
}

//��������
bool CD3DSound::CreateD3DSound(HWND hWnd)
{
	return true;
}

//��������
HSTREAM CD3DSound::LoadSound(LPCTSTR pszFileName, bool bRepetition)
{
	HSTREAM hStream;
	return hStream;
}

//��������
HSTREAM CD3DSound::LoadSound(HINSTANCE hInstance, LPCTSTR pszResource, LPCTSTR pszTypeName, bool bRepetition)
{	
	HSTREAM hStream;

	return hStream;
}

//��ȡ����
CD3DSound * CD3DSound::GetInstance()
{
	static CD3DSound _Instance;

	return &_Instance;
}

//��������
void CD3DSound::SetMusVolume( DWORD dwVolume )
{
}

//��ȡ����
DWORD CD3DSound::GetMusVolume()
{
	return 0;
}

//��������
HCHANNEL CD3DSound::PlaySound( HSTREAM hStream )
{
	HCHANNEL hChannel;
	return hChannel;
}

//��������
HCHANNEL CD3DSound::StopSound( HSTREAM hStream )
{
	HCHANNEL hChannel;
	return hChannel;
}
//ֹͣ����
bool CD3DSound::StopSound()
{
	return true;
	
}
//��������
bool CD3DSound::PlaySound(LPCTSTR pszFileName, bool bRepetition)
{
	return true;
}
//��������
bool CD3DSound::PlaySound(HINSTANCE hInstance, LPCTSTR pszResource, LPCTSTR pszTypeName, bool bRepetition)
{
	return true;
}

//ɾ������
void CD3DSound::FreeSound( HSTREAM hStream )
{
}

//��ͣ����
void CD3DSound::Channel_Pause( HCHANNEL hChannel )
{
}

//��������
void CD3DSound::Channel_Resume( HCHANNEL hChannel )
{
}	

//ֹͣ����
void CD3DSound::Channel_Stop( HCHANNEL hChannel )
{
}

//��ͣ����
void CD3DSound::Channel_PauseAll()
{
}

//��������
void CD3DSound::Channel_ResumeAll()
{
}

//ֹͣ����
void CD3DSound::Channel_StopAll()
{
}

//���ڲ���
bool CD3DSound::Channel_IsPlaying( HCHANNEL hChannel )
{
	return false;
}

//��ȡ��С
double CD3DSound::Channel_GetLength( HCHANNEL hChannel )
{
	return 0.0f;
}

//��ȡλ��
double CD3DSound::Channel_GetPos( HCHANNEL hChannel )
{
	return 0.0f;
}

//����λ��
void CD3DSound::Channel_SetPos( HCHANNEL hChannel, double dSeconds )
{
}



