#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <memory>

struct SensorData {
    double x, y, z;  // Simplified example
};

class Sensor {
public:
    virtual std::string getName() const = 0;
    virtual SensorData readData() = 0;
    virtual ~Sensor() = default;
};

#endif // SENSOR_H
