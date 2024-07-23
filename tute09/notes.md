# Notes

### 9.1: Introduction to Templates

**What are templates in C++**
- Mechanism used by C++ to allow programmers to use types as variables in code
- Roughly speaking, it achieves the same goal as Java generics, which is compile time polymorphism. However the way it does so is different
- Templates can be thought of as code generation
- Many tools provided by the STL are templated. For example, `std::vector<T>`
    - If we instantiate a `std::vector<T>` to contain integers, C++ will make a copy of the `std::vector<T>` source code and replace every occurrance of `T` with `int`

**Why do code that use templates need to exist in header files?**
- The process of building C++ code involves preprocessing, compilation, assembler and linking
    - Preprocessing: deal with anything that begins with `#` like `#include`
    - Compilation: parse raw C++ code, perform syntatic and semantic analysis and generate assembly code
        - This is when template instantiations get converted to code
        - We need the definition of templates now so the compiler knows what the generate
        - This is also why templates make compilation take longer
    - Linking: produces the final shared library or executable
        - Link declarations from headers to their definitions that were originally in `.cpp` files

### 9.2 Template Specialisation

**What is template specialisation**
- The templates defined so far like `template<typename T>` are completely generic in the sense that `T` can literally be anything
- There may be situations where we need to refine this generic type to be something more specific
    - Partial specialisation: the templated type takes on a different "form"
        ```C++
        template<typename T>
        struct is_pointer : std::false_type {}

        template<typename T> // partial specialisation where the template is allowed to work for pointers
        struct is_pointer<T*> : std::true_type {}
        ```
    - Explicit specialisation: the templated types takes on a concrete type
        ```C++
        template<typename T>
        struct is_void : std::false_type {}

        template<> // explicit specialisation where T is replaced with void
        struct is_void<void> : std::true_type {}
        ```

**When not to specialise**
- Don't specialise if you want to change the behaviour of a class for a specific type
    - Example: specialising `std::stack<std::string>` such that `.pop` removes the earliest inserted element is not cool
- Refer to lecture slides for more examples

**What does the `...` syntax mean**
Programmer can provide as many types as they like

**Showcase how we can perform evaluations at compile time using `constexpr` because the information that the type `sunk` emits**