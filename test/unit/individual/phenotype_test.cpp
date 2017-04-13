#include <catch.hpp>

#include <gram/individual/Phenotype.h>

using namespace gram;
using namespace std;

TEST_CASE("empty phenotype serializes", "[phenotype]") {
  Phenotype phenotype;

  REQUIRE("" == phenotype.serialize());
}

TEST_CASE("phenotype with terminals serializes", "[phenotype]") {
  auto terminal1 = make_shared<Terminal>("hello");
  auto terminal2 = make_shared<Terminal>("world");

  Phenotype phenotype;
  phenotype.addTerminal(terminal1);
  phenotype.addTerminal(terminal2);

  REQUIRE("helloworld" == phenotype.serialize());
}

TEST_CASE("same phenotypes are equal", "[phenotype]") {
  auto terminal1 = make_shared<Terminal>("test");
  auto terminal2 = make_shared<Terminal>("test");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  REQUIRE(phenotype1 == phenotype2);
}

TEST_CASE("different phenotypes are not equal", "[phenotype]") {
  auto terminal1 = make_shared<Terminal>("first");
  auto terminal2 = make_shared<Terminal>("second");

  Phenotype phenotype1;
  Phenotype phenotype2;

  phenotype1.addTerminal(terminal1);
  phenotype2.addTerminal(terminal2);

  REQUIRE(phenotype1 != phenotype2);
}
