#ifndef GRAM_ERROR_FITNESS_NOT_CALCULATED
#define GRAM_ERROR_FITNESS_NOT_CALCULATED

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class FitnessNotCalculated : public std::logic_error {
 public:
  FitnessNotCalculated();
};
}

#endif // GRAM_ERROR_FITNESS_NOT_CALCULATED
