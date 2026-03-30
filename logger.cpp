#include "logger.h"
#include <iostream>

Logger::Logger(const std::string& logLevel) : logLevel_(logLevel) {}

void Logger::log(const std::string& message) {
    if (logLevel_ == "DEBUG") {
        std::cout << "DEBUG: " << message << std::endl;
    } else if (logLevel_ == "INFO") {
        std::cout << "INFO: " << message << std::endl;
    } else if (logLevel_ == "WARNING") {
        std::cout << "WARNING: " << message << std::endl;
    } else if (logLevel_ == "ERROR") {
        std::cout << "ERROR: " << message << std::endl;
    } else if (logLevel_ == "CRITICAL") {
        std::cout << "CRITICAL: " << message << std::endl;
    }
}