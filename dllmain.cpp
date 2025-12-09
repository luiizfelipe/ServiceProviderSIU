#include <windows.h>
#include <xfsspi.h>
#include <xfssiu.h>
#include "util.h"
#include <vector>


vector<HWND> windows = {};

HRESULT extern WINAPI WFPCancelAsyncRequest(HSERVICE hService, REQUESTID RequestID){
    TRACE("Entrei na função WFPCancelAsyncRequest...");
    return WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPClose(HSERVICE hService, HWND hWnd, REQUESTID ReqID){
    TRACE("Entrei na função WFPClose...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID) {
    HRESULT hResult = WFS_ERR_INTERNAL_ERROR;

    TRACE("Executando o FPRegister...");

    TRACE("hService: %d", hService);
    TRACE("dwEventClass: %02x", hService);
    TRACE("hWndReg: 02X", hService);
    TRACE("hWnd: %d", hService);
    TRACE("ReqId: %d", hService);

    windows.push_back(hWndReg);
    hResult = WFS_SUCCESS;


    LPWFSRESULT lpPostRest;
    SendPostMessage(hWnd, hResult, hService, ReqID, WFS_REGISTER_COMPLETE, lpPostRest);
    //TO DO: Validar:  Já existe |Inválido


    TRACE("WFPRegister Finalizado. hResult: %d", hResult);

    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID){ 
    TRACE("Entrei na função WFPDeregister...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    TRACE("Executando o WFPExecute...");
    
    HRESULT hResult = WFS_ERR_INTERNAL_ERROR;

    Sleep(2000);

    hResult = WFS_SUCCESS;

    LPWFSRESULT lpPostRest;
    SendPostMessage(hWnd, hResult, hService, ReqID, WFS_REGISTER_COMPLETE, lpPostRest);

    if (!lpPostRest) {
        TRACE("Error WFPExecute: lpPostRest não existe valor"); // Validar posteriormente
    }

    for (HWND window : windows) {
        PostMessage(window, WFS_SYSTEM_EVENT, 0, (LPARAM)lpPostRest);
    }

    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    TRACE("Entrei na função WFPGetInfo...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPLock(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID){ 
    TRACE("Entrei na função WFPLock...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPOpen(HSERVICE hService, LPCSTR lpszLogicalName, HAPP hApp, LPCSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID, HPROVIDER hProvider, 
    DWORD dwSPIVersionsRequired, LPWFSVERSION lpSPIVersion, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion){ 
    HRESULT hResult = WFS_ERR_INTERNAL_ERROR;
    TRACE("Entrei na função WFPOpen...");

    hService = 1;

    TRACE("lpszLogicalName (SIU): %s", lpszLogicalName);
    TRACE("hApp: %02X", hApp);
    TRACE("lpszAppID: %s", lpszAppID);
    TRACE("dwTraceLevel: %d", dwTraceLevel);
    TRACE("dwTimeout: %d", dwTimeOut);
    TRACE("hWnd: %02X", hWnd);
    TRACE("ReqId: %d", ReqID);
    TRACE("hProvider: %02X", hProvider);
    TRACE("dwSPIVersionsRequired: %02X", dwSPIVersionsRequired);
    TRACE("dwSPIVersionsRequired highster version: %02X", MAIORVERSAO(dwSPIVersionsRequired));
    TRACE("dwSPIVersionsRequired lowster version: %02X", MENORVERSAO(dwSPIVersionsRequired));
    TRACE("dwSrvcVersionsRequired: %02X", dwSrvcVersionsRequired);
    TRACE("dwSrvcVersionsRequired highster version: %02X", MAIORVERSAO(dwSrvcVersionsRequired));
    TRACE("dwSrvcVersionsRequired lowster version: %02X", MENORVERSAO(dwSrvcVersionsRequired));



    WFMSetTraceLevel(hService, dwTraceLevel);

    lpSrvcVersion->wVersion = 0x0A03;
    lpSrvcVersion->wLowVersion = 0x0003;
    lpSrvcVersion->wHighVersion  = 0x0A03;

    memset(lpSrvcVersion->szDescription, 0x00, WFSDDESCRIPTION_LEN + 1);
    strcpy_s(lpSrvcVersion->szDescription, "Meu primeiro SP (Servicce Provider");


    memset(lpSrvcVersion->szSystemStatus, 0x00, WFSDDESCRIPTION_LEN + 1);
    strcpy_s(lpSrvcVersion->szSystemStatus, "Ainda em desenvolvimento");

    if (lpSPIVersion != NULL) {
        lpSPIVersion->wVersion = 0x0A03;
        lpSPIVersion->wLowVersion = 0x0003;
        lpSPIVersion->wHighVersion = 0x0A03;

        memset(lpSPIVersion->szDescription, 0x00, WFSDDESCRIPTION_LEN + 1);
        strcpy_s(lpSPIVersion->szDescription, lpSrvcVersion->szDescription);


        memset(lpSPIVersion->szSystemStatus, 0x00, WFSDDESCRIPTION_LEN + 1);
        strcpy_s(lpSPIVersion->szSystemStatus, lpSrvcVersion->szSystemStatus);
    }

    Sleep(2000);

    hResult = WFS_SUCCESS;
    SendPostMessage(hWnd,hResult,hService,ReqID, WFS_OPEN_COMPLETE);

    TRACE("WFPOpen Finalizado. hResult: %d", hResult);
    return hResult;
}


HRESULT extern WINAPI WFPSetTraceLevel(HSERVICE hService, DWORD dwTraceLevel){ 
    TRACE("Entrei na função WFPSetTraceLevel...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPUnloadService(){ 
    TRACE("Entrei na função WFPUnloadService...");
    return 	WFS_ERR_INTERNAL_ERROR;
}

HRESULT extern WINAPI WFPUnlock(HSERVICE hService, HWND hWnd, REQUESTID ReqID){ 
    TRACE("Entrei na função WFPUnlock...");
    return 	WFS_ERR_INTERNAL_ERROR;
}


BOOL SendPostMessage(HWND hWnd, HRESULT hResult, HSERVICE hService,  REQUESTID ReqID, UINT Msg, OUT LPWFSRESULT lpPostRest) {
    WFSRESULT wfsResLocal;
    memset(&wfsResLocal, 0, sizeof(wfsResLocal));

    wfsResLocal.hResult = hResult;
    wfsResLocal.hService = hService;
    wfsResLocal.RequestID = ReqID;
    GetSystemTime(&wfsResLocal.tsTimestamp);


    if (WFMAllocateBuffer(sizeof(WFSRESULT), WFS_MEM_ZEROINIT | WFS_MEM_SHARE, (LPVOID*)&lpPostRest) != WFS_SUCCESS) {
        TRACE("Post Result: ERROR WFMAllocateBuffer");
        return false;
    }

    memcpy(lpPostRest, &wfsResLocal, sizeof(WFSRESULT));

    PostMessage(hWnd, Msg, 0, (LPARAM)lpPostRest);
    return true;
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

