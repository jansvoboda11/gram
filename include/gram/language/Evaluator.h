#ifndef GRAM_LANGUAGE_EVALUATOR
#define GRAM_LANGUAGE_EVALUATOR

#include <gram/individual/Individual.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class Evaluator {
 public:
  virtual int evaluate(gram::individual::Individual individual) = 0;
};
}
}

#endif // GRAM_LANGUAGE_EVALUATOR
