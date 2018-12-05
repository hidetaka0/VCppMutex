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
		//�I��
		CloseHandle(g_hMutex);
	}

	void Lock()
	{
		WaitForSingleObject(g_hMutex, INFINITE);//���b�N
	}
	void Unlock()
	{
		ReleaseMutex(g_hMutex);//�A�����b�N
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
		g_Mutex->Lock();//���b�N
	}

	~MutexLockGuard()
	{
		g_Mutex->Unlock();//���b�N
	}
};
