#include "config.h"
#include <fstream>
#include <json/json.h>

Config::Config() : logLevel_("INFO"), port_("8080") {}

void Config::load(const std::string& filename) {
    Json::Value root;
    std::ifstream file(filename);
    file >> root;

    logLevel_ = root.get("log_level", "INFO").asString();
    port_ = root.get("port", "8080").asString();
    Json::Value services = root.get("services", Json::Value(Json::arrayValue));
    for (const auto& service : services) {
        services_.push_back(service.asString());
    }
}

std::string Config::getLogLevel() const {
    return logLevel_;
}

std::string Config::getPort() const {
    return port_;
}

std::vector<std::string> Config::getServices() const {
    return services_;
}