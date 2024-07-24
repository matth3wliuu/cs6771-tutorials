#ifndef A2ED8F36_5FFB_42F8_A541_B0983ECDD0DF
#define A2ED8F36_5FFB_42F8_A541_B0983ECDD0DF

#include <type_traits>

template<typename... Ts>
struct sink : std::true_type {}; /* 1 */

template<typename T>
struct sink<int, T> : std::false_type {}; /* 2 */

using sunk = sink<int, void>;

#endif /* A2ED8F36_5FFB_42F8_A541_B0983ECDD0DF */
