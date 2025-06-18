#include "IMUSensor.h"

IMUSensor::IMUSensor(const std::string& given_name):name(given_name) {
};

std::string IMUSensor::getName() const {
    return name;
}

SensorData IMUSensor::readData() {
    return SensorData{1.0, 0.0, 0.0};
}
