#ifndef _PROXY_H
#define _PROXY_H

#include "Notifier.h"
#include "IProxy.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Mvc::Interface;

        class Proxy : public Notifier, public IProxy
        {
        public:
            Proxy(IFacade* facade);

            Proxy(IFacade* facade, PROXY_NAME_TYPE proxyName);

            Proxy(IFacade* facade, PROXY_NAME_TYPE proxyName, void* data);

            virtual void        OnRegister();
            virtual void        OnRemove();

            PROXY_NAME_TYPE     getProxyName();

        public:
            void                setData(void* aData);
            void*               getData();

        protected:
            PROXY_NAME_TYPE     m_proxyName;
            void*               m_data;
        };
    }
}

#endif
