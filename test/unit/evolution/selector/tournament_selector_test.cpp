#include <gtest/gtest.h>

#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/util/number_generator/NumberGeneratorMock.h>
#include <gram/individual/IndividualMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;
using namespace gram::language;
using namespace gram::grammar;

using ::testing::NiceMock;
using ::testing::Return;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Population population{};

  NiceMock<NumberGeneratorMock> generator;

  TournamentSelector selector(generator);

  ASSERT_THROW(selector.select(population), std::logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{0};

  auto individual = std::make_shared<NiceMock<Individual>>(genotype, language);
  Population population{individual};

  NiceMock<NumberGeneratorMock> generator;

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual, selectedIndividual);
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  Terminal terminal("hello");
  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);
  auto start = std::make_shared<NonTerminal>();
  start->addOption(option);
  Grammar grammar(start);
  Mapper mapper(grammar);
  Language language(grammar, mapper);

  Genotype genotype{0};

  NiceMock<NumberGeneratorMock> generator;
  EXPECT_CALL(generator, generate())
      .WillOnce(Return(1))
      .WillOnce(Return(3));

  auto individual1 = std::make_shared<NiceMock<IndividualMock>>(genotype, language);
  auto individual2 = std::make_shared<NiceMock<IndividualMock>>(genotype, language);
  auto individual3 = std::make_shared<NiceMock<IndividualMock>>(genotype, language);
  auto individual4 = std::make_shared<NiceMock<IndividualMock>>(genotype, language);

  ON_CALL(*individual1, getFitness())
      .WillByDefault(Return(0.0));
  ON_CALL(*individual2, getFitness())
      .WillByDefault(Return(1.0));
  ON_CALL(*individual3, getFitness())
      .WillByDefault(Return(2.0));
  ON_CALL(*individual4, getFitness())
      .WillByDefault(Return(3.0));

  Population population{individual1, individual2, individual3, individual4};

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual2, selectedIndividual);
}
