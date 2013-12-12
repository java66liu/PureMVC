#ifndef _SIMPLECOMMAND_H
#define _SIMPLECOMMAND_H

#include "ICommand.h"
#include "Notifier.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Interface;

        class SimpleCommand :  public Notifier,public ICommand
        {
        public:
            virtual void Execute(INotification* notification)
            {
            }
        };
    }
}

#endif
