#ifndef _IHANDLER_NOTIFICATION_H
#define _IHANDLER_NOTIFICATION_H

namespace Mvc
{
    namespace Interface
    {
        class INotification;
        class IHandlerNotification
        {
        public:
            virtual ~IHandlerNotification() {}
            virtual void    HandlerNotification(INotification*) = 0;
        };
    }
}

#endif
