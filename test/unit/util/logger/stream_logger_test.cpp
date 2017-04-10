#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/util/helper.h>
#include <gram/util/logger/StreamLogger.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(stream_logger_test, test_it_does_something) {
  ostream &stream = cout;

  Mock<Population> populationMock;
  Population population = populationMock.get();

  StreamLogger logger(stream);

  logger.log(population);

  // todo: verify that operator<< was called on the ostream
}
