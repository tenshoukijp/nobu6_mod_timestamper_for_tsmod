// TimerStamp.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "TimerStamp.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	int iMaxSleepCnt = 60;
	for ( int i=0; i<=iMaxSleepCnt; i++ ) {
		// �V�ċL�������オ���Ă�����҂B
		if ( FindWindow("Tenshouki95", NULL ) ) {
			Sleep(500); // 0.5�b�҂�
		} else {
			break;
		}
		// �ő�܂ő҂��Ĕ������Ȃ���ΏI���B
		if ( i==iMaxSleepCnt ) {
			return 0;
		}
	}

	HANDLE file;
	FILETIME file_time,local_file_time;
	SYSTEMTIME system_time;


	//----------------------------------- tenshou.exe
	//�t�@�C�����J���i���݂���̂Ƃ��̂݁j
	file = CreateFile("tenshou.exe",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(file == INVALID_HANDLE_VALUE){
		OutputDebugString("�t�@�C�����J���܂���B\n");
		return 1;
	}


	//-- ���݂̍X�V����
	//�X�V���Ԃ̎擾�i�K�v�Ȃ�����NULL�łn�j�j
	GetFileTime(file,NULL,NULL,&file_time);
	//���[�J���̎��Ԃ֕ϊ�
	FileTimeToLocalFileTime(&file_time,&local_file_time);//�f�[�^�̌^�͕ς���ĂȂ�
	//SYSTEMTIME�\���̂֕ϊ�
	FileTimeToSystemTime(&local_file_time,&system_time);//�f�[�^�̌^�̕ϊ�
	//�擾���̕\��


	//-- �����C��
	system_time.wYear  = 2005;
	system_time.wMonth =    2;
	system_time.wDay   =   20;
	system_time.wHour  =   11;
	system_time.wMinute=   24;
	system_time.wSecond=   26;

	//FILETIME�\���֖̂߂�
	SystemTimeToFileTime(&system_time,&local_file_time);
	//���[�J������V�X�e�����Ԃ֕ϊ�
	LocalFileTimeToFileTime(&local_file_time,&file_time);
	//�X�V���Ԃ̍X�V�i�X�V�s�v�ȏ���NULL�łn�j�j
	SetFileTime(file,NULL,NULL,&file_time);

	//�t�@�C�������
	CloseHandle(file);

	/*
	//----------------------------------- n6paudio.dll
	//�t�@�C�����J���i���݂���̂Ƃ��̂݁j
	file = CreateFile("n6paudio.dll",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(file == INVALID_HANDLE_VALUE){
		OutputDebugString("�t�@�C�����J���܂���B\n");
		return 1;
	}


	//-- ���݂̍X�V����
	//�X�V���Ԃ̎擾�i�K�v�Ȃ�����NULL�łn�j�j
	GetFileTime(file,NULL,NULL,&file_time);
	//���[�J���̎��Ԃ֕ϊ�
	FileTimeToLocalFileTime(&file_time,&local_file_time);//�f�[�^�̌^�͕ς���ĂȂ�
	//SYSTEMTIME�\���̂֕ϊ�
	FileTimeToSystemTime(&local_file_time,&system_time);//�f�[�^�̌^�̕ϊ�
	//�擾���̕\��


	//-- �����C��
	system_time.wYear  = 2002;
	system_time.wMonth =    7;
	system_time.wDay   =   26;
	system_time.wHour  =   16;
	system_time.wMinute=   30;
	system_time.wSecond=   44;

	//FILETIME�\���֖̂߂�
	SystemTimeToFileTime(&system_time,&local_file_time);
	//���[�J������V�X�e�����Ԃ֕ϊ�
	LocalFileTimeToFileTime(&local_file_time,&file_time);
	//�X�V���Ԃ̍X�V�i�X�V�s�v�ȏ���NULL�łn�j�j
	SetFileTime(file,NULL,NULL,&file_time);

	//�t�@�C�������
	CloseHandle(file);
	*/


	return 0;
}
