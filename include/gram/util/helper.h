#ifndef GRAM_UTIL_HELPER
#define GRAM_UTIL_HELPER

#include <string>
#include <vector>

namespace gram {
/**
 * Function.
 */
std::vector<std::string> explode(std::string input, std::string delimiter);
/**
 * Function.
 */
std::string left_trim(std::string input);
}

#endif // GRAM_UTIL_HELPER
