#include <gtest/gtest.h>

#include <gram/population/processor/Processor.h>
#include <gram/individual/MapperMock.h>
#include <gram/language/EvaluatorMock.h>
#include <gram/evolution/fitness_calculator/FitnessCalculatorMock.h>

using namespace gram::grammar;
using namespace gram::language;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::evolution;

TEST(processor_test, test_something) {
  auto startSymbol = std::make_shared<NonTerminal>();
  gram::grammar::Grammar grammar(startSymbol);

  MapperMock mapper(grammar);
  EvaluatorMock evaluator;
  FitnessCalculatorMock calculator;

  Processor processor(mapper, evaluator, calculator);
}
