#ifndef GRAM_INDIVIDUAL_INVERSE_ONE_POINT_CROSSOVER_OPERATOR
#define GRAM_INDIVIDUAL_INVERSE_ONE_POINT_CROSSOVER_OPERATOR

#include <gram/individual/operator/Crossover.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
class InverseOnePointCrossover : public Crossover {
 public:
  InverseOnePointCrossover(std::unique_ptr<NumberGenerator> numberGenerator);
  virtual Genotype apply(const Genotype& first, const Genotype& second) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_INVERSE_ONE_POINT_CROSSOVER_OPERATOR
