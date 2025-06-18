cmake_minimum_required(VERSION 3.10)
project(SensorFusionProject)

set(CMAKE_CXX_STANDARD 14)

add_library(sensor_core
    src/IMUSensor.cpp
    src/GPSSensor.cpp
    src/SensorManager.cpp
    src/FusionModule.cpp
    src/CompassSensor.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(sensor_fusion src/main.cpp)
target_link_libraries(sensor_fusion sensor_core)

# testing
enable_testing()
add_subdirectory(external/googletest)

add_executable(sensor_test tests/SensorTest.cpp)
target_link_libraries(sensor_test gtest gtest_main sensor_core)
