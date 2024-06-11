#ifndef COMP6771_INVERSE_MAPPINGS_H
#define COMP6771_INVERSE_MAPPINGS_H

#include <map>
#include <string>

/**
 * @brief invert the keys and values of the given map. if, after the inversion, the same key
 * appears multiple times, only the key-value pair with the longest string should be kept
 * in the resulting map
 */
auto invert(const std::map<std::string, int>& mp) -> std::map<int, std::string>;

#endif // COMP6771_INVERSE_MAPPINGS_H