#ifndef FUSIONMODULE_H
#define FUSIONMODULE_H

#include<vector>
#include "Sensor.h"
#include "FusionResult.h"
#include "SensorDataN.h"

class FusionModule {
    public:
    FusionResult fuse(const std::vector<SensorData>& sensorDataList) const;
    FusionResult fuse(std::vector<SensorData>&& sensorDataList) const;

    template<size_t N>
    FusionResultN<N> fuse_generic(const std::vector<SensorDataN<N>>& sensorDataList) const {
        FusionResultN<N> result;
        if (sensorDataList.empty()) {
            return result;
        }

        for (const auto& data : sensorDataList) {
            for (size_t i = 0; i < N; ++i){
                result.fused_values[i] += data.values[i];
            }
        }

        double count = static_cast<double>(sensorDataList.size());
        for (size_t i = 0; i < N; ++i){
            result.fused_values[i] /= count;
        }

        return result;
    }
};
#endif