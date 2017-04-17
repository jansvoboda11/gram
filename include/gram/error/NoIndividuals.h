#ifndef GRAM_ERROR_NO_INDIVIDUALS
#define GRAM_ERROR_NO_INDIVIDUALS

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

#endif // GRAM_ERROR_NO_INDIVIDUALS
