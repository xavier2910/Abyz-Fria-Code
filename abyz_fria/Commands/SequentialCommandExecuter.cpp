#ifndef SequentialCommandExecuter_h
#define SequentialCommandExecuter_h

#include "CommandExecuter.cpp"

class SequentialCommandExecuter : public CommandExecuter
{
protected:
    virtual void setup() override {}
    virtual void teardown() override {}

    void execute() override
    {
        if ((_commands.front().second)())
        {
            _commands.front().first->begin();
        }
        _commands.front().first->operator()();
        if (_commands.front().first->isFinished())
        {
            _commands.erase(_commands.begin());
        }
    }
};

#endif