#ifndef GRAM_NO_INDIVIDUALS
#define GRAM_NO_INDIVIDUALS

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class NoIndividuals : std::out_of_range {
public:
  NoIndividuals();
};
}

#endif
