#include "Proxy.h"

using namespace Mvc;
using namespace Mvc::Patterns;
using namespace Mvc::Interface;

Proxy::Proxy(IFacade* facade) : Notifier(facade)
{
    m_proxyName = PROXY_NAME_TYPE();
    m_data = 0;
}

Proxy::Proxy(IFacade* facade, PROXY_NAME_TYPE proxyName) : Notifier(facade)
{
    m_proxyName = proxyName;
    m_data = 0;
}

Proxy::Proxy(IFacade* facade, PROXY_NAME_TYPE proxyName, void* data) : Notifier(facade)
{
    m_proxyName = proxyName;
    m_data = data;
}

void Proxy::OnRegister()
{
}

void Proxy::OnRemove()
{
}

PROXY_NAME_TYPE Proxy::getProxyName()
{
    return m_proxyName;
}

void    Proxy::setData(void* aData)
{
    m_data = aData;
}

void*    Proxy::getData()
{
    return m_data;
}
