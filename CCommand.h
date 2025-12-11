#pragma once
#include <XFSAPI.H>
class CCommand
{
private:
	REQUESTID m_reqId;
	HSERVICE m_hService;
	HWND m_hWnd;
	DWORD m_dwTimeout;
	DWORD m_dwCommand;
	int m_spiFunction;
	LPVOID m_buffer;
	int m_buffersize;
	char m_logicalName[128];
	LPVOID m_result;
	char* m_BufferLszExtra;

public:
	CCommand(
		REQUESTID reqId,
		HSERVICE hService,
		HWND hWnd,
		int spiFunction,
		long timeout,
		DWORD command,
		LPVOID buffer,
		int size
		);
	REQUESTID getReqId();
	HSERVICE getService();
	HWND getHWND();
	DWORD getTimeout();
	DWORD getCommand();
	int getSPIFunction();
	LPVOID  getBuffer();
	int getBufferSize();
	LPVOID getResult();
	char* getLpszExtra();

	void setResult(LPVOID result);

};

