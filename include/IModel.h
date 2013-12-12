#ifndef _IMODEL_H
#define _IMODEL_H

#include "MvcType.h"

namespace Mvc
{
    namespace Interface
    {
        class IProxy;

        class IModel
        {
        public:
            virtual bool        RegisterProxy(IProxy*) = 0;
            virtual IProxy*     RetrieveProxy(PROXY_NAME_TYPE proxyName) = 0;
            virtual IProxy*     RemoveProxy(PROXY_NAME_TYPE proxyName) = 0;
            virtual bool        HasProxy(PROXY_NAME_TYPE proxyName) = 0;
        };
}

}

#endif
