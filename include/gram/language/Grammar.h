#ifndef GRAM_GRAMMAR_GRAMMAR
#define GRAM_GRAMMAR_GRAMMAR

#include <gram/language/symbol/Option.h>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class Grammar {
 public:
  Grammar(std::shared_ptr<NonTerminal> startSymbol);
  std::shared_ptr<NonTerminal> startSymbol() const;
 private:
  std::weak_ptr<NonTerminal> start;
};
}
}

#endif // GRAM_GRAMMAR_GRAMMAR
