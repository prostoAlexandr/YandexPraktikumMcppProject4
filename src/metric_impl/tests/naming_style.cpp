#include "metric_impl/naming_style.hpp"

#include <gtest/gtest.h>
#include <string>

namespace analyzer::metric::metric_impl {

// здесь ваш код
auto naming_style_getter = [](std::string sv) {
    file::File file("/workspaces/YandexPraktikumMcppProject4/src/metric_impl/tests/files/" + sv);
    analyzer::metric::metric_impl::NamingStyleMetric lines_metric;
    return function::FunctionExtractor{}.Get(file) |
           std::views::transform([&lines_metric](auto &&func) { return lines_metric.Calculate(func).value; }) |
           std::ranges::to<std::vector>();
};

TEST(NamingStyleCheck, CommentsPyTest) {
    auto naming_style = naming_style_getter("comments.py");
    auto test = {"Unknown"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, ExceptionsPyTest) {
    auto naming_style = naming_style_getter("exceptions.py");
    auto test = {"Unknown"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, IfPyTest) {
    auto naming_style = naming_style_getter("if.py");
    auto test = {"Camel Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, LoopsPyTest) {
    auto naming_style = naming_style_getter("loops.py");
    auto test = {"Pascal Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, ManyLinesPyTest) {
    auto naming_style = naming_style_getter("many_lines.py");
    auto test = {"Lower Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, ManyParametersPyTest) {
    auto naming_style = naming_style_getter("many_parameters.py");
    auto test = {"Snake Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, MatchCasePyTest) {
    auto naming_style = naming_style_getter("match_case.py");
    auto test = {"Unknown"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, NestedIfPyTest) {
    auto naming_style = naming_style_getter("nested_if.py");
    auto test = {"Pascal Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, SimplePyTest) {
    auto naming_style = naming_style_getter("simple.py");
    auto test = {"Snake Case"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

TEST(NamingStyleCheck, TernaryPyTest) {
    auto naming_style = naming_style_getter("ternary.py");
    auto test = {"Unknown"};
    EXPECT_EQ(naming_style.size(), test.size());
    std::ranges::for_each(std::views::zip(naming_style, test), [](auto &&pair) {
        auto &[val, test_val] = pair;
        EXPECT_EQ(std::get<std::string>(val), test_val);
    });
}

}  // namespace analyzer::metric::metric_impl
