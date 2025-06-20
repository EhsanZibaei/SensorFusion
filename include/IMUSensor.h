#ifndef IMUSENSOR_H
#define IMUSENSOR_H
#include<iostream>

#include "Sensor.h"

class IMUSensor : public Sensor {
private:
    std::string name;
public:
    IMUSensor(const std::string& given_name);
    std::string getName() const override;
    SensorData readData() override;
    // ~IMUSensor() {std::cout << "destrcutor of IMU" << std::endl;};

};

#endif // IMUSENSOR_H
