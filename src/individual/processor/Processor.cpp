#include <gram/individual/processor/Processor.h>

using namespace gram;
using namespace std;

Processor::Processor(Evaluator &evaluator, FitnessCalculator &calculator)
    : evaluator(evaluator), calculator(calculator) {
  //
}

double Processor::process(string program, int goal) {
  int result = evaluator.evaluate(program);

  return calculator.calculate(goal, result);
}
