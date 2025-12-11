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

	

	
public:
	CServiceProvider();

	HRESULT InsertCommand(CCommand* cmd);
	CCommand* removeCommmand();

	HRESULT allocateBuffer(LPWFSRESULT* bufferPointer);
	void setCommonData(LPWFSRESULT result, CCommand* cmd);
	void postMessageToWindow(CCommand* cmd);

	HRESULT wfpOpen(CCommand* cmd);
	HRESULT wfpClose(CCommand* cmd);
	HRESULT wfpRegister(CCommand* cmd);
	HRESULT wfpDeregister(CCommand* cmd);
	HRESULT wfpExecute(CCommand* cmd);
	HRESULT wfpGetInfo(CCommand* cmd);
	HRESULT wfpLock(CCommand* cmd);
	HRESULT wfpUnlock(CCommand* cmd);
	void* run();

};

