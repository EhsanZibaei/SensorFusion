#ifndef IMUSENSOR_H
#define IMUSENSOR_H

#include "Sensor.h"

class IMUSensor : public Sensor {
private:
    std::string name;
public:
    IMUSensor(std::string given_name);
    std::string getName() const override;
    SensorData readData() override;
};

#endif // IMUSENSOR_H
