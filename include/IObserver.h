#ifndef _IOBSERVER_H
#define _IOBSERVER_H

namespace Mvc
{
    namespace Interface
    {
        class INotification;

        class IObserver
        {
        public:
            virtual ~IObserver()    {}
            virtual void            setNotifyContext(void*) = 0;
            virtual void*           getNotifyContext() = 0;

            virtual void            NotifyObserver(INotification*) = 0;
            virtual bool            CompareNotifyContext(void*) = 0;
        };
    }
}

#endif
