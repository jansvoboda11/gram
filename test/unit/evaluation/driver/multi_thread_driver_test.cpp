#include "gram/evaluation/driver/MultiThreadDriver.h"

#include <catch.hpp>
#include <fakeit.hpp>

#include <memory>

#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("multi thread driver evaluates all individuals in a population", "[multi_thread_driver]") {
  Individual individual1(Genotype({0, 0, 0}));
  Individual individual2(Genotype({1, 1, 1}));
  Individual individual3(Genotype({2, 2, 2}));

  Individuals individuals({individual1, individual2, individual3});

  Mock<SingleThreadDriver> driverMock1;
  Mock<SingleThreadDriver> driverMock2;
  Mock<SingleThreadDriver> driverMock3;

  Fake(Dtor(driverMock1));
  Fake(Dtor(driverMock2));
  Fake(Dtor(driverMock3));

  Fake(Method(driverMock1, evaluateOne));
  Fake(Method(driverMock2, evaluateOne));
  Fake(Method(driverMock3, evaluateOne));

  auto driver1 = unique_ptr<SingleThreadDriver>(&driverMock1.get());
  auto driver2 = unique_ptr<SingleThreadDriver>(&driverMock2.get());
  auto driver3 = unique_ptr<SingleThreadDriver>(&driverMock3.get());

  vector<unique_ptr<SingleThreadDriver>> drivers;
  drivers.push_back(move(driver1));
  drivers.push_back(move(driver2));
  drivers.push_back(move(driver3));

  MultiThreadDriver driver(move(drivers));

  driver.evaluate(individuals);

  Verify(Method(driverMock1, evaluateOne)).AtLeastOnce();
  Verify(Method(driverMock2, evaluateOne)).AtLeastOnce();
  Verify(Method(driverMock3, evaluateOne)).AtLeastOnce();
}
