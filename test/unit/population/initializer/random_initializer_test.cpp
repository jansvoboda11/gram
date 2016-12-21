#include <gtest/gtest.h>

#include <gram/population/initializer/RandomInitializer.h>

#include "../../../lib/fakeit/fakeit.hpp"

using namespace gram::population;
using namespace gram::individual;
using namespace gram::util;
using namespace gram::grammar;
using namespace gram::language;

using namespace fakeit;

TEST(random_initializer_test, test_it_initializes_individuals_with_random_genotype) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype1{0, 1, 2};
  Genotype genotype2{3, 0, 1};
  Genotype genotype3{2, 3, 0};

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);
  Individual individual3(genotype3, language);

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generateMany))
      .Return(std::vector<unsigned long>{0, 1, 2})
      .Return(std::vector<unsigned long>{3, 0, 1})
      .Return(std::vector<unsigned long>{2, 3, 0});

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  RandomInitializer initializer(std::move(numberGenerator), language, 3);

  Population population = initializer.initialize(3);

  ASSERT_EQ(individual1, *population[0]);
  ASSERT_EQ(individual2, *population[1]);
  ASSERT_EQ(individual3, *population[2]);
}
