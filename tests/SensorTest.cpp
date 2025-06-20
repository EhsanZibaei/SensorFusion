// #include "Sensor.h"
#include "IMUSensor.h"
#include <gtest/gtest.h>
#include "SensorManager.h"
#include "FusionModule.h"
#include "SensorDataN.h"
#include <iostream>

TEST(IMUTest, DISABLED_NameCheck) {
    IMUSensor* imu = new IMUSensor("hd_imu2");
    // auto imu = std::make_shared<IMUSensor>("standard_pointer");
    // auto imu = std::make_shared<IMUSensor>("hd_imu");
    EXPECT_EQ(imu->getName(), "hd_imu2");
}

TEST(UsingTemplates, DISABLED_SingleFusion){
    auto sensor1 = std::make_shared<IMUSensor>("sensor 1");
    auto sensor2 = std::make_shared<IMUSensor>("sensor 2");

    SensorManager sm;
    sm.addSensor(sensor1);
    sm.addSensor(sensor2);

    FusionModule fm;
    auto data = sm.readAllSensors();
    FusionResult result = fm.fuse(data);

    EXPECT_EQ(result.fusedX, 2.0);  
}


TEST(UsingTemplates, GenericFusion){
    SensorDataN<5> dataN = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<SensorDataN<5>> dataList = { dataN }; 

    FusionModule fm;

    FusionResultN<5> result = fm.fuse_generic(dataList);
    result.print();
}