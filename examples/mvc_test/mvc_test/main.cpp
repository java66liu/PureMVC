#include <iostream>
using namespace std;

#include "Mediator.h"
using namespace Mvc::Patterns;
using namespace Mvc::Interface;

enum NOTIFY_TYPE
{
    NT_ONE,
    NT_TWO,
    NT_THREE,
    NT_TEST,
    NT_MAX
};

enum MEDIATOR_TYPE
{
    MT_ONE,
    MT_TWO,
    MT_MAX
};

class MyMediator : public Mediator
{
public:
    MyMediator()
    {
        m_mediatorName = MT_ONE;
    }

private:
    vector<NOTIFICATION_NAME_TYPE>    ListNotificationInterests()
    {
        vector<NOTIFICATION_NAME_TYPE> tempList;
        tempList.push_back(NT_ONE);
		tempList.push_back(NT_TWO);
        tempList.push_back(NT_TEST);
        return tempList;
    }

    void    HandlerNotification(INotification* pNotification)
    {
        if(NT_ONE == pNotification->getName())
        {
            cout << "handler NT noe" << endl;
        }
        else if(NT_TEST == pNotification->getName())
        {
            Facade::Instance()->RemoveMediator(MT_TWO);
        }
    }
};

class MyTwoMediator : public Mediator
{
public:
    MyTwoMediator()
    {
        m_mediatorName = MT_TWO;
    }

private:
    vector<NOTIFICATION_NAME_TYPE>    ListNotificationInterests()
    {
        vector<NOTIFICATION_NAME_TYPE> tempList;
        tempList.push_back(NT_TWO);
        tempList.push_back(NT_TWO);
        tempList.push_back(NT_TEST);
        return tempList;
    }

    void    HandlerNotification(INotification* pNotification)
    {
        if(NT_TWO == pNotification->getName())
        {
            cout << "handler NT two, and nofity NT one" << endl;
            
            SendNotification(NT_ONE, NULL);
        }
    }
};

class MyCommand : public ICommand
{
private:
    void    Execute(INotification*)
    {
        cout << "in my command" << endl;
    }
};

ICommand* myCommandCreator()
{
    return new MyCommand;
}

int main()
{
    Mvc::Patterns::Facade::Instance()->RegisterMediator(new MyMediator());
    Mvc::Patterns::Facade::Instance()->RegisterMediator(new MyTwoMediator());
    
    // RegisterCommand 第二个参数必须为函数指针,用于框架中调用此回调以创建派生类Command对象
    // 且当创建的对象调用Execute函数后,会被摧毁
    Mvc::Patterns::Facade::Instance()->RegisterCommand(NT_THREE, myCommandCreator);
    Mvc::Patterns::Facade::Instance()->RegisterCommand(NT_THREE, myCommandCreator);


    Mvc::Patterns::Facade::Instance()->SendNotification(NT_THREE, NULL);

    Mvc::Patterns::Facade::Instance()->SendNotification(NT_ONE, NULL);
    Mvc::Patterns::Facade::Instance()->SendNotification(NT_TWO, NULL);
    Mvc::Patterns::Facade::Instance()->SendNotification(NT_TEST, NULL);

    cin.get();
    return 0;
}