#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Reproducer> reproducer, unsigned long number)
    : individuals(individuals), reproducer(reproducer), _number(number) {
  //
}

double Population::bestFitness() const {
  return bestIndividual().getFitness();
}

Individual& Population::bestIndividual() const {
  return individuals.bestIndividual();
}

Individual& Population::operator[](unsigned long index) const {
  return individuals[index];
}

unsigned long Population::size() const {
  return individuals.size();
}

unsigned long Population::number() const {
  return _number;
}

void Population::evaluate(Evaluator& evaluator) {
  for (auto& individual : individuals) {
    individual->evaluate(evaluator);
  }
}

Population Population::reproduce() const {
  Individuals successors = reproducer->reproduce(individuals);

  unsigned long newNumber = _number + 1;

  return Population(successors, reproducer, newNumber);
}
