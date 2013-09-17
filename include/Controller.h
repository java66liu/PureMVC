#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "IController.h"
#include "Observer.h"
#include "View.h"
#include "ICommand.h"

#include <map>
using namespace std;
using namespace Mvc::Interface;
using namespace Mvc::Core;
using namespace Mvc::Patterns;

namespace Mvc
{
    namespace Core
    {
        class Controller : public IController
        {
        public:
            Controller()
            {
                InitializeController();
            }

            void HandlerNotification(INotification* note)
            {
                map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(note->getName());

                if(it == m_commandMap.end())
                    return;

                fnCreateICommand commandType = (fnCreateICommand)it->second;

                if(commandType != NULL)
                {
                    ICommand* commandInstance = (*commandType)();
                    if(commandInstance != NULL)
                    {
                        commandInstance->Execute(note);
                        delete commandInstance;
                        commandInstance = NULL;
                    }
                }

            }
            void RegisterCommand(NOTIFICATION_NAME_TYPE notificationName, void* commandType)
            {
                if (m_commandMap.find(notificationName) == m_commandMap.end())
                {
                    m_view->RegisterObserver(notificationName, new Observer((void*)this));
                }

                m_commandMap[notificationName] = commandType;
            }

            bool HasCommand(NOTIFICATION_NAME_TYPE notificationName)
            {
                return m_commandMap.find(notificationName) != m_commandMap.end();
            }

            void RemoveCommand(NOTIFICATION_NAME_TYPE notificationName)
            {
                map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(notificationName);

                if (it != m_commandMap.end())
                {
                    m_view->RemoveObserver(notificationName, this);
                    m_commandMap.erase(it);
                }
            }

            void* GetCommandFunc(NOTIFICATION_NAME_TYPE notificationName)
            {
                map<NOTIFICATION_NAME_TYPE, void*>::iterator it = m_commandMap.find(notificationName);
                if (it != m_commandMap.end())
                {
                    return (*it).second;
                }
                else
                {
                    return NULL;
                }
            }

            static IController* Instance()
            {
                if (m_instance == NULL)
                {
                    m_instance = new Controller();
                }

                return m_instance;
            }

        protected:
            virtual void InitializeController()
            {
                m_view = View::Instance();
            }

            IView*             m_view;
            map<NOTIFICATION_NAME_TYPE, void*>    m_commandMap;

            static IController* m_instance;
        };
    }
}

#endif
