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
        this->setup();
    }
    void operator()()
    {
        if (_canExecute)
            this->execute();
    }

    virtual void end()
    {
        this->teardown();
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

protected:
    virtual void setup() = 0;
    virtual void execute() = 0;
    virtual void teardown() = 0;

private:
    bool _canExecute;
    bool _isFinished;
};

#endif