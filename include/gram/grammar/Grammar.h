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
  Grammar(Rule startRule);
  Rule getStartRule();
 private:
  Rule startRule;
};
}
}

#endif // GRAM_GRAMMAR_GRAMMAR
