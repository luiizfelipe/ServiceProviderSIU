#pragma once
#include <XFSSPI.H>
#include "CCommand.h"
#include <deque>
#include "CThread.h"

using namespace std;

class  CServiceProvider : public CThread
{
private:
	deque<CCommand*> m_wosaQueue;
	char m_logicalName[128];

public:
	CServiceProvider();

	HRESULT InsertCommand(CCommand* cmd);
	CCommand* removeCommmand();

	HRESULT allocateBuffer(LPWFSRESULT* bufferPointer);

	HRESULT wfpOpen(CCommand* cmd);
	HRESULT wfpClose(CCommand* cmd);
	HRESULT wfpRegister(CCommand* cmd);
	HRESULT wfpDeregister(CCommand* cmd);
	HRESULT wfpExecute(CCommand* cmd);
	HRESULT wfpGetInfo(CCommand* cmd);
	HRESULT wfpLock(CCommand* cmd);
	HRESULT wfpUnlock(CCommand* cmd);


	const char* getLogicalName();
	void setLogicalName(const char* logicalName);
	void setCommonData(LPWFSRESULT result, CCommand* cmd);
	void postMessageToWindow(CCommand* cmd);


	void* run();

};

