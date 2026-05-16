#pragma once

#include "metric_accumulator_impl/average_accumulator.hpp"
#include "metric_accumulator_impl/categorical_accumulator.hpp"
#include "metric_accumulator_impl/sum_average_accumulator.hpp"

namespace analyzer::metric_accumulator::metric_accumulator_impl {

template <typename T>
struct TestDataProducer {
    static auto Metrics() {
        using namespace analyzer::metric_accumulator::metric_accumulator_impl;
        using namespace analyzer::metric;
        if constexpr (std::is_same_v<AverageAccumulator, T> || std::is_same_v<SumAverageAccumulator, T>) {
            return std::vector<MetricResult>{{"M1", 1}, {"M2", 2}, {"M3", 9}};
        } else if constexpr (std::is_same_v<CategoricalAccumulator, T>) {
            return std::vector<MetricResult>{{"M1", "CamelCase"}, {"M2", "Undefined"}, {"M3", "CamelCase"}};
        } else {
            static_assert(false, "TestDataProducer: unsupported accumulator type");
        }
    }
};

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test