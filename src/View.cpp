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

void View::RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator)
{
    /*  TODO::所有观察者可以考虑为值对象   */
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
        m_observerMap[notificationName] = new std::vector<IObserver*>();
    }

    m_observerMap[notificationName]->push_back(observer);
}

void View::NotifyObservers(INotification* notification)
{
    std::map<NOTIFICATION_NAME_TYPE, std::vector<IObserver*>*>::iterator it = m_observerMap.find(notification->getName());

    if (it != m_observerMap.end())
    {
        std::vector<IObserver*>* observers = it->second;

        if (observers != NULL)
        {
            std::vector<IObserver*>::iterator it = observers->begin();
            for(size_t i = 0; i < observers->size(); )
            {
                IObserver* observer = (*observers)[i];

                if(observer == NULL || observer->getNotifyContext() == NULL)
                {
                    it = observers->erase(it);
                    delete observer;
                    continue;
                }

                observer->NotifyObserver(notification);
                ++i;
                ++it;
            }
        }
    }
}

void View::RemoveObserver(NOTIFICATION_NAME_TYPE notificationName, void* notifyContext)
{
    std::map<NOTIFICATION_NAME_TYPE, std::vector<IObserver*>*>::iterator it = m_observerMap.find(notificationName);
    if(it != m_observerMap.end())
    {
        std::vector<IObserver*>* observers = it->second;

        for(size_t i = 0; i < observers->size(); ++i)
        {
            IObserver* observer = (*observers)[i];
            if (observer->CompareNotifyContext(notifyContext))
            {
                /*  设置为无效状态 */
                observer->setNotifyContext(NULL);
                break;
            }
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