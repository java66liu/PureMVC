#include "Mediator.h"

using namespace Mvc;
using namespace Mvc::Patterns;

Mediator::Mediator(IFacade* facade) : Notifier(facade)
{
    m_mediatorName = MEDIATOR_NAME_TYPE();
    m_viewComponent = NULL;
}

Mediator::Mediator(IFacade* facade, MEDIATOR_NAME_TYPE mediatorName) : Notifier(facade)
{
    m_mediatorName = mediatorName;
    m_viewComponent = NULL;
}

Mediator::Mediator(IFacade* facade, MEDIATOR_NAME_TYPE mediatorName, void* viewComponent) : Notifier(facade)
{
    m_mediatorName = mediatorName;
    m_viewComponent = viewComponent;
}

std::vector<NOTIFICATION_NAME_TYPE> Mediator::ListNotificationInterests()
{
    std::vector<NOTIFICATION_NAME_TYPE> temp;
    return temp;
}

void Mediator::OnRegister()
{
}

void Mediator::OnRemove()
{
}

MEDIATOR_NAME_TYPE Mediator::getMediatorName()
{
    return m_mediatorName;
}

void* Mediator::getViewComponent()
{
    return m_viewComponent;
}

void Mediator::setViewComponent(void* aViewComponent)
{
    m_viewComponent = aViewComponent;
}

void Mediator::HandlerNotification(INotification*)
{
}