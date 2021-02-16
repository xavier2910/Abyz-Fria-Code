#ifndef CommandExecuter_h
#define CommandExecuter_h

#include <StandardCplusplus.h>
#include <queue>
#include <utility.h>

#include "Command.cpp"

class CommandExecuter
{
private:
    std::queue<std::pair<Command, bool (*)(unsigned long)>> _commands;

public:
    CommandExecuter();

    void addCommand(Command *, bool (*)(unsigned long));

    void executeCommands();
};

CommandExecuter::CommandExecuter()
{
}

void CommandExecuter::addCommand(Command *command, bool (*condition)(unsigned long))
{
    _commands.push(std::make_pair(*command, condition));
}

void CommandExecuter::executeCommands()
{
    while (!_commands.empty())
    {
        if (_commands.front().second(millis()))
        {
            _commands.front().first.begin();
        }
        if (_commands.front().first.canExecute())
        {
            _commands.front().first.execute();
            _commands.pop();
        }
    }
}

#endif