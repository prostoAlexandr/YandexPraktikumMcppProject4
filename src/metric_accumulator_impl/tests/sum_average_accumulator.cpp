#include "metric_accumulator_impl/sum_average_accumulator.hpp"
#include "metric.hpp"

#include <algorithm>
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

// здесь ваш код
TEST(SumAverageCase, RegularUsageCase) {
    SumAverageAccumulator saa;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 12);
    EXPECT_DOUBLE_EQ(avg, 4.);
}

TEST(SumAverageCase, NoFinalizeTest) {

    SumAverageAccumulator saa;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    EXPECT_THROW(saa.Get(), std::runtime_error);
}

TEST(SumAverageCase, EmptyAccumulatorTest)
{
    SumAverageAccumulator saa;
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 0);
    EXPECT_DOUBLE_EQ(avg, 0.);
}

TEST(SumAverageCase, ResetThrowCase)
{
    SumAverageAccumulator saa;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    saa.Reset();
    EXPECT_THROW(saa.Get(), std::runtime_error);
}

TEST(SumAverageCase, ResetNothrowCase)
{

    SumAverageAccumulator saa;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    saa.Reset();
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 0);
    EXPECT_DOUBLE_EQ(avg, 0.);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
