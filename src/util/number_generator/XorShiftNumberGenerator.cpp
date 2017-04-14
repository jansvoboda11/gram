#include <gram/util/number_generator/XorShiftNumberGenerator.h>

#include <random>

using namespace gram;
using namespace std;

XorShiftNumberGenerator::XorShiftNumberGenerator() {
  random_device device;

  state = device();
}

unsigned long XorShiftNumberGenerator::generate() {
  uint32_t nextState = state;

  nextState ^= nextState << 13;
  nextState ^= nextState >> 17;
  nextState ^= nextState << 5;

  state = nextState;

  return nextState;
}

unsigned long XorShiftNumberGenerator::getMax() {
  return numeric_limits<uint32_t>::max();
}
