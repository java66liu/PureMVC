#ifndef _INOTIFIER
#define _INOTIFIER

#include "INotification.h"

namespace Mvc
{
    namespace Interface
    {
        class INotifier
        {
        public:
            virtual ~INotifier()    {}
            virtual void    SendNotification(NOTIFICATION_NAME_TYPE notificationName) = 0;
            virtual void    SendNotification(NOTIFICATION_NAME_TYPE notificationName, void* body) = 0;
            //virtual void    SendNotification(  notificationName, void* body, string type) = 0;
        };
    }
}

#endif
