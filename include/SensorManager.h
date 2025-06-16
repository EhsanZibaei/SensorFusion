#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <vector>
#include <memory>
#include "Sensor.h"

class SensorManager {
public:
    void addSensor(std::shared_ptr<Sensor> sensor);
    std::vector<SensorData> readAllSensors() const;
    std::vector<std::string> getNames();
private:
    std::vector<std::shared_ptr<Sensor>> sensors_;
};

#endif
