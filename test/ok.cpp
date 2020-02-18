//
// Created by siyualpark on 20. 2. 18..
//

#include <iostream>
#include "../include/ok.h"

int main() {
    auto a = rust::Ok<int>{10};

    std::cout << a.unwarp() << "\n";
    return 0;
}