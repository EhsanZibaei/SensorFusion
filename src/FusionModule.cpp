#include "FusionModule.h"
#include <numeric>

FusionResult FusionModule::fuse(const std::vector<SensorData>& sensorDataList) const {
    FusionResult result{0.0, 0.0, 0.0};
    if (sensorDataList.empty()) {
        return result;
    }

    for (const auto& data : sensorDataList) {
        result.fusedX += data.x;
        result.fusedY += data.y;
        result.fusedZ += data.z;
        
    }

    double count = static_cast<double>(sensorDataList.size());
    result.fusedX /= count;
    result.fusedY /= count;
    result.fusedZ /= count;

    return result;
}