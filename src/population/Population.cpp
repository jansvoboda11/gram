#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Reproducer> reproducer, unsigned long number)
    : individuals(individuals), reproducer(reproducer), _number(number) {
  //
}

double Population::bestFitness() {
  return bestIndividual().getFitness();
}

Individual& Population::bestIndividual() {
  return individuals.bestIndividual();
}

Individual& Population::operator[](unsigned long index) {
  return individuals[index];
}

unsigned long Population::size() const {
  return individuals.size();
}

unsigned long Population::number() const {
  return _number;
}

void Population::evaluate(Evaluator& evaluator) {
  // todo: create EvaluationDrivers for serial and parallel evaluation

  for (auto& individual : individuals) {
    individual.evaluate(evaluator);
  }
}

Population Population::reproduce() {
  Individuals successors = reproducer->reproduce(individuals);

  unsigned long newNumber = _number + 1;

  return Population(successors, reproducer, newNumber);
}
