#ifndef ParallelCommandExecuter_h
#define ParallelCommandExecuter_h

#include "CommandExecuter.cpp"

class ParallelCommandExecuter : public CommandExecuter
{
protected:
    virtual void setup() override {}
    virtual void teardown() override {}

    void execute() override
    {
        for (auto element = _commands.end(); element != _commands.begin(); --element)
        {
            if ((element->second)())
            {
                element->first->begin();
            }
            (element->first)->operator()();
            if (element->first->isFinished())
            {
                _commands.erase(element);
            }
        }
    }
};

#endif