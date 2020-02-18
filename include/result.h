//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUST_RESULT_RESULT_H
#define RUST_RESULT_RESULT_H

#include <optional>
#include <functional>

#include "result_value.h"
#include "ok.h"
#include "err.h"

namespace rust {

template <typename T, typename E>
class Result {
    using _Ok = Ok<T>;
    using _Err = Err<E>;

    using _Ok_Ref = Ok<T*>;
    using _Err_Ref = Err<E*>;
public:
    inline Result(const _Ok &ok) : ok_value{ok}, err_value{} {}
    inline Result(const _Err &err) : ok_value{}, err_value{err} {}

public:
    inline bool contains(const T &x) const noexcept {
        if (is_err())
            return false;
        return unwrap() == x;
    }

    inline bool contains_err(const E &e) const noexcept {
        if (is_ok())
            return false;
        return unwrap_err() == e;
    }

    inline Result<T*, E*> as_ref() noexcept {
        if (!is_ok())
            return _Err_Ref{const_cast<E*>(&(*err_value).value)};
        return _Ok_Ref{const_cast<T*>(&(*ok_value).value)};
    }

    inline T unwrap() const {
        if (!is_ok())
            throw (*err_value).value;
        return (*ok_value).value;
    }

    inline E unwrap_err() const {
        if (!is_err())
            throw (*ok_value).value;
        return (*err_value).value;
    }

    inline T unwrap_or(const T &optb) {
        if (!is_ok())
            throw optb;
        return (*ok_value).value;
    }

    inline T unwrap_or_else(const std::function<T(const E&)> &op) {
        if (!is_ok())
            throw op((*err_value).value);
        return (*ok_value).value;
    }

    inline bool is_ok() const noexcept {
        return ok_value.has_value();
    }
    inline bool is_err() const noexcept {
        return err_value.has_value();
    }

    inline std::optional<_Ok> ok() const noexcept {
        return ok_value;
    }

    inline std::optional<_Err> err() const noexcept {
        return err_value;
    }

private:
    bool success;

    std::optional<_Ok> ok_value;
    std::optional<_Err> err_value;
};

}

#endif //RUST_RESULT_RESULT_H
