#include <gram/evolution/Evolution.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::language;
using namespace gram::population;

Individual Evolution::run(int populationSize, int iterationCount) {
  Population population = initializer->initialize(populationSize);
  processGeneration(population);

  for (int i = 0; i < iterationCount; i++) {
    if (population.bestIndividual().getFitness() == 0) {
      break;
    }

    population = generator->generateSuccessor(population);

    processGeneration(population);
  }

  return population.bestIndividual();
}

void Evolution::processGeneration(Population &population) {
  for (auto &individual : population) {
    Phenotype phenotype = mapper->map(individual.getGenotype());
    individual.setPhenotype(phenotype);

    int result = evaluator->evaluate(individual);
    double fitness = calculator->calculate(5, result);
    individual.setFitness(fitness);
  }
}

void Evolution::setGenerator(Generator *newGenerator) {
  generator = newGenerator;
}

void Evolution::setEvaluator(Evaluator *newEvaluator) {
  evaluator = newEvaluator;
}

void Evolution::setCalculator(FitnessCalculator *newCalculator) {
  calculator = newCalculator;
}

void Evolution::setMapper(gram::individual::Mapper *newMapper) {
  mapper = newMapper;
}

void Evolution::setInitializer(Initializer *newInitializer) {
  initializer = newInitializer;
}
