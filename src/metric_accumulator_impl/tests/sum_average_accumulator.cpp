#include "test_data_producer.hpp"
#include "metric.hpp"

#include <algorithm>
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

const auto metrics_vector = TestDataProducer<SumAverageAccumulator>::Metrics();

// здесь ваш код
TEST(SumAverageCase, RegularUsageCase) {
    SumAverageAccumulator saa;
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 12);
    EXPECT_DOUBLE_EQ(avg, 4.);
}

TEST(SumAverageCase, EmptyAccumulatorTest)
{
    SumAverageAccumulator saa;
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 0);
    EXPECT_DOUBLE_EQ(avg, 0.);
}

TEST(SumAverageCase, ResetNothrowCase)
{

    SumAverageAccumulator saa;
    std::ranges::for_each(metrics_vector, [&saa](const auto &met) { saa.Accumulate(met); });
    saa.Reset();
    saa.Finalize();
    auto [sum, avg] = saa.Get();
    EXPECT_EQ(sum, 0);
    EXPECT_DOUBLE_EQ(avg, 0.);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
