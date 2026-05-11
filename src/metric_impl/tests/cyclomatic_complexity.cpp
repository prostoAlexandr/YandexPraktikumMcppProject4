#include "metric_impl/cyclomatic_complexity.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// здесь ваш код
auto cyclomatic_complexity_getter = [](std::string sv) {
    file::File file("/workspaces/YandexPraktikumMcppProject4/src/metric_impl/tests/files/" + sv);
    analyzer::metric::metric_impl::CyclomaticComplexityMetric lines_metric;
    return function::FunctionExtractor{}.Get(file) |
           std::views::transform([&lines_metric](auto &&func) { return lines_metric.Calculate(func).value; }) |
           std::ranges::to<std::vector>();
};

TEST(CyclomaticComplexityCheck, CommentsPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("comments.py");
    auto test = {1};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, ExceptionsPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("exceptions.py");
    auto test = {4};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, IfPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("if.py");
    auto test = {2};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, LoopsPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("loops.py");
    auto test = {4};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, ManyLinesPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("many_lines.py");
    auto test = {2};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, ManyParametersPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("many_parameters.py");
    auto test = {2};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, MatchCasePyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("match_case.py");
    auto test = {4};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, NestedIfPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("nested_if.py");
    auto test = {4};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, SimplePyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("simple.py");
    auto test = {2};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

TEST(CyclomaticComplexityCheck, TernaryPyTest) {
    auto cyclomatic_complexity = cyclomatic_complexity_getter("ternary.py");
    auto test = {3};
    EXPECT_EQ(cyclomatic_complexity.size(), test.size());
    std::ranges::for_each(std::views::zip(cyclomatic_complexity, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<int>(val), test_val);
    });
}

}  // namespace analyzer::metric::metric_impl
