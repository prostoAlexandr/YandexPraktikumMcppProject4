#include "metric_impl/code_lines_count.hpp"
#include "file.hpp"
#include "function.hpp"

#include <algorithm>
#include <gtest/gtest.h>
#include <ranges>
#include <string>
#include <vector>

namespace analyzer::metric::metric_impl {

// здесь ваш код
auto lines_count_getter = [](std::string sv) {
    file::File file("/workspaces/YandexPraktikumMcppProject4/src/metric_impl/tests/files/" + sv);
    analyzer::metric::metric_impl::CodeLinesCountMetric lines_metric;
    return function::FunctionExtractor{}.Get(file) |
           std::views::transform([&lines_metric](auto &&func) { return lines_metric.Calculate(func).value; }) |
           std::ranges::to<std::vector>();
};

TEST(CodeLinesCheck, CommentsPyTest) {
    auto function_lines = lines_count_getter("comments.py");
    auto test = {3};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, ExceptionsPyTest) {
    auto function_lines = lines_count_getter("exceptions.py");
    auto test = {7};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, IfPyTest) {
    auto function_lines = lines_count_getter("if.py");
    auto test = {3};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, LoopsPyTest) {
    auto function_lines = lines_count_getter("loops.py");
    auto test = {6};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, ManyLinesPyTest) {
    auto function_lines = lines_count_getter("many_lines.py");
    auto test = {11};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, ManyParametersPyTest) {
    auto function_lines = lines_count_getter("many_parameters.py");
    auto test = {1};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, MatchCasePyTest) {
    auto function_lines = lines_count_getter("match_case.py");
    auto test = {7};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, NestedIfPyTest) {
    auto function_lines = lines_count_getter("nested_if.py");
    auto test = {8};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, SimplePyTest) {
    auto function_lines = lines_count_getter("simple.py");
    auto test = {5};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

TEST(CodeLinesCheck, TernaryPyTest) {
    auto function_lines = lines_count_getter("ternary.py");
    auto test = {1};
    EXPECT_EQ(function_lines.size(), test.size());
    for (const auto &[val, test_val] : std::views::zip(function_lines, test)) {
        EXPECT_EQ(val, test_val);
    }
}

}  // namespace analyzer::metric::metric_impl
