#include "SensorManager.h"
#include "FusionModule.h"
#include "IMUSensor.h"
#include "GPSSensor.h"
#include<iostream>

int main() {
    
    auto imu = std::make_shared<IMUSensor>("hd_imu");
    auto gps = std::make_unique<GPSSensor>();

    SensorManager manager;
    manager.addSensor(imu);
    manager.addSensor(std::move(gps));


    auto data = manager.readAllSensors();

    auto printSensors = [&manager](){
        for (const auto& sensorName: manager.getNames()){
            std::cout << "sensor: " << sensorName << std::endl; 
        }
    };
    printSensors();

    FusionModule fusion;
    auto result = fusion.fuse(data);

    std::cout << "Fused Sensor Data:" << std::endl;
    std::cout << "x: " << result.fusedX << ", y: " << result.fusedY << ", z: " << result.fusedZ << std::endl;
    
    auto my_lambda = [&imu] () {
        std::cout << "This is the name of imu: " << imu->getName() << std::endl;
    };
    my_lambda();

    std::unique_ptr<IMUSensor> imu_unique(new IMUSensor("e.g. "));
    std::cout << "This is the second imu: " << imu_unique->getName() << std::endl;
    
    return 0;
}