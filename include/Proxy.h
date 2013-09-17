#ifndef _PROXY_H
#define _PROXY_H

#include "Notifier.h"
#include "IProxy.h"

using namespace Mvc::Interface;

namespace Mvc
{
    namespace Patterns
    {
        class Proxy : public Notifier, public IProxy
        {
        public:
            Proxy()
            {
                m_proxyName = PROXY_NAME_TYPE();
                m_data = NULL;
            }

            Proxy(PROXY_NAME_TYPE proxyName)
            {
                m_proxyName = proxyName;
                m_data = NULL;
            }

            Proxy(PROXY_NAME_TYPE proxyName, void* data)
            {
                m_proxyName = proxyName;
                m_data = data;
            }

            virtual void OnRegister()
            {
            }

            virtual void OnRemove()
            {
            }

            PROXY_NAME_TYPE getProxyName()
            {
                return m_proxyName;
            }

        public:
            void    setData(void* aData)
            {
                m_data = aData;
            }
            void*    getData()
            {
                return m_data;
            }

        protected:
            PROXY_NAME_TYPE            m_proxyName;
            void*            m_data;

        };
    }
}

#endif
