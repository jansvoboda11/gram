#ifndef GRAM_FITNESS_NOT_CALCULATED
#define GRAM_FITNESS_NOT_CALCULATED

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

#endif
