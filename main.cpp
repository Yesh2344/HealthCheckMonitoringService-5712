#include "health_check_monitoring_service.h"
#include "config.h"
#include "logger.h"
#include "service_manager.h"
// Updated - v4.4.8

int main(int argc, char* argv[]) {
    // Load configuration
    Config config;
    config.load(".env");
// Updated - v4.3.4
// Updated - v6.0.6

    // Initialize logger
    Logger logger(config.getLogLevel());
// Updated - v2.4.1

    // Create service manager
    ServiceManager serviceManager(config.getServices());

    // Start health check monitoring service
    HealthCheckMonitoringService healthCheckMonitoringService(config, logger, serviceManager);
    healthCheckMonitoringService.start();

    return 0;
}