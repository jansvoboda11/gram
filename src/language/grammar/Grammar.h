#ifndef GRAM_LANGUAGE_GRAMMAR_GRAMMAR
#define GRAM_LANGUAGE_GRAMMAR_GRAMMAR

#include "Rule.h"

namespace gram {
namespace language {
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
}

#endif // GRAM_LANGUAGE_GRAMMAR_GRAMMAR
