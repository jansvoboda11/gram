#ifndef GRAM_LANGUAGE_EVALUATOR
#define GRAM_LANGUAGE_EVALUATOR

#include <string>

namespace gram {
namespace language {
/**
 * Class.
 */
class Evaluator {
 public:
  virtual int evaluate(std::string program) = 0;
};
}
}

#endif // GRAM_LANGUAGE_EVALUATOR
