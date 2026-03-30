#include "service_manager.h"

Service::Service(const std::string& id, const std::string& name)
    : id_(id), name_(name), status_("Unknown") {}

std::string Service::getId() const {
    return id_;
}

std::string Service::getName() const {
    return name_;
}

std::string Service::getStatus() const {
    return status_;
}

ServiceManager::ServiceManager(const std::vector<std::string>& services) {
    for (const auto& service : services) {
        services_.emplace_back(service, service);
    }
}

std::vector<Service> ServiceManager::getServices() const {
    return services_;
}

Service* ServiceManager::getService(const std::string& id) const {
    for (const auto& service : services_) {
        if (service.getId() == id) {
            return new Service(service.getId(), service.getName());
        }
    }
    return nullptr;
}