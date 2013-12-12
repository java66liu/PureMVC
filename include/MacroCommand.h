#ifndef _MACROCOMMAND_H
#define _MACROCOMMAND_H

#include <vector>

#include "Notifier.h"
#include "ICommand.h"

namespace Mvc
{
    namespace Patterns
    {
        using namespace Mvc::Interface;

        class MacroCommand : public Notifier, public ICommand
        {
        public:
            MacroCommand(IFacade* facade);

            void                Execute(INotification* notification);

        protected:
            void                AddSubCommand(void* commandType);

        private:
            std::vector<void*>  m_subCommands;
        };
    }
}
#endif
