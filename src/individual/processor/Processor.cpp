#include <gram/individual/processor/Processor.h>

using namespace gram;
using namespace std;

Processor::Processor(unique_ptr<Evaluator> evaluator, unique_ptr<FitnessCalculator> fitnessCalculator)
    : evaluator(move(evaluator)), fitnessCalculator(move(fitnessCalculator)) {
  //
}

double Processor::process(string program, int goal) const {
  int result = evaluator->evaluate(program);

  return fitnessCalculator->calculate(goal, result);
}
