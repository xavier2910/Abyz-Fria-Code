#include <SD.h>
#include "arduino.h"

class Logger
{
private:
    SDLib::File logFile;
    bool canLog;

public:
    Logger() {}
    Logger(const char *fileName) : logFile(SD.open(fileName, FILE_READ))
    {
        if (!logFile)
        {
            canLog = false;
        }
        else
        {
            canLog = true;
        }
    }

    bool log(int paramNum, String params[])
    {
        if (!canLog)
        {
            return false;
        }

        String line = "";
        for (int i = 0; i < paramNum; i++)
        {
            line += line.length() == 0 ? "" : ",";
            line += params[i];
        }
        logFile.println(line);
        return true;
    }
};