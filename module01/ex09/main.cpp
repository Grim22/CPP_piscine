#include "Logger.hpp"

int main()
{
    Logger log;
    log.log("console", "console log1");
    log.log("console", "console log2");
    log.log("file", "file log1");
    log.log("file", "file log2");
}