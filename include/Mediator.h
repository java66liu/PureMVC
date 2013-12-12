#ifndef _MEDIATOR_H
#define _MEDIATOR_H

#include "Notifier.h"
#include "IMediator.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Mvc::Interface;

        class Mediator : public Notifier, public IMediator
        {
        public:
            Mediator(IFacade* facade);

            Mediator(IFacade* facade, MEDIATOR_NAME_TYPE mediatorName);

            Mediator(IFacade* facade, MEDIATOR_NAME_TYPE mediatorName, void* viewComponent);

            std::vector<NOTIFICATION_NAME_TYPE> ListNotificationInterests();

            void                                OnRegister();

            void                                OnRemove();

            MEDIATOR_NAME_TYPE                  getMediatorName();

            void*                               getViewComponent();
            void                                setViewComponent(void* aViewComponent);

            void                                HandlerNotification(INotification*);
        protected:
            MEDIATOR_NAME_TYPE                  m_mediatorName;
            void*                               m_viewComponent;
        };
    }
}

#endif
