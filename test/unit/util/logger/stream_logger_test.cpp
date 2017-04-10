#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/util/logger/StreamLogger.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("stream logger writes to the given stream", "[stream_logger]") {
  // todo: verify that operator<< was called on the ostream
}
