#include "SensorManager.h"
#include<iostream>

void SensorManager::addSensor(std::unique_ptr<Sensor> sensor) {
    sensors_.push_back(std::move(sensor));
}

std::vector<SensorData> SensorManager::readAllSensors() const {
    [&](){
    for (const auto& sensor : sensors_){
        std::cout << "sensor: " << sensor->getName() << std::endl;
    }
    }();
    
    std::vector<SensorData> allData;
    for (const auto& sensor : sensors_) {
        allData.push_back(sensor->readData());
    }
    return allData;
}

