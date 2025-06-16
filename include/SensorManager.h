#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <vector>
#include <memory>
#include "Sensor.h"

class SensorManager {
public:
    void addSensor(std::shared_ptr<Sensor> sensor_ptr);
    std::vector<SensorData> readAllSensors() const;
    std::vector<std::string> getNames();
    void removeSensor(const std::string& sensor_name);
private:
    std::vector<std::shared_ptr<Sensor>> sensors_;
};

#endif
