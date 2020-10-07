#include "Logger.hpp"
#include <iostream> // std::cout
#include <sstream> // std::stringstream
#include <ctime> // std::localtime
#include <iomanip> // std::setw / setfill

void Logger::logToConsole(std::string log)
{
    std::cout << log << std::endl;
}

void Logger::logToFile(std::string log)
{
    this->file << log << std::endl;
}

std::string Logger::makeLogEntry(std::string message) const
{
    std::stringstream ss;

    time_t time;
    tm *time_info;

    time = std::time(0);
    time_info = std::localtime(&time);
    ss << std::setfill('0') << "[" << time_info->tm_year + 1900 << std::setw(2) << time_info->tm_mon + 1 << std::setw(2) << time_info->tm_mday << "_"
        << std::setw(2) << time_info->tm_hour << std::setw(2) << time_info->tm_min << std::setw(2) << time_info->tm_sec << "] ";
    ss << message;
    return ss.str();
}

Logger::Logger(void)
{
    this->file.open("log_file", std::ofstream::trunc);
}

Logger::~Logger(void)
{
    this->file.close();
}

int set_index(std::string const &dest)
{
    if (dest=="console")
        return 0;
    if (dest=="file")
        return 1;
    else
    {
        std::cout << "destination must be either [console] or [file]" << std::endl;
        return -1;
    }    
}

void Logger::log(std::string const &dest, std::string const &message)
{
    int index;
    void (Logger::*ptr_to_func_member[2])(std::string log) = {&Logger::logToConsole, &Logger::logToFile};
    index = set_index(dest);
    if (index == -1)
        return ;
    (this->*ptr_to_func_member[index])(this->makeLogEntry(message));
}