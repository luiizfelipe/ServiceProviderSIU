#include "CServiceProvider.h"

CCommand* CServiceProvider::removeCommmand()
{
    CCommand* command = nullptr;
    if (m_wosaQueue.size() > 0) {
        command = m_wosaQueue.at(0);
        m_wosaQueue.pop_front();
    }
    return command;
}

HRESULT CServiceProvider::allocateBuffer(LPWFSRESULT* bufferPointer)
{
    HRESULT res = WFMAllocateBuffer(sizeof(WFSRESULT), WFS_MEM_SHARE | WFS_MEM_ZEROINIT, (LPVOID*)bufferPointer );
    
    if (res != WFS_SUCCESS) {
        (*bufferPointer) = NULL;
    }

    
    return res;
}

void CServiceProvider::setCommonData(LPWFSRESULT result, CCommand* cmd)
{
    SYSTEMTIME time; 
    GetSystemTime(&time);

    result->hResult = WFS_SUCCESS;
    result->hService = cmd->getService();
    result->lpBuffer = NULL;
    result->RequestID = cmd->getReqId();
    result->tsTimestamp = time;
    result->u.dwCommandCode = cmd->getCommand();
}

void CServiceProvider::postMessageToWindow(CCommand* cmd)
{
    while (PostMessage(cmd->getHWND(), cmd->getSPIFunction(), 0, (LPARAM)cmd->getResult()) == FALSE) {
        Sleep(32L);
    }
}

HRESULT CServiceProvider::wfpOpen(CCommand* cmd)
{

    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpClose(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpRegister(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpDeregister(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpExecute(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpGetInfo(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpLock(CCommand* cmd)
{
    return E_NOTIMPL;
}

HRESULT CServiceProvider::wfpUnlock(CCommand* cmd)
{
    return E_NOTIMPL;
}

CServiceProvider::CServiceProvider()
{

}

HRESULT CServiceProvider::InsertCommand(CCommand* cmd)
{
    HRESULT hResult = WFS_ERR_INTERNAL_ERROR;
    if (cmd != NULL) {
        // TODO: Implementar Mutext
        m_wosaQueue.push_back(cmd);
        // TODO: s
        hResult = WFS_SUCCESS;
    }

    return E_NOTIMPL;
}

void* CServiceProvider::run()
{
    CCommand* pCmdExecuting;

    while (!this->isToExit()) {
        pCmdExecuting = removeCommmand();

        if (pCmdExecuting) {

        }

        this->m_wosaQueue;
    };

    return nullptr;
}

