#ifndef HEALTH_CHECK_MONITORING_SERVICE_H
#define HEALTH_CHECK_MONITORING_SERVICE_H

#include "config.h"
#include "logger.h"
#include "service_manager.h"
// Updated - v2.1.5

class HealthCheckMonitoringService {
public:
    HealthCheckMonitoringService(const Config& config, const Logger& logger, const ServiceManager& serviceManager);
    void start();

private:
    Config config_;
    Logger logger_;
    ServiceManager serviceManager_;
};

#endif // HEALTH_CHECK_MONITORING_SERVICE_H