# Rusty Result

C++ implement Rust Standard library Result by using template

​    

## Usage

```c++
#include <iostream>
#include <stdexcept>
#include "../include/result.h"

using namespace rusty;

Result<int, std::exception> div_optional(int a, int b) {
    if (b == 0)
        return Err<std::exception>{std::runtime_error{"Cant divide by zero."}};

    return Ok<int>{a / b};
}

void check(bool pass) {
    if (pass)
        std::cout << "Is True.\n";
    else
        std::cout << "Is False.\n";
}

int main() {
    auto result{ div_optional(10, 2) };
    auto error_result{ div_optional(10, 0) };

    check(result.is_ok());
    check(result.contains(5));
    check(result.ok().has_value());

    check(result.unwrap_or_else([](const std::exception &str) -> auto { return 0; }) == 5);
    check(error_result.unwrap_or_else([](const std::exception &str) -> auto { return 0; }) == 0);

    std::cout << result.as_ref().unwrap() << "\n";
    std::cout << result.unwrap() << "\n";
    std::cout << error_result.unwrap() << "\n";  // throw error

    return 0;
}
```

    

## API
```c++
template <typename T, typename E>
class rusty::Result {
    Result(const Ok<T> &ok) noexcept;
    Result(const Err<E> &err) noexcept;
    Result(const Result<T, E> &other) noexcept;
    Result(Result<T, E> &&other) noexcept;

    Result& operator=(const Result<T, E> &other) noexcept
    Result& operator=(Result<T, E> &&other) noexcept
    
    bool contains(const T &x) const noexcept;
    bool contains_err(const E &e) const noexcept;

    Result<T*, E*> as_ref() noexcept;
              
    T& unwrap();
    const T& unwrap() const;
              
    E& unwrap_err();
    const E& unwrap_err() const;
              
    T& unwrap_or(const T &optb);
    const T& unwrap_or(const T &optb) const;
              
    T& unwrap_or_else(const std::function<T(const E&)> &op);
    const T& unwrap_or_else(const std::function<T(const E&)> &op) const;
              
    bool is_ok() const noexcept
    bool is_err() const noexcept
              
    std::optional<_Ok> ok() const noexcept;
    std::optional<_Err> err() const noexcept;
};
```
