#pragma once
#include <windows.h>

class Mutex
{
private:
	HANDLE g_hMutex;

public:
	Mutex()
	{
		//Mutex����
		g_hMutex = CreateMutex(NULL, FALSE, NULL);
	}

	~Mutex()
	{
		//�N���[�Y
		CloseHandle(g_hMutex);
	}

	//���b�N
	void Lock()
	{
		WaitForSingleObject(g_hMutex, INFINITE);
	}
	//�A�����b�N
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
