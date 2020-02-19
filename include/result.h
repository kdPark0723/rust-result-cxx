//
// Created by siyualpark on 20. 2. 18..
//

#ifndef RUSTY_RESULT_RESULT_H
#define RUSTY_RESULT_RESULT_H

#include <optional>
#include <functional>

#include "ok.h"
#include "err.h"

namespace rusty {

template<typename T, typename E>
class Result {
    using _Result = Result<T, E>;

    using _Ok = Ok<T>;
    using _Err = Err<E>;

    using _Result_Ref = Result<T *, E *>;

    using _Ok_Ref = Ok<T *>;
    using _Err_Ref = Err<E *>;

public:
    inline Result(const _Ok &ok) noexcept : ok_value{ok}, err_value{} {}

    inline Result(const _Err &err) noexcept : ok_value{}, err_value{err} {}

    inline Result(_Result &&other) noexcept : ok_value{std::move(other.ok_value)},
                                              err_value{std::move(other.err_value)} {}

    inline Result &operator=(_Result &&other) noexcept {
        ok_value = std::move(other.ok_value);
        err_value = std::move(other.err_value);
    }

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

    inline _Result_Ref as_ref() noexcept {
        if (!is_ok())
            return _Err_Ref{const_cast<E *>(&(*err_value).value)};
        return _Ok_Ref{const_cast<T *>(&(*ok_value).value)};
    }

    inline T &unwrap() {
        return const_cast<T &>(const_cast<const _Result *>(this)->unwrap());
    }

    inline const T &unwrap() const {
        if (!is_ok())
            throw (*err_value).value;
        return (*ok_value).value;
    }

    inline E &unwrap_err() {
        return const_cast<E &>(const_cast<const _Result *>(this)->unwrap_err());
    }

    inline const E &unwrap_err() const {
        if (!is_err())
            throw (*ok_value).value;
        return (*err_value).value;
    }

    inline T &unwrap_or(const T &optb) {
        return const_cast<T &>(const_cast<const _Result *>(this)->unwrap_or(optb));
    }

    inline const T &unwrap_or(const T &optb) const {
        if (!is_ok())
            return optb;
        return (*ok_value).value;
    }

    inline T &unwrap_or_else(const std::function<T &(const E &)> &op) {
        return const_cast<T &>(const_cast<const _Result *>(this)->unwrap_or_else(op));
    }

    inline const T &unwrap_or_else(const std::function<T &(const E &)> &op) const {
        if (!is_ok())
            return op((*err_value).value);
        return (*ok_value).value;
    }

    inline T &unwrap_or_else(const std::function<T &&(const E &)> &op) {
        return const_cast<T &>(const_cast<const _Result *>(this)->unwrap_or_else(op));
    }

    inline const T &unwrap_or_else(const std::function<T &&(const E &)> &op) const {
        if (!is_ok())
            return op((*err_value).value);
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
    std::optional<_Ok> ok_value{};
    std::optional<_Err> err_value{};
};

}

#endif //RUSTY_RESULT_RESULT_H
