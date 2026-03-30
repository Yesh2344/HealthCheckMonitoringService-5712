#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    Logger(const std::string& logLevel);
    void log(const std::string& message);

private:
    std::string logLevel_;
};

#endif // LOGGER_H