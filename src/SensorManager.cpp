#include "SensorManager.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

void SensorManager::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors_.push_back(sensor);
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

void SensorManager::removeSensor(const std::string& sensor_name){
    auto it = std::remove_if(sensors_.begin(), sensors_.end(),
        [&](std::shared_ptr<Sensor> sensor){return sensor->getName() == sensor_name;});
    sensors_.erase(it, sensors_.end());
}



