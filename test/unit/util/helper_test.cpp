#include "gram/util/helper.h"

#include <catch.hpp>

using namespace gram;
using namespace std;

TEST_CASE("explode string containing the given delimiter", "[helper]") {
  vector<string> pieces = explode("hello world, she said", " ");

  REQUIRE(pieces.size() == 4);
  REQUIRE(pieces[0] == "hello");
  REQUIRE(pieces[1] == "world,");
  REQUIRE(pieces[2] == "she");
  REQUIRE(pieces[3] == "said");
}

TEST_CASE("explode ignores string that does not contain the given delimiter", "[helper]") {
  vector<string> pieces = explode("hello world", "x");

  REQUIRE(pieces.size() == 1);
  REQUIRE(pieces[0] == "hello world");
}

TEST_CASE("explode handles multiple delimiters in a row", "[helper]") {
  vector<string> pieces = explode("hello world", "l");

  REQUIRE(pieces.size() == 4);
  REQUIRE(pieces[0] == "he");
  REQUIRE(pieces[1] == "");
  REQUIRE(pieces[2] == "o wor");
  REQUIRE(pieces[3] == "d");
}

TEST_CASE("left trim deletes whitespace on the left", "[helper]") {
  string trimmed = left_trim(" \n hello world ");

  REQUIRE(trimmed == "hello world ");
}

TEST_CASE("left trim handles string with no whitespace on the left", "[helper]") {
  string trimmed = left_trim("hello world");

  REQUIRE(trimmed == "hello world");
}

TEST_CASE("left trim handles empty string", "[helper]") {
  string trimmed = left_trim("");

  REQUIRE(trimmed == "");
}
