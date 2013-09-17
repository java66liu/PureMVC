#ifndef _IMEDIATOR_H
#define _IMEDIATOR_H

#include "IHandlerNotification.h"

#include <vector>
using namespace std;

#include "INotification.h"

typedef int MEDIATOR_NAME_TYPE;

namespace Mvc
{
    namespace Interface
    {
        class INotification;

        class IMediator : public IHandlerNotification
        {
        public:
            virtual ~IMediator()    {}
            virtual MEDIATOR_NAME_TYPE    getMediatorName() = 0;
            virtual void*            getViewComponent() = 0;
            virtual    void            setViewComponent(void*) = 0;

            virtual vector<NOTIFICATION_NAME_TYPE>  ListNotificationInterests() = 0;
            virtual void            OnRegister() = 0;
            virtual void            OnRemove() = 0;

        };
    }
}


#endif
