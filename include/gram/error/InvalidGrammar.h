#ifndef GRAM_INVALID_GRAMMAR
#define GRAM_INVALID_GRAMMAR

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class InvalidGrammar : public std::domain_error {
public:
  InvalidGrammar();
};
}

#endif
