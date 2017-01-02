#ifndef GRAM_LANGUAGE_EVALUATOR
#define GRAM_LANGUAGE_EVALUATOR

#include <string>

namespace gram {
/**
 * Class.
 */
class Evaluator {
 public:
  virtual ~Evaluator() = default;
  virtual double evaluate(std::string program) const = 0;
};
}

#endif // GRAM_LANGUAGE_EVALUATOR
