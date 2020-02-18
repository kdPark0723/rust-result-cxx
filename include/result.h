//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUST_RESULT_RESULT_H
#define RUST_RESULT_RESULT_H

#include <new>
#include <optional>

#include "result_value.h"
#include "ok.h"
#include "err.h"

namespace rust {

template <typename T, typename E>
class Result {
    using _Ok = Ok<T>;
    using _Err = Err<E>;
public:
    inline Result(const _Ok &ok) : ok_value{ok}, err_value{} {}
    inline Result(const _Err &err) : ok_value{}, err_value{err} {}

public:
    inline bool is_ok() const noexcept {
        return ok_value.has_value();
    }
    inline bool is_err() const noexcept {
        return err_value.has_value();
    }

    inline T unwarp() const {
        if (!is_ok())
            throw (*err_value).value;
        return (*ok_value).value;
    }

private:

    bool success;

    std::optional<_Ok> ok_value;
    std::optional<_Err> err_value;
};

}

#endif //RUST_RESULT_RESULT_H
