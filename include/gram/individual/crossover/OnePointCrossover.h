#ifndef GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER
#define GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER

#include <memory>

#include "gram/individual/Genotype.h"
#include "gram/individual/crossover/Crossover.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class OnePointCrossover : public Crossover {
public:
  OnePointCrossover(std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(const Genotype& first, const Genotype& second);

private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER
