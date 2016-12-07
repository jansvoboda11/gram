#ifndef GRAM_GRAMMAR_GRAMMAR
#define GRAM_GRAMMAR_GRAMMAR

#include <gram/grammar/Rule.h>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class Grammar {
 public:
  Grammar(std::weak_ptr<Rule> startRule);
  std::shared_ptr<Rule> getStartRule();
 private:
  std::weak_ptr<Rule> startRule;
};
}
}

#endif // GRAM_GRAMMAR_GRAMMAR
