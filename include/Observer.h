#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "MvcType.h"
#include "IObserver.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Mvc::Interface;

        class Observer : public IObserver
        {
        public:
            Observer(void* notifyContext);

            void                NotifyObserver(INotification* notification);

            bool                CompareNotifyContext(void* obj);

            void*               getNotifyContext();
            void                setNotifyContext(void* aContext);

        private:
            void*               m_notifyContext;
        };
    }
}

#endif
