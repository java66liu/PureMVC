#ifndef _NOTIFIER_H
#define _NOTIFIER_H

#include "INotifier.h"

namespace Mvc
{
    namespace Interface
    {
        class IFacade;
    }

    namespace Patterns
    {
        using namespace Mvc::Interface;

        class Notifier : public INotifier
        {
        public:
            Notifier(IFacade* facade);

            void            SendNotification(NOTIFICATION_NAME_TYPE notificationName);

            void            SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body);

        private:
            IFacade*        m_facade;
        };
    }
}

#endif
