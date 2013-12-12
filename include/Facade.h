#ifndef _FACADE_H
#define _FACADE_H

#include "INotification.h"
#include "IFacade.h"

namespace Mvc
{
    namespace Interface
    {
        class IView;
        class IModel;
        class IController;
    }

    namespace Patterns
    {
        using namespace Interface;

        class Facade : public IFacade
        {
        public:
            Facade();

        public:
            bool            RegisterProxy(IProxy* proxy);

            IProxy*         RetrieveProxy(PROXY_NAME_TYPE proxyName);

            IProxy*         RemoveProxy(PROXY_NAME_TYPE proxyName);
            bool            HasProxy(PROXY_NAME_TYPE proxyName);

            void            RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType);

            void            RemoveCommand(NOTIFICATION_NAME_TYPE notificationName);

            bool            HasCommand(NOTIFICATION_NAME_TYPE notificationName);

            void            RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator);

            bool            RegisterMediator(IMediator* mediator);

            IMediator*      RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName);

            IMediator*      RemoveMediator(MEDIATOR_NAME_TYPE mediatorName);

            bool            HasMediator(MEDIATOR_NAME_TYPE mediatorName);

            void            NotifyObservers(INotification* notification);

            void            SendNotification(NOTIFICATION_NAME_TYPE notificationName);

            void            SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body);

        protected:
            virtual void    InitializeFacade();

            virtual void    InitializeController();

            virtual void    InitializeModel();

            virtual void    InitializeView();

        protected:
            IController*    m_controller;

            IModel*         m_model;

            IView*          m_view;
        };
    }
}

#endif
