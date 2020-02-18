//
// Created by siyualpark on 20. 2. 18..
//

#include <iostream>
#include <stdexcept>
#include "../include/result.h"

using namespace rusty;

Result<int, std::exception> div_optional(int a, int b) {
    if (b == 0)
        return Err<std::exception>{std::runtime_error{"Cant divide by zero."}};

    return Ok<int>{a / b};
}

void check(bool pass) {
    if (pass)
        std::cout << "Is True.\n";
    else
        std::cout << "Is False.\n";
}

int main() {
    auto result{ div_optional(10, 2) };
    auto error_result{ div_optional(10, 0) };

    check(result.is_ok());
    check(result.contains(5));
    check(result.ok().has_value());

    check(result.unwrap_or_else([](const std::exception &str) -> auto { return 0; }) == 5);
    check(error_result.unwrap_or_else([](const std::exception &str) -> auto { return 0; }) == 0);

    std::cout << result.as_ref().unwrap() << "\n";
    std::cout << result.unwrap() << "\n";
    std::cout << error_result.unwrap() << "\n";  // throw error

    return 0;
}