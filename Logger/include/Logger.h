#ifndef LOGGER_H
#define LOGGER_H

// Logger not in use - using boost library for now
class Logger
{
public:
    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }
private:
    Logger() {}
    Logger(Logger const&);
    void operator=(Logger const&);

};

#endif // LOGGER_H
