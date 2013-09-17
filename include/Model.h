#ifndef _MODEL_H
#define _MODEL_H

#include <map>
using namespace std;

#include "IModel.h"
#include <stddef.h>
using namespace Mvc::Interface;

namespace Mvc
{
    namespace Core
    {
        class Model : public IModel
        {
        protected:
            Model()
            {
                InitializeModel();
            }

            bool RegisterProxy(IProxy* proxy)
            {
                if(m_proxyMap.find(proxy->getProxyName()) == m_proxyMap.end())
                {
                    m_proxyMap[proxy->getProxyName()] = proxy;
                    proxy->OnRegister();

                    return true;
                }

                return false;
            }

            IProxy* RetrieveProxy(PROXY_NAME_TYPE proxyName)
            {
                map<PROXY_NAME_TYPE, IProxy*>::iterator it = m_proxyMap.find(proxyName);
                if (it == m_proxyMap.end()) return NULL;
                return (*it).second;
            }

            bool HasProxy(PROXY_NAME_TYPE proxyName)
            {
                return m_proxyMap.find(proxyName) != m_proxyMap.end();
            }

            IProxy* RemoveProxy(PROXY_NAME_TYPE proxyName)
            {
                IProxy* proxy = NULL;

                if (m_proxyMap.find(proxyName) != m_proxyMap.end())
                {
                    proxy = RetrieveProxy(proxyName);
                    m_proxyMap.erase(m_proxyMap.find(proxyName));
                }

                if (proxy != NULL) proxy->OnRemove();
                return proxy;
            }

        public:
            static IModel* Instance()
            {
                if (m_instance == NULL) m_instance = new Model();

                return m_instance;
            }

        protected:
            virtual void InitializeModel()
            {
            }

            map<PROXY_NAME_TYPE, IProxy*> m_proxyMap;

            static  IModel* m_instance;
        };
    }
}

#endif
