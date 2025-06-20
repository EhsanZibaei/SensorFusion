#include "FusionModule.h"
#include <numeric>
#include "FusionResult.h"

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
    std::cout << "DEBUG: Called fuse(const std::vector<SensorData>) - move semantics enabled!" << std::endl;

    return result;
}

FusionResult FusionModule::fuse(std::vector<SensorData>&& sensorDataList) const {
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
    std::cout << "DEBUG: Called fuse(std::vector<SensorData>&&) - move semantics enabled!" << std::endl;
    return result;
}