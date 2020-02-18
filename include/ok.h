//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUSTY_RESULT_OK_H
#define RUSTY_RESULT_OK_H

namespace rusty {

template<typename T>
struct Ok {
    constexpr Ok(const T value) : value{value} {}

    const T value;
};

}

#endif //RUSTY_RESULT_OK_H
