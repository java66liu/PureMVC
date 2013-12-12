#ifndef _MODEL_H
#define _MODEL_H

#include <map>

#include "IModel.h"

namespace Mvc
{
    namespace Core
    {
        using namespace Mvc::Interface;

        class Model : public IModel
        {
        public:
            Model();

        protected:
            bool            RegisterProxy(IProxy* proxy);

            IProxy*         RetrieveProxy(PROXY_NAME_TYPE proxyName);

            bool            HasProxy(PROXY_NAME_TYPE proxyName);

            IProxy*         RemoveProxy(PROXY_NAME_TYPE proxyName);

        protected:
            virtual void    InitializeModel();

        private:
            std::map<PROXY_NAME_TYPE, IProxy*> m_proxyMap;
        };
    }
}

#endif
