#ifndef _IVIEW_H
#define _IVIEW_H

#include "MvcType.h"

namespace Mvc
{
    namespace Interface
    {
        class IMediator;
        class IObserver;
        class INotification;

        class IView
        {
        public:
            virtual void        RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator) = 0;
            virtual void        RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IObserver* observer) = 0;
            virtual void        RemoveObserver(NOTIFICATION_NAME_TYPE notificationName, void* notifyContext) = 0;
            virtual void        NotifyObservers(INotification* note) = 0;

            virtual bool        RegisterMediator(IMediator* mediator) = 0;
            virtual IMediator*  RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;

            virtual IMediator*  RemoveMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;
            virtual bool        HasMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;
        };
    }
}

#endif
