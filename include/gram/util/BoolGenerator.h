#ifndef GRAM_UTIL_BOOL_GENERATOR
#define GRAM_UTIL_BOOL_GENERATOR

namespace gram {
namespace util {
/**
 * Class.
 */
class BoolGenerator {
 public:
  virtual bool generate() = 0;
  virtual std::vector<bool> generate(int count) = 0;
};
}
}

#endif // GRAM_UTIL_BOOL_GENERATOR
