//
// Created by siyualpark on 20. 2. 18..
//

#include <iostream>
#include "../include/err.h"

int main() {
    auto a = rust::Err<int>{10};

    std::cout << a.unwarp();
    return 0;
}