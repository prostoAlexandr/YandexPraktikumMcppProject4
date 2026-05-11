#include "metric_accumulator_impl/average_accumulator.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

// здесь ваш код
TEST(AverageCase, RegularUsageCase) {
    AverageAccumulator aac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 4.);
}

TEST(AverageCase, NoFinalizeTest) {

    AverageAccumulator aac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    EXPECT_THROW(aac.Get(), std::runtime_error);
}

TEST(AverageCase, EmptyAccumulatorTest)
{
    AverageAccumulator aac;
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 0.);
}

TEST(AverageCase, ResetThrowCase)
{
    AverageAccumulator aac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    aac.Reset();
    EXPECT_THROW(aac.Get(), std::runtime_error);
}

TEST(AverageCase, ResetNothrowCase)
{

    AverageAccumulator aac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", 1}, {"M2", 2}, {"M3", 9}};
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    aac.Reset();
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 0.);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
