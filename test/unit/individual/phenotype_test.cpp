#include <catch.hpp>

#include <gram/individual/Phenotype.h>

using namespace gram;

TEST_CASE("empty phenotype serializes", "[phenotype]") {
  Phenotype phenotype;

  REQUIRE("" == phenotype.serialize());
}

TEST_CASE("phenotype with terminals serializes", "[phenotype]") {
  Terminal terminal("hello");
  Terminal terminal2("world");

  Phenotype phenotype;
  phenotype.addTerminal(terminal);
  phenotype.addTerminal(terminal2);

  REQUIRE("helloworld" == phenotype.serialize());
}

TEST_CASE("same phenotypes are equal", "[phenotype]") {
  Terminal terminal1("test");
  Terminal terminal2("test");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  REQUIRE(phenotype1 == phenotype2);
}

TEST_CASE("different phenotypes are not equal", "[phenotype]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  REQUIRE(phenotype1 != phenotype2);
}
