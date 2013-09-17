#ifndef _NOTIFIER_H
#define _NOTIFIER_H

#include "INotifier.h"
#include "IFacade.h"
#include "Facade.h"
using namespace Mvc::Interface;

namespace Mvc
{
    namespace Patterns
    {
        class Notifier : public INotifier
        {
        public:
            Notifier()
            {
                m_facade = Patterns::Facade::Instance();
            }

            void SendNotification(NOTIFICATION_NAME_TYPE notificationName)
            {
                m_facade->SendNotification(notificationName);
            }

            void SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body)
            {
                m_facade->SendNotification(notificationName, body);
            }

        protected:
            IFacade*    getFacade()
            {
                return m_facade;
            }

        private:
            IFacade*        m_facade;                    // = PureMVC.Patterns.Facade.Instance;    TODO
        };
    }
}

#endif
