#include "INotification.h"
#include "IMediator.h"
#include "Observer.h"
#include "View.h"

using namespace Mvc;
using namespace Mvc::Core;


View::View()
{
    InitializeView();
}

View::~View()
{
    std::map<MEDIATOR_NAME_TYPE, IMediator*> tmp(m_mediatorMap);
    for each(auto &i in tmp)
    {
        RemoveMediator(i.first);
    }
}

void View::RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator)
{
    IObserver* observer = new Observer((void*)mediator);
    if(NULL != observer)
    {
        RegisterObserver(notificationName, observer);
    }
}

void View::RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IObserver* observer)
{
    if (m_observerMap.find(notificationName) == m_observerMap.end())
    {
        m_observerMap[notificationName] = new OBSERVER_LIST_TYPE;
    }

    m_observerMap[notificationName]->push_back(std::shared_ptr<IObserver>(observer));
}

void View::NotifyObservers(INotification* notification)
{
    std::map<NOTIFICATION_NAME_TYPE, OBSERVER_LIST_TYPE*>::iterator it = m_observerMap.find(notification->getName());

    if (it != m_observerMap.end())
    {
        OBSERVER_LIST_TYPE* observers = it->second;

        std::vector<std::weak_ptr<IObserver> > tmp;

        for each(auto &i in *observers)
        {
            tmp.push_back(i);
        }

        for each(auto &i in tmp)
        {
            auto r = i.lock();
            if(r)
            {
                r->NotifyObserver(notification);
            }
        }
    }
}

void View::RemoveObserver(NOTIFICATION_NAME_TYPE notificationName, void* notifyContext)
{
    std::map<NOTIFICATION_NAME_TYPE, OBSERVER_LIST_TYPE*>::iterator it = m_observerMap.find(notificationName);
    if(it != m_observerMap.end())
    {
        OBSERVER_LIST_TYPE* observers = it->second;

        {
            for(OBSERVER_LIST_TYPE::iterator it = observers->begin(); it != observers->end(); )
            {
                auto& i = *it;
                if(i->CompareNotifyContext(notifyContext))
                {
                    i.reset();
                    it = observers->erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }

        if(observers->empty())
        {
            m_observerMap.erase(it);
            delete observers;
        }
    }
}

bool View::RegisterMediator(IMediator* mediator)
{
    if (m_mediatorMap.find(mediator->getMediatorName()) != m_mediatorMap.end()) return false;

    m_mediatorMap[mediator->getMediatorName()] = mediator;

    std::vector<NOTIFICATION_NAME_TYPE> interests = mediator->ListNotificationInterests();

    for(size_t i = 0; i < interests.size(); ++i)
    {
        RegisterObserver(interests[i], new Observer((void*)mediator));
    }

    // alert the mediator that it has been registered
    mediator->OnRegister();

    return true;
}

IMediator* View::RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    if (m_mediatorMap.find(mediatorName) == m_mediatorMap.end())
        return NULL;
    return m_mediatorMap[mediatorName];
}

IMediator* View::RemoveMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    IMediator* mediator = NULL;
    std::map<MEDIATOR_NAME_TYPE, IMediator*>::iterator it = m_mediatorMap.find(mediatorName);

    if (it == m_mediatorMap.end()) return NULL;

    mediator = it->second;

    std::vector<NOTIFICATION_NAME_TYPE> interests = mediator->ListNotificationInterests();

    for(size_t i = 0; i < interests.size(); ++i)
    {
        RemoveObserver(interests[i], mediator);
    }

    m_mediatorMap.erase(it);

    if (mediator != NULL) mediator->OnRemove();

    return mediator;
}

bool View::HasMediator(MEDIATOR_NAME_TYPE mediatorName)
{
    return m_mediatorMap.find(mediatorName) != m_mediatorMap.end();
}

void View::InitializeView()
{
}