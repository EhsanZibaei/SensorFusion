#ifndef SENSORDATAN_H
#define SENSORDATAN_H

#include <array>   



template<size_t N>
struct SensorDataN {
    std::array<double, N> values; // Stores N double values

    SensorDataN() = default;

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < N; ++i) {
            std::cout << values[i] << (i == N - 1 ? "" : ", ");
        }
        std::cout << "]";
    }
};

template<size_t N>
struct FusionResultN {
    std::array<double, N> fused_values; 

    FusionResultN() {
        fused_values.fill(0.0);
    }

    void print() const {
        std::cout << "{";
        for (size_t i = 0; i < N; ++i) {
            std::cout << fused_values[i] << (i == N - 1 ? "" : ", ");
        }
        std::cout << "}";
    }
};

#endif // SENSORDATAN_H
