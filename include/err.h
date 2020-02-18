//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUSTY_RESULT_ERR_H
#define RUSTY_RESULT_ERR_H

namespace rusty {

template<typename T>
struct Err {
    constexpr Err(const T value) : value{value} {}

    const T value;
};

}

#endif //RUST_RESULT_ERR_H
