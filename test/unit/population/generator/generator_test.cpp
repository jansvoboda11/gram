#include <gtest/gtest.h>

#include <gram/population/generator/Generator.h>
#include <gram/evolution/selector/IndividualSelectorMock.h>
#include <gram/evolution/operator/CrossoverMock.h>
#include <gram/evolution/operator/MutationMock.h>

using namespace gram::population;
using namespace gram::evolution;

TEST(generator_test, test_something) {
  IndividualSelectorMock selector;
  CrossoverMock crossover;
  MutationMock mutation;

  Generator generator(selector, crossover, mutation);
}
