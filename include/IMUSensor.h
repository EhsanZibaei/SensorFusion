#ifndef IMUSENSOR_H
#define IMUSENSOR_H

#include "Sensor.h"

class IMUSensor : public Sensor {
public:
    IMUSensor();
    std::string getName() const override;
    SensorData readData() override;
};

#endif // IMUSENSOR_H
