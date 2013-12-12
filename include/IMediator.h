#ifndef _IMEDIATOR_H
#define _IMEDIATOR_H

#include <vector>

#include "IHandlerNotification.h"

namespace Mvc
{
    namespace Interface
    {
        class INotification;

        class IMediator : public IHandlerNotification
        {
        public:
            virtual ~IMediator()                        {}
            virtual MEDIATOR_NAME_TYPE                  getMediatorName() = 0;
            virtual void*                               getViewComponent() = 0;
            virtual void                                setViewComponent(void*) = 0;

            virtual std::vector<NOTIFICATION_NAME_TYPE> ListNotificationInterests() = 0;
            virtual void                                OnRegister() = 0;
            virtual void                                OnRemove() = 0;

        };
    }
}

#endif
