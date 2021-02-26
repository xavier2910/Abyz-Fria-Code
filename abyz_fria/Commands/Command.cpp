#ifndef Command_h
#define Command_h

class Command
{
public:
    Command()
    {
        _canExecute = false;
        _isFinished = false;
    }

    virtual void begin()
    {
        _canExecute = true;
    }
    void operator()()
    {
        if (_canExecute)
            this->execute();
    }

    virtual void execute() = 0;

    virtual void end()
    {
        _canExecute = false;
        _isFinished = true;
    }

    bool canExecute()
    {
        return _canExecute;
    }

    bool isFinished()
    {
        return _isFinished;
    }

private:
    bool _canExecute;
    bool _isFinished;
};

#endif