#ifndef _NOTIFICATION_H
#define _NOTIFICATION_H

#include "INotification.h"
#include <stddef.h>
using namespace Mvc::Interface;

namespace Mvc
{
    namespace Patterns
    {
        class Notification : public INotification
        {
        public:
            Notification(int name)
            {
                m_name = name;
                m_body = NULL;
            }

            Notification(int name, void* body)
            {
                m_name = name;
                m_body = body;
            }

            NOTIFICATION_NAME_TYPE    getName()
            {
                return m_name;
            }

            void    setBody(void* aBody)
            {
                m_body = aBody;
            }
            void*    getBody()
            {
                return m_body;
            }

        private:
            NOTIFICATION_NAME_TYPE            m_name;
            void*            m_body;
        };
    }
}

#endif
