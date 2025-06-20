#ifndef SENSOR_H
#define SENSOR_H
#include<iostream>

#include <string>
#include <memory>
#include "SensorData.h"
class Sensor {
public:
    virtual std::string getName() const = 0;
    virtual SensorData readData() = 0;
    virtual ~Sensor() = default;
};

#endif // SENSOR_H
