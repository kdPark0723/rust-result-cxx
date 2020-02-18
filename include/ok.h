//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUST_RESULT_OK_H
#define RUST_RESULT_OK_H

#include "result_value.h"

namespace rust {

template <typename T>
class Ok : public ResultVale<T> {
public:
    constexpr Ok(const T value) : ResultVale<T>{value} {}
};

}

#endif //RUST_RESULT_OK_H
