#ifndef _IPROXY_H
#define _IPROXY_H

#include "MvcType.h"

namespace Mvc
{
    namespace Interface
    {
        class IProxy
        {
        public:
            virtual ~IProxy()   {}
            virtual PROXY_NAME_TYPE     getProxyName() = 0;
            virtual void*               getData() = 0;
            virtual void                setData(void*) = 0;

            virtual void                OnRegister() = 0;
            virtual void                OnRemove() = 0;
        };
    }
}


#endif
