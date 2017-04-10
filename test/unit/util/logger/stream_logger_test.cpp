#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/util/helper.h>
#include <gram/util/logger/StreamLogger.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("stream logger writes to the given stream", "[stream_logger]") {
  ostream &stream = cout;

  Mock<Population> populationMock;
  Population population = populationMock.get();

  StreamLogger logger(stream);

  logger.log(population);

  // todo: verify that operator<< was called on the ostream
}
