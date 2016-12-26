#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/processor/Processor.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(processor_test, test_it_processes_program) {
  Mock<Evaluator> evaluatorMock;
  Fake(Dtor(evaluatorMock));
  When(Method(evaluatorMock, evaluate)).Return(20);

  Mock<FitnessCalculator> calculatorMock;
  Fake(Dtor(calculatorMock));
  When(Method(calculatorMock, calculate)).Return(0.6);

  unique_ptr<Evaluator> evaluator(&evaluatorMock.get());
  unique_ptr<FitnessCalculator> calculator(&calculatorMock.get());

  Processor processor(move(evaluator), move(calculator));

  double fitness = processor.process("hello world", 5);

  ASSERT_NEAR(0.6, fitness, 0.001);
}
