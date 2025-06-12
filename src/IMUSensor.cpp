#include "IMUSensor.h"

IMUSensor::IMUSensor() = default;

std::string IMUSensor::getName() const {
    return "IMU Sensor";
}

SensorData IMUSensor::readData() {
    return SensorData{1.0, 0.0, 0.0};
}
