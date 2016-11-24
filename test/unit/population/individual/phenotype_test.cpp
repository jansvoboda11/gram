#include <gtest/gtest.h>

#include <population/individual/Phenotype.h>

using namespace gram::population::individual;
using namespace gram::language::grammar;

TEST(phenotype_test, test_it_accepts_terminal) {
  Terminal terminal("terminal");

  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  ASSERT_EQ(terminal, phenotype.terminalAt(0));
}

TEST(phenotype_test, test_it_serializes_terminals) {
  Terminal firstTerminal("hello");
  Terminal secondTerminal("world");

  Phenotype phenotype;
  phenotype.addTerminal(firstTerminal);
  phenotype.addTerminal(secondTerminal);

  ASSERT_EQ("hello world", phenotype.serialize());
}

TEST(phenotype_test, test_it_recognizes_two_equal_objects) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  Phenotype firstPhenotype;
  firstPhenotype.addTerminal(firstTerminal);
  Phenotype secondPhenotype;
  secondPhenotype.addTerminal(secondTerminal);

  ASSERT_TRUE(firstPhenotype == secondPhenotype);
}

TEST(phenotype_test, test_it_recognizes_two_different_objects) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Phenotype firstPhenotype;
  firstPhenotype.addTerminal(firstTerminal);
  Phenotype secondPhenotype;
  secondPhenotype.addTerminal(secondTerminal);

  ASSERT_TRUE(firstPhenotype != secondPhenotype);
}
