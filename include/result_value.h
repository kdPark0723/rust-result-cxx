//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUST_RESULT_RESULT_VALUE_H
#define RUST_RESULT_RESULT_VALUE_H

namespace rust {

template <typename T>
class ResultVale {
public:
    constexpr ResultVale(const T value) : value{value} {}
    const T value;
};

}

#endif //RUST_RESULT_RESULT_VALUE_H
