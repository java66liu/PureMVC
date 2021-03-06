#ifndef _INOTIFICATION_H
#define _INOTIFICATION_H

#include "MvcType.h"

namespace Mvc
{
    namespace Interface
    {
        class INotification
        {
        public:

            virtual NOTIFICATION_NAME_TYPE          getName() = 0;
            virtual    void*                        getBody() = 0;
            virtual    void                         setBody(void*) = 0;
        };
    }
}

#endif
