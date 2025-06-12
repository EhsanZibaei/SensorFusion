#include "GPSSensor.h"

GPSSensor::GPSSensor() = default;

std::string GPSSensor::getName() const {
    return "GPS Sensor";

}

SensorData GPSSensor::readData() {
    return SensorData{0.0, 0.0, 0.0};
}
