// #include "Sensor.h"
#include "IMUSensor.h"
#include <gtest/gtest.h>

TEST(IMUTest, NameCheck) {
    IMUSensor* imu = new IMUSensor("hd_imu2");
    // auto imu = std::make_shared<IMUSensor>("standard_pointer");
    // auto imu = std::make_shared<IMUSensor>("hd_imu");
    EXPECT_EQ(imu->getName(), "hd_imu2");
}

