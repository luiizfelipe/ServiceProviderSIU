#include <windows.h>
#include <xfsspi.h>
#include <xfssiu.h>

HRESULT extern WINAPI WFPCancelAsyncRequest(HSERVICE hService, REQUESTID RequestID){
    WFMOutputTraceData("Entrei na função WFPCancelAsyncRequest...");
    return WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPClose(HSERVICE hService, HWND hWnd, REQUESTID ReqID){
    WFMOutputTraceData("Entrei na função WFPClose...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPDeregister...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPExecute...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPGetInfo...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPLock(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPLock...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPOpen(HSERVICE hService, LPCSTR lpszLogicalName, HAPP hApp, LPCSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID, HPROVIDER hProvider, DWORD dwSPIVersionsRequired, LPWFSVERSION lpSPIVersion, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion){ 
    WFMOutputTraceData("Entrei na função WFPOpen...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPRegister...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPSetTraceLevel(HSERVICE hService, DWORD dwTraceLevel){ 
    WFMOutputTraceData("Entrei na função WFPSetTraceLevel...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPUnloadService(){ 
    WFMOutputTraceData("Entrei na função WFPUnloadService...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPUnlock(HSERVICE hService, HWND hWnd, REQUESTID ReqID){ 
    WFMOutputTraceData("Entrei na função WFPUnlock...");
    return 	WFS_ERR_INTERNAL_ERROR;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

