#include <gram/evolution/Evolution.h>

using namespace gram::evolution;
using namespace gram::grammar;
using namespace gram::individual;
using namespace gram::language;
using namespace gram::population;
using namespace gram::util;

Evolution::Evolution(gram::grammar::Grammar &grammar, gram::language::Evaluator &evaluator)
    : grammar(grammar), evaluator(evaluator) {
  //
}

Individual Evolution::run(int populationSize, int iterationCount) {
  Population population = initializer->initialize(populationSize);
  processGeneration(population);

  for (int i = 0; i < iterationCount; i++) {
    if (population.bestIndividual().getFitness() == 0) {
      break;
    }

    population = generateGeneration(population);
    processGeneration(population);
  }

  return population.bestIndividual();
}

void Evolution::setCalculator(FitnessCalculator *newCalculator) {
  calculator = newCalculator;
}

void Evolution::setSelector(IndividualSelector *newSelector) {
  selector = newSelector;
}

void Evolution::setMapper(gram::individual::Mapper *newMapper) {
  mapper = newMapper;
}

void Evolution::setInitializer(Initializer *newInitializer) {
  initializer = newInitializer;
}

void Evolution::setCrossover(Crossover *newCrossover) {
  crossover = newCrossover;
}

void Evolution::setMutation(Mutation *newMutation) {
  mutation = newMutation;
}

void Evolution::processGeneration(Population &population) {
  for (auto &individual : population) {
    Phenotype phenotype = mapper->map(individual.getGenotype());
    individual.setPhenotype(phenotype);

    int result = evaluator.evaluate(individual);
    double fitness = calculator->calculate(5, result);
    individual.setFitness(fitness);
  }
}

Population Evolution::generateGeneration(Population &population) {
  std::vector<Individual> parents;

  for (int i = 0; i < population.size(); i++) {
    Individual parent = selector->select(population);
    parents.push_back(parent);
  }

  Population generated;

  for (int i = 0; i < population.size() - 1; i += 2) {
    Individual firstParent = parents[i];
    Individual secondParent = parents[i + 1];

    Genotype firstGenotype = crossover->apply(firstParent.getGenotype(), secondParent.getGenotype());
    Genotype secondGenotype = crossover->apply(secondParent.getGenotype(), firstParent.getGenotype());

    Individual firstChild(firstGenotype);
    Individual secondChild(secondGenotype);

    generated.addIndividual(firstChild);
    generated.addIndividual(secondChild);
  }

  for (auto &individual : generated) {
    Genotype oldGenotype = individual.getGenotype();
    Genotype mutatedGenotype = mutation->apply(oldGenotype);

    individual.setGenotype(mutatedGenotype);
  }

  return generated;
}
