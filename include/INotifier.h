#ifndef _INOTIFIER
#define _INOTIFIER

#include "MvcType.h"

namespace Mvc
{
    namespace Interface
    {
        class INotifier
        {
        public:
            virtual ~INotifier()    {}
            virtual void            SendNotification(NOTIFICATION_NAME_TYPE notificationName) = 0;
            virtual void            SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body) = 0;
        };
    }
}

#endif
