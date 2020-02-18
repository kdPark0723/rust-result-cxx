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

void assert(bool pass) {
    if (pass)
        std::cout << "Is True.\n";
    else
        std::cout << "Is False.\n";
}

int main() {
    auto result = div_test(10, 2);

    assert(result.is_ok());
    assert(result.contains(5));
    assert(result.contains_err("Cant divided zero."));
//
//    result.ok().

    std::cout << div_test(10, 2).unwarp() << "\n";

    std::cout << div_test(10, 0).unwarp() << "\n";
    return 0;
}