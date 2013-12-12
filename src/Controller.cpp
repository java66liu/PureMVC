#include "INotification.h"
#include "IController.h"
#include "ICommand.h"

#include "Observer.h"
#include "View.h"

#include "Controller.h"

using namespace Mvc;
using namespace Mvc::Core;
using namespace Mvc::Interface;

Controller::Controller()
{
    InitializeController();
}

Controller::~Controller()
{
    std::map<NOTIFICATION_NAME_TYPE, void*> tmp(m_commandMap);
    for(std::map<NOTIFICATION_NAME_TYPE, void*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        RemoveCommand(it->first);
    }

    delete m_view;
    m_view = NULL;
}

void Controller::HandlerNotification(INotification* note)
{
    std::map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(note->getName());

    if(it != m_commandMap.end())
    {
        fnCreateICommand commandType = (fnCreateICommand)it->second;

        if(commandType != NULL)
        {
            ICommand* commandInstance = (*commandType)();
            if(commandInstance != NULL)
            {
                commandInstance->Execute(note);
                delete commandInstance;
                commandInstance = NULL;
            }
        }
    }
}

void Controller::RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType)
{
    if (m_commandMap.find(notificationName) == m_commandMap.end())
    {
        m_view->RegisterObserver(notificationName, new Observer((void*)this));
    }

    m_commandMap[notificationName] = commandType;
}

bool Controller::HasCommand(NOTIFICATION_NAME_TYPE notificationName)
{
    return m_commandMap.find(notificationName) != m_commandMap.end();
}

void Controller::RemoveCommand(NOTIFICATION_NAME_TYPE notificationName)
{
    std::map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(notificationName);

    if (it != m_commandMap.end())
    {
        m_view->RemoveObserver(notificationName, this);
        m_commandMap.erase(it);
    }
}

void* Controller::GetCommandFunc(NOTIFICATION_NAME_TYPE notificationName)
{
    std::map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(notificationName);
    if (it != m_commandMap.end())
    {
        return (*it).second;
    }
    else
    {
        return NULL;
    }
}

void Controller::InitializeController()
{
    m_view = new View;
}