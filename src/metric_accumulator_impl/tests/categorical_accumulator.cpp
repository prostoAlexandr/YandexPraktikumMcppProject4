

#include "test_data_producer.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

const auto metrics_vector = TestDataProducer<CategoricalAccumulator>::Metrics();

TEST(CategoricalCase, RegularUsageCase) {
    CategoricalAccumulator cat_ac;
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result["CamelCase"], 2);
    EXPECT_EQ(result["Undefined"], 1);
}

TEST(CategoricalCase, EmptyAccumulatorTest)
{
    CategoricalAccumulator cat_ac;
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 0);
}

TEST(CategoricalCase, ResetNothrowCase)
{

    CategoricalAccumulator cat_ac;
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    cat_ac.Reset();
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 0);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
