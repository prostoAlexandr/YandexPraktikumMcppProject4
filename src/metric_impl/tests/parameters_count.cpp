#include "metric_impl/parameters_count.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// здесь ваш код
auto params_count_getter = [](std::string sv) {
    file::File file("/workspaces/YandexPraktikumMcppProject4/src/metric_impl/tests/files/" + sv);
    analyzer::metric::metric_impl::CountParametersMetric lines_metric;
    return function::FunctionExtractor{}.Get(file) |
           std::views::transform([&lines_metric](auto &&func) { return lines_metric.Calculate(func).value; }) |
           std::ranges::to<std::vector>();
};

TEST(ParamsCountCheck, CommentsPyTest) {
    auto params_counts = params_count_getter("comments.py");
    auto test = {3};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, ExceptionsPyTest) {
    auto params_counts = params_count_getter("exceptions.py");
    auto test = {0};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, IfPyTest) {
    auto params_counts = params_count_getter("if.py");
    auto test = {1};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, LoopsPyTest) {
    auto params_counts = params_count_getter("loops.py");
    auto test = {1};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, ManyLinesPyTest) {
    auto params_counts = params_count_getter("many_lines.py");
    auto test = {0};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, ManyParametersPyTest) {
    auto params_counts = params_count_getter("many_parameters.py");
    auto test = {5};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, MatchCasePyTest) {
    auto params_counts = params_count_getter("match_case.py");
    auto test = {1};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, NestedIfPyTest) {
    auto params_counts = params_count_getter("nested_if.py");
    auto test = {2};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, SimplePyTest) {
    auto params_counts = params_count_getter("simple.py");
    auto test = {0};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(ParamsCountCheck, TernaryPyTest) {
    auto params_counts = params_count_getter("ternary.py");
    auto test = {1};
    EXPECT_EQ(params_counts.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(params_counts, test)) {
        EXPECT_EQ(val, test_val);
    }
}

}  // namespace analyzer::metric::metric_impl
