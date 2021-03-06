#ifndef CommandExecuter_h
#define CommandExecuter_h

#include <StandardCplusplus.h>
#include <list>
#include <utility.h>

#include "Command.cpp"

class CommandExecuter : public Command
{
protected:
    std::list<std::pair<Command *, bool (*)()>> _commands;

public:
    virtual void addCommand(Command *, bool (*)());
};

void CommandExecuter::addCommand(Command *command, bool (*nullaryPredicate)())
{
    _commands.push_back(std::make_pair(command, nullaryPredicate));
}

#endif