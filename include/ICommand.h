#ifndef _ICOMMAND_H
#define _ICOMMAND_H

namespace Mvc
{
    namespace Interface
    {
        class INotification;
        class ICommand;
        typedef ICommand* (*fnCreateICommand)();

        class ICommand
        {
        public:
            virtual ~ICommand() {}
            virtual void    Execute(INotification*) = 0;
        };

        template<typename T>
        class CreateCommand
        {
        public:
            static ICommand* create()
            {
                static T _t;
                return &_t;
            }
        };
    }
}

#endif
