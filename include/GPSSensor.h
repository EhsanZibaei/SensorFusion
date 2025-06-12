#ifndef GPSSENSOR_H
#define GPSSENSOR_H

#include "Sensor.h"

class GPSSensor : public Sensor {
public:
    GPSSensor();
    std::string getName() const override;
    SensorData readData() override;
};

#endif // GPSSENSOR_H
