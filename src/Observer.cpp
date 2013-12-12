#include "IHandlerNotification.h"

#include "Observer.h"

using namespace Mvc;
using namespace Mvc::Patterns;

Observer::Observer(void* notifyContext)
{
    m_notifyContext = notifyContext;
}

void Observer::NotifyObserver(INotification* notification)
{
    void* context;

    context = getNotifyContext();

    IHandlerNotification* pHandlerNotification = (IHandlerNotification*)context;
    if(0 != pHandlerNotification)
    {
        pHandlerNotification->HandlerNotification(notification);
    }
}

bool Observer::CompareNotifyContext(void* obj)
{
    return m_notifyContext == obj;
}

void* Observer::getNotifyContext()
{
    return m_notifyContext;
}

void Observer::setNotifyContext(void* aContext)
{
    m_notifyContext = aContext;
}