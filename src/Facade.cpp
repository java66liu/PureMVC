#include "Notification.h"
#include "Controller.h"
#include "Model.h"
#include "View.h"

#include "Facade.h"

using namespace Mvc;
using namespace Mvc::Patterns;
using namespace Mvc::Core;

Facade::Facade()
{
    m_controller = NULL;
    m_model = NULL;
    m_view = NULL;

    InitializeFacade();
}

Facade::~Facade()
{
    delete m_controller;
    m_controller = NULL;

    delete m_view;
    m_view = NULL;

    delete m_model;
    m_model = NULL;
}

bool Facade::RegisterProxy(IProxy* proxy)
{
    return m_model->RegisterProxy(proxy);
}

IProxy* Facade::RetrieveProxy(PROXY_NAME_TYPE proxyName)
{
    return m_model->RetrieveProxy(proxyName);
}

IProxy* Facade::RemoveProxy(PROXY_NAME_TYPE proxyName)
{
    return m_model->RemoveProxy(proxyName);
}
bool Facade::HasProxy(PROXY_NAME_TYPE proxyName)
{
    return m_model->HasProxy(proxyName);
}

void Facade::RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType)
{
    m_controller->RegisterCommand(notificationName, commandType);
}

void Facade::RemoveCommand(NOTIFICATION_NAME_TYPE notificationName)
{
    m_controller->RemoveCommand(notificationName);
}

bool Facade::HasCommand(NOTIFICATION_NAME_TYPE notificationName)
{
    return m_controller->HasCommand(notificationName);
}

void Facade::RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator)
{
    return m_view->RegisterObserver(notificationName, mediator);
}

bool Facade::RegisterMediator(IMediator* mediator)
{
    return m_view->RegisterMediator(mediator);
}

IMediator* Facade::RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    return m_view->RetrieveMediator(mediatorName);
}

IMediator* Facade::RemoveMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    return m_view->RemoveMediator(mediatorName);
}

bool Facade::HasMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    return m_view->HasMediator(mediatorName);
}

void Facade::NotifyObservers(INotification* notification)
{
    m_view->NotifyObservers(notification);
}

void Facade::SendNotification(NOTIFICATION_NAME_TYPE notificationName)
{
    Notification notification(notificationName);
    NotifyObservers(&notification);
}

void Facade::SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body)
{
    Notification notification(notificationName, body);
    NotifyObservers(&notification);
}

void Facade::InitializeFacade()
{
    InitializeModel();
    InitializeView();
    InitializeController();
}

void Facade::InitializeController()
{
    m_controller = new Controller;
}

void Facade::InitializeModel()
{
    m_model = new Model;
}

void Facade::InitializeView()
{
    m_view = new View;
}