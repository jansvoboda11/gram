#include <gram/individual/processor/Processor.h>

using namespace gram::individual;
using namespace gram::language;

Processor::Processor(Evaluator &evaluator, FitnessCalculator &calculator) 
    : evaluator(evaluator), calculator(calculator) {
  //
}

double Processor::process(std::string program, int goal) {
  int result = evaluator.evaluate(program);

  return calculator.calculate(goal, result);
}
