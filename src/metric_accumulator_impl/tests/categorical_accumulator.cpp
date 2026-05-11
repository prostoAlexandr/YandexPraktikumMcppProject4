

#include "metric_accumulator_impl/categorical_accumulator.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

// здесь ваш код
TEST(CategoricalCase, RegularUsageCase) {
    CategoricalAccumulator cat_ac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", "CamelCase"}, {"M2", "Undefined"}, {"M3", "CamelCase"}};
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result["CamelCase"], 2);
    EXPECT_EQ(result["Undefined"], 1);
}

TEST(CategoricalCase, NoFinalizeTest) {

    CategoricalAccumulator cat_ac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", "CamelCase"}, {"M2", "Undefined"}, {"M3", "CamelCase"}};
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    EXPECT_THROW(cat_ac.Get(), std::runtime_error);
}

TEST(CategoricalCase, EmptyAccumulatorTest)
{
    CategoricalAccumulator cat_ac;
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 0);
}

TEST(CategoricalCase, ResetThrowCase)
{
    CategoricalAccumulator cat_ac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", "CamelCase"}, {"M2", "Undefined"}, {"M3", "CamelCase"}};
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    cat_ac.Reset();
    EXPECT_THROW(cat_ac.Get(), std::runtime_error);
}

TEST(CategoricalCase, ResetNothrowCase)
{

    CategoricalAccumulator cat_ac;
    std::vector<analyzer::metric::MetricResult> metrics_vector = {{"M1", "CamelCase"}, {"M2", "Undefined"}, {"M3", "CamelCase"}};
    std::ranges::for_each(metrics_vector, [&cat_ac](const auto &met) { cat_ac.Accumulate(met); });
    cat_ac.Reset();
    cat_ac.Finalize();
    auto result = cat_ac.Get();
    EXPECT_EQ(result.size(), 0);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
