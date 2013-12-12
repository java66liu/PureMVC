#ifndef _NOTIFICATION_H
#define _NOTIFICATION_H

#include "INotification.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Mvc::Interface;

        class Notification : public INotification
        {
        public:
            Notification(int name);

            Notification(int name, void* body);

            NOTIFICATION_NAME_TYPE  getName();

            void                    setBody(void* aBody);
            void*                   getBody();

        private:
            NOTIFICATION_NAME_TYPE  m_name;
            void*                   m_body;
        };
    }
}

#endif
