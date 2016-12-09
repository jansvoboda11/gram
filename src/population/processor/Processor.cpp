#include <gram/population/processor/Processor.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::language;
using namespace gram::evolution;

Processor::Processor(Mapper &mapper, Evaluator &evaluator, FitnessCalculator &calculator)
    : mapper(mapper), evaluator(evaluator), calculator(calculator) {
  //
}

void Processor::process(Population &population) {
  for (auto &individual : population) {
    Phenotype phenotype = mapper.map(individual.getGenotype());
    individual.setPhenotype(phenotype);

    int result = evaluator.evaluate(individual);
    double fitness = calculator.calculate(5, result);
    individual.setFitness(fitness);
  }
}
