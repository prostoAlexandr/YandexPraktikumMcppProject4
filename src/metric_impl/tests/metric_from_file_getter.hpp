#pragma once

#include <file.hpp>
#include <function.hpp>
#include <string>

namespace analyzer::metric::metric_impl {

template <typename T>
auto metric_from_file(std::string sv) {
    using namespace analyzer;
    file::File file("/workspaces/YandexPraktikumMcppProject4/src/metric_impl/tests/files/" + sv);
    T lines_metric;
    return function::FunctionExtractor{}.Get(file) |
           std::views::transform([&lines_metric](auto &&func) { return lines_metric.Calculate(func).value; }) |
           std::ranges::to<std::vector>();
};

}  // namespace analyzer::metric::metric_impl