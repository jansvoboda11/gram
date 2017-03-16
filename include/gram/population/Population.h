#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>
#include <gram/population/reproducer/Reproducer.h>
#include <gram/population/Individuals.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(Individuals individuals, std::shared_ptr<Reproducer> reproducer);
  double bestFitness() const;
  Individual& bestIndividual() const;
  Individual& operator[](unsigned long index) const;
  unsigned long size() const;
  void evaluate(Evaluator& evaluator);
  Population reproduce() const;
 private:
  Individuals individuals;
  std::shared_ptr<Reproducer> reproducer;
};
}

#endif // GRAM_POPULATION
