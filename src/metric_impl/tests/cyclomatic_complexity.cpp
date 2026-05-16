#include "metric_impl/cyclomatic_complexity.hpp"
#include "metric_from_file_getter.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// filename, expected result
class CyclomaticComplexityCheck : public ::testing::TestWithParam<std::pair<std::string, std::vector<int>>> {};

TEST_P(CyclomaticComplexityCheck, CyclomaticComplexityCheck) {
    auto [file, expected_val] = GetParam();

    auto function_lines = metric_from_file<CyclomaticComplexityMetric>(file);

    EXPECT_EQ(function_lines.size(), expected_val.size());
    std::ranges::for_each(std::views::zip(function_lines, expected_val), [](auto &&pair) {
        auto &[val, test_val] = pair;
        ASSERT_TRUE(std::holds_alternative<int>(val));
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    BasicCases,
    CyclomaticComplexityCheck,
    ::testing::Values(
        std::make_pair("comments.py",           std::vector{1}),
        std::make_pair("exceptions.py",         std::vector{4}),
        std::make_pair("if.py",                 std::vector{2}),
        std::make_pair("loops.py",              std::vector{4}),
        std::make_pair("many_lines.py",         std::vector{2}),
        std::make_pair("many_parameters.py",    std::vector{2}),
        std::make_pair("match_case.py",         std::vector{4}),
        std::make_pair("nested_if.py",          std::vector{4}),
        std::make_pair("simple.py",             std::vector{2}),
        std::make_pair("ternary.py",            std::vector{3})
    )
);
// clang-format on

}  // namespace analyzer::metric::metric_impl
