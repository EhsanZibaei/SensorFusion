#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <vector>
#include <memory>
#include "Sensor.h"

class SensorManager {
public:
    void addSensor(std::unique_ptr<Sensor> sensor);
    std::vector<SensorData> readAllSensors() const;
private:
    std::vector<std::unique_ptr<Sensor>> sensors_;
};

#endif // SENSORMANAGER_H
