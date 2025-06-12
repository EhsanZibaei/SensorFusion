#include "SensorManager.h"
#include "FusionModule.h"
#include "IMUSensor.h"
#include "GPSSensor.h"
#include<iostream>

int main() {
    
    auto imu = std::make_unique<IMUSensor>();
    auto gps = std::make_unique<GPSSensor>();

    SensorManager manager;
    manager.addSensor(std::move(imu));
    manager.addSensor(std::move(gps));


    auto data = manager.readAllSensors();

    FusionModule fusion;
    auto result = fusion.fuse(data);

    std::cout << "Fused Sensor Data:" << std::endl;
    std::cout << "x: " << result.fusedX << ", y: " << result.fusedY << ", z: " << result.fusedZ << std::endl;
    return 0;
}