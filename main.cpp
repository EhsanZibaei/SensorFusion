#include "SensorManager.h"
#include "FusionModule.h"
#include "IMUSensor.h"
#include "GPSSensor.h"
#include<iostream>

int main() {
    
    std::shared_ptr<Sensor> imu = std::make_shared<IMUSensor>();
    std::shared_ptr<Sensor> gps = std::make_shared<GPSSensor>();

    SensorManager manager;
    manager.addSensor(imu);
    manager.addSensor(gps);

    auto data = manager.readAllSensors();

    FusionModule fusion;
    auto result = fusion.fuse(data);

    std::cout << "Fused Sensor Data:" << std::endl;
    std::cout << "x: " << result.fusedX << ", y: " << result.fusedY << ", z: " << result.fusedZ << std::endl;
    return 0;
}