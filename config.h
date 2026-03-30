#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    Config();
    void load(const std::string& filename);
    std::string getLogLevel() const;
    std::string getPort() const;
    std::vector<std::string> getServices() const;

private:
    std::string logLevel_;
    std::string port_;
    std::vector<std::string> services_;
};

#endif // CONFIG_H