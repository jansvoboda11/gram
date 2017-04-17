#include "gram/language/symbol/Terminal.h"

#include <catch.hpp>

using namespace gram;

TEST_CASE("same terminals are equal", "[terminal]") {
  Terminal terminal1("test");
  Terminal terminal2("test");

  REQUIRE(terminal1 == terminal2);
}

TEST_CASE("different terminals are not equal", "[terminal]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  REQUIRE(terminal1 != terminal2);
}
