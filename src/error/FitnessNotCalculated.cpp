#include "gram/error/FitnessNotCalculated.h"

using namespace gram;

FitnessNotCalculated::FitnessNotCalculated() : logic_error("Gram error: Fitness not calculated yet.") {
  //
}
