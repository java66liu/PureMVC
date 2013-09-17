#ifndef _VIEW_H
#define _VIEW_H

#include <map>
#include <vector>
#include <stddef.h>
using namespace std;

#include "IView.h"
#include "Observer.h"
#include "INotification.h"
#include "IMediator.h"

using namespace Mvc::Interface;
using namespace Mvc::Patterns;

namespace Mvc
{
    namespace Core
    {
        class View : public IView
        {
        protected:
            View()
            {
                InitializeView();
            }

            void RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator)
            {
                /*  TODO::所有观察者可以考虑为值对象   */
                IObserver* observer = new Observer((void*)mediator);
                if(NULL != observer)
                {
                    RegisterObserver(notificationName, observer);
                }
            }

            void RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IObserver* observer)
            {
                if (m_observerMap.find(notificationName) == m_observerMap.end())
                {
                    m_observerMap[notificationName] = new vector<IObserver*>();
                }

                m_observerMap[notificationName]->push_back(observer);
            }

            void NotifyObservers(INotification* notification)
            {
                map<NOTIFICATION_NAME_TYPE, vector<IObserver*>*>::iterator it = m_observerMap.find(notification->getName());

                if (it != m_observerMap.end())
                {
                    vector<IObserver*>* observers = it->second;

                    if (observers != NULL)
                    {
                        vector<IObserver*>::iterator it = observers->begin();
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

            void RemoveObserver(NOTIFICATION_NAME_TYPE notificationName, void* notifyContext)
            {
                map<NOTIFICATION_NAME_TYPE, vector<IObserver*>*>::iterator it = m_observerMap.find(notificationName);
                if(it != m_observerMap.end())
                {
                    vector<IObserver*>* observers = it->second;

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

            bool RegisterMediator(IMediator* mediator)
            {
                if (m_mediatorMap.find(mediator->getMediatorName()) != m_mediatorMap.end()) return false;

                m_mediatorMap[mediator->getMediatorName()] = mediator;

                vector<NOTIFICATION_NAME_TYPE> interests = mediator->ListNotificationInterests();

                for(size_t i = 0; i < interests.size(); ++i)
                {
                    RegisterObserver(interests[i], new Observer((void*)mediator));
                }

                // alert the mediator that it has been registered
                mediator->OnRegister();

                return true;
            }

            IMediator* RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                if (m_mediatorMap.find(mediatorName) == m_mediatorMap.end())
                    return NULL;
                return m_mediatorMap[mediatorName];
            }

            IMediator* RemoveMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                IMediator* mediator = NULL;
                map<MEDIATOR_NAME_TYPE, IMediator*>::iterator it = m_mediatorMap.find(mediatorName);

                if (it == m_mediatorMap.end()) return NULL;

                mediator = it->second;

                vector<NOTIFICATION_NAME_TYPE> interests = mediator->ListNotificationInterests();

                for(size_t i = 0; i < interests.size(); ++i)
                {
                    RemoveObserver(interests[i], mediator);
                }

                m_mediatorMap.erase(it);

                if (mediator != NULL) mediator->OnRemove();

                return mediator;
            }

            bool HasMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                return m_mediatorMap.find(mediatorName) != m_mediatorMap.end();
            }

        public:
            static IView* Instance()
            {
                if (m_instance == NULL)
                {
                    m_instance = new View();
                }

                return m_instance;
            }

        protected:
            virtual void InitializeView()
            {
            }

        protected:
            map<MEDIATOR_NAME_TYPE, IMediator*>                m_mediatorMap;
            map<NOTIFICATION_NAME_TYPE, vector<IObserver*>*>            m_observerMap;

        protected:
            static    IView* m_instance;
        };
    }
}

#endif
