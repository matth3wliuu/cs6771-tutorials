# Tutorial 10

### Background

The `std::function` utility from the C++ standard library is an abstraction over callable objects. As such, instances of `std::function` can store, copy and invoke callable objects like lambda expressions, bind expressions, pointers to member functions, etc...

Some examples include:
```C++
#include <functional>

auto some_func(std::string s) -> std::size_t {
    return s.size();
}

auto main() -> int {
    /* lambda expression */
    auto fun1 = std::function<int(int)>([] (int x) {
        return x;
    });

    fun1(42); // output: 42

    /* class that implements a call operator */
    struct BinarySum {
        auto operator()(int a, int b) -> int { return a + b; }
    } binary_sum;

    auto fun2 = std::function<int(int, int)>(binary_sum);

    fun2(40, 2); // output: 42

    /* function defined in the TU */
    auto fun3 = std::function(some_func);

    fun3(std::string("hello world")); // output: 11
}

```

### Our Task

Work through the following questions and implement a toy version of `std::function` called `Function`.

**Question 1**

The type signature of `fun1`, `fun2` and `fun3` all seem to be different. For example, `fun1` accepts one integer and returns one integer, while `fun2` accepts two integers and returns one integer.

What technique can we use to handle function objects with different return and argument types?

**Question 2**

Dynamic polymorphism allows a pointer / reference to a base class to bind an instance of a subclass

```C++
struct Animal {
    virtual auto name() const -> std::string = 0;
    virtual ~Animal() = default;
};

struct Dog : public Animal {
    auto name() const -> std::string override {
        return "Dog";
    }
    virtual ~Dog() = default;
};

struct Cat : public Animal {
    auto name() const -> std::string override {
        return "Cat";
    }
    virtual ~Cat() = default;
};

auto main() -> int {
    auto dptr = std::make_unique<Animal>(Dog());
    dptr->name(); // output: Dog
}
```

Simply put, the `Animal` class provides an "unifying interface" for all possible subtypes of animals

`std::function` seems to be provide this convenience for callable object types (i.e. lambdas, class with the call operator, etc). However, interestingly these callable types do not extend from the same base class or any base class for that fact... they are completely different to each other as far as their type goes.

Huh...

Part i) What are some common characteristics of these function objects?


Part ii) Is it possible to leverage these characteristics in some way to replicate an "unifying interface"?

**Question 3**

Our toy function class is useless if we can't instantiate it or invoke it.

Part i) Implement a constructor that can accept any type of function object
- Hint: Templated and universal reference

Part ii) Implement the call operator
- Hint: Ensure the value category of arguments passed in are retained

Note: things like the copy constructor have been as deleted because they are slightly inconvenient to implement based on our current code. Can you think of the reason?

**Question 4**

In tutorial 9, you saw an example of CTAD that allowed users to construct an instance of a templated class with explicitly writing the template parameters

Let's do the same thing with our toy `Function` class such that code like the following would compile

```c++
auto func(double x, int y, const std::string &z) -> std::string {
    return std::to_string(x) + std::to_string(y) + z;
}

auto main() -> int {
    auto fun1 =
        Function([](int, double) -> std::string { return std::string("hello"); });

    auto fun2 = Function(func);
}
```

Part i) Implement a deduction guide that will allow users to construct a `Function` using a function pointer

Part ii) As of C++17, the standard specifies 2 deduction guides for `std::function`

```C++
template< class R, class... ArgTypes >
function(R(*)(ArgTypes...)) -> function<R(ArgTypes...)>;

template<typename F >
function(F) -> std::function<R(A...)>; /* see below */
```

The first overload allows `std::function` to be deduced from functions

The second overload participates in overload resolution only if `&F::operator()` is well-formed when treated as an unevaluated operand and `decltype(&F::operator())` is of the form `R(G::*)(A...)`. The deduced type is `std::function<R(A...)>`.


Implement these two deduction guides for our toy function class
- Hint 1: Introduce a layer of indirection
- Hint 2: Consider type qualifiers like `&`, `const` and `const &`
