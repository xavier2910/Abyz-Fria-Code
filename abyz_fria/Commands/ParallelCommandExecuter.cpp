#ifndef ParallelCommandExecuter_h
#define ParallelCommandExecuter_h

#include "CommandExecuter.cpp"

class ParallelCommandExecuter : public CommandExecuter
{
public:
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