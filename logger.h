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
// Updated - v7.9.5

#endif // LOGGER_H