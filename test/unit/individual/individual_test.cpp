#include <gtest/gtest.h>

#include <gram/individual/Individual.h>

using namespace gram::individual;
using namespace gram::language;
using namespace gram::grammar;

TEST(individual_test, test_it_returns_valid_fitness) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{1, 2, 3};

  Individual individual(genotype, language);

  individual.setFitness(1.5);
  double fitness = individual.getFitness();

  ASSERT_EQ(1.5, fitness);
}

TEST(individual_test, test_it_rejects_negative_fitness) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{1, 2, 3};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.setFitness(-1), std::logic_error);
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{1, 2, 3};

  Individual individual(genotype, language);

  ASSERT_THROW(individual.getFitness(), std::logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{1, 2, 3};

  Individual individual1(genotype, language);
  Individual individual2(genotype, language);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype1{1, 2, 3};
  Genotype genotype2{3, 2, 1};

  Individual individual1(genotype1, language);
  Individual individual2(genotype2, language);

  ASSERT_TRUE(individual1 != individual2);
}
