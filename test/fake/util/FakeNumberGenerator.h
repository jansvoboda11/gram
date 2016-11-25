#ifndef GRAM_FAKE_NUMBER_GENERATOR
#define GRAM_FAKE_NUMBER_GENERATOR

#include <util/NumberGenerator.h>

namespace gram {
namespace fake {
namespace util {
/**
 * Class.
 */
class FakeNumberGenerator : public gram::util::NumberGenerator {
 public:
  int generate();
};
}
}
}

#endif // GRAM_FAKE_NUMBER_GENERATOR
