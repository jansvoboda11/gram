#include <gtest/gtest.h>

#include <gram/individual/Phenotype.h>

using namespace gram::individual;
using namespace gram::grammar;

TEST(phenotype_test, test_it_accepts_terminal) {
  Terminal terminal("terminal");

  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Terminal acceptedTerminal = phenotype.terminalAt(0);

  ASSERT_EQ(terminal, acceptedTerminal);
}

TEST(phenotype_test, test_it_serializes_terminals) {
  Terminal terminal("hello");
  Terminal terminal2("world");

  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  phenotype.addTerminal(terminal2);

  std::string serialized = phenotype.serialize();

  ASSERT_EQ("helloworld", serialized);
}

TEST(phenotype_test, test_it_recognizes_two_equal_objects) {
  Terminal terminal1("test");
  Terminal terminal2("test");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  ASSERT_TRUE(phenotype1 == phenotype2);
}

TEST(phenotype_test, test_it_recognizes_two_different_objects) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  ASSERT_TRUE(phenotype1 != phenotype2);
}
