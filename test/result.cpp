//
// Created by siyualpark on 20. 2. 18..
//

#include <iostream>
#include <string>
#include "../include/result.h"

rust::Result<int, std::string> div_test(int a, int b) {
    if (b == 0)
        return rust::Err<std::string>{"Cant divided zero."};

    return rust::Ok<int>{a / b};
}

void check(bool pass) {
    if (pass)
        std::cout << "Is True.\n";
    else
        std::cout << "Is False.\n";
}

int main() {
    auto result = div_test(10, 2);
    auto error_result = div_test(10, 0);
    check(result.is_ok());
    check(result.contains(5));
    check(result.contains_err("Cant divided zero."));
    check(result.ok().has_value());

    check(result.unwrap_or_else([](const std::string &str) -> int { return 0; }) == 5);
    check(error_result.unwrap_or_else([](const std::string &str) -> int { return 0; }) == 0);

    std::cout << result.as_ref().unwrap() << "\n";

    std::cout << div_test(10, 2).unwrap() << "\n";
    std::cout << div_test(10, 0).unwrap() << "\n";
    return 0;
}