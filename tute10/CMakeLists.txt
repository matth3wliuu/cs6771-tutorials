# ------------------------------------------------------------ #
# -------------- DO NOT TOUCH BELOW THIS LINE ---------------- #
# ------------------------------------------------------------ #

# this must be the first line of a CMake script.
# sets the lowerbound on what CMake version can be used.
cmake_minimum_required(VERSION 3.0...3.5)

# the name of this CMake project and what language it uses
# we could list more languages if we were using more.
project(COMP6771_TUT_010 LANGUAGES CXX)

# we use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# this is helpful for editors like VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# helpful compiler flags for gcc/clang
# the descriptions for these flags can be found on the GNU Compiler Collection's webpage.
add_compile_options(
    -Wall
    -Wextra
    -Werror
    -pedantic-errors
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wcast-align
    -Wformat=2
    -Wuninitialized
    -Wnull-dereference
    -Wnon-virtual-dtor
    -Woverloaded-virtual
    -Wdeprecated-copy-dtor
    -Wold-style-cast
    -Wzero-as-null-pointer-constant
    -Wsuggest-override
    -fstack-protector-strong
)

# debug builds should be compiled with sanitizers
# sanitizers are small libraries that check things like buffer overrun with minimal runtime overhead.
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")

# ------------------------------------------------------------ #
# -------------- DO NOT MODIFY ABOVE THIS LINE --------------- #
# ------------------------------------------------------------ #

# 3.1
add_library(function_lib src/function.cpp)

add_executable(function_exec src/function.cpp)

# add_library(sort_descending src/3.1/sort_descending.cpp)
# link_libraries(sort_descending)

# add_executable(sort_descending_test src/3.1/sort_descending.test.cpp)
