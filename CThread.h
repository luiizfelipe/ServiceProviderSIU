#include <windows.h>
#pragma once
class CThread
{

public:
	void start();
	bool stop();
	bool join();
	bool isRunning();
	bool isToExit();
	HANDLE getHandle();
	DWORD getId();

protected:
	virtual void* run() = 0;

private:
	HANDLE  hThreadHandle;
	DWORD dThreadId;
	bool running = false;
	bool exit = false;
	static DWORD FAR PASCAL Dispatch(LPVOID threadObj);
};

