#include <gram/error/InvalidProbability.h>

using namespace gram;

InvalidProbability::InvalidProbability() : domain_error("Gram error: Probability has invalid value.") {
  //
}
