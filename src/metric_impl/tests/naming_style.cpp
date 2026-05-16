#include "metric_impl/naming_style.hpp"
#include "metric_from_file_getter.hpp"

#include <gtest/gtest.h>
#include <string>

namespace analyzer::metric::metric_impl {

// filename, expected result
class NamingStyleCheck : public ::testing::TestWithParam<std::pair<std::string, std::vector<std::string>>> {};

TEST_P(NamingStyleCheck, NamingStyleCheck) {
    auto [file, expected_val] = GetParam();

    auto function_lines = metric_from_file<NamingStyleMetric>(file);

    EXPECT_EQ(function_lines.size(), expected_val.size());
    std::ranges::for_each(std::views::zip(function_lines, expected_val), [](auto &&pair) {
        auto &[val, test_val] = pair;
        ASSERT_TRUE(std::holds_alternative<std::string>(val));
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

using namespace std::string_literals;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    BasicCases,
    NamingStyleCheck,
    ::testing::Values(
        std::make_pair("comments.py",           std::vector{"Unknown"s}),
        std::make_pair("exceptions.py",         std::vector{"Unknown"s}),
        std::make_pair("if.py",                 std::vector{"Camel Case"s}),
        std::make_pair("loops.py",              std::vector{"Pascal Case"s}),
        std::make_pair("many_lines.py",         std::vector{"Lower Case"s}),
        std::make_pair("many_parameters.py",    std::vector{"Snake Case"s}),
        std::make_pair("match_case.py",         std::vector{"Unknown"s}),
        std::make_pair("nested_if.py",          std::vector{"Pascal Case"s}),
        std::make_pair("simple.py",             std::vector{"Snake Case"s}),
        std::make_pair("ternary.py",            std::vector{"Unknown"s})
    )
);
// clang-format on

}  // namespace analyzer::metric::metric_impl
