//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUST_RESULT_ERR_H
#define RUST_RESULT_ERR_H

#include "result_value.h"

namespace rust {

template <typename T>
class Err : public ResultVale<T> {
public:
    constexpr Err(const T value) : ResultVale<T>{value} {}
};

}

#endif //RUST_RESULT_ERR_H
