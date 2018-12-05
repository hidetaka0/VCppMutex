#pragma once
#include <windows.h>

class Mutex
{
private:
	HANDLE g_hMutex;

public:
	Mutex()
	{
		//Mutex生成
		g_hMutex = CreateMutex(NULL, FALSE, NULL);
	}

	~Mutex()
	{
		//終了
		CloseHandle(g_hMutex);
	}

	void Lock()
	{
		WaitForSingleObject(g_hMutex, INFINITE);//ロック
	}
	void Unlock()
	{
		ReleaseMutex(g_hMutex);//アンロック
	}
};

class MutexLockGuard
{
private:
	Mutex * g_Mutex;

public:
	MutexLockGuard(Mutex * mutex)
	{
		g_Mutex = mutex;
		g_Mutex->Lock();//ロック
	}

	~MutexLockGuard()
	{
		g_Mutex->Unlock();//ロック
	}
};
