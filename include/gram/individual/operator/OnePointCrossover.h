#ifndef GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER_OPERATOR
#define GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER_OPERATOR

#include <memory>

#include <gram/individual/operator/Crossover.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class OnePointCrossover : public Crossover {
 public:
  OnePointCrossover(std::unique_ptr<NumberGenerator> numberGenerator);
  virtual Genotype apply(const Genotype& first, const Genotype& second) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_ONE_POINT_CROSSOVER_OPERATOR
