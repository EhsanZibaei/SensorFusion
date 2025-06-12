#ifndef FUSIONMODULE_H
#define FUSIONMODULE_H

#include<vector>
#include "Sensor.h"

struct FusionResult {
    double fusedX;
    double fusedY;
    double fusedZ;
};

class FusionModule {
    public:
    FusionResult fuse(const std::vector<SensorData>& sensorDataList) const;

};
#endif