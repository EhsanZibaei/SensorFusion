cmake_minimum_required(VERSION 3.10)
project(SensorFusionProject)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    src/IMUSensor.cpp
    src/GPSSensor.cpp
    src/SensorManager.cpp
    src/FusionModule.cpp
    main.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(sensor_fusion ${SOURCES})
