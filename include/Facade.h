#ifndef _FACADE_H
#define _FACADE_H

#include "IFacade.h"
#include "IController.h"
#include "IModel.h"
#include "IView.h"

#include "Notification.h"
#include "Controller.h"
#include "Model.h"
#include "View.h"

using namespace Mvc::Interface;
using namespace Mvc::Core;

namespace Mvc
{
    namespace Patterns
    {
        class Facade : public IFacade
        {
        protected:
            Facade()
            {
                m_controller = NULL;
                m_model = NULL;
                m_view = NULL;

                InitializeFacade();
            }

        public:
            bool RegisterProxy(IProxy* proxy)
            {
                return m_model->RegisterProxy(proxy);
            }

            IProxy* RetrieveProxy(PROXY_NAME_TYPE proxyName)
            {
                return m_model->RetrieveProxy(proxyName);
            }

            IProxy* RemoveProxy(PROXY_NAME_TYPE proxyName)
            {
                return m_model->RemoveProxy(proxyName);
            }
            bool HasProxy(PROXY_NAME_TYPE proxyName)
            {
                return m_model->HasProxy(proxyName);
            }

            void RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType)
            {
                m_controller->RegisterCommand(notificationName, commandType);
            }

            void RemoveCommand(NOTIFICATION_NAME_TYPE notificationName)
            {
                m_controller->RemoveCommand(notificationName);
            }

            bool HasCommand(NOTIFICATION_NAME_TYPE notificationName)
            {
                return m_controller->HasCommand(notificationName);
            }

            void        RegisterObserver(NOTIFICATION_NAME_TYPE notificationName, IMediator* mediator)
            {
                return m_view->RegisterObserver(notificationName, mediator);
            }

            bool RegisterMediator(IMediator* mediator)
            {
                return m_view->RegisterMediator(mediator);
            }

            IMediator* RetrieveMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                return m_view->RetrieveMediator(mediatorName);
            }

            IMediator* RemoveMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                return m_view->RemoveMediator(mediatorName);
            }

            bool HasMediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                return m_view->HasMediator(mediatorName);
            }

            void NotifyObservers(INotification* notification)
            {
                m_view->NotifyObservers(notification);
            }

            void SendNotification(NOTIFICATION_NAME_TYPE notificationName)
            {
                Notification notification(notificationName);
                NotifyObservers(&notification);
            }

            void SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body)
            {
                Notification notification(notificationName, body);
                NotifyObservers(&notification);
            }

            static IFacade* Instance()
            {
                if (m_instance == NULL)
                {
                    m_instance = new Facade();
                }

                return m_instance;
            }


        public:
            virtual void InitializeFacade()
            {
                InitializeModel();
                InitializeView();
                InitializeController();
            }

        protected:
            virtual void InitializeController()
            {
                if (m_controller != NULL) return;
                m_controller = Controller::Instance();
            }

            virtual void InitializeModel()
            {
                if (m_model != NULL) return;
                m_model = Model::Instance();
            }

            virtual void InitializeView()
            {
                if (m_view != NULL) return;
                m_view = View::Instance();
            }

        protected:
            IController*        m_controller;

            IModel*                m_model;

            IView*                m_view;

            static IFacade* m_instance;
        };
    }
}

#endif
