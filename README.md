# Health Check Monitoring Service

A C++ application designed to monitor the health of various services and report their status.

## Installation

1. Clone the repository
2. Create a build directory and navigate to it
3. Run `cmake ..` to generate build files
4. Run `cmake --build .` to build the project
5. Copy the `.env.example` file to `.env` and configure as needed

## Usage

1. Run the application with `./health_check_monitoring_service`
2. Use the API to retrieve the status of services:
	* `GET /services`: Retrieve a list of all services
	* `GET /services/{id}`: Retrieve the status of a specific service

## API Documentation

### Services

#### GET /services
Retrieve a list of all services

* Response:
	+ 200 OK: List of services
	+ 500 Internal Server Error: Unable to retrieve services

#### GET /services/{id}
Retrieve the status of a specific service

* Parameters:
	+ id (string): The ID of the service
* Response:
	+ 200 OK: Status of the service
	+ 404 Not Found: Service not found
	+ 500 Internal Server Error: Unable to retrieve service status

## Badges

[![Build Status](https://travis-ci.org/username/health_check_monitoring_service.svg?branch=master)](https://travis-ci.org/username/health_check_monitoring_service)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)