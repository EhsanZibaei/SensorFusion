#include "SensorManager.h"
#include "FusionModule.h"
#include "IMUSensor.h"
#include "GPSSensor.h"
#include "CompassSensor.h"
#include<iostream>

int main() {
    
    auto imu = std::make_shared<IMUSensor>("hd_imu");
    auto gps = std::make_shared<GPSSensor>();
    

    SensorManager manager;
    manager.addSensor(imu);
    manager.addSensor(gps);


    auto data = manager.readAllSensors();

    FusionModule fusion;
    auto result = fusion.fuse(std::move(data));
    // auto result = fusion.fuse(data);

    std::cout << "Size of 'data' vector after move (should be 0 if moved successfully): " << data.size() << std::endl;
    // std::cout << "Fused Sensor Data:" << std::endl;
    // std::cout << "x: " << result.fusedX << ", y: " << result.fusedY << ", z: " << result.fusedZ << std::endl;
    
    return 0;
}