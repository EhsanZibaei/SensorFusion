#include "SensorManager.h"
#include<iostream>
#include<string>
#include<vector>

void SensorManager::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors_.push_back(std::move(sensor));
}

std::vector<SensorData> SensorManager::readAllSensors() const {

    
    std::vector<SensorData> allData;
    for (const auto& sensor : sensors_) {
        allData.push_back(sensor->readData());
    }
    return allData;
}

std::vector<std::string> SensorManager::getNames(){
    std::vector<std::string> names;
    for (const auto &sensor : sensors_){
        names.push_back(sensor->getName());
    }
    return names;
}

