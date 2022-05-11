// TimerStamp.cpp : アプリケーションのエントリ ポイントを定義します。
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
		// 天翔記が立ち上がっていたら待つ。
		if ( FindWindow("Tenshouki95", NULL ) ) {
			Sleep(500); // 0.5秒待つ
		} else {
			break;
		}
		// 最大まで待って抜けられなければ終了。
		if ( i==iMaxSleepCnt ) {
			return 0;
		}
	}

	HANDLE file;
	FILETIME file_time,local_file_time;
	SYSTEMTIME system_time;


	//----------------------------------- tenshou.exe
	//ファイルを開く（存在するのときのみ）
	file = CreateFile("tenshou.exe",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(file == INVALID_HANDLE_VALUE){
		OutputDebugString("ファイルが開けません。\n");
		return 1;
	}


	//-- 現在の更新時間
	//更新時間の取得（必要ない情報はNULLでＯＫ）
	GetFileTime(file,NULL,NULL,&file_time);
	//ローカルの時間へ変換
	FileTimeToLocalFileTime(&file_time,&local_file_time);//データの型は変わってない
	//SYSTEMTIME構造体へ変換
	FileTimeToSystemTime(&local_file_time,&system_time);//データの型の変換
	//取得情報の表示


	//-- 時刻修正
	system_time.wYear  = 2005;
	system_time.wMonth =    2;
	system_time.wDay   =   20;
	system_time.wHour  =   11;
	system_time.wMinute=   24;
	system_time.wSecond=   26;

	//FILETIME構造体へ戻す
	SystemTimeToFileTime(&system_time,&local_file_time);
	//ローカルからシステム時間へ変換
	LocalFileTimeToFileTime(&local_file_time,&file_time);
	//更新時間の更新（更新不要な情報はNULLでＯＫ）
	SetFileTime(file,NULL,NULL,&file_time);

	//ファイルを閉じる
	CloseHandle(file);

	/*
	//----------------------------------- n6paudio.dll
	//ファイルを開く（存在するのときのみ）
	file = CreateFile("n6paudio.dll",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(file == INVALID_HANDLE_VALUE){
		OutputDebugString("ファイルが開けません。\n");
		return 1;
	}


	//-- 現在の更新時間
	//更新時間の取得（必要ない情報はNULLでＯＫ）
	GetFileTime(file,NULL,NULL,&file_time);
	//ローカルの時間へ変換
	FileTimeToLocalFileTime(&file_time,&local_file_time);//データの型は変わってない
	//SYSTEMTIME構造体へ変換
	FileTimeToSystemTime(&local_file_time,&system_time);//データの型の変換
	//取得情報の表示


	//-- 時刻修正
	system_time.wYear  = 2002;
	system_time.wMonth =    7;
	system_time.wDay   =   26;
	system_time.wHour  =   16;
	system_time.wMinute=   30;
	system_time.wSecond=   44;

	//FILETIME構造体へ戻す
	SystemTimeToFileTime(&system_time,&local_file_time);
	//ローカルからシステム時間へ変換
	LocalFileTimeToFileTime(&local_file_time,&file_time);
	//更新時間の更新（更新不要な情報はNULLでＯＫ）
	SetFileTime(file,NULL,NULL,&file_time);

	//ファイルを閉じる
	CloseHandle(file);
	*/


	return 0;
}
