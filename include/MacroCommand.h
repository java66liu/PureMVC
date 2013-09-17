#ifndef _MACROCOMMAND_H
#define _MACROCOMMAND_H

#include "Notifier.h"
#include "ICommand.h"

using namespace Interface;
using namespace Core;

namespace Patterns
{
class MacroCommand : public Notifier, public ICommand
{
public:
    MacroCommand()
    {
    }

    void Execute(INotification* notification)
    {
        for(int i = 0; i < m_subCommands.size(); ++i)
        {
            fnCreateICommand pfnCreateICommand = (fnCreateICommand)m_subCommands[i];
            ICommand* commandInstance = (*pfnCreateICommand)();
            if(commandInstance != NULL)
            {
                commandInstance->Execute(notification);
                delete commandInstance;
                commandInstance = NULL;
            }
        }
    }


protected:
    void AddSubCommand(void* commandType)
    {
        if(commandType != NULL)
        {
            m_subCommands.push_back(commandType);
        }
    }


private:
    vector<void*>        m_subCommands;
};
}
#endif
