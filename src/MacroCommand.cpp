#include "MacroCommand.h"

using namespace Mvc;
using namespace Mvc::Patterns;

MacroCommand::MacroCommand(IFacade* facade) : Notifier(facade)
{
}

void MacroCommand::Execute(INotification* notification)
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

void MacroCommand::AddSubCommand(void* commandType)
{
    if(commandType != NULL)
    {
        m_subCommands.push_back(commandType);
    }
}