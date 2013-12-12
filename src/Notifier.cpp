#include "IFacade.h"
#include "Notifier.h"

using namespace Mvc;
using namespace Mvc::Patterns;

Notifier::Notifier(IFacade* facade)
{
    m_facade = facade;
}

void Notifier::SendNotification(NOTIFICATION_NAME_TYPE notificationName)
{
    m_facade->SendNotification(notificationName);
}

void Notifier::SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body)
{
    m_facade->SendNotification(notificationName, body);
}