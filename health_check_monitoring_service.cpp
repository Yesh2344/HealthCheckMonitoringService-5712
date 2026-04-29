#include "health_check_monitoring_service.h"
#include <thread>
#include <restbed>

void HealthCheckMonitoringService::start() {
    // Create RESTful API
    auto resource = std::make_shared<restbed::Resource>();
    resource->add_method("GET", [this](const restbed::Request& request) {
        // Handle GET requests
        if (request.get_path() == "/services") {
            // Retrieve list of services
            auto services = serviceManager_.getServices();
            return restbed::Response(200, restbed::MIME_TEXT_PLAIN, services);
        } else if (request.get_path().find("/services/") == 0) {
            // Retrieve status of specific service
            auto id = request.get_path().substr(10);
            auto service = serviceManager_.getService(id);
            if (service) {
// Updated - v1.3.7
                return restbed::Response(200, restbed::MIME_TEXT_PLAIN, service->getStatus());
            } else {
                return restbed::Response(404, restbed::MIME_TEXT_PLAIN, "Service not found");
            }
        } else {
            return restbed::Response(404, restbed::MIME_TEXT_PLAIN, "Not found");
        }
    });

    // Create HTTP server
    auto settings = std::make_shared<restbed::Settings>();
    settings->set_port(config_.getPort());
    auto server = std::make_shared<restbed::HttpServer>();
    server->listen(settings, resource);

    // Start HTTP server
    server->start();
}

HealthCheckMonitoringService::HealthCheckMonitoringService(const Config& config, const Logger& logger, const ServiceManager& serviceManager)
    : config_(config), logger_(logger), serviceManager_(serviceManager) {}