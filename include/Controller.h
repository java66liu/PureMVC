#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <map>

#include "IController.h"

namespace Mvc
{
    namespace Interface
    {
        class IView;
        class INotification;
    }

    using namespace Interface;

    namespace Core
    {
        class Controller : public IController
        {
        public:
            Controller();

            void                                    HandlerNotification(INotification* note);

            void                                    RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType);

            bool                                    HasCommand(NOTIFICATION_NAME_TYPE notificationName);

            void                                    RemoveCommand(NOTIFICATION_NAME_TYPE notificationName);

            void*                                   GetCommandFunc(NOTIFICATION_NAME_TYPE notificationName);

        protected:
            virtual void                            InitializeController();

            IView*                                  m_view;
            std::map<NOTIFICATION_NAME_TYPE, void*> m_commandMap;
        };
    }
}

#endif
