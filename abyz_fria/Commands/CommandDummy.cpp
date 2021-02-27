#ifndef CommandDummy_h
#define CommandDummy_h

#include "Command.cpp"

class CommandDummy : public Command
{
public:
    bool hasSetup;
    int executedTime;
    bool torndown;

    CommandDummy();

    void setup() override
    {
        hasSetup = true;
    }

    void execute() override
    {
        ++executedTime;
    }

    void teardown() override
    {
        torndown = true;
    }
};

CommandDummy::CommandDummy()
{
}

#endif