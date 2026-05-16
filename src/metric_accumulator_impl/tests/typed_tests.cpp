#include <gtest/gtest.h>
#include <type_traits>
#include "test_data_producer.hpp"

/*
    Possible implementation of generic sests,
    but return value of Get is not unified between metrics.
    So suitable for throwing tests only
*/

using namespace analyzer::metric_accumulator::metric_accumulator_impl;

// объявляем типы и typed test suite
using AccTypes = ::testing::Types<CategoricalAccumulator, AverageAccumulator, SumAverageAccumulator>;

template <typename T>
class AccumulatorTest : public ::testing::Test {};

TYPED_TEST_SUITE(AccumulatorTest, AccTypes);

TYPED_TEST(AccumulatorTest, NoFinalizeTest)
{
    TypeParam acc;
    auto metrics_vector = TestDataProducer<TypeParam>::Metrics();

    std::ranges::for_each(metrics_vector, [&acc](const auto& m) { acc.Accumulate(m); });
    EXPECT_THROW(acc.Get(), std::runtime_error);
}

TYPED_TEST(AccumulatorTest, ResetThrowCase)
{
    TypeParam acc;
    auto metrics_vector = TestDataProducer<TypeParam>::Metrics();
    std::ranges::for_each(metrics_vector, [&acc](const auto &met) { acc.Accumulate(met); });
    acc.Reset();
    EXPECT_THROW(acc.Get(), std::runtime_error);
}