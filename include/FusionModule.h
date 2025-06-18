#ifndef FUSIONMODULE_H
#define FUSIONMODULE_H

#include<vector>
#include "Sensor.h"
#include "FusionResult.h"
class FusionModule {
    public:
    FusionResult fuse(const std::vector<SensorData>& sensorDataList) const;

};
#endif