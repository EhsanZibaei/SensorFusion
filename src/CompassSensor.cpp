#include "CompassSensor.h"

CompassSensor::CompassSensor(std::string given_name):name(given_name){
};

std::string CompassSensor::getName() const{
    return name;
}

SensorData CompassSensor::readData(){

    return SensorData{25.0, 26.0, 27.0};
} 
