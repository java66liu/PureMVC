#ifndef _IFACADE_H
#define _IFACADE_H

#include "INotifier.h"
#include "IProxy.h"
#include "IMediator.h"

namespace Mvc
{
    namespace Interface
    {
        class IProxy;
        class INotification;
        class IMediator;

        class IFacade : public INotifier
        {
        public:
            virtual bool        RegisterProxy(IProxy* proxy) = 0;
            virtual IProxy*        RetrieveProxy(PROXY_NAME_TYPE proxyName) = 0;
            virtual IProxy*        RemoveProxy(PROXY_NAME_TYPE proxyName) = 0;
            virtual bool        HasProxy(PROXY_NAME_TYPE proxyName) = 0;

            virtual void        RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType) = 0;
            virtual void        RemoveCommand(NOTIFICATION_NAME_TYPE notificationName) = 0;
            virtual bool        HasCommand(NOTIFICATION_NAME_TYPE notificationName) = 0;

            virtual void        RegisterObserver(NOTIFICATION_NAME_TYPE, IMediator* mediator) = 0;

            virtual bool        RegisterMediator(IMediator* mediator) = 0;
            virtual IMediator*    RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;
            virtual IMediator*    RemoveMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;
            virtual bool        HasMediator(MEDIATOR_NAME_TYPE mediatorName) = 0;

            virtual void        NotifyObservers(INotification* note) = 0;
        };
    }
}

#endif
