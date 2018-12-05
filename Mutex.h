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
		//クローズ
		CloseHandle(g_hMutex);
	}

	//ロック
	void Lock()
	{
		WaitForSingleObject(g_hMutex, INFINITE);
	}
	//アンロック
	void Unlock()
	{
		ReleaseMutex(g_hMutex);
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
		g_Mutex->Lock();
	}

	~MutexLockGuard()
	{
		g_Mutex->Unlock();
	}
};
