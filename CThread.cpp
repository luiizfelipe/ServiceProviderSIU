#include "CThread.h"

void CThread::start() {
	this->hThreadHandle = CreateThread(
		NULL,
		0,
		Dispatch,
		this,
		0,
		&this->dThreadId
	);
}
bool CThread::stop(){
	this->exit = true;
	return true;
}
bool CThread::join(){
	WaitForSingleObject(this->hThreadHandle, INFINITE);
	return true;
}
bool CThread::isRunning(){
	return this->running;
}
bool CThread::isToExit()
{
	return this->exit;
}
HANDLE CThread::getHandle(){
	return this->hThreadHandle;
}
DWORD CThread::getId(){
	return this->dThreadId;
}
DWORD CThread::Dispatch(LPVOID threadObj) {
	((CThread*)threadObj)->run();
}


