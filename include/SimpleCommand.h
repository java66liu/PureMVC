#ifndef _SIMPLECOMMAND_H
#define _SIMPLECOMMAND_H

#include "Notifier.h"
#include "ICommand.h"

using namespace Interface;
using namespace Patterns;

namespace Patterns
{
class SimpleCommand :  public Notifier,public ICommand
{
public:
    virtual void Execute(INotification* notification)
    {
    }
};
}

#endif
