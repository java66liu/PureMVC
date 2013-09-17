#ifndef _ICONTROLLER_H
#define _ICONTROLLER_H

#include "IHandlerNotification.h"
#include "INotification.h"
using namespace Mvc::Interface;

namespace Mvc
{
    namespace Interface
    {
        class IController : public IHandlerNotification
        {
        public:
            virtual void    RegisterCommand(NOTIFICATION_NAME_TYPE, void*) = 0;
            virtual void    RemoveCommand(NOTIFICATION_NAME_TYPE) = 0;
            virtual bool    HasCommand(NOTIFICATION_NAME_TYPE) = 0;
            virtual void*   GetCommandFunc(NOTIFICATION_NAME_TYPE) = 0;
        };
    }
}


#endif
