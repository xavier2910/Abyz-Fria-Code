#ifndef CommandExecuter_h
#define CommandExecuter_h

#include <StandardCplusplus.h>
#include <queue>
#include <utility.h>

#include "Command.cpp"

class CommandExecuter : public Command
{
protected:
    std::queue<std::pair<Command *, bool (*)()>> _commands;

public:
    virtual void addCommand(Command *, bool (*)());
};

void CommandExecuter::addCommand(Command *command, bool (*nullaryPredicate)())
{
    _commands.push(std::make_pair(command, nullaryPredicate));
}

#endif