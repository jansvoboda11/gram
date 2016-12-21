#include <gram/population/processor/Processor.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::language;
using namespace gram::evolution;

Processor::Processor(Evaluator &evaluator, FitnessCalculator &calculator) 
    : evaluator(evaluator), calculator(calculator) {
  //
}

void Processor::process(Population &population) {
  for (auto &individual : population) {
    int result = evaluator.evaluate(individual);
    double fitness = calculator.calculate(5, result);
    individual->setFitness(fitness);
  }
}
