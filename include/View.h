#ifndef _VIEW_H
#define _VIEW_H

#include <map>
#include <vector>

#include "IView.h"

namespace Mvc
{
    namespace Interface
    {
        class INotification;
        class IMediator;
    }

    namespace Core
    {
        using namespace Mvc::Interface;
        using namespace Mvc::Patterns;

        class View : public IView
        {
        public:
            View();
            ~View();

        protected:

            void            RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator);

            void            RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IObserver* observer);

            void            NotifyObservers(INotification* notification);

            void            RemoveObserver(NOTIFICATION_NAME_TYPE notificationName, void* notifyContext);

            bool            RegisterMediator(IMediator* mediator);

            IMediator*      RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName);

            IMediator*      RemoveMediator(MEDIATOR_NAME_TYPE mediatorName);

            bool            HasMediator(MEDIATOR_NAME_TYPE mediatorName);

        protected:
            virtual void    InitializeView();

        protected:
            std::map<MEDIATOR_NAME_TYPE, IMediator*>                        m_mediatorMap;

            typedef std::vector<std::shared_ptr<IObserver> > OBSERVER_LIST_TYPE;
            std::map<NOTIFICATION_NAME_TYPE, OBSERVER_LIST_TYPE*>           m_observerMap;
        };
    }
}

#endif
