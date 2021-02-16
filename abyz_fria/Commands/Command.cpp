#ifndef Command_h
#define Command_h

class Command
{
public:
    Command()
    {
        _canExecute = false;
    }

    virtual void begin()
    {
        _canExecute = true;
    }
    virtual void execute();
    virtual void end()
    {
        _canExecute = false;
    }

    bool canExecute()
    {
        return _canExecute;
    }

protected:
    bool _canExecute;
};

#endif