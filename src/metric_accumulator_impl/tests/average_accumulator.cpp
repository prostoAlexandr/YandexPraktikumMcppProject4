#include "test_data_producer.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

const auto metrics_vector = TestDataProducer<AverageAccumulator>::Metrics();

TEST(AverageCase, RegularUsageCase) {
    AverageAccumulator aac;
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 4.);
}

TEST(AverageCase, EmptyAccumulatorTest)
{
    AverageAccumulator aac;
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 0.);
}

TEST(AverageCase, ResetNothrowCase)
{

    AverageAccumulator aac;
    std::ranges::for_each(metrics_vector, [&aac](const auto &met) { aac.Accumulate(met); });
    aac.Reset();
    aac.Finalize();
    EXPECT_DOUBLE_EQ(aac.Get(), 0.);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
