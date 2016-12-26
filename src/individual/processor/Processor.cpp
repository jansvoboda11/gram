#include <gram/individual/processor/Processor.h>

using namespace gram;
using namespace std;

Processor::Processor(unique_ptr<Evaluator> evaluator, unique_ptr<FitnessCalculator> calculator)
    : evaluator(move(evaluator)), calculator(move(calculator)) {
  //
}

double Processor::process(string program, int goal) const {
  int result = evaluator->evaluate(program);

  return calculator->calculate(goal, result);
}
