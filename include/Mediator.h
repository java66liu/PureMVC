#ifndef _MEDIATOR_H
#define _MEDIATOR_H

#include "Notifier.h"
#include "IMediator.h"

using namespace Mvc::Interface;
using namespace Mvc::Patterns;

namespace Mvc
{
    namespace Patterns
    {
        class Mediator : public Notifier, public IMediator
        {
        public:
            Mediator()
            {
                m_mediatorName = MEDIATOR_NAME_TYPE();
                m_viewComponent = NULL;
            }

            Mediator(MEDIATOR_NAME_TYPE mediatorName)
            {
                m_mediatorName = mediatorName;
                m_viewComponent = NULL;
            }

            Mediator(MEDIATOR_NAME_TYPE mediatorName, void* viewComponent)
            {
                m_mediatorName = mediatorName;
                m_viewComponent = viewComponent;
            }

            vector<NOTIFICATION_NAME_TYPE> ListNotificationInterests()
            {
                vector<NOTIFICATION_NAME_TYPE> temp;
                return temp;
            }

            void OnRegister()
            {
            }

            void OnRemove()
            {
            }

            MEDIATOR_NAME_TYPE getMediatorName()
            {
                return m_mediatorName;
            }

            void*    getViewComponent()
            {
                return m_viewComponent;
            }
            void    setViewComponent(void* aViewComponent)
            {
                m_viewComponent = aViewComponent;
            }

            void    HandlerNotification(INotification*)
            {

            }
        protected:
            MEDIATOR_NAME_TYPE    m_mediatorName;
            void*            m_viewComponent;
        };
    }
}

#endif
