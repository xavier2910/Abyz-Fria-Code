#ifndef CommandExecuter_h
#define CommandExecuter_h

#include <StandardCplusplus.h>
#include <queue>
#include <utility.h>
#include <functional>

#include "Command.cpp"

class CommandExecuter : public Command
{
private:
    std::queue<std::pair<Command *, std::unary_function<bool, bool>>> _commands; //TODO: create own type for function

public:
    virtual void addCommand(Command *, std::unary_function<bool, bool>);
};

void CommandExecuter::addCommand(Command *command, std::unary_function<bool, bool> nullaryPredicate)
{
    _commands.push(std::make_pair(command, nullaryPredicate));
}

/* TODO: move to SequentialCommandExecuter
void CommandExecuter::executeCommands()
{
    while (!_commands.empty())
    {
        bool dummy = false;

        if ((_commands.front().second)(dummy))
        {
            _commands.front().first->begin();
        }
        if (_commands.front().first->canExecute())
        {
            _commands.front().first->execute();
            _commands.pop();
        }
    }
}
*/
#endif