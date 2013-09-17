#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "IHandlerNotification.h"
#include "ICommand.h"
#include "IObserver.h"
#include "INotification.h"
#include "IController.h"

using namespace Mvc::Interface;

namespace Mvc
{
    namespace Patterns
    {
        class Observer : public IObserver
        {
        public:
            Observer(void* notifyContext)
            {
                m_notifyContext = notifyContext;
            }

            void NotifyObserver(INotification* notification)
            {
                void* context;

                context = getNotifyContext();

                IHandlerNotification* pHandlerNotification = (IHandlerNotification*)context;
                if(0 != pHandlerNotification)
                {
                    pHandlerNotification->HandlerNotification(notification);
                }
            }

            bool CompareNotifyContext(void* obj)
            {
                return m_notifyContext == obj;
            }

            void*            getNotifyContext()
            {
                return m_notifyContext;
            }
            void            setNotifyContext(void* aContext)
            {
                m_notifyContext = aContext;
            }

        private:
            void*            m_notifyContext;
        };
    }
}

#endif
