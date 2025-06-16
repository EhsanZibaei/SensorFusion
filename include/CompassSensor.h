#ifndef COMPASSSENSOR_H
#define COMPASSSENSOR_H

#include "Sensor.h"

class CompassSensor : public Sensor {
    private:
        std::string name;
    public:
        CompassSensor(std::string given_name);

        std::string getName() const override;

        SensorData readData() override;       
};

#endif