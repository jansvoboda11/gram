#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/processor/Processor.h>

using namespace fakeit;
using namespace gram;

TEST(processor_test, test_it_processes_program) {
  Mock<Evaluator> evaluatorMock;
  When(Method(evaluatorMock, evaluate)).Return(20);

  Mock<FitnessCalculator> calculatorMock;
  When(Method(calculatorMock, calculate)).Return(0.6);

  Evaluator &evaluator = evaluatorMock.get();
  FitnessCalculator &fitnessCalculator = calculatorMock.get();

  Processor processor(evaluator, fitnessCalculator);

  double fitness = processor.process("hello world", 5);

  ASSERT_NEAR(0.6, fitness, 0.001);
}
