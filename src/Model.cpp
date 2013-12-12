#include "IProxy.h"
#include "Model.h"

using namespace Mvc::Core;

Model::Model()
{
    InitializeModel();
}

bool Model::RegisterProxy(IProxy* proxy)
{
    if(m_proxyMap.find(proxy->getProxyName()) == m_proxyMap.end())
    {
        m_proxyMap[proxy->getProxyName()] = proxy;
        proxy->OnRegister();

        return true;
    }

    return false;
}

IProxy* Model::RetrieveProxy(PROXY_NAME_TYPE proxyName)
{
    std::map<PROXY_NAME_TYPE, IProxy*>::iterator it = m_proxyMap.find(proxyName);
    if (it == m_proxyMap.end()) return NULL;
    return (*it).second;
}

bool Model::HasProxy(PROXY_NAME_TYPE proxyName)
{
    return m_proxyMap.find(proxyName) != m_proxyMap.end();
}

IProxy* Model::RemoveProxy(PROXY_NAME_TYPE proxyName)
{
    IProxy* proxy = NULL;

    if (m_proxyMap.find(proxyName) != m_proxyMap.end())
    {
        proxy = RetrieveProxy(proxyName);
        m_proxyMap.erase(m_proxyMap.find(proxyName));
    }

    if (proxy != NULL) proxy->OnRemove();
    return proxy;
}

void Model::InitializeModel()
{
}