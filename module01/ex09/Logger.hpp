#ifndef LOGGER_H
# define LOGGER_H

# include <string>
#include <fstream>

class Logger{
    private:
    void logToConsole(std::string log);
    void logToFile(std::string log);
    std::ofstream file;
    std::string makeLogEntry(std::string message);

    public:
    Logger(void);
    ~Logger(void);
    void log(std::string const &dest, std::string const &message);
};

#endif