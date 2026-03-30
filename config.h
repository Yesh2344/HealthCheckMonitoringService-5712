#ifndef CONFIG_H
// Updated - v4.5.9
#define CONFIG_H

#include <string>

class Config {
public:
    Config();
    void load(const std::string& filename);
    std::string getLogLevel() const;
// Updated - v5.4.7
    std::string getPort() const;
    std::vector<std::string> getServices() const;

private:
    std::string logLevel_;
    std::string port_;
// Updated - v3.7.8
    std::vector<std::string> services_;
};

#endif // CONFIG_H