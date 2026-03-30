#include "health_check_monitoring_service.h"
#include "config.h"
#include "logger.h"
#include "service_manager.h"

int main(int argc, char* argv[]) {
    // Load configuration
    Config config;
    config.load(".env");

    // Initialize logger
    Logger logger(config.getLogLevel());

    // Create service manager
    ServiceManager serviceManager(config.getServices());

    // Start health check monitoring service
    HealthCheckMonitoringService healthCheckMonitoringService(config, logger, serviceManager);
    healthCheckMonitoringService.start();

    return 0;
}