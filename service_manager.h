#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <string>
#include <vector>

class Service {
public:
    Service(const std::string& id, const std::string& name);
    std::string getId() const;
    std::string getName() const;
    std::string getStatus() const;

private:
    std::string id_;
    std::string name_;
    std::string status_;
};

class ServiceManager {
public:
    ServiceManager(const std::vector<std::string>& services);
    std::vector<Service> getServices() const;
    Service* getService(const std::string& id) const;

private:
    std::vector<Service> services_;
};

#endif // SERVICE_MANAGER_H