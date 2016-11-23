#ifndef GRAM_INDIVIDUAL_EVALUATOR
#define GRAM_INDIVIDUAL_EVALUATOR

#include "../population/individual/Individual.h"

namespace gram {
namespace individual {
/**
 * Class.
 */
class Evaluator {
 public:
  virtual int evaluate(gram::population::individual::Individual individual) = 0;
};
}
}

#endif // GRAM_INDIVIDUAL_EVALUATOR
