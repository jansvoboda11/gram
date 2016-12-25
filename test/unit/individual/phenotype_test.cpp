#include <gtest/gtest.h>

#include <gram/individual/Phenotype.h>

using namespace gram;


TEST(phenotype_test, test_it_serializes_terminals) {
  Terminal terminal("hello");
  Terminal terminal2("world");

  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  phenotype.addTerminal(terminal2);

  ASSERT_EQ("helloworld", phenotype.serialize());
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
