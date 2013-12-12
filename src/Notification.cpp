#include "Notification.h"

using namespace Mvc;
using namespace Mvc::Patterns;

Notification::Notification(int name)
{
    m_name = name;
    m_body = 0;
}

Notification::Notification(int name, void* body)
{
    m_name = name;
    m_body = body;
}

NOTIFICATION_NAME_TYPE Notification::getName()
{
    return m_name;
}

void Notification::setBody(void* aBody)
{
    m_body = aBody;
}

void* Notification::getBody()
{
    return m_body;
}